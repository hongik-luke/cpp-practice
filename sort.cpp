#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// 정렬 정리해보기!
//1 버블정렬 O(n*n)
int arr[10000];
void bubble_sort(){
    for(int i = 0 ; i < 1000 ; i++){
        for(int j = 0 ; j < 1000-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
//2 선택정렬 O(n*n)
void selection_sort(){
    for(int i = 0 ; i < 1000 ; i++){
        int t = i;
        for(int j = i+1 ; j < 1000 ; j++){
            if(arr[t] > arr[j]){
                t = j;
            }
        }
        swap(arr[i],arr[t]);
    }
}

//3 삽입정렬 O(n*n)
void insertion_sort(){
    for(int i = 0 ; i < 1000 ; i++){
        int num = arr[i];
        int t = i;
        while(t-1 >= 0){
            if(arr[t-1] > num){
                arr[t] = arr[t-1];
            }
            else break;
            t--;
        }
        arr[t] = num;
    }
}

//4 힙정렬 O(nlogn)
void Heap_sort(){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0 ; i < 1000 ; i++){
        pq.push(arr[i]);
    }
    for(int i = 0 ; i < 1000 ; i++){
        arr[i] = pq.top();
        pq.pop();
    }
}

//5 힙정렬 O(nlogn)
void Merge_sort(int arr[], int lo, int hi){
    if(lo == hi) return;
    
    int mid = (lo+hi)/2;
    Merge_sort(arr,lo, mid);
    Merge_sort(arr,mid+1, hi);

    int newarr[1000];
    int nidx = lo; 
    int fidx = lo; int sidx = mid+1;
    while(fidx <= mid && sidx <= hi){
        if(arr[fidx] <= arr[sidx])
            newarr[nidx++] = arr[fidx++];
        else
            newarr[nidx++] = arr[sidx++];
    }
    if(fidx == mid+1){
        while(sidx <= hi){
            newarr[nidx++] = arr[sidx++];
        }
    }
    if(sidx == hi+1){
        while(fidx <= mid){
            newarr[nidx++] = arr[fidx++];
        }
    }
    for(int i = lo ; i <= hi ; i++)
        arr[i] = newarr[i];
}

//6 퀵정렬 O(nlogn)

int partition(int lo, int hi){
    int pivot = arr[lo];
    int l = lo+1 ; int r = hi;
    while(l <= r){
        while(pivot >= arr[l] && l <= hi){             // while문 내부도 중요함
            l++;
        }
        while(pivot <= arr[r] && r >= lo+1){
            r--;
        }
        if (l > r) break;                                            // 제일 중요
        swap(arr[l],arr[r]);
    }
    swap(arr[lo],arr[r]);
    return r;
}
void quick_sort(int lo, int hi){
    if(lo <= hi){

        int pivot = partition(lo,hi);
        quick_sort(lo, pivot-1);
        quick_sort(pivot+1, hi);
    }
}

int main(void){

    for(int i = 0 ; i < 1000; i++)
        arr[i] = rand()%10000;
    bubble_sort();
    for(int i = 0 ; i < 1000; i++)
        cout << arr[i] << " ";
    cout<<"\n";
    
    for(int i = 0 ; i < 1000; i++)
        arr[i] = rand()%10000;
    selection_sort();
    for(int i = 0 ; i < 1000; i++)
        cout << arr[i] << " ";
    cout<<"\n";
    
    for(int i = 0 ; i < 1000; i++)
        arr[i] = rand()%10000;
    insertion_sort();
    for(int i = 0 ; i < 1000; i++)
        cout << arr[i] << " ";
    cout<<"\n";
    
    for(int i = 0 ; i < 1000; i++)
        arr[i] = rand()%10000;
    Heap_sort();
    for(int i = 0 ; i < 1000; i++)
        cout << arr[i] << " ";
    cout<<"\n";
    
    for(int i = 0 ; i < 1000; i++)
        arr[i] = rand()%10000;
    Merge_sort(arr,0,999);
    for(int i = 0 ; i < 1000; i++)
        cout << arr[i] << " ";
    cout<<"\n";
    
    for(int i = 0 ; i < 1000; i++)
        arr[i] = rand()%10000;
    quick_sort(0,999);
    for(int i = 0 ; i < 1000; i++)
        cout << arr[i] << " ";
    cout<<"\n";
}