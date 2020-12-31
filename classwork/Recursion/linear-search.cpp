#include<iostream>

using namespace std;
#define n 6
int RLinear(int arr[],int index,int key)
{
    if(index < 0 )
    return -1; 

    if(arr[index] == key)
    return index; 
    else
    {
        return RLinear(arr,index - 1,key); 
    }
    

}

int B_Search(int arr[],int left,int right,int key)
{
    
    while(left <= right)
    {
         int mid = (left + right)/2;

        if(arr[mid] == key)
         return mid; 
    else if(key < mid)
     right = mid - 1; 
    else 
    left = mid + 1; 
    
     

    }
    return -1; 
    



}


int main(void)
{

int arr[] = {1,2,3,4,5,6}; 

int indexCount = n;
int key = 6; 
//int result = RLinear(arr,indexCount,key); 
int result = B_Search(arr,0,n,key); 

cout <<"element "<< key << " at : "  <<result << endl;
}