#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

double f_x1,f_y1,l_x1,l_y1;
double f_x2,f_y2,l_x2,l_y2;


// 0<=x<=1
double checkdistance(double x){
    double nowx1 = (l_x1-f_x1)*x + f_x1; 
    double nowy1 = (l_y1-f_y1)*x + f_y1; 
    double nowx2 = (l_x2-f_x2)*x + f_x2; 
    double nowy2 = (l_y2-f_y2)*x + f_y2;
    
    return sqrt((nowx2-nowx1)*(nowx2-nowx1) + (nowy2-nowy1)*(nowy2-nowy1));
}
double result(){
    double lo = 0.0; double hi = 1.0;
    double mida,midb;
    for(int i = 0 ; i < 100 ; i++){
        mida = (2*lo + hi)/3;
        midb = (lo + 2*hi)/3;
        //cout<<mida<<midb<<"\n";
        if(checkdistance(mida) < checkdistance(midb)){
            hi = midb;
        }
        else 
            lo = mida;
    }
    
    return checkdistance(lo);
}
int main(void){
    cin>>f_x1>>f_y1>>l_x1>>l_y1>>f_x2>>f_y2>>l_x2>>l_y2;
    printf("%0.10lf",result());
}

