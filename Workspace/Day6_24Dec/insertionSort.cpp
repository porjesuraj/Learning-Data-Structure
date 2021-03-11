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

  



int main()
{

int arr[] = {10,7,15,21,9,8,12 }; 

//int arr[] = {7,8,9,10,12,15,21}; 
::print(arr); 


insertion_sort(arr); 

::print(arr); 

    return 0; 
}