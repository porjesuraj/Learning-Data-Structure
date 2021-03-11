#include<iostream>
#include<string>
using namespace std;

int main(){


int index = 0 ; 
int size = 5; 

for (int i = 1; i <= size; i++)
{   
    int result = i % size; 

    cout <<"result no "<<i  <<" % 5 = "<< result<<endl; 


}


    return 0 ;
}