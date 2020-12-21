
# include<iostream>
#include <string>
#include<queue>

using namespace std;


int main(void)
{

priority_queue<int> que; 

que.push(50); 
que.push(10); 

que.push(20);
 que.push(100); 
que.push(30); 
que.push(40); 
que.push(50); 


int element; 

while(!que.empty())
{ 

    element = que.top(); 
    cout<<"Removed element :  "<< element <<endl; 

que.pop(); 

}

return 0; 
   
}

