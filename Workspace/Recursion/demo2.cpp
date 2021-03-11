#include<iostream>
using namespace std;


int sum(int arr[])
{
  int i = 8, result = 0; 
  while(i >= 0)
  {
      result =  i ;  
      i--; 
  }
 
 return result; 

}

int main(void)
{

 int arr[] = {2,3,4,5,6,7,8,9}; 


 int result = sum(arr);

 cout<<result<<endl;  
}