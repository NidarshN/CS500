#include <iostream>
#include "user.h"

int main() {
    // Create some User objects
    User user1("Alice", "alice@example.com", 100);
    User user2("Bob", "bob@example.com", 100);
    User user3("Charlie", "charlie@example.com", 100);

    // Add friends
    user1.addFriend(&user2);
    user1.addFriend(&user3);

    user2.addFriend(&user1);
    user2.addFriend(&user3);

    user3.addFriend(&user1);
    user3.addFriend(&user2);

    // Display user information
    std::cout << "User 1's Name: " << user1.getUserName() << std::endl;
    std::cout << "User 1's Email: " << user1.getEmail() << std::endl;
    std::cout << "User 1's Number of Friends: " << user1.numFriends() << std::endl;

    // Display friend lists
    std::cout << "User 1's Friends:" << std::endl;
    for (int i = 0; i < user1.numFriends(); ++i) {
        User* friendUser = user1.getFriendAt(i);
        std::cout << "Friend " << i + 1 << ": " << friendUser->getUserName() << std::endl;
    }

    // Remove a friend
    user1.removeFriend("Bob");

    std::cout << "User 1's Updated Friends:" << std::endl;
    for (int i = 0; i < user1.numFriends(); ++i) {
        User* friendUser = user1.getFriendAt(i);
        std::cout << "Friend " << i + 1 << ": " << friendUser->getUserName() << std::endl;
    }

    return 0;
}
