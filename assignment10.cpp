#include <iostream>
#include <string>
using namespace std;
void searchBook(const int isbn[], const string titles[], const string authors[], int size, int search_isbn) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (isbn[i] == search_isbn) {
            cout << "Book Title: " << titles[i] << endl;
            cout << "Author: " << authors[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "The book is not available in library." << endl;
    }
}
int main() {
    const int isbn[] = {1, 2, 3}; 
    const string titles[] = {"Let Us C", "Python Programming", "Lost Child"};
    const string authors[] = {"Yashavant Kanetkar", "John M Zelle", "Mulk Raj Anand"};
    int size = sizeof(isbn) / sizeof(isbn[0]); 
    int search_isbn;
    cout << "Enter the ISBN of the book: ";
    cin >> search_isbn;
    searchBook(isbn, titles, authors, size, search_isbn);

    return 0;
}
