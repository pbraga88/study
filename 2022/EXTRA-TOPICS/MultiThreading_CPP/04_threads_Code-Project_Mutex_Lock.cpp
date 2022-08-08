#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex g_lock; // mutex declaration

void func() {
   g_lock.lock(); // lock function so only one thread at a time will access it
   std::cout<<"Entered thread "<<std::this_thread::get_id()<<std::endl;
   std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
   std::cout<<"Leaving thread "<<std::this_thread::get_id()<<std::endl;
   g_lock.unlock(); // unlock function so other threads can access it
}

int main() {
   srand((unsigned int)time(0));

   std::thread t1(func);
   std::thread t2(func);
   std::thread t3(func);

   t1.join();
   t2.join();
   t3.join();

   return 0;
}