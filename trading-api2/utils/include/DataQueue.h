#pragma once

#include <iostream>
#include <mutex>
#include <queue>

namespace utils {

template <class T>
class DataQueue
{
public:
    void push(T data)
    {
        std::lock_guard<std::mutex> lg(mtx);
        // std::cout << std::this_thread::get_id() << "push\n";
        //  may need to add max size
        que.push(data);
    }

    void pop()
    {
        std::lock_guard<std::mutex> lg(mtx);
        // std::cout << std::this_thread::get_id() << "pop\n";
        que.pop();
    }

    size_t size()
    {
        std::lock_guard<std::mutex> lg(mtx);
        // std::cout << std::this_thread::get_id() << "size\n";
        size_t size = que.size();
        return size;
    }

    bool isEmpty()
    {
        std::lock_guard<std::mutex> lg(mtx);
        // std::cout << std::this_thread::get_id() << "isempty\n";
        bool empty = que.empty();
        return empty;
    }

    T front()
    {
        std::lock_guard<std::mutex> lg(mtx);
        // std::cout << std::this_thread::get_id() << "front\n";
        T data = que.front();
        return data;
    }

private:
    std::queue<T> que;
    std::mutex mtx;
};
} // namespace utils