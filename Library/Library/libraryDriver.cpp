// You are given a partially completed program which consist of a class 'Book' defined in book.h
// The definitions of class member functions are to be filled in book.cpp (this file).
// libraryDriver.c creates an array of objects 'b[]' and uses a menu driven program to add a book, display book info, 
// sort the book list and to find the book with the longest title among the books whose bookType contain a specific substring.

#include "book.h"
#include <iostream>
#include <string.h>

#define MAX_BOOKS 5

using namespace std;

// forward declaration of functions (already implmented)
void executeAction(char);

// functions that need implementation:
// in book.cpp :



int addBook(string title_input, int id_input, int aisle_input, string bookType_input); 
void displayBooks();				
void sort();						
void bookTypeWithSpecificString();		


Book b[MAX_BOOKS];		// array of objects
int currentCount = 0;				// number of books in the list


int main()
{
	char choice = 'i';		// initialized to a dummy value
	do
	{
		cout << "\nCSE240 HW8\n";
		cout << "Please select an action:\n";
		cout << "\t a: add a new book\n";
		cout << "\t d: display book list\n";
		cout << "\t s: sort the books in descending order based on ID (within a range)\n";
		cout << "\t n: display the book with the longest title among the books whose bookType contain a specific substring\n";
		cout << "\t q: quit\n";
		cin >> choice;
		cin.ignore();			// ignores the trailing \n
		executeAction(choice);
	} while (choice != 'q');

	return 0;
}


// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string title_input, bookType_input;
	int ID_input, aisle_input, result = 0;

	switch (c)
	{
	case 'a':	// add book
				// input book details from user
		cout << "Please enter book title: ";
		getline(cin, title_input);
		cout << "Please enter book ID: ";
		cin >> ID_input;
		cin.ignore();
		cout << "Please enter aisle number: ";
		cin >> aisle_input;
		cin.ignore();
		cout << "Please enter bookType: ";
		getline(cin, bookType_input);

		// add the book to the list
		result = addBook(title_input, ID_input, aisle_input, bookType_input);
		if (result == 0)
			cout << "\nThat book is already in the list or list is full! \n\n";
		else
			cout << "\nBook successfully added to the list! \n\n";
		break;

	case 'd':		// display the list
		displayBooks();
		break;

	case 's':		// sort the list
		sort();
		break;

	case 'n':		// find and display book with the longest title among the books whose bookType contain a specific substring.
		bookTypeWithSpecificString();
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// This function adds a new book with the details given in function arguments.
// Add the book in 'b' (array of objects) only if there is remaining capacity in the array and if the book does not already exist in the list (title or ID)
// This function returns 1 if the book is added successfully, else it returns 0 for the cases mentioned above.
// Assume user enters ID and aisle number  in 0 - any positive integer range.
int addBook(string title_input, int id_input, int aisle_input, string bookType_input)
{
	// enter code here
	if (currentCount > MAX_BOOKS) {
		return 0; // array/list of books was fulll 
	}

	else if (currentCount > 0) {// check to see if the array/list of books is already full or not 

		for (int i = 0; i < sizeof(currentCount); i++) { //  if not full then loops through the array 

			if (b[i].getID() == id_input) { // checks for duplicate book based on Id OR Title 
				return 0; // means it found a duplicate book based on Id or Title 
			}
			if (b[i].getTitle() == title_input) {
				return 0; // means duplicate was found based on book name 
			}

		}


		currentCount = currentCount + 1; // update the book count 

		b[currentCount].setTitle(title_input); // sets the title 
		b[currentCount].setID(id_input); // sets the ID 
		b[currentCount].setAisle(aisle_input);// sets the aisle # 
		b[currentCount].setBookType(bookType_input);// sets the bookType 
		return 1; // Book was added 
	}
	else { // list was equal to 0 
		currentCount = currentCount + 1; // update the book count 

		b[currentCount].setTitle(title_input); // sets the title 
		b[currentCount].setID(id_input); // sets the ID 
		b[currentCount].setAisle(aisle_input);// sets the aisle # 
		b[currentCount].setBookType(bookType_input);// sets the bookType
		return 1; // Book was added 
	}

	return 0; // Book list/array was full 

}


// This function displays the list of books.
// Parse the object array 'b' and display the details of all books in the array. See expected output given in question file.
// You can call the class function 'displayBook()' here. Note that these are two different functions.
// Book::displayBook() displays details of one Book object, while displayBooks() should display all books.
void displayBooks()
{
	// enter code here
	for (int i = 0; i <= currentCount; i++) {
		b[i].displayBook(); // displays all contents of the book in single call based on how it was setup in the book class 
	}

}


// This function sorts the books in descending order of ID, and then display the books within a given range.
// You need to get lower bound and higher bound from user after printing a prompt. (Check the output in the pdf)
// You may use the 'temp' object for sorting logic, if needed.
void sort()
{
	Book temp;
	int lower_bound;
	int higher_bound;
	// enter code here
	cout << "Please insert the lower bound of the ID: "; // prompts user to give the upper bound
	cin >> lower_bound; // takes the input and stores it 
	//cout << lower_bound << endl; // prints 
	cout << "Please isert the higher bound of the ID: ";// prompts the user to give the lower bound 
	cin >> higher_bound;

	for (int i = 0; i <= currentCount; i++) { //first indexer 
		for (int k = i + 1; k <= currentCount; k++) {//second indexer that is infront of i indexer
			if (b[i].getID() < b[k].getID()) { // compares the IDs and goes to if body if i ID value is less that that of the k ID value 
				temp = b[i];
				b[i] = b[k]; // swap places 
				b[k] = temp;
			}
		}
	}
	for (int j = 0; j <= currentCount; j++) {
		if (b[j].getID() <= higher_bound && b[j].getID() > lower_bound) { // will print out the books that have an ID # specifically inbetween the high and low bounds.
			b[j].displayBook(); // if book ID # meets the rewuirment this will print out all of the books details
		}

	}

}

// This function displays an book with the longest name among the books whose bookType contain a specific substring.
// You should find the book as follows:
// 1. By traversing all books, you should find the books whose booktype include a specific substring. 
// NOTE: you need to get a substring from user after printing a prompt. (Check the output in the pdf)
// HINT: You may refer to the document of string::find.
// 2. After step 1, you should find the book whose title is the longest. You may use 'titleLength' and 'index' variable.
// 3. After step 2, copy the details of the book to 'bookWithLengthyTitle' object created using 'new' 
// and display the book's details using 'bookWithLengthyTitle' object.
// NOTE: You necessarily have to use the 'bookWithLengthyTitle' object to store the book details in it and delete it after displaying.
//       You should not display book details using 'b[]' object.
// 4. Finally delete the 'bookWithLengthyTitle' object.
void bookTypeWithSpecificString()
{
	string subString;				// Ask the user for a character
	Book* bookWithLengthyTitle = new Book;
	int titleLength = 0;
	int index = -1;
	string keyWord;
	// enter code here
	cout << "Enter the substring of the book's bookType: "; // prompts user to give the upper bound
	cin >> subString; // save the give nsubstring inside of subString 
	//size_t subMatch = b[i].find(subString);
	for (int i = 0; i < currentCount; i++) {

		if (subString == "Fic")
		{
			//size_t subMatch = .find(subString);

			if (b[i].getBookType() == "Fiction") { // subString was Fic so it will look for books with the Fiction bookType
				if (titleLength < b[i].getTitle().size()) {
					titleLength = b[i].getTitle().size(); // saves the length of the longest word 
					keyWord = b[i].getTitle(); // saves the exact name so i can go back through the array and find this book with the matching name and then set it to the new book 

				}
				else if (titleLength == b[i].getTitle().size()) {
					keyWord = keyWord + " "; // keeps the key word the same 
					keyWord = b[i].getTitle(); // updates the title to the newest occurance with the same length

				}
			}
		}
		else { // this runs if the subString is not equal to Fic meaning look for only books with bookType Nonfiction
			if (titleLength < b[i].getTitle().size()) {
				titleLength = b[i].getTitle().size(); // saves the length of the longest word 
				keyWord = b[i].getTitle(); // saves the exact name so i can go back through the array and find this book with the matching name and then set it to the new book 

			}
			else if (titleLength == b[i].getTitle().size()) {

				keyWord = keyWord + " "; // keeps the key word the same 
				keyWord = b[i].getTitle(); // updates the title to the newest occurance with the same length

			}
		}
		for (int j = 0; j < currentCount; j++) { // one more for loop to go through find the book name that matches keyWord and then set said books details to the new book
			if (b[j].getTitle() == keyWord) {
				bookWithLengthyTitle->setTitle(keyWord);// sets the title of the lengthy book to the book name that was the longest 
				bookWithLengthyTitle->setAisle(b[j].getAisle()); // sets the aisle 
				bookWithLengthyTitle->setID(b[j].getID());// sets the ID 
				bookWithLengthyTitle->setBookType(b[j].getBookType());// sets the bookType 

			}
		}
		// display the bookWithLengthyTitle, then delete it
		bookWithLengthyTitle->displayBook();
		delete bookWithLengthyTitle;// new delete the book
		return;
	}

}
