#include <ctime>
#include <iostream>
#include <map>

enum Level { ROCK = 1, PAPER = 2, SCISSORS = 3 };

std::map<Level, std::map<std::string, Level>> hMap = {
    {ROCK, {{"BEATS", SCISSORS}, {"LOSES", PAPER}}},
    {PAPER, {{"BEATS", ROCK}, {"LOSES", SCISSORS}}},
    {SCISSORS, {{"BEATS", PAPER}, {"LOSES", ROCK}}},
};

std::string getLevelName(Level level) {
  if (level == ROCK) {
    return "Rock";
  }
  if (level == PAPER) {
    return "Paper";
  }
  if (level == SCISSORS) {
    return "Scissors";
  }
  return "invalid";
}

int main() {

  srand(time(0));

  int randomNum = rand() % 3 + 1;
  int userChoice;
  std::cout
      << "\n-------------------------------------------------------------\n\n";
  std::cout << "ROCK PAPER SCISSORS... SHOOT!\n\n";
  std::cout << "1 for ROCK\n\n2 for PAPER\n\n3 for SCISSORS\n\n";

  std::cin >> userChoice;
  Level userLevel = static_cast<Level>(userChoice);
  Level computerLevel = static_cast<Level>(randomNum);

  if (userLevel == computerLevel) {
    std::cout << "It's a tie! both chose " << getLevelName(userLevel);
    return 0;
  }

  if (hMap[userLevel]["BEATS"] == computerLevel) {
    std::cout << "You won! " << getLevelName(userLevel) << " Beats "
              << getLevelName(computerLevel);
  } else {
    std::cout << "You lost! " << getLevelName(computerLevel) << " Beats "
              << getLevelName(userLevel);
  }
  std::cout
      << "\n-------------------------------------------------------------";

  return 0;
}
