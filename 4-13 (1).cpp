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
	c = c/10 +1;

	fin.seekg(0,ios::beg);
	char *buf = new char [c];
	int cnt = 1;
	int i = 1;
	while(!fin.eof()) {
	        
	        fin.read(buf,c);
	        int n = fin.gcount();
	        
	        fout.write(buf,n);
	        fout.write("\n\n\n",3);
	        cout<<(i)*10<<"%"<<"\n";
	        i++;
	}
    //110까지 뜨는 이유 = 853byte -> 85byte 이렇게 되었기에 남은 부분이 호출되야해서 한번 더 진행됨
    //물론 c = c/10 +1 을 통해 반올림하면 사라지는 문제!
	fin.close();
}




























