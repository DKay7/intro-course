// RUN: clang++ sorted_sum.cpp -o sorted_sum

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

float sum(const std::vector<float> &values) {
  float result = 0.0f;

  for (float x : values) {
    result += x;
  }

  return result;
}

int main() {
  std::vector<float> values;

  values.push_back(1e8f);

  for (int i = 0; i < 1000000; ++i) {
    values.push_back(1.0f);
  }

  values.push_back(-1e8f);

  float unsorted_sum = sum(values);

  std::sort(values.begin(), values.end(),
            [](float a, float b) { return std::fabs(a) < std::fabs(b); });

  float sorted_sum = sum(values);

  std::cout << std::fixed << std::setprecision(20);

  std::cout << "unsorted sum = " << unsorted_sum << '\n';
  std::cout << "sorted sum   = " << sorted_sum << '\n';

  return 0;
}
