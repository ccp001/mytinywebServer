//
// Created by ccp on 2023/3/14.
//
#include <iostream>
#include <future>
#include <thread>
#include <queue>

int do_thread() {
    // 将一个返回值为7的 lambda 表达式封装到 task 中
    // std::packaged_task 的模板参数为要封装函数的类型
    int a = 12;
    std::packaged_task<int(int)> task([&](int x) { return a + x + 7; });
    // 获得 task 的期物
    std::future<int> result = task.get_future(); // 在一个线程中执行 task
    std::thread(std::move(task), 5).detach();
    std::cout << "waiting...";
    result.wait(); // 在此设置屏障，阻塞到期物的完成
    // 输出执行结果
    std::cout << "done!" << std::endl << "future result is "
              << result.get() << std::endl;
    return 0;
}

using namespace std;

int producer_consumer() {
    int max_size = 10;
    queue<int> que;
    mutex mtx;
    condition_variable cv;
    bool flag = false;

    auto producer = [&]() {
        for (int i = 0; i < max_size; ++i) {
            cout << "start producer :" << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << " producer sleep over :" << endl;
            unique_lock<mutex> lock(mtx);
            cout << "producer :" << i << endl;
            que.push(i);

            cout << " producer produce over :" << endl;
            flag = true;
//            cv.notify_all();
//            lock.unlock();
        }
    };
    auto consumer = [&]() {
        while (true) {
            auto tid = this_thread::get_id();
            cout << tid << " start consumer :" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            unique_lock<mutex> lock(mtx);
//            cout << tid << " consumer flag:" << flag << endl;
            if (!flag) {
                cout << tid << " consumer is wait:" << endl;
                cv.wait(lock);
            }
            while (!que.empty()) {
                cout << tid << "consumer :" << que.front() << endl;
                que.pop();
            }
            flag = false;
            cout << tid << " consumer is over:" << endl;
            lock.unlock();
        }
    };
//    thread p1(producer);
    thread c_arr[2];

    for (int i = 0; i < 2; ++i) {
        c_arr[i] = thread(consumer);
    }
//    p1.join();
    for (int i = 0; i < 2; ++i) {
        c_arr[i].join();
    }
    cout << "main is done";
    return 0;
}
