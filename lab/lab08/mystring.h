#ifndef _mystring_h
#define _mystring_h

#include <iostream>

class MyString {

    friend std::ostream& operator<<(std::ostream& os, const MyString &str);
    friend MyString operator+(const MyString &str1, const MyString &str2);
    friend bool operator==(const MyString &s1, const MyString &s2); 
    friend bool operator!=(const MyString &s1, const MyString &s2); 
    friend bool operator<(const MyString &s1, const MyString &s2); 
    friend bool operator<=(const MyString &s1, const MyString &s2); 
    friend bool operator>(const MyString &s1, const MyString &s2); 
    friend bool operator>=(const MyString &s1, const MyString &s2); 


    private:
        char* mystring;
        int strLength;
    public:
        MyString(std::string str);
        ~MyString();
        void display();
        std::string toString() const;
        int length() const;
        char* substr(
        int start, int n) const;
        char &operator[](unsigned int index) const;
        MyString &operator+=(const MyString &str); 

};
#endif