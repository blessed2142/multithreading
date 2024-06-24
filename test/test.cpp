#include <string>
#include <cctype>
#include <iostream>
#include <map>
#include <vector>
#include <thread>
#include <condition_variable>

std::vector<int> data;
std::condition_variable data_cond;
std::mutex m;
 
void thread_func1()
{
   std::unique_lock<std::mutex> lock(m);
   data.push_back(10);
   data_cond.notify_one();
}
 
void thread_func2()
{
   std::unique_lock<std::mutex> lock(m);
   data_cond.wait(lock, [] {
      return !data.empty();
   });
   std::cout << data.back() << std::endl;
}
 
int main()
{
   std::thread th2(thread_func2);
   std::thread th1(thread_func1);
   th2.join();
   th1.join();
}