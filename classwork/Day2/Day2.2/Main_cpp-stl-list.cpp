#include<iostream>
#include<list>

using namespace std;

int main(void) 
{
    list<int> intList; 

    intList.push_front(10); 
    intList.push_back(20); 
    intList.push_back(30); 
    intList.push_back(40); 
     intList.push_back(50); 
    intList.push_back(60);
intList.pop_back();
    intList.pop_front(); 


    for(int element : intList)
    cout<<element<<"  "; 
    return 0; 
}


int main1(void) 
{
    list<int> intList; 

    intList.push_front(10); 
    intList.push_back(20); 
    intList.push_back(30); 
    intList.push_back(40); 
     intList.push_back(50); 
    intList.push_back(60);

    

    list<int>::iterator itrStart = intList.begin();  
    list<int>::iterator itrEnd = intList.end(); 
    while(itrStart != itrEnd)
    {
      cout << (*itrStart) <<" "; 
      ++ itrStart; 

    }
    return 0; 
}