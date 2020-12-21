
# include<iostream>
#include <queue>


using namespace std;


int main(void)
{

queue<int> que;
que.push(10); 
que.push(20);
que.push(30);
que.push(40);
que.push(50);
que.pop(); 
que.pop(); 

que.push(60); 
que.push(70);
int element = 0; 

while(!que.empty())
{
    element = que.front(); 
    cout<<"Removed element : " <<element <<endl; 
    que.pop(); 
}

return 0; 
   
}

