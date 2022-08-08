#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <exception>
#include <vector>
#include <stdexcept>

std::mutex                       g_mutex; // mutex declaration
std::vector<std::exception_ptr>  g_exceptions; // vector of exception pointers

// Throw exception
void throw_function()
{
   throw std::domain_error( "domain error" );
}

void func()
{
   try
   {
      throw_function();
   }
   catch(std::domain_error)
   {
      // uses lock_guard: it will aqcuire the mutex on it's construction and release on object destruction 
      std::lock_guard<std::mutex> lock(g_mutex);
      g_exceptions.push_back(std::current_exception()); // push to vector of exception pointers
   }
}

int main()
{
   // Clean the global vector
   g_exceptions.clear();
   
   // Create the thread 't' passing function 'func' as argument
   std::thread t(func);
   // 'main' thread will wait 't' thread conclusion 
   t.join();

   // routine to print vector of exception pointers
   for(auto& e : g_exceptions)
   {
      try 
      {
         if(e != nullptr)
         {
            std::rethrow_exception(e);
         }
      }
      catch(const std::exception& e)
      {
         std::cout << "what: "<<e.what() << std::endl;
      }
   }

   return 0;
}