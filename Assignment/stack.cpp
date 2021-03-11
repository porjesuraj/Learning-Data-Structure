#include <iostream>

using namespace std;


class stack
{
    private: 
    int top;
     int size; 
    int *arr;

   public: 
    stack(void) : top(-1),size(5)
    {
        this->arr = new int [this->size];

    } 

  stack(int size) : top(-1)
    {
        this->arr = new int [this->size];

    } 

   bool empty()
   {
       return this->top == -1; 
   }

   bool full ()
   {
       return this->top == this->size - 1; 
   }
  
    void push(int element)
    {
        if(this->full())
         throw exception();

         this->arr[++this->top] = element; 
    }

    int peek(void )
    {
        if(this->empty())
        throw exception(); 

        return this->arr[this->top]; 
    }

    void pop(void)
    {
         if(this->empty())
        throw exception(); 
 
        -- this->top; 
    }

    void print_stack()
    {
    for (int i = 0; i <= this->top; i++)
    {
          cout<< arr[i] << " "; 
    }
    cout << endl; 
    

    }

    ~stack()
    {
        if(this->arr != NULL)
        {
            delete[] this->arr;
            this->arr = NULL; 
        }
    }

};


int main()
{

    stack stk(10); 

    stk.push(10); 
    stk.push(20); 
    stk.push(30); 
    stk.push(40);

    stk.print_stack(); 

     cout << stk.peek() << endl; 

    stk.pop();

    stk.print_stack();   

}