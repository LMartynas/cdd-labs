#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

/**
   \file main.cpp
   \brief Demonstrates mutual exclusion
*/

/**
   Declare 100 threads
 */
static const int num_threads = 100;
static int num = 1;
int sharedVariable=0;

/* \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/** Shared variable is accessed only by a single thread at a time */
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){
  firstSem->Wait();
  for(int i=0;i<numUpdates;i++){
    //UPDATE SHARED VARIABLE HERE!
    sharedVariable++;
  }
  firstSem->Signal();
}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore(1));
  /** Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /** Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
