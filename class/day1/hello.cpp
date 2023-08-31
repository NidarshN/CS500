#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cout << "Please enter your name: ";
  getline(cin, s);
  cout << "Hello " << s << endl;
  cout << "Have fun learning c++!" << endl;
  return 0;
}
