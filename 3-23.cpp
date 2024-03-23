#include <iostream>
#include <queue>
#include <string>
using namespace std;



int main(void)
{
    int answer[200001] = {0,};
    int n, t;
    int cnt = 0;
    int quesize;
    int nownum;
    
    queue<int> que;
    
    cin>>n>>t;
    
    answer[n] = 1;
    que.push(n);

    while(1)
    {
        if(answer[t] != 0)
            break;
            
        quesize = que.size();
        
        for(int i = 0 ; i < quesize ; i++)
        {
            nownum = que.front();
            que.pop();

            if(nownum-1 >= 0 && answer[nownum-1] == 0)
            {
                answer[nownum-1] = 1;
                que.push(nownum-1);
            }
            if(nownum+1 <= 200000 && answer[nownum+1] == 0)
            {
                answer[nownum+1] = 1;
                que.push(nownum+1);
            }
            if(nownum*2 <= 200000 && answer[nownum*2] == 0)
            {
                answer[nownum*2] = 1;
                que.push(nownum*2);
            }
        }
        
        cnt++;
    }

    cout<<cnt<<"\n";
 
}