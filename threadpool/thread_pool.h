//
// Created by ccp on 2023/3/10.
//


#ifndef TINYWEBSERVERINIT_THREAD_POOL_H
#define TINYWEBSERVERINIT_THREAD_POOL_H

#include "pthread.h"

class ThreadPool{
public:

    ThreadPool(int core_size,int max_size,int work_queue_size){
        this.core_size_ = core_size;
        this.max_size_ = max_size;
        this->work_queue_size_ = work_queue_size;
    }

    void append(){

    }


private:
    int core_size_;
    int max_size_;
    int work_queue_size_;
    std::pthread_t * work_queue_;
};








#endif //TINYWEBSERVERINIT_THREAD_POOL_H
