// READ BEFORE YOU START:
// You are given a partially completed program which consist of a class 'Book' defined in book.h
// The definitions of class member functions are to be filled in book.cpp (this file).
// libraryDriver.c creates an array of objects 'b[]' and uses a menu driven program to add a book, display book info, 

#include "book.h"
#include <iostream>
#include <string.h>

using namespace std;

// title: The Alchemist
// ID: 0
// aisle: 101
// BookType: Fiction
Book::Book()
{
	// enter code here
	title = "The Alchemist";
	ID = 0;
	aisle = 101;
	bookType = "Fiction";

}


// Define all the class member functions.
// While defining member functions, note that these functions will be called using 
// a 'Book' object which will represent one book.
// Eg-  Book b[10]; creates 10 Book objects
//		b[2].setAisle(202); will set 3rd book's aisle number to 202.

// setTitle assigns 'title_input' to class data member 'title'
void Book::setTitle(string title_input) {
	// enter code here
	this->title = title_input;
}

// setID assigns id_input to class data member 'ID'
void Book::setID(int id_input) {
	// enter code here
	this->ID = id_input;
}

// setAisle assigns aisle_input to class data member 'aisle'
void Book::setAisle(int aisle_input) {
	// enter code here
	this->aisle = aisle_input;
}

// setBookType assigns bookType_input to class data member 'bookType'
void Book::setBookType(string bookType_input) {
	// enter code here
	this->bookType = bookType_input;
}

// displayBook displays the title, ID, aisle and bookType of the book
// See expected output in question file.
void Book::displayBook() {
	// enter code here
	cout << "Title: ";
	cout << title << endl; // print out the title 
	cout << "ID: ";
	cout << ID << endl; // print out the ID# 
	cout << "Aisle: " << aisle << endl; // all done in one line to try and see what it would look like 
	cout << "Book Type: " << bookType << endl; // all doen in one line again 
	cout << "\n"; // prints out a blank line which acts as a space before the next set of book details is printed/displayed

}

// getTitle returns the class data member 'title'.
string Book::getTitle() {
	// enter code here
	return title;
}

// getID returns the class data member 'ID'.
int Book::getID() {
	// enter code here
	return ID;
}

// getAisle returns the class data member 'aisle'.
int Book::getAisle() {
	// enter code here
	return aisle;
}

// getBookType returns the class data member 'bookType'.
string Book::getBookType() {
	// enter code here
	return bookType;
}