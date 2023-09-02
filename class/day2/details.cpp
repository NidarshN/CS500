#include <iostream>
#include <string>
#include <iomanip>

struct Details {
  std::string firstName;
  std::string lastName;
  std::string address;
  double phoneNumber;
};

int main(){
  Details detail;
  std::cout << "Enter your first name: " << std::endl;
  std::cin >> detail.firstName;
  std::cout << "Enter your last name: " << std::endl;
  std::cin >> detail.lastName;
  std::cout << "Enter your phone number: " << std::endl;
  std::cin >> detail.phoneNumber;
  
  std::getline(std::cin, detail.address);
  std::cout << "Enter your address: " << std::endl;
  std::getline(std::cin, detail.address);
 
  std::cout << std::setprecision(0) << std::fixed << std::endl;
  std::cout << "Your Details: " << std::endl;
  std::cout << "Your Name: " << detail.firstName
            << " " << detail.lastName << std::endl;
  std::cout << "Your Address: " << detail.address << std::endl;
  std::cout << "Your Phone Number: " << detail.phoneNumber << std::endl; 

  
  return 0;
}
