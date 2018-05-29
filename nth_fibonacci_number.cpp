#include <iostream>
#include <vector>

unsigned long long int FibonacciRecursive(int nn) {

  if (nn < 2) {
    return nn;
  } else {
    return FibonacciRecursive(nn - 1) + FibonacciRecursive(nn - 2);
  }
}

unsigned long long int FibonacciMemoized(int nn, std::vector<unsigned long long int> &table) {

  unsigned long long int kReqModulo{1000000007ull};  // Required modulo to print asnwers.

  if (table.at(nn) == 0ull) {
    table.at(nn) = FibonacciMemoized(nn - 1, table) + FibonacciMemoized(nn - 2, table);
    table.at(nn) %= kReqModulo;
  }

  return table.at(nn);
}

unsigned long long int FibonacciTabulated(int nn) {

  unsigned long long int kReqModulo{1000000007ull};  // Required modulo to print asnwers.
  std::vector<unsigned long long int> sp_space(nn + 1);  // Sup-problem space.

  // Base case.
  sp_space.at(1) = 1;
  sp_space.at(2) = 1;
  // Recursive step.
  for (int ii = 3; ii <= nn; ++ii) {
    sp_space.at(ii) = sp_space.at(ii - 1) + sp_space.at(ii - 2);
    sp_space.at(ii) %= kReqModulo;
  }
  return sp_space.at(nn);
}

int main() {

  int tt{};  // Number of test cases.

  std::cin >> tt;

  constexpr unsigned long long int kMaxNN{1001};  // Maximum number of sub-problems invocation.

  std::vector<unsigned long long int> table(kMaxNN);  // Table to remember previous results.

  table.at(1) = 1ull;
  table.at(2) = 1ull;
  for (int ii = 1; ii <= tt; ++ii) {

    int nn{};  // Number of required Fibonacci number.

    std::cin >> nn;

    std::cout << FibonacciTabulated(nn) << std::endl;
  }
}
