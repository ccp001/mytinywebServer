#include <iostream>
#include "threadpool/thread_pool.h"
#include "threadpool/my_task.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    thread_pool<my_task> tp(2);
    my_task mt1;
    my_task mt2;
    mt1.do_run();
    mt2.do_run();
    tp.add_task(&mt1);
//    tp.add_task(mt2);

    return 0;
}
