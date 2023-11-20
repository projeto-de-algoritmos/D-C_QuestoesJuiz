#include <iostream>
using namespace std;

void divide_and_conquer(string str) {
  if (str.length() == 1) {
    // base case: single character string is already divided and conquered
    if (str[0] == '@') {
      cout << 'a';
    } else if (str[0] == '&') {
      cout << 'e';
    } else if (str[0] == '!') {
      cout << 'i';
    } else if (str[0] == '*') {
      cout << 'o';
    } else if (str[0] == '#') {
      cout << 'u';
    } else {
      cout << str[0];
    }
    return;
  }

  // divide the string into two equal halves
  int mid = str.length() / 2;
  string left = str.substr(0, mid);
  string right = str.substr(mid);

  // recursively apply the divide and conquer approach to each half of the string
  divide_and_conquer(left);
  divide_and_conquer(right);
}

int main() {
  while (true) {
    string str;
    try {
      getline(cin, str);
      if (str == "") {
        break; // sair se a linha estiver vazia
      }
      divide_and_conquer(str);
      cout << endl;
    } catch (exception const &e) {
      break;
    }
  }

  return 0;
}