#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct Node{
    int key;
    Node* parent;
    Node* left;
    Node* right;
    Node(int val){
        key = val;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    
};
void get(Node* now){
    if(now->left != NULL) get(now->left);
    if(now->right != NULL) get(now->right);
    cout<<now->key<<"\n";
    
}
void input_make(){
    int a;
    scanf("%d",&a);
    Node* root = new Node(a);
    Node* now;
    while(scanf("%d",&a) != EOF){
        now = root;
        while(1){
            if(now->key > a){
                if(now->left == NULL){
                    now->left = new Node(a);
                    now->left->parent = now;
                    break;
                }
                now = now->left;
            }
            else{
                if(now->right == NULL){
                    now->right = new Node(a);
                    now->right->parent = now;
                    break;
                }
                now = now->right;
            }
        }
    }
    get(root);
}

int main(void){
    input_make();
}