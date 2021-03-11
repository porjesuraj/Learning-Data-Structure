
#include<iostream>

using namespace std; 
class Queue
    {

       int rear;
		int front;
		int size;
		int *arr;
	public:
		Queue( void )  : rear( -1 ), front( -1 ) , size( 5 )
		{
			this->arr = new int[ this->size ];
		}
		Queue( int size )  : rear( -1 ), front( -1 ) , size( size )
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

        void enqueue(int element) 
        {
            if(this-> full())
            throw ; 
            if(this->rear == -1)
            this->front = 0;
            this->rear = this->rear + 1; 
            this->arr[this->rear] = element;  
        }

        int peek() const 
        {
            if(this->empty()) 
             throw ;
            return this->arr[this->front]; 
        }
 
         void dequeue()
         {
            if(this->empty()) 
             throw  ;

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

