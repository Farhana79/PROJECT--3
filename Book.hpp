
// Farhana Sultana 
// farhana.sultana79@myhunter.cuny.edu
// Csci 235
// project 3

#ifndef BOOK_HPP_
#define BOOK_HPP_

#include <iostream>
#include <string>

class Book {
public:
    /**
     * Default constructor.
     * Default-initializes all private members. Booleans are default-initialized to False.
     */
    Book() = default;

    /**
     * Parameterized constructor.
     * @param title The title of the book (a string).
     * @param author The author of the book (a string).
     * @param page_count The number of pages in the book (a positive int).
     * @param is_digital A flag indicating whether the book is in digital form (a Boolean),
     *                   with default value False.
     * @post The private members are set to the values of the corresponding parameters.
     */
    Book(std::string title, std::string author, int page_count, bool is_digital = false);

    /**
     * Returns the title of the Book.
     * @return The title of the Book.
     */
    std::string getTitle() const;

    /**
     * Returns the author of the Book.
     * @return The author of the Book.
     */
    std::string getAuthor() const;

    /**
     * Returns the page count.
     * @return The page count.
     */
    int getPageCount() const;

    /**
     * Returns true if the book is available in digital form, false otherwise.
     * Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getDigital.
     * @return True if the book is available in digital form, false otherwise.
     */
    bool isDigital() const;

    /**
     * Sets the Book's title to the value of the parameter.
     * @param title A reference to title of the Book.
     * @post The Book's title is set to the value of the parameter.
     */
    void setTitle(const std::string &title);

    /**
     * Sets the Book's author to the value of the parameter.
     * @param author A reference to the name of the author of the Book.
     * @post The Book's author is set to the value of the parameter.
     */
    void setAuthor(const std::string &author);

    /**
     * Sets the page count to the value of the parameter.
     * @param page_count A reference to a positive integer page count.
     * @pre page count > 0 - books cannot have a negative number of pages.
     * @post The page count is set to the value of the parameter.
     */
    void setPageCount(const int &page_count);

    /**
     * Sets the digital flag to true.
     * @post The digital flag is set to true.
     */
    void setDigital();

    /**
     * check if is two book are equal
     * Note: All attributes must be aqual for two books to be deemed equal
     * @param b : b reference to the right hand of the operator ==
     * @return : Returns true if the right hand side book is identical; false otherwise 
     */

    bool operator==(const Book &b)const;

    /**
     *Note: All attributes must be equal for two books to be deemed 
     * @param b : b A reference to the right hand of the operator !=
     * @return : Returns true if the right hand side book is not identical(!=),false otherwise. 
     */
    bool operator!=(Book &b);

    /**
     *   @post     : displays Book data in the form:
     * "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] 
     * available digitally.\n"
     */ 
    void display();

private:
    std::string title_;     // The title of the book (a string)
    std::string author_;    // The author of the book (a string)
    int page_count_ = 0;    // The page count (an integer)
    bool is_digital_ = false;  // A flag indicating whether the book is available in digital form (a Boolean)
};

#endif  // BOOK_HPP_
