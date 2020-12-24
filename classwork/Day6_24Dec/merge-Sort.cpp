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

void insertion_sort(int *arr)
{ 
   
    int count = 1; 
  
  for (int i = 1; i < SIZE  ; ++i) 
  {

      int key = arr[i];

      int j = i - 1; 

      while(key < arr[j] && j >= 0)
      {
          arr[j + 1] = arr[j]; 
          --j; 

      }
     arr[ j + 1] = key; 
    }

     
  }

 void merge(int *arr,int left,int mid,int right)
 {
     int i = left;
     int j = mid + 1;
     int k = 0; 
     int size = right - left + 1; 
     int *temp = new int[size]; 

     while(i <= mid && j <= right)
     {
         if(arr[i] < arr[j])
         {
             temp[k++] = arr[i++];

         } else
         {
             temp[k++] = arr[j ++]; 

         }
         
      while(i <= mid)
        temp[k++] = arr[i ++];

      while(j <= right)
      {
          temp[k ++] = arr[j ++]; 
      }    

     for ( i = left,k = 0; i <= right;++ i,++ k)
     {
       arr[i] = temp[k]; 
     }
      
      
         
     }
     delete [] temp; 

 } 

void merge_sort(int *arr,int left,int right)
{

    if(left < right)
    {
     int mid = (left + right) / 2; 
    merge_sort(arr,left,mid); 
    merge_sort(arr,mid + 1,right); 

    merge(arr,left,mid,right); 
    }
   
}

int main()
{

int arr[] = {10,7,15,21,9,8,12 }; 

//int arr[] = {7,8,9,10,12,15,21}; 
::print(arr); 


merge_sort(arr,0,6); 

::print(arr); 

    return 0; 
}