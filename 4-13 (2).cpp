#include <iostream>
#include <fstream>
using namespace std;
//주석문
int main() {
	ifstream fin("test.txt");
	ofstream fout("test2.txt");
	if(!fin) {
		cout << "열기 오류" << endl;
		cout << "경로명이 옳은지 파일이 있는지 확인하세요" << endl;//주석문
		return 0;
	} //주석문
	if(!fout) {
		cout << "열기 오류" << endl;
		cout << "경로명이 옳은지 파일이 있는지 확인하세요" << endl; //주석문
		return 0;
	}
	
	fin.seekg(-1,ios::end);
	int c = fin.tellg();

	for(int i = 0 ; i < c ; i++){
	    fin.seekg(c-1-i,ios::beg);
	    int ch = fin.get();
	    fout.put(ch);
	}
	
	fin.close();
	fout.close();
}




























