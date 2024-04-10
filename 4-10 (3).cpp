#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;
class printer{
protected:
    printer* next;
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;
    
public:
    string Catagory;
    virtual void show() = 0;
    virtual bool printpaper(int n) = 0;
    printer(string model,string manufacturer,int availableCount) {
        next = NULL;
        this->model = model;
        this->manufacturer = manufacturer;
        this->printedCount = 0;
        this->availableCount = availableCount;
    };
    printer* add(printer* p){
        this->next = p;
        return p;
    }
    printer* getnext(){return next;}
};


class InkJetprinter : public printer{
protected:
    int remainCount;
public:
    InkJetprinter(string model,string manufacturer,int availableCount,int remainCount) : printer(model,manufacturer,availableCount){
        this->remainCount = remainCount;
        this->Catagory = "InkJet";
    }
    void show(){
        cout<<model<<", "<<manufacturer<<", 남은종이 : "<<availableCount<<", 남은잉크 : "<<remainCount<<"\n";  
    }
    bool printpaper(int n){
        if(availableCount < n || remainCount < n)
            return false;
        else{
            availableCount -= n; 
            remainCount -= n;
            return true;
        }
    }
    
};
class Laserprinter : public printer{
protected:
    int remainCount;
public:
    Laserprinter(string model,string manufacturer,int availableCount,int remainCount) : printer(model,manufacturer,availableCount){
        this->remainCount = remainCount;
        this->Catagory = "Laser";
    }
    void show(){
        cout<<model<<", "<<manufacturer<<", 남은종이 : "<<availableCount<<", 남은토너 : "<<remainCount<<"\n";  
    }
    bool printpaper(int n){
        if(availableCount < n || remainCount < n)
            return false;
        else{
            availableCount -= n; 
            remainCount -= n;
            return true;
        }
    }
    
};


int main(void){
    printer *pstart = NULL;
    printer *plast = pstart;
    
    pstart = new InkJetprinter("pRITE-ogd12","INTEL",10,10);
    plast = pstart;
    plast = plast->add(new Laserprinter("SCX-51FR9","삼성전자",5,10));
    plast = plast->add(new InkJetprinter("OfficleX-91","HP",3,20));
    plast = plast->add(new Laserprinter("TK124-9","LG전자",10,5));
    plast = plast->add(new Laserprinter("ROD123","LG전자",7,4));
    plast = plast->add(new Laserprinter("V2","삼성전자",5,3));
    
    cout<<"---------현재 프린터----------"<<"\n";
    int cnt = 0;
    printer* newstart = pstart;
    while(newstart != NULL){
        if(newstart->Catagory =="InkJet")
            cout<<"잉크젯 : ";
        else
            cout<<"레이져 : ";
        newstart->show();
        newstart = newstart->getnext();
        cnt++;
    }
    int n,m;
    char k;
    while(1){
        cout<<"프린터"<<"(1~"<<cnt<<")"<<"와 매수 입력>> ";
        cin>>n>>m;
        newstart = pstart;
        for(int i = 0 ; i < n-1 ;i++){
            newstart = newstart->getnext();
        }
        if(newstart->printpaper(m))
            cout<<"프린트 성공하였습니다."<<"\n\n";
        else
            cout<<"용지나 잉크/토너 부족"<<"\n\n";
        cout<<"---------현재 프린터----------"<<"\n";

        newstart = pstart;
        while(newstart != NULL){
            if(newstart->Catagory =="InkJet")
                cout<<"잉크젯 : ";
            else
                cout<<"레이져 : ";
            newstart->show();
            newstart = newstart->getnext();

        }    
        cout<<"\n";
        
        cout<<"계속 프린트하시겠습니까?(y/n)";
        cin>>k;
        if(k == 'n')
            break;
        
    }
    
    
    
    
}






































































