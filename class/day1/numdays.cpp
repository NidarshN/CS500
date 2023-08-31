#include <iostream>

bool evalLeap(int year);

bool evalLeap(int year){
  return ((year % 4 == 0 && year % 100 != 0)) || (year % 400 == 0);
}

int main(){

  int year;
  int month;
  int result = 0;
  
  std::cout << "Enter a year: ";
  std::cin >> year;
  std::cout << "Enter the month:\n"
	    << "1 - January\n"
	    << "2 - Febraury\n"
            << "3 - March\n"
            << "4 - April \n"
	    << "5 - May\n"
	    << "6 - June\n"
	    << "7 - July\n"
	    << "8 - August\n"
	    << "9 - September\n"
	    << "10 - October\n"
	    << "11 - November\n"
	    << "12 - December\n";
  std::cin >> month;
  result = evalLeap(year);
  switch(month){
      case 1: std::cout<< "January has 31 days";
              break;

      case 2: if(result == 1){
	          std::cout<< "Febraury has 29 days";
              }else{
		  std::cout<< "Febraury has 28 day";
	      }
	      break;

      case 3: std::cout<< "March has 31 days";
              break;

      case 4: std::cout<< "April has 30 days";
              break;

      case 5: std::cout<< "May has 31 days";
              break;

      case 6: std::cout<< "June has 30 days";
              break;

      case 7: std::cout<< "July has 31 days";
              break;

      case 8: std::cout<< "August has 31 days";
              break;

      case 9: std::cout<< "September has 30 days";
              break;

      case 10: std::cout<< "October has 31 days";
              break;

      case 11: std::cout<< "November has 30 days";
              break;

      case 12: std::cout<< "December has 31 days";
              break;

      default: std::cout <<"Invalid Option, Please run the program again!";
  }
  return 0;

}
