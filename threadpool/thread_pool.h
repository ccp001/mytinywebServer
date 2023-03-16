//
// Created by changwang on 2023/3/15.
//

#ifndef MYTINYWEBSERVER_THREAD_POOL_H
#define MYTINYWEBSERVER_THREAD_POOL_H


#include <queue>
#include <iostream>
#include <thread>

class thread_pool {
public:
    thread_pool(int core_size, int max_size) : core_size_(core_size), max_size_(max_size), active_size_(0) {};

    template<typename FUNC, typename ...ARG>
    void append(FUNC &&func, ARG &&...);
    ~thread_pool(){
        for (auto &item: thread_vec_){
            item.join();
        }
    }
private:
    int active_size_;
    int core_size_;
    int max_size_;
    std::queue<std::function<void()>> task_que_;
    std::vector<std::thread> thread_vec_;
};

template<typename FUNC, typename ...ARG>
void thread_pool::append(FUNC &&func, ARG &&...arg) {
    if (active_size_ < core_size_) {
        std::thread t([&]() {
            std::function<void()> run_task = [=]() { func(arg...); };
            while (true) {
                if (run_task) {
                    run_task();
                    run_task = nullptr;
                } else {
                    if (!task_que_.empty()) {
                        run_task = std::move(task_que_.front());
                        task_que_.pop();
                    } else {
                        run_task = nullptr;
                        std::cout<<"i am waiting task "<<std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                    }
                }
            }
        });
        active_size_++;
        thread_vec_.emplace_back(std::move(t));
    } else {
        task_que_.push([&]() { func(arg...); });
        auto task_func = task_que_.front();
        task_func();
    }
}


#endif //MYTINYWEBSERVER_THREAD_POOL_H
