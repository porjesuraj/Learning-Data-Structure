#include<iostream>

using namespace std;

int factorial(int num)
{
    if(num <= 0)
    return 1; 
    else
    {
        return num * factorial(num - 1); 
    }
    


}

int sum (int *arr,int n )
{
   int sum = 0; 

  for (int i = 0; i < n; i++)
  { 
      sum += arr[i]; 
         
  }
  
  return sum; 


}

int main(void)
{

int num = factorial(5);

cout<<num <<endl; 

int arr[] = {1,2,3,4,5}; 
int n = 5; 
int sumresult = sum(arr,n); 

cout<< sumresult <<endl; 
    return 0; 
}