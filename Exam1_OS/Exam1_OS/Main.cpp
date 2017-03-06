#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Alex Blair
// OS 
// 3-5-17
// Exam 1

// Known issues:
// Each thread calculates the same values for the factorization function
// The map is not functional
// The threads only do one instance of factorization, not 200.
// Currently displays values in the vector
// Does not check for values that already exist in the map

// Create a vector of integers to store the factors
vector<int> factors(1);
// Create a map to store pairs of integer keys and the vector values
map<int, vector<int>> storage;
// Create a mutex
mutex m;

void factorize() {
     // Generate a random number between 1 and 10,000
     int randval = rand() % 10000 + 1;
     // Set the modulo variable
     int divnum;
     {
          lock_guard<mutex> g(m);
          for (int divnum = 1; divnum <= randval; divnum++) {
               if (randval % divnum == 0) {
                    factors.push_back(divnum);
               }
          }
     }
}
/*
void addMap()
{

}
*/
/*
void PrintM(){}
*/
void makeT()
{
     const int thct = 500;
     // This is the maximum number of threads that should yield 100,000 computations.
     // I did 100,000/200 = 500. So 500 threads with 200 computations each. 

     // Create an array of threads based on the threadcount
     thread t[thct];
     for (int i = 0; i < thct; i++)
     {
          // Create threads and execute the factorize function
          t[i] = thread(factorize);

     }
     // Join every thread with the main thread
     for (int i = 0; i < thct; i++)
     {
          t[i].join();
     }

}

void printV()
{
     for (unsigned int j = 0; j < factors.size(); j++)
     {
          cout << factors[j] << " ";
          //cout << factors.size();
     }
}

int main() {


     // Create the random number seed
     srand(time(NULL));

     makeT();
     printV();

     return 0;
}


