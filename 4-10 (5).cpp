#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

template <class T>
T biggest(T* arr, int size){
    T max = arr[0];
    for(int i = 1 ; i < size ; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}
template <class T>
bool equalArr(T* arr1,T* arr2, int size){

    for(int i = 0 ; i < size ; i++)
    {
        if(arr2[i] != arr1[i])
            return false;
    }
    return true;
}
template <class T>
void reverseArr(T* arr, int size){
    T temp;
    for(int i = 0 ; i < size/2 ;i++)
    {
        temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}
template <class T> bool searchArr(T search ,T* arr , int size){

    for(int i = 0 ; i < size ;i++)
    {
        if(search == arr[i])
            return true;
    }
}

template <class T1> T1* concat(T1 a[] ,int asize, T1 b[] , int bsize){
    T1* newarr = new T1 [asize+bsize];
    for(int i = 0 ; i < asize; i++){
        newarr[i] = a[i];
    }
    for(int i = 0 ; i < bsize; i++){
        newarr[i+asize] = b[i];
    }
    return newarr;
}

template <class T1>
T1* remover(T1 src[],int sizesrc,T1 minus[],int sizeminus,int &retsize){
    T1 *p = new T1 [sizesrc]; 
    retsize = 0;
    for(int i = 0 ; i < sizesrc ; i++){
        int cnt = 0;
        for(int j = 0 ; j < sizeminus ; j++){
            if(src[i] == minus[j])
                break;
            if(j == sizeminus-1)
                p[retsize++] = src[i];
        }
        
    }
    T1* result = new T1 [retsize];
    for(int i = 0 ; i < retsize ; i++)
        result[i] = p[i];
    return result;
}



class Comparable
{
public:
	virtual bool operator > (Comparable& op2) = 0;
	virtual bool operator < (Comparable& op2) = 0;
	virtual bool operator == (Comparable& op2) = 0;
};
class Circle : public Comparable{
	int radius;
	
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator >(Comparable& op2){
	    Circle* a = (Circle*)&op2;
	    if(this->getRadius() > a->getRadius()) return true;
	    else return false;
	}
	bool operator <(Comparable& op2){
	    Circle* a = (Circle*)&op2;
	    if(this->getRadius() < a->getRadius()) return true;
	    else return false;
	}
	bool operator ==(Comparable& op2){
	    Circle* a = (Circle*)&op2;
	    if(this->getRadius() == a->getRadius()) return true;
	    else return false;
	}
};


template <class T>
T bigger(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}






int main(void){
    int x[] = {1,53,51 ,414 ,12};
    int y[] = {1,53,51 ,414 ,2};
    cout<<biggest(x,5)<<"\n";
    
    if(equalArr(x,y,5)) cout<<"같다."<<"\n";
    else cout<<"다르다"<<"\n";
    
    reverseArr(x,5);
    for(int i = 0 ; i < 5 ; i++) cout<<x[i]<<" ";
    cout<<"\n";
    
    if(searchArr(414,x,5)) cout<<"있다."<<"\n";
    else cout<<"없다"<<"\n";
    
    int* p = concat(x,5,y,5);
    for(int i = 0 ; i < 10 ; i++)
        cout<<p[i]<<" ";
    cout<<"\n";
    
    int retsize = 0;
    int k[] = {55,27,411,414 ,2};
    int *pp = remover(p,10,k,5,retsize);
    for(int i = 0 ; i < retsize ; i++){
        cout<<pp[i]<<" ";
    }
    cout<<"\n";
    
	Circle waffle(10), pizza(20), y3;
	y3 = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y3.getRadius() << endl;
}



























