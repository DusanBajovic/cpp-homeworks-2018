#include <cstdlib>
#include <ctime>
#include <iostream>


int main() {
  std::srand(
      std::time(nullptr)); // use current time as seed for random generator
  int random_number =
      1 + std::rand() / ((RAND_MAX + 1u) / 99); // random number [0, 99]
  int guessed_number = 0;

  std::cout << "Please guess the number: ";
  std::cin >> guessed_number;

  while (guessed_number != random_number) {
    if (random_number > guessed_number) {
      std::cout << "My number is larger" << std::endl;
    } else if (random_number < guessed_number) {
      std::cout << "My number is smaller" << std::endl;
    } else {
      break;
    }

    std::cout << "Please guess the number again: ";
    std::cin >> guessed_number;
  }

  std::cout << "You have won! You guessed right number!" << std::endl;

  return 0;
}
