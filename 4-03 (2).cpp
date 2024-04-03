#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define TRUE	1
#define FALSE	0

#define HEAP_LEN	1000100

typedef int HData;

struct jewel{
    int weight;
    int price;
};

int compare1(const void *a , const void *b) 
{
    jewel pos1 = *(jewel*)a;
    jewel pos2 = *(jewel*)b;
    
    if(pos1.weight > pos2.weight)
        return 1;
    
    else
        return -1;
}

int DataPriorityComp1(int ch1, int ch2)
{
	if(ch1 > ch2)
	    return 1;
	else
	    return -1;
}

typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap 관련 연산들 ****/
void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);
HData HPeek(Heap * ph);
void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    int64_t result_sum = 0;
    cin>>n>>k;
    
    
    jewel* jewelarr = new jewel [n];
    int * bagarr = new int [k];
    
    for(int i = 0 ; i < n ; i++)
        cin>>jewelarr[i].weight>>jewelarr[i].price;
    for(int i = 0 ; i < k ; i++)
        cin>>bagarr[i];
        
    qsort(jewelarr,n,sizeof(jewel),compare1);
    qsort(bagarr,k,sizeof(int),compare1);
    
    
    Heap pq;
    HeapInit(&pq,DataPriorityComp1);

    int idx = 0;
    for(int i = 0 ; i < k ;i++)
    {
        while(idx < n && bagarr[i] >= jewelarr[idx].weight)
            HInsert(&pq,jewelarr[idx++].price);

        if(HIsEmpty(&pq))
            continue;
    
        result_sum += HDelete(&pq);
    }
    
    cout<<result_sum;
}

void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap * ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) 
{ 	return idx/2; }

int GetLChildIDX(int idx) 
{ 	return idx*2; }

int GetRChildIDX(int idx) 
{ 	return GetLChildIDX(idx)+1; }

int GetHiPriChildIDX(Heap * ph, int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], 
					ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData+1;

	while(idx != 1)
	{
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}
	
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap * ph)
{
    
    
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while(childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}
HData HPeek(Heap * ph)
{    return ph->heapArr[1];     }