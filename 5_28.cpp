#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
const double PI = 3.141592;
struct vector2{
    double x,y;
};
vector<vector2> v;
int N;
double dist(vector2 a, vector2 b){ return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y)); }

double polar(vector2 standard, vector2 a) { return atan2(a.y-standard.y, a.x-standard.x);}

double get(vector2 standard, vector2 a,vector2 b){
    return sin(polar(standard,b) - polar(standard,a))/2*dist(standard,a)*dist(standard,b);
}
void input(){
    cin>>N;
    vector2 n;
    for(int i = 0 ; i < N ; i++){
        cin>>n.x>>n.y;
        v.push_back(n);
    }
}


int main(void){
    input();
    double result = 0;
    for(int i = 1 ; i < v.size()-1 ;i++ ){
        //cout<<get(v[0],v[i],v[i+1])<<"  ";
        result += get(v[0],v[i],v[i+1]);

    }
    result = abs(result);
    printf("%0.1lf",result);
    
}