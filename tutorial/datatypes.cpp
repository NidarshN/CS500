#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct {
    int rollNo;
    string name;
} student;

int main(){

    int num = 10, y = 2;
    int myNumbers[5] = {10, 20, 30, 40, 50};
    double floatNum = 3.14;
    char letter = 'D';
    string text = "Hello, world";
    string firstName = "John";
    string lastName = "Doe";
    string fullName = firstName + " " + lastName;
    string userName = "";
    bool isFlag = false;

    cout << num << endl
            << y << endl
            << fullName << endl
            << floatNum << endl
            << letter << endl
            << text << endl
            << isFlag << endl;

    cout << "Enter your name: ";
    getline(cin, userName);
    cout << userName << endl;

    // C++11 Extension
    for(int i : myNumbers){
        cout<< i << endl;
    }

    student.rollNo = 1;
    student.name = "Arkham";

    cout << student.name << endl
            << student.rollNo << endl;

    int* ref = &num;
    num = 11;
    cout << &num << endl
            << *ref << endl;
    return 0;
}