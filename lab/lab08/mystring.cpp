#include <iostream>
#include "mystring.h"


MyString::MyString(std::string str)
{
    int n = str.length();
    mystring = new char[n];
    strLength = n;
    for(int i=0; i<n; i++){
        mystring[i] = str[i];
    }
    mystring[n] = '\0';
}

MyString::~MyString(){
    delete[] mystring;
}

void MyString::display(){
    std::cout << mystring << std::endl;
}

std::string MyString::toString() const
{
    std::string temp = "";
    for(int i = 0; i < strLength; i++){
        temp += mystring[i];
    }
    return temp;
}

int MyString::length() const{
    return strLength;
}

char* MyString::substr(int start, int n=-1) const{
    if(n ==-1){
        return mystring;
    }
    else{
        int count = 0;
        char* temp = new char[n];
        for(int i=start; i<n; i++){
            temp[count++] = mystring[i];
        }
        std::cout << std::string(temp);
        return temp;
    }
}

MyString operator+(const MyString &str1, const MyString &str2){
    std::string temp = "";
    for(int i = 0; i < str1.strLength; i++){
        temp += str1.mystring[i];
    }
    for(int i = 0; i < str1.strLength; i++){
        temp += str1.mystring[i];
    }
    return MyString(temp);
}

std::ostream &operator<<(std::ostream &os, const MyString &str){
    os << str.toString();
    return os;
}

char &MyString::operator[](unsigned int index) const
{
    if(index > strLength){
        std::cout << "Index out of range!" << std::endl;
        static char temp = '\0';
        return temp;
    }else{
        return mystring[index];
    }
}

MyString &MyString::operator+=(const MyString &str){
    char *temp = new char[strLength + str.strLength];
    for(int i = 0; i < strLength; i++){
        temp[i] = mystring[i];
    }
    for(int i = 0; i < str.strLength; i++){
        temp[i + strLength] = str.mystring[i];
    }
    strLength += str.strLength;
    delete[] mystring;
    mystring = temp;
    return *this;
} 

bool operator==(const MyString &s1, const MyString &s2)
{
    if(s1.strLength != s2.strLength){
        return false;
    }else{
        bool temp = false;
        for(int i = 0; i < s1.strLength; i++){
            for(int j = 0; j < s2.strLength; j++){
                if(s1.mystring[i] == s2.mystring[j]) temp = true;
                else temp = false;
            }
        }
        return temp;
    }
}

bool operator!=(const MyString &s1, const MyString &s2)
{
    if(s1.strLength != s2.strLength){
        return true;
    }else{
        bool temp = false;
        for(int i = 0; i < s1.strLength; i++){
            for(int j = 0; j < s2.strLength; j++){
                if(s1.mystring[i] == s2.mystring[j]) temp = true;
                else temp = false;
            }
        }
        return temp;
    }
}


bool operator<(const MyString &s1, const MyString &s2)
{
    return (s1.mystring < s2.mystring);
}

bool operator<=(const MyString &s1, const MyString &s2)
{
    return (s1.mystring <= s2.mystring);
}

bool operator>(const MyString &s1, const MyString &s2)
{
    return (s1.mystring > s2.mystring);
}

bool operator>=(const MyString &s1, const MyString &s2)
{
    return (s1.mystring >= s2.mystring);
}