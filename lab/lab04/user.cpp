#include <iostream>
#include <string>
#include <vector>
#include "user.h"


User::User(std::string name, std::string email_address, int friendListSize = 100){
  userName = name;
  email = email_address;
  friendList.reserve(friendListSize);
}

std::string User::getUserName(){
  return userName;
}

void User::setUserName(std::string name){
  userName = name;
}

std::string User::getEmail(){
  return email;
}

void User::setEmail(std::string email_address){
  email = email_address;
}

void User::addFriend(User* friendUser){
  if(friendList.size() < 100){
    friendList.push_back(friendUser);
  }else{
    std::cout << "Max out friend list! Cannot add more friends!" << std::endl;
  }
}

void User::removeFriend(std::string friendUserName){
  for(int index = 0; index < numFriends(); ++index){
    if(friendList[index]->getUserName() == friendUserName){
      friendList.erase(friendList.begin() + index);
      return;
    } 
  }
}

int User::numFriends(){
  return friendList.size();
}

User* User::getFriendAt(int index){
  if(index >= 0 && index < numFriends()){
    return friendList[index];
  }else{
    return nullptr;
  }
}
