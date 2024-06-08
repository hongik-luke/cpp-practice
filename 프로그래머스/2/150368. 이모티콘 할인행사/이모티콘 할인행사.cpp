#include <string>
#include <vector>

using namespace std;
int max_result1 = 0;
int max_result2 = 0;

int now_dis[8];

int emo_cnt;
int user_cnt;
vector<int> emo_value;
vector<int> user_dis;
vector<int> user_pri;

void get(int idx){
    if(idx == emo_cnt){
        int ret1 = 0,ret2 = 0;
        for(int i = 0 ; i < user_cnt ; i++){
            int now = 0;
            
            for(int j = 0 ; j < emo_cnt ; j++){
                if(now_dis[j] >= user_dis[i])
                    now += (emo_value[j]*(100 - now_dis[j]));
            }
            if(now >= user_pri[i]) ret1++;
            else ret2 += now;
        }
        if(ret1 > max_result1){
            max_result1 = ret1;
            max_result2 = ret2;
        }
        else if(ret1 == max_result1){
            max_result2 = max(ret2, max_result2);
        }       
        return;
    }
    for(int i = 1 ; i <= 4 ; i++){
        now_dis[idx] = 10*i;
        get(idx+1);
    }
    return;
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    emo_cnt = emoticons.size();
    for(int i = 0 ; i < emo_cnt ; i++){
        emo_value.push_back(emoticons[i]/100);
    }
    user_cnt = users.size();
    for(int i = 0 ; i < user_cnt ; i++){
        user_dis.push_back(users[i][0]);
        user_pri.push_back(users[i][1]);
    }
    get(0);
    vector<int> v;
    v.push_back(max_result1);
    v.push_back(max_result2);
    
    return v;
}









