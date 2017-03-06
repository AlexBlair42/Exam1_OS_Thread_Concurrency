#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>
using namespace std;

// Alex Blair
// OS 
// 3-5-17
// Exam 1


mutex m;
int factors = 99;

void countdown(int i) {
     int b = 0;
     do {
          int w = rand() % 500 + 100;
          {
               lock_guard<mutex> g(m);
               b = factors;
          }
          cout << i << ": " << b << " bottles of coke on the wall\n";
          cout << i << ": " << b << " bottles of coke\n";
          this_thread::sleep_for(chrono::milliseconds(w));
          cout << i << ": " << b << " take one down, pass it around\n";
          this_thread::sleep_for(chrono::milliseconds(w));
          {
               lock_guard<mutex> g(m);
               factors--;
               b = factors;
          }
          cout << i << ": " << b << " bottles of coke on the wall\n";
     } while (b > 0);
}

int main() {
     srand(time(NULL));
     thread t0, t1;

     t0 = thread(countdown, 0);
     t1 = thread(countdown, 1);

     t0.join();
     t1.join();
}