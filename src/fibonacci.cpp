#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    return round((pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n))/(pow(2, n) * sqrt(5)));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;
    for (int i = 2; i <= n; i++){
      int64_t third = fib_prev + fib_curr;
      fib_prev = fib_curr;
      fib_curr = third;
    }
    return fib_curr;
  }

  int64_t fib_recursive(int n) {
    if (n <= 1){
      return n;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }
    cache[n] = fib_recursive_memoization(n-1,cache) + fib_recursive_memoization(n-2,cache);
    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }
    Matrix2x2 res = matrix_power(FibMatrix, n);
    return res[0][1];
  }

}  // namespace assignment
