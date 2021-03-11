#include<iostream>

using namespace std;

static int count = 0; 
int fun1(int value)
{
    count ++; 
    if(value < 1)
    return 0; 
  cout<<"count = "<< count << " value = " <<value<<endl;  
    fun1(value - 1); 

  
}


int function1(int value1) {
   if(value1 < 1)
      return 0;
      printf("%d ",value1); 
   function1(value1 - 1);
     
}
int function2(int value2) {
   function1(value2);
}
int main(void)
{
fun1(10); 

function2(5); 
}