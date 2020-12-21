#include<iostream> 
#include<stack> 

using namespace std;


int main(void)
{
    stack<int> stk; 

    stk.push(10);
     stk.push(20);
      stk.push(30);

 int element; 

 while(!stk.empty())
 {
     element = stk.top(); 
      cout <<"Popped element  : " << element<<endl; 
      stk.pop(); 
      
 }

    return 0; 
}