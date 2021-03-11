
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

  
   
   class Queue
    {

       int rear;
		int front;
		int size;
		int *arr;
	public:
		Queue( void ) throw( bad_alloc ) : rear( -1 ), front( -1 ) , size( 5 )
		{
			this->arr = new int[ this->size ];
		}
		Queue( int size ) throw( bad_alloc ) : rear( -1 ), front( -1 ) , size( size )
		{
			this->arr = new int[ this->size ];
		}
		bool empty( void )const throw( )
		{
			return this->rear == -1 || this->front > this->rear;
		}
		bool full( void )const throw( )
		{
			return this->rear == size - 1;
		}

        void enqueue(int element) throw(Exception)
        {
            if(this-> full())
            throw Exception("QUeue is full"); 
            if(this->rear == -1)
            this->front = 0;
            this->rear = this->rear + 1; 
            this->arr[this->rear] = element;  
        }

        int peek() const throw(Exception)
        {
            if(this->empty()) 
             throw Exception("Queue is empty") ;
            return this->arr[this->front]; 
        }
 
         void dequeue()
         {
            if(this->empty()) 
             throw Exception("Queue is empty") ;

             this->front = this->front + 1; 

         }
        ~Queue(void)
        {
            if(this->arr != NULL)
            {
                delete[] this->arr;
                this->arr = NULL; 
            }
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
    
    cout<<"1. Enqueue"<<endl;
    cout<<"2. dequeue "<<endl;
   
  
    cout<<"Enter choice"<<endl;
    cin>>choice;
    return choice;
}


int main(void)
{

    int choice,element ; 
   using namespace collection; 
  
  Queue  que; 


try{

 while ((choice = ::menu_list()) != 0)
    { 
        switch (choice)
        {
           case 1:
              accept_record( element);
                que.enqueue(element); 
            break;
             case 2:
              element =  que.peek(); 
            ::print_record(element);
            que.dequeue();  
            break;
             case 3:
              que.dequeue(); 
            break;
             
        }

    }
} catch(Exception &ex)
{
    cout<<ex.what()<<endl; 

}

return 0; 
   
}

