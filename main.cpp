#include <iostream>
#include "Book.h"

const int LIBRARY_SIZE = 5;

void displayCatalogue(Book books[], int size) {
    std::cout << "\n===== Library Catalogue (sorted by ISBN) =====\n";
    for (int i = 0; i < size; ++i) {
        books[i].displayBookDetails();
    }
    std::cout << "===============================================\n";
}

int main() {
    // Initialise an array with 5 books for the library
    Book library[LIBRARY_SIZE];
    library[0].setBookDetails("The Hobbit", "J.R.R. Tolkien", "9780261102217", true, "12/01/2023");
    library[1].setBookDetails("Clean Code", "Robert C. Martin", "9780132350884", true, "03/05/2022");
    library[2].setBookDetails("The C++ Programming Language", "Bjarne Stroustrup", "9780321563842", true, "20/08/2021");
    library[3].setBookDetails("Introduction to Algorithms", "Cormen et al.", "9780262033848", false, "14/02/2022");
    library[4].setBookDetails("Design Patterns", "Gamma et al.", "9780201633610", true, "30/11/2020");

    // sortBookData(): sort the book data in the array by ISBN
    sortBookData(library, LIBRARY_SIZE);

    displayCatalogue(library, LIBRARY_SIZE);

    std::string inputIsbn;
    while (true) {
        std::cout << "\nEnter the ISBN of the book you wish to borrow (or 0 to exit): ";
        std::cin >> inputIsbn;

        // Program terminates when the user enters "0" as the ISBN
        if (inputIsbn == "0") {
            std::cout << "Thank you for using the Community Library System. Goodbye!\n";
            break;
        }

        bool found = false;
        for (int i = 0; i < LIBRARY_SIZE; ++i) {
            if (library[i].getIsbn() == inputIsbn) {
                found = true;
                if (library[i].borrowBook()) {
                    std::cout << "Success! You have borrowed:\n  ";
                    library[i].displayBookDetails();
                } else {
                    // Book found but not available -> error message
                    std::cout << "Error: \"" << library[i].getTitle()
                              << "\" is currently unavailable (already borrowed).\n";
                }
                break;
            }
        }

        if (!found) {
            std::cout << "Error: No book found in the library with ISBN " << inputIsbn << ".\n";
        }
    }

    return 0;
}
