#include <iostream>
#include "threadpool/thread_pool.h"
#include "json/json.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    thread_pool pool(2, 5);
    int x = 1;
    double y = 2;
    pool.append([](int x) { std::cout << "ccc " << x << std::endl; }, x);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    pool.append([](int x, double y) { std::cout << "ddd " << x + y << std::endl; }, x, y);
    Json::Value json;
    json["name"] = "Wiki";
    json["age"] = 18;

    std::cout << json.toStyledString() << std::endl;
    auto redis = Redis("tcp://127.0.0.1:6379");
    return 0;
}

