#include <iostream>
#include <fstream>
using namespace std;
//주석문
int main() {
	ifstream fin("4-13.cpp");
	if(!fin) {
		cout << "열기 오류" << endl;
		cout << "경로명이 옳은지 파일이 있는지 확인하세요" << endl;//주석문
		return 0;
	} //주석문
	ofstream fdest("test2.txt");
	if(!fdest) {
		cout << "열기 오류" << endl;
		cout << "경로명이 옳은지 파일이 있는지 확인하세요" << endl; //주석문
		return 0;
	}
	int ch;
	
	while((ch = fin.get()) != EOF) {
        if(ch == '/'){
            if((ch = fin.get()) == '/'){
                fin.ignore(100,'\n');
                fdest.put('\n');
            }
        }
	    else{
	        fdest.put(ch);
	    }
	}

	fin.close();
}




























