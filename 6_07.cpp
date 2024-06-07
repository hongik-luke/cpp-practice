#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct Node{
    int idx;
    Node* left;
    Node* right;
    Node(){
        idx = 0;
        left = NULL;
        right = NULL;
    };
};
int N;
vector<int> in,post;

Node* get_tree(int in_start, int in_end, int p_start, int p_end, int len){
    Node* ret = new Node();
    ret->idx = post[p_end];
    if(p_start == p_end){
        return ret;
    }
    
    int i;
    for(i = in_start ; i <= in_end ; i++){
        if(in[i] == post[p_end]) break;
    }
    int cnt = i - in_start;
    if(cnt != 0) ret->left = get_tree(in_start, in_start+cnt-1, p_start, p_start+cnt-1, cnt);
    if(len-cnt-1 != 0) ret->right = get_tree(in_start+cnt+1, in_end, p_start+cnt, p_end-1, len-cnt-1);

    return ret;
}
void input(){
    cin>>N;
    int n;
    for(int i = 0; i < N ;i++){
        cin>>n;
        in.push_back(n);
    }
    for(int i = 0; i < N ;i++){
        cin>>n;
        post.push_back(n);
    }

}
void pre_order(Node* root){
    if(root == NULL) return;
    cout<<root->idx<<" ";
    pre_order(root->left);
    pre_order(root->right);
}
int main(void){
    input();
    Node* root = new Node();
    root = get_tree(0, N-1, 0, N-1, N);
    pre_order(root);
}
