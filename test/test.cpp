#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
 
std::timed_mutex test_mutex;
 
void f()
{
    auto now=std::chrono::steady_clock::now();
    bool jk = test_mutex.try_lock_until(now + std::chrono::seconds(10));
    std::cout << "hello world\n" << std::boolalpha << jk << std::endl;
}
 
int main()
{
    std::lock_guard<std::timed_mutex> l(test_mutex);
    std::thread t(f);
    t.join();
}