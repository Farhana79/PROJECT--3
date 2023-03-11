
// Farhana Sultana 
// farhana.sultana79@myhunter.cuny.edu
// Csci 235
// project 3

#include"LibraryRecord.hpp"

/** @param: new_book  A reference to a Book object to be checked in
	 * @return:  returns true if a book was successfully added to items_, false otherwise
	 * @post:    adds book to items_.
	 */
	bool LibraryRecord::checkIn(Book &new_book){
		return add(new_book);
	}

/** @param:  new_checked_out A reference to a Book object to be checked out   
	 * @return:  returns true if a book was successfully removed from items_, false otherwise
	 * @post:    removes the book from the LibraryRecord and if remove was successful, it adds the book to the vector of checked-out books
	 */
	bool LibraryRecord::checkOut(const Book &new_checked_out){

		if(remove(new_checked_out)){
			this->checked_out_.push_back(new_checked_out);
			return true;
		}
		return false;
	}
/**
	 * @param:   book A reference to a Book object
	 * @return:  The number of times (int) the referenced Book has been checked out
	 */
	int LibraryRecord::getCheckOutHistory(Book &book){
		 int count=0;
		 for(size_t i=0;i<checked_out_.size();i++)
		 	if(checked_out_[i]==book)
		 		count++;

		 return count;
	}
/**
 	* @post:    Outputs the names of the Books in the LibraryRecord and the number of times each Book has been cheked out
	* For each Book in the LibraryRecord you will output:
 	* "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] available digitally.\n
 	* It has been checked out [_] times.\n"
 	*/
 	void LibraryRecord::display(){
 		for(Book book : checked_out_){
 			book.display();
 			std::cout<<"It has been checked out"<<" "<<getCheckOutHistory(book)<<" "<<"times.\n";
 		}
 	}
/**
 	 * @post:    Prints the title of each Book in the LibraryRecord
 	 * Example:
 	 * "title1, title2, title3, title4!\n" Note the commas and exclamation mark.
 	 */
 	void LibraryRecord::displayTitles(){
 		std::cout<<items_[0].getTitle()<<",";
 		for(int i=1;i<item_count_-1;i++){
 			std::cout<<" "<<items_[i].getTitle()<<",";
 		}
 		std::cout<<" "<<items_[item_count_-1].getTitle()<<"!\n";
 	}
/**@return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
 * * @post:      Duplicates all the items in the LibraryRecord
 * *Example: we originally have [book1, book2] and after duplication we have [book1, book2, book1, book2]
 * */
 	bool LibraryRecord::duplicateStock(){
 		int nb=item_count_;
 		if(item_count_==0 || item_count_<(0.5*DEFAULT_CAPACITY))
 			return false;
 		for(int i=0;i<nb;i++)
 			checked_out_.push_back(items_[i]);
 		return true;
 	}
/**
 * @param:  book A reference to a book
 * @return: True if at least one copy of the referenced book was removed from items_, false otherwise 
 * @post: remove all occurrences of the referenced book
 */
 	bool LibraryRecord::removeStock(Book &book){
 		bool status = false;
 		while(remove(book)){
 			status=true;
 		}
 		return status;
 	}
/**
 * @param:   library A reference to another LibraryRecord
 * @return:  Returns true if the 2 library records have the same contents (including the same number of duplicates for each book), regardless of their order. For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
 * and those of the referenced LibraryRecord are [book3, book1, book2], it will return true.
 * However, [book1, book2, book2, book3] is not equivalent to [book1, book2, book3, book3], because it contains two copies of book2 and only one copy of book3*/

bool LibraryRecord::equivalentRecord(LibraryRecord &library){
	if(item_count_!=library.item_count_)
		return false;
	for(Book b : items_){
		if(getFrequencyOf(b)!=library.getFrequencyOf(b))
			return false;
	}
	return true;
}

/**

    @param:   library A reference to another LibraryRecord object

    @post:    Combines the contents from both LibraryRecord objects, including duplicates.

    Example: [book1, book2, book3] += [book1, book4] will produce [book1, book2, book3, book1, book4]


    IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 += LibraryRecord2 and

    book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the += operation

    Hint: use getCheckOutHistory and the checkout history vector

*/

LibraryRecord LibraryRecord::operator+=(LibraryRecord &library){
	this->checked_out_=library.checked_out_;
	return *this+=library;
}

/** @param:   A reference to another LibraryRecord object

    @post:    Combines the contents from both LibraryRecord objects, EXCLUDING duplicates.

    Example: [book1, book2, book3] /= [book1, book4] will produce [book1, book2, book3, book4]


    IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 /= LibraryRecord2 and

    book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the /= operation

    Hint: use getCheckOutHistory and the checkout history vector

*/

LibraryRecord LibraryRecord::operator/=(LibraryRecord &library){
	this->checked_out_=library.checked_out_;
	return *this+=library;
}
