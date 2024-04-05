#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)

using namespace std;
class Trace {
public:
	static string tag[100];
	static string str[100];
	static int index;
	static void put(string tager, string strr);
	static void printer(string tager);
	static void printer();
};
string Trace::tag[100] ={""};
string Trace::str[100] ={""};
int Trace::index = 0;

void Trace:: put(string tager, string strr){

    tag[index] = tager;
    str[index] = strr;
    index++;
    return;
}

void Trace:: printer(string tager){
    for(int i =0 ; i < index ; i++)
        if(tag[i] == tager)
            cout<<tag[i]<<str[i]<<"\n";
}
void Trace:: printer(){
    for(int i =0 ; i < index ; i++)
        cout<<tag[i]<<str[i]<<"\n";
}


void f() {
	int a, b, c;
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
}

int main() {
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");
	Trace::printer("f()");
	Trace::printer();
	return 0;
}