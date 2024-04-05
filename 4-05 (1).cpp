#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)

using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price);
	void set(string tile, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book :: Book(string title, int price){
    this->title = title;
    this->price = price;
}


void Book :: set(string tile, int price){
    this->title = tile;
    this->price = price;
}


int main() {
	Book cpp("erewgsadf", 10000);
	Book java = cpp;
	java.set("java", 12000);
	cpp.show();
	java.show();

	return 0;
}