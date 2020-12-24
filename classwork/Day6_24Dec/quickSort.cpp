#include<iostream>

using namespace std;

#define SIZE 7
void print(int *arr)
{
    for (int index = 0; index < SIZE; ++index)
    {
        cout<<arr[index]<< " "; 
    }
    cout<<endl; 
    
}

void quick_sort(int *arr,int left,int right)
{ 
   if(left > right)
    return; 
   int pivot = arr[left]; 
   int i = left;
   int j = right;

while(i <= j)
{
 while( arr[i] <= pivot)
   {
       ++i; 
   }
   while (arr[j] > pivot)
   {
       --j;
   }
   if(i < j)
   {
       swap(arr[i],arr[j]); 
   }
}

swap(arr[left],arr[j]); 
  
  quick_sort(arr,left,j - 1); 
  quick_sort(arr,j + 1,right); 


     
  }

  



int main()
{

int arr[] = {10,7,15,21,9,8,12 }; 

//int arr[] = {7,8,9,10,12,15,21}; 
::print(arr); 


quick_sort(arr); 

::print(arr); 

    return 0; 
}