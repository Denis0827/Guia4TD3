#include <iostream>
#include <string>
using namespace std;

int fibonacci(int n) {
      if (n <= 1) {
            return n;
      }
      else {
            return fibonacci(n-1) + fibonacci(n-2);
      }
}

bool es_par(int n) {
      if (n-2 == 0) {
            return true;
      } else if (n-2 < 0) {
            return false;
      }
      else {
            return es_par(n - 1);
      }
}

