#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class statistics{
    int* arr;
    int tmp;
public:
    statistics(){
        arr = new int [1000];
        tmp = 0;
        return;
    }
    bool operator!(){
        if(tmp == 0)
            return true;
        else return false;
    }
    statistics& operator<<(int n){
        arr[tmp] = n;
        tmp++;
        return *this;
    }
    void operator>>(int &n){
        int sum = 0;
        for(int i = 0 ; i < tmp ; i++){
            sum += arr[i];
        }
        n = sum/tmp;
        return;
    }
    void operator~(){
        for(int i = 0 ; i < tmp ; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    
};





int main() {
	statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;

	int x[5];
	cout << "5개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) 
	    cin >> x[i];
	for (int i = 0; i < 5; i++) 
	    stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;

	return 0;
}










