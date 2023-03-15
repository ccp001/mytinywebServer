//
// Created by changwang on 2023/3/15.
//

#ifndef TINYWEBSERVERINIT_MY_TASK_H
#define TINYWEBSERVERINIT_MY_TASK_H
#include <iostream>

class my_task {
public:
    int do_run() {
        std::cout << "hello my thread pool" << std::endl;
        return 0;
    }
};


#endif //TINYWEBSERVERINIT_MY_TASK_H
