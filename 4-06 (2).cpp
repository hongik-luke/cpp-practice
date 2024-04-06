#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class airline{
    int a,b;
    string airplane[10][100];
    string *airplanetime;
public:
    airline(int x, int y,string *timer){
        a = x; b = y;
        
        airplanetime = new string [x];
        for(int i = 0 ; i < a ;i++)
            airplanetime[i] = timer[i];
            
        for(int i = 0 ; i < x ;i++)
            for(int j = 0 ; j < y ; j++)
                airplane[i][j] = "---";
        
        
    }
    void reset(){
        for(int i = 0 ; i < a ;i++)
            for(int j = 0 ; j < b ; j++)
                airplane[i][j] = "---";
    }
    int geta(){return a;}
    int getb(){return b;}
    void setdata(int i , int j, string name){
        airplane[i][j] = name;
    }
    string getdata(int i, int j){
        return airplane[i][j];
    }
    string gettimedata(int i){
        return airplanetime[i];
    }
    
};

class reservation : virtual public airline{
public:
    reservation(int x, int y,string* timer) : airline(x,y,timer){}
    void reserve(){
        for(int i = 0 ; i < this->geta() ; i++)
        {
            cout<<gettimedata(i)<<":"<<i+1;
            if(i != this->geta()-1)
                cout<<", ";
        }
        cout<<">>";
        int n;
        cin>>n;
        n -=1;
        cout<<gettimedata(n)<<"\t";
        for(int i = 0 ; i < this->getb() ; i++)
            cout<<this->getdata(n,i)<<"\t";
            
        cout<<"\n";
        cout<<"예약하실 번호와 이름을 입력해주세요 (예 : 3 김기현)"<<"\n";
        int m;
        string nammm;
        cin>>m>>nammm;
        m = m-1;
        setdata(n,m,nammm);
        cout<<"예약되었습니다."<<"\n";
    }

};

class delet : virtual public airline{
public:
    delet(int x, int y,string* timer) : airline(x,y,timer){}    
    void dele(){
        for(int i = 0 ; i < this->geta() ; i++)
        {
            cout<<gettimedata(i)<<":"<<i+1;
            if(i != this->geta()-1)
                cout<<", ";
        }
        cout<<">>";
        int n;
        cin>>n;
        n -=1;
        cout<<gettimedata(n)<<"\t";
        for(int i = 0 ; i < this->getb() ; i++)
            cout<<this->getdata(n,i)<<"\t";
            
        cout<<"\n";
        cout<<"삭제하실 번호와 이름을 입력해주세요 (예 : 3 김기현)"<<"\n";    
        int m;
        string nammm;
        cin>>m>>nammm;
        m = m-1;
        if(this->getdata(n,m) == nammm)
        {
            this->setdata(n,m,"---");
            cout<<"정상삭제되었습니다."<<"\n";
        }
        else
        {
            cout<<"정상삭제되지 않았습니다. 번호와 이름을 확인해주세요."<<"\n";
        }
    }
    
    
    
};
class see : virtual public airline{
public:
    see(int x, int y,string* timer) : airline(x,y,timer){}    
    void watchall(){
        for(int i = 0 ; i < this->geta() ; i++){
            cout<<gettimedata(i)<<": ";
            for(int j = 0 ; j < this->getb() ; j++){
                cout<<getdata(i,j)<<"\t";
            }
            cout<<"\n";
        }
        return;
    }
};

class service : public reservation , public delet , public see{
    string companyname;
public:    
    service(string companyname, string* timer,int x = 3, int y = 8) : see(x,y,timer),delet(x,y,timer),reservation(x,y,timer), airline(x,y,timer){
        this->companyname = companyname;
    };
    void orderr(){
        int order;
        while(1){
            cout<<"예약 1 | 취소 2 | 보기 3 | 끝내기 4 >> ";
            cin>>order;
            if(order == 4)
            {
                cout<<"\n"<<"이용해주셔서 감사합니다."<<"\n";
                return;
            }
            else if(order == 1){
                this->reserve();
            }
            else if(order == 2){
                this->dele();
            }
            else if(order == 3){
                this->watchall();
            }
        }
        return;
    }
    string getcompanyname() {
        return companyname; 
        
    }
    
    
};




int main(void)
{
    int x,y;
    string s;
    cout<<"시간의 갯수 : ";
    cin>>x;
    cout<<"좌석의 갯수 : ";
    cin>>y;
    cout<<"항공사 이름 : ";
    cin>>s;
    cout<<"시간 "<<x<<"번 입력 : ";
    string* timer = new string [x];
    for(int i = 0 ; i < x ; i ++)
        cin>>timer[i];
    
    service company1(s,timer,x,y);
    cout<<"***"<<company1.getcompanyname()<<"에 오신것을 환영합니다***";
    company1.orderr();
}




