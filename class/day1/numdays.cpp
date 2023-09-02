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
  std::cout << "Enter the month: " << std::endl
	    << "1 - January" << std::endl
	    << "2 - Febraury" << std::endl
            << "3 - March" << std::endl
            << "4 - April" << std::endl
	    << "5 - May" << std::endl
	    << "6 - June" << std::endl 
	    << "7 - July" << std::endl
	    << "8 - August" << std::endl
	    << "9 - September" << std::endl
	    << "10 - October" << std::endl
	    << "11 - November" << std::endl
	    << "12 - December" << std::endl;
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
