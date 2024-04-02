#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100010
typedef int HData;

int DataPriorityComp1(int ch1, int ch2)
{
	if(ch1 > ch2)
	    return -1;
	else
	    return 1;
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
    
    int result_cnt = 0;
    int numofrazer = 0;
    int razerarr[50001];
    int low,high;
    string str;
    stack<int> firststack;
    
    Heap lowheap;
    Heap highheap;
    HeapInit(&lowheap,DataPriorityComp1);
    HeapInit(&highheap,DataPriorityComp1);
    
    cin>>str;
    int len =str.length();
    for(int i = 0 ; i < len ; i++)
    {
        if(str[i] == '(')
            firststack.push(i);
        else
        {  
            low = firststack.top();
            high = i;
            firststack.pop();
            if(high - low == 1)
                razerarr[numofrazer++] = i;
            else
            {
                result_cnt++;
                HInsert(&lowheap,low);
                HInsert(&highheap,high);
            }
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < numofrazer ;i++)
    {
        while(!HIsEmpty(&lowheap) && razerarr[i] > HPeek(&lowheap))
        {
            HDelete(&lowheap);
            cnt++;
        }
        while(!HIsEmpty(&highheap) && razerarr[i] > HPeek(&highheap))
        {
            HDelete(&highheap);
            cnt--;
        }
        result_cnt += cnt;
    }
    
    cout<<result_cnt;
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