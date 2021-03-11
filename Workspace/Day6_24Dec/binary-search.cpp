#include<iostream>
#include <string>
using namespace std;

class ArrayIndexOutOfBound
{
    private:
    string mesaage; 

    public: 
    ArrayIndexOutOfBound(string message): mesaage(mesaage)
    { }

    string what(string message){

        return mesaage; 
    }
};


class Array
{


    private:
    int size;
    int *arr;

    public:
    Array(void)
    {
        this->size = 0;  
        this->arr = NULL; 
    }

    Array(int size) throw(bad_alloc): size(size), arr(new int[this->size])
    { 

    }

    int find(int key)
    {
        for (int index = 0; index < this->size; index++)
        {
           if(arr[index] == key)
           return index;
        }
        return -1; 
        
    }
 int findByRecursion(int key)
    {
        for (int index = 0; index < this->size; index++)
        {
           if(arr[index] == key)
           return index;
        }
        return -1; 
        
    }

    int binarySearch(int key)
    {
        int left = 0;
        int right = this->size - 1; 

while(left <=right)
   {
        int mid = (left + right) / 2 ; 

        if(key == arr[mid])
        {
            return mid; 
        }else if( key <arr[mid])
        {
            right = mid - 1; 
        }else
        {
            left = mid + 1; 
        }

   }    
       return -1;  
    }

    int operator[](int index) throw(ArrayIndexOutOfBound)
    {
        if(index >= 0 && index < this->size)
        {
            return this->arr[index]; 
        }
        throw ArrayIndexOutOfBound("array index out of bound ");
    }


    ~Array(void)
    {
        if(this->arr != NULL)
        {
            delete[] this->arr;
            this->arr = NULL; 
        }
    }
 
    friend istream& operator>>(istream &cin,Array &other)
{
    for (int index = 0; index < other.size; ++index)
    {
        cout <<"arr ["<<index << "] :  " ; 
        cin>>other.arr[index]; 
    }
    
    return cin; 
}

friend ostream& operator<<(ostream &cout,Array &other)
{

    for (int index = 0; index < other.size; ++index)
    {
        cout <<"arr ["<<index << "] :  "<<other.arr[index] <<endl; 
       cout<<endl; 
    }
    return cout; 
}
}; 



int main(void)
{

    Array a1(5); 
      
    cin>> a1; 
    //operator>>(cin,a1)
     cout<<endl; 
     cout<<a1; // operator<<()


int key = 50; 

int index = a1.binarySearch(key); 

if(index != -1)
{
    cout <<"Key found at index :  "<<index<<endl; 
}else
{
    cout<<"Key not found"<<endl; 
}


    return 0; 
}
