#include <iostream>
#include <string>

using namespace std;

int main() {

  string position = "\033[42m \033[m";

  for(int i = 0; i < 10; i++) {
    cout << "\n";
    for(int i = 0; i < 10; i++) {
      cout << "   ";
      cout << position;
    }
    cout << "\n";
  }

  return 0;
}
