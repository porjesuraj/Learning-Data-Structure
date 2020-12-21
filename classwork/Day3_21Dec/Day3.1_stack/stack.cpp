# include<iostream>
#include <string>

using namespace std;

namespace collection
{

    class Exception 
    {

        private : 
        string message; 

        public: 

        Exception(string messages) : message(messages)
        {}

         string what(void) const throw()
    {
        return this->message;
    }
    }; 

    # define size 5
   
   class Stack
    {

        private : 
        int top;
        int arr[size]; 

      public: 

      Stack (void) :top(-1)
      {}

      bool empty(void) const throw()
      {
          return this->top == -1; 
      }
        
        bool full (void) const throw()
        {
            return this->top == size - 1; 
        }

      void push(int element)throw(Exception)
      {
          if(this->full()) 
          throw Exception("Stack is full"); 

        //  this->top = this->top + 1; 
          // this-> arr[this->top] = element;
         this-> arr[++this->top] = element;
          
      }

      int peek(void) const throw(Exception)
      {
          if(this->empty())
           throw Exception("Stack empty");
          
          return this->arr[this->top]; 
      }

      void pop(void)  throw(Exception)
      {
           if(this->empty())
           throw Exception("Stack empty");
          else
          -- this->top;
        
      }
 
   };


}

void accept_record(int &element)
{
    cout <<"Enter element"; 
    cin>>element; 

}

void print_record(const int &element)
{
   cout<< "popped element is :" <<element <<endl; 
}

int menu_list(void){
   int choice; 
    cout<<"0. Exit"<<endl;
    
    cout<<"1. push"<<endl;
    cout<<"2. peek and pop"<<endl;
    cout<<"3. pop"<<endl;
    cout<<"4. print"<<endl;
  
    cout<<"Enter choice"<<endl;
    cin>>choice;
    return choice;
}


int main(void)
{

    int choice,element ; 
   using namespace collection; 

   Stack stk; 


try{

 while ((choice = ::menu_list()) != 0)
    { 
        switch (choice)
        {
        case 1:

              accept_record( element);
                stk.push(element); 
            break;
             case 2:
              element =  stk.peek(); 
            ::print_record(element); 
             stk.pop(); 
            break;
             case 3:
              stk.pop(); 
            break;
            
        }

    }
} catch(Exception &ex)
{
   cout<<ex.what() <<endl;
}

   
}

