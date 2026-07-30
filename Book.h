#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;
    std::string dateAdded;

public:
    // Constructors
    Book();
    Book(const std::string& title,
         const std::string& author,
         const std::string& isbn,
         bool available,
         const std::string& dateAdded);

    // Core behaviour required by the assessment brief
    void setBookDetails(const std::string& title,
                         const std::string& author,
                         const std::string& isbn,
                         bool available,
                         const std::string& dateAdded);

    void displayBookDetails() const;

    bool borrowBook();   
    bool returnBook();   
    
    // Accessors
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    bool isAvailable() const;
    std::string getDateAdded() const;
};

// Free function: sorts an array of Book objects by ISBN (ascending).
// Implemented using bubble sort for simplicity/readability.
// Fixed array size (5 books) used by the main application in Phase 1.
void sortBookData(Book books[], int size);

#endif // BOOK_H
