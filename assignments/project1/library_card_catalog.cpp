#include <iostream>
#include <string>
#include <vector>

struct libraryT {
  std::string title;
  std::vector<std::string> author_list = std::vector<std::string>(5);
  std::string congress_catalog_number;
  std::vector<std::string> subject_headings = std::vector<std::string>(5);
  std::string publisher;
  int year;
  bool isCirculating;
};

void populateLibData(std::vector<libraryT>& libdata_vec);
void addBook(std::vector<libraryT>& library_vec);
void displayBooks(std::vector<libraryT> libdata_vec);
void searchBySubject(std::vector<libraryT> libdata_vec, std::string query_subject);
  
int main(){
  std::vector<libraryT> libdata_vec;
   
  int option;

  populateLibData(libdata_vec);
  
  std::cout << "Welcome to the Library Card Catalog System" << std::endl;

  while(true){
    std::cout << "****** Main Menu *****" << std::endl << std::endl;
    std::cout << "1. Add New Book" << std::endl;
    std::cout << "2. Search By Subject" << std::endl;
    std::cout << "3. Display all books" << std::endl;
    std::cout << "4. Exit" << std::endl << std::endl;

    std::cout << "Enter the option you want to choose from (1, 2, 3, 4): "
              << std::endl;
    std::cin >> option;

    switch(option){
       case 1: {
                 addBook(libdata_vec);
       break;
    }
    case 2: {
      std::string query_subject;
      std::cout << "Enter the subject whose books you want to display: ";
      std::getline(std::cin, query_subject);
      std::getline(std::cin, query_subject);
      searchBySubject(libdata_vec, query_subject);
      break;
    }
    case 3: displayBooks(libdata_vec);
      break;
    case 4: std::cout << std::endl << std::endl;
      goto exit_loop;
      break;
    } 
    
  }
  exit_loop:;
  
  return 0;
}

void addBook(std::vector<libraryT>& library_vec){
  libraryT temp_book;
  int author_num, subject_num;
  std::string author_name, subject;

  if(library_vec.size() < 1000 - 1){
  
    std::cout << "Enter the book title: " << std::endl;
    std::getline(std::cin, temp_book.title);
    std::getline(std::cin, temp_book.title);
   
    std::cout << "Enter the number of authors: ";
    std::cin >> author_num;
    std::getline(std::cin, author_name);
    for(int i=0; i < author_num; ++i){
      std::cout << "Enter the " << i+1 << " author name: " << std::endl ;
      std::getline(std::cin, author_name);
      temp_book.author_list[i] = author_name;
    }
  
    std::cout << "Enter the catalog number: " << std::endl;
    std::getline(std::cin, temp_book.congress_catalog_number);

    std::cout << "Enter the number of subject headings: " << std::endl;
    std::cin >> subject_num;
    std::getline(std::cin, subject);

    for(int i=0; i < subject_num; ++i){
      std::cout << "Enter the " << i+1 << " subject heading: " << std::endl;
      std::getline(std::cin, subject);
      temp_book.subject_headings[i] = subject;
    }

    std::cout << "Enter the name of the publisher: " << std::endl;
    std::getline(std::cin, temp_book.publisher);
  
    
    std::cout << "Enter the year of publication: " << std::endl;
    std::cin >> temp_book.year;

    std::cout << "Is the book in circulation (1 for Yes or 0 for No)?: " << std::endl;
    std::cin >> temp_book.isCirculating;

    std::cout << "Size of lib: " << library_vec.size() << std::endl;
 
    library_vec.push_back(temp_book);
  

    std::cout << std::endl << "New Book Added Successfully!" << std::endl << std::endl;
  }else{
    std::cout << "Catalog reached its size limit. Cannot add a new book!" << std::endl << std::endl;
  }

}

void displayBooks(std::vector<libraryT> libdata_vec){
  std::cout << std::endl <<  "****** Book Catalog ******" << std::endl <<std::endl;
  if(!libdata_vec.empty()){
    for(int i = 0; i < libdata_vec.size(); ++i){
      std::cout << "Title: " << libdata_vec[i].title << std::endl;
      std::cout << "Authors: ";
      for(int j =0; j < libdata_vec[i].author_list.size(); ++j){
	std::cout << libdata_vec[i].author_list[j] << " ";
      }
      std::cout << std::endl << std::endl;
    }
  }else{
    std::cout << "Catalog Empty! Add a new book first!" << std::endl;
  }

  std::cout << std::endl;
}

void searchBySubject(std::vector<libraryT> libdata_vec, std::string query_subject) {
  std::cout << std::endl;
  bool isFound = false;
  for(int i=0; i < libdata_vec.size(); ++i) {
    for(int j=0; j < libdata_vec[i].subject_headings.size(); ++j){
      if(!libdata_vec[i].subject_headings[j].empty())
      {
	if((libdata_vec[i].subject_headings[j].compare(query_subject)) == 0){
	  std::cout << "Title: " << libdata_vec[i].title << std::endl
		    << "First Author: " << libdata_vec[i].author_list[0] << std::endl
		    << "Congress Catalog Number: " << libdata_vec[i].congress_catalog_number << std::endl;
	  isFound = true;
      }
      }
    }
    std::cout << std::endl;
  }
  if(!isFound){
    std::cout << "Books with subject: " << query_subject << " not found!" << std::endl;
  }
  std::cout << std::endl;
}

void populateLibData(std::vector<libraryT>& libdata_vec){
  libraryT temp_book[5];

  temp_book[0].title = "One Piece";
  temp_book[0].author_list[0] = "Eiichiro Oda";
  temp_book[0].congress_catalog_number = "LCCNM01";
  temp_book[0].subject_headings[0] = "manga";
  temp_book[0].subject_headings[1] = "drama";
  temp_book[0].subject_headings[2] = "adventure";
  temp_book[0].subject_headings[3] = "thriller";
  temp_book[0].publisher = "Shueisha";
  temp_book[0].year = 1997;
  temp_book[0].isCirculating = 1;


  temp_book[1].title = "Naruto";
  temp_book[1].author_list[0] = "Masahi Kishimoto";
  temp_book[1].congress_catalog_number = "LCCNM02";
  temp_book[1].subject_headings[0] = "manga";
  temp_book[1].subject_headings[1] = "drama";
  temp_book[1].subject_headings[2] = "adventure";
  temp_book[1].subject_headings[3] = "thriller";
  temp_book[1].publisher = "Shueisha";
  temp_book[1].year = 1997;
  temp_book[1].isCirculating = 1;


  temp_book[2].title = "Moby Dick";
  temp_book[2].author_list[0] = "Herman Melville";
  temp_book[2].congress_catalog_number = "LCCNL01";
  temp_book[2].subject_headings[0] = "fiction";
  temp_book[2].subject_headings[1] = "adventure";
  temp_book[2].subject_headings[2] = "thriller";
  temp_book[2].publisher = "Richard Bentley";
  temp_book[2].year = 1851;
  temp_book[2].isCirculating = 1;
  
  temp_book[3].title = "The Wizard of Oz";
  temp_book[3].author_list[0] = "L. Frank Baum";
  temp_book[3].congress_catalog_number = "LCCNL02";
  temp_book[3].subject_headings[0] = "fantasy";
  temp_book[3].subject_headings[1] = "adventure";
  temp_book[3].subject_headings[2] = "magic";
  temp_book[3].publisher = "L. Frank Baum";
  temp_book[3].year = 1900;
  temp_book[3].isCirculating = 1;

  temp_book[4].title = "Programming Abstractions in C++";
  temp_book[4].author_list[0] = "Eric S. Roberts";
  temp_book[4].congress_catalog_number = "LCCNCS01";
  temp_book[4].subject_headings[0] = "c++";
  temp_book[4].subject_headings[1] = "computer";
  temp_book[4].subject_headings[2] = "coding";
  temp_book[4].publisher = "Pearson";
  temp_book[4].year = 2013;
  temp_book[4].isCirculating = 1;

  for(int i=0; i < 5; ++i){
    libdata_vec.push_back(temp_book[i]);
  }
  
}

