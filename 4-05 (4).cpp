#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)

using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
    
    Book& operator+=(int n){
        this->price += n;
        return *this;
    }
    bool operator==(Book a){
        if(this->title == a.title && this->price == a.price && this->pages == a.pages)
            return true;
        else
            return false;
    }
    bool operator<(Book a){
        if(this->title < a.title )
            return true;
        else
            return false;
    }
    
    bool operator!(){
        if(this->price == 0 )
            return true;
        else
            return false;
    }
};

int main() {
	Book a("가나다", 20000, 300);
    Book b("청춘", 20000, 300);
	if (b < a)
		cout << a.getTitle() << "이 " << b.getTitle() << "보다 뒤에 있구나!" << "\n";
	else
	    cout << b.getTitle() << "이 " << a.getTitle() << "보다 뒤에 있구나!" << "\n";
	return 0;
}

