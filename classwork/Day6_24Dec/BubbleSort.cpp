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

void bubble_sort(int *arr)
{ 
    bool flag = true; 

    int count = 1; 
  // puter : no of passes // innder comparison 
  for (int i = 0; i < SIZE - 1 && flag == true ; ++i) // no of passes
  {
      flag = false; 
     for(int j = 0; j < SIZE - 1 - i ; ++j)
     {
         if(arr[j] > arr[j + 1])
         {
             flag = true; 
             swap(arr[j],arr[j+ 1]); 
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


bubble_sort(arr); 

::print(arr); 

    return 0; 
}