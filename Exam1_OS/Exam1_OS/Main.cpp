#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

// Alex Blair
// OS 
// 3-5-17
// Exam 1

// Create a vector of integers to store the factors

void factorize() {
     // Generate a random number between 1 and 10,000
     int randval = rand() % 10000 + 1;
     vector<int> factors;
     for (unsigned int i = 0; i < factors.size(); i++) {
          // Set the random value to a variable
          int x = randval;
          // Set the changable variable
          int modnum = x;

          int result = x % modnum;

          if (result == 0) {
               factors.push_back(modnum);
               modnum--;
          }
          else
          {
               modnum--;
          }

          for (vector<int>::const_iterator i = factors.begin(); i != factors.end(); i++)
          {
               cout << *i << " " << endl;
          }

     }
}

int main() {

     // Create a vector of integers to store the factors
     vector<int> factors;
     // Create the random number seed
     srand(time(NULL));


     factorize();
     














     return 0;
}





