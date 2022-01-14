#include <bits/stdc++.h>
using namespace std;

struct libraryBook{
    string bookID;
    string title;
    vector<string> authors;
    vector<string> publishers;
    libraryBook(string bookID, string title, vector<string> authors, vector<string> publishers) : bookID(bookID), title(title), authors(authors), publishers(publishers) {}
};

string libraryID="";
int totalRacks=0; 
map<int, vector<libraryBook>> rackDetails;
map<string, vector<string>> bookCopyDetails;

void createLibrary(string libID, int racks){
    libraryID = libID;
    totalRacks = racks;
    for(int i=0; i<racks; i++){
        rackDetails[i] =  vector<libraryBook> ();
    }
    cout << "Library: " << libID << " with " << racks << " racks created." << endl;
}

bool vectorsAreSame(vector<string> v1, vector<string> v2){
    int v1Size = v1.size();
    int v2Size = v2.size();
    if(v1Size != v2Size)
        return false;

    set<string> v1Details;
    for(int i=0; i<v1Size; i++){
        v1Details.insert(v1[i]);
    }
    for(int j=0; j<v2Size; j++){
        if(v1Details.find(v2[j]) == v1Details.end())
            return false;
    }
    return true;
}

bool twoBooksAreSame(libraryBook book1, libraryBook book2){
    bool areAuthorsSame = vectorsAreSame(book1.authors, book2.authors);
    bool arePublishersSame = vectorsAreSame(book1.authors, book2.authors);
    bool isTitleSame = book1.title==book2.title;

    return areAuthorsSame && arePublishersSame && isTitleSame;
}

bool canThisBookAddedToRack(libraryBook curBook,  vector<libraryBook> bookDetailsInRacks){
    int booksInRack = bookDetailsInRacks.size();
    for(int i=0; i<booksInRack; i++){
        if(twoBooksAreSame(curBook, bookDetailsInRacks[i]))
            return false;
    }
    return true;
}

void addBook(string bookID, string title, vector<string> authors, vector<string> publishers, vector<string> bookCopies){
    libraryBook curBook = libraryBook(bookID, title, authors, publishers);

    vector<string> bookCopiesArray;
    for(int i=0; i<bookCopies.size(); i++){
        bookCopiesArray.push_back(bookCopies[i]);
    }
    bookCopyDetails[bookID] = bookCopiesArray;

    if(totalRacks > bookCopies.size()+1){
        cout << "Error adding book. Rack not available." << endl;
        return;
    }

    rackDetails[0].push_back(curBook);

    bool addedToRack = false;
    for(int i=1; i<bookCopies.size(); i++){
        auto bookDetailsInRacks = rackDetails[i];
        libraryBook curBookCopy = libraryBook(bookCopies[i-1], title, authors, publishers);
        rackDetails[i].push_back(curBookCopy);
    }
}

void removeBook(string curBookID){
    bool bookRemoved=false;
    for(int i=0; i<totalRacks; i++){
        auto bookDetailsInRacks = rackDetails[i];
        for(auto bookIterator = bookDetailsInRacks.begin(); bookIterator != bookDetailsInRacks.end(); ++bookIterator){
            if(bookIterator->bookID == curBookID){
                bookDetailsInRacks.erase(bookIterator);
                bookRemoved = true;
                break;
            }
        }
        if(bookRemoved)
            break;
    }

    if(!bookRemoved)
        cout << "Error removing book. Book not found." << endl;
}

