//
// Created by changwang on 2023/3/15.
//

#ifndef MYTINYWEBSERVER_THREAD_POOL_H
#define MYTINYWEBSERVER_THREAD_POOL_H


#include <queue>
#include <iostream>

template<typename T>
class thread_pool {
public:
    thread_pool(int pool_size) : pool_size_(pool_size) {};

    int add_task(T* task) {
        que_.push(task);
        do_task();
        return 0;
    }

    int do_task(){
        if(!que_.empty()){
            T* task = que_.front();
            que_.pop();
            task->do_run();
        }
        return 0;
    };

private:
    int pool_size_;
    std::queue<T*> que_;
};


#endif //MYTINYWEBSERVER_THREAD_POOL_H
