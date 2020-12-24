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

void selection_sort(int *arr)
{ 
    //bool flag = true; 

    int count = 1; 
  
  for (int i = 0; i < SIZE - 1 ; ++i) // no of passes
  {
      //flag = false; 
     for(int j = i + 1; j < SIZE  ; ++j)
     {
         if(arr[i] > arr[j ])
         {
           
             swap(arr[i],arr[j]); 
         }


      ++ count; 
     }

     
  }

  cout <<"Count " <<count <<endl; 
  

}


int main()
{

//int arr[] = {10,7,15,21,9,8,12 }; 

int arr[] = {7,8,9,10,12,15,21}; 
::print(arr); 


selection_sort(arr); 

::print(arr); 

    return 0; 
}