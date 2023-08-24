#include <iostream>
#include <stdbool.h>
#include <stdint.h>

int main() {
  int array_size = 100 * 1024 / sizeof(double);

  while (true) {
    double arr[array_size];
    double array_sum = 0;

    for (double array_element : arr) {
      array_element = 1;
      array_sum += array_element;
    }

    std::cerr << sizeof(arr) / 1024 << std::endl;

    array_size += 100 * 1024 / sizeof(double);
  }

  return 0;
}