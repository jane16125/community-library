#include "Book.h"
#include <iostream>

// Default constructor
Book::Book()
    : title(""), author(""), isbn(""), available(true), dateAdded("") {
}

// Parameterised constructor - delegates to setBookDetails()
Book::Book(const std::string& title,
           const std::string& author,
           const std::string& isbn,
           bool available,
           const std::string& dateAdded) {
    setBookDetails(title, author, isbn, available, dateAdded);
}

// Assigns values to the book's attributes
void Book::setBookDetails(const std::string& t,
                           const std::string& a,
                           const std::string& i,
                           bool avail,
                           const std::string& d) {
    title = t;
    author = a;
    isbn = i;
    available = avail;
    dateAdded = d;
}

// Displays the book's title, author, ISBN and current availability
void Book::displayBookDetails() const {
    std::cout << "ISBN: " << isbn
              << " | Title: " << title
              << " | Author: " << author
              << " | Added: " << dateAdded
              << " | Status: " << (available ? "Available" : "Borrowed")
              << std::endl;
}

// Marks the book as borrowed, only if it is currently available.
// Returns true if the borrow succeeded, false if the book was already borrowed.
bool Book::borrowBook() {
    if (available) {
        available = false;
        return true;
    }
    return false;
}

// Returns the book and marks it as available again.
// Returns true if the return succeeded, false if the book was already
// marked as available
bool Book::returnBook() {
    if (!available) {
        available = true;
        return true;
    }
    return false;
}

// ---- Accessors ----------------------------------------------------------
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getIsbn() const { return isbn; }
bool Book::isAvailable() const { return available; }
std::string Book::getDateAdded() const { return dateAdded; }

// ---- sortBookData ---------------------------------------------------------
// Sorts the array of Book objects in ascending order of ISBN using a
// simple bubble sort. Book objects are swapped using std::swap-style
// manual swapping via the copy assignment operator
void sortBookData(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (books[j].getIsbn() > books[j + 1].getIsbn()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}
