#ifndef _USER_H
#define _USER_H

#include <string>
#include <vector>

class User{
 private:
  std::string userName;
  std::string email;
  std::vector<User*> friendList;

 public:

  User(std::string name, std::string email_address, int friendListSize);

  std::string getUserName();
  void setUserName(std::string name);
  std::string getEmail();
  void setEmail(std::string email_address);

  void addFriend(User* friendUser);
  void removeFriend(std::string friendUserName);
  int numFriends();
  User* getFriendAt(int index);

};
#endif
