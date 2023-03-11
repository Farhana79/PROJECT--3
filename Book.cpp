

#include "Book.hpp"

/**
Parameterized constructor.
@param title: The title of the book (a string)
@param author: The author of the book (a string)
@param page_count: The number of pages in the book (a positive int)
@param is_digital: A flag indicating whether the book is in digital form (a Boolean),
with default value False
@post: The private members are set to the values of the corresponding parameters.
*/
Book::Book(std::string title, std::string author, int page_count, bool is_digital):
title_{title}, author_{author}, page_count_{page_count},is_digital_{is_digital}{}

/**
@return: The title of the Book
*/
std::string Book::getTitle() const{
return title_;
}

/**
@return: The author of the Book
*/
std::string Book::getAuthor() const{
return author_;
}

/**
@return: The page count
*/
int Book::getPageCount() const{
return page_count_;
}

/**
@return: True if the book is available in digital form, false otherwise

Note: This is an accessor function and must follow the same convention as all accessor functions even if it is not called getDigital
*/
bool Book::isDigital() const{
return is_digital_;
}

/**
@param title: A reference to title of the Book
@post: Sets the Book's title to the value of the parameter
*/
void Book::setTitle(const std::string& title){
title_ = title;
}

/**
@param author: A reference to the name of the author of the Book
@post: Sets the Book's author to the value of the parameter
*/
void Book::setAuthor(const std::string& author){
author_ = author;
}

/**
@param page_count: A reference to a positive integer page count
@pre: page count > 0 - books cannot have a negative number of pages
@post: Sets the page count to the value of the parameter
*/
void Book::setPageCount(const int& page_count){
if (page_count > 0)
{
page_count_ = page_count;
}
}

/**
@post: Sets the digital flag to true
*/
void Book::setDigital(){
is_digital_ = true;
}

/**
     * check if is two book are equal
     * Note: All attributes must be aqual for two books to be deemed equal
     * @param b : b reference to the right hand of the operator ==
     * @return : Returns true if the right hand side book is identical; false otherwise 
     */

bool Book::operator==(const Book &b)const{
	if(this->title_!=b.title_)
		return false;
	if(this->author_!=b.author_)
		return false;
	if(this->page_count_!=b.page_count_)
		return false;
	if(this->is_digital_!=b.is_digital_)
		return false;

	return true;
}
 /**
     *Note: All attributes must be equal for two books to be deemed 
     * @param b : b A reference to the right hand of the operator !=
     * @return : Returns true if the right hand side book is not identical(!=),false otherwise. 
     */
    bool Book::operator!=(Book &b){
    	return !operator==(b);
    }
 /**
     *   @post     : displays Book data in the form:
     * "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] 
     * available digitally.\n"
     */ 
    void Book::display(){
    	std::cout<< this->title_+" is written by "+this->author_+". Page Count: "<<page_count_<<". "<<(this->is_digital_?" It is":" It is not")<<" available digitally.\n";
    }
