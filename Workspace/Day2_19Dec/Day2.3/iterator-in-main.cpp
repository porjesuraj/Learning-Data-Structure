#include<iostream>
#include<string>
using namespace std;

namespace collection
{
	class Exception
	{
	private:
		string message;
	public:
		Exception( string message = " " ) throw( ) : message( message )
		{	}
		string getMessage( void )const throw( )
		{
			return this->message;
		}
	};
	class Iterator;		//Forward declration
	class LinkedList;	//Forward declration
	class Node
	{
	private:
		int data;
		Node *next;
	public:
		Node( int data = 0 ) throw( ) : data( data ), next( NULL )
		{	}
		friend class Iterator;
		friend class LinkedList;
	};
	
   class Iterator{
   
   private: 
    Node *trav; 

  	public: 
	  Iterator(Node *trav)
	  { 
		  this->trav = trav; 
          
	  }   

	  bool operator!=(Iterator &other)
	  {
		return  this->trav != other.trav; 
	  }

	  void operator++(void)
	  {
		  this->trav = this->trav->next; 
	  }

	  int operator*(void)
	  {
		  return this->trav->data; 
	  }

   };

	class LinkedList
	{
	private:
		Node *head;
		Node *tail;
	public:
		LinkedList( void )throw( ) : head( NULL ), tail( NULL )
		{	}
		bool empty( void )const throw( )
		{
			return this->head == NULL;
		}
		void addLast( int data )throw( bad_alloc )
		{
			Node *newNode  = new Node( data );
			if( this->empty( ) )
				this->head = newNode;
			else
				this->tail->next = newNode;
			this->tail = newNode;
		}
		void removeFirst( void )throw( Exception )
		{
			if( this->empty( ) )
				throw Exception( "LinkedList is empty" );
			else if( this->head == this->tail )
			{
				delete this->head;
				this->head = this->tail = NULL;
			}
			else
			{
				Node *ptrNode = this->head;
				//this->head = ptrNode->next;	//or
				this->head = this->head->next;
				delete ptrNode;
			}
		}

		Iterator begin(void)
		{
            Iterator itr(this->head);

			return itr;  
		}
		Iterator end(void)
		{
			Iterator itr(NULL);

           return itr; 
		}
		
	};
}
int main( void )
{
    // iterate list in non member function 
  using namespace collection; 
  LinkedList list; 
  list.addLast(10); 
  list.addLast(20);
  list.addLast(30);  
    
 Iterator itrStart	= list.begin();
	Iterator itrEnd = list.end();

	while(itrStart != itrEnd) // itrStart.operator!= (itrEnd) 
	{
        cout<< ( *itrStart ) <<endl; // itrStart.operator*() 
		++ itrStart; //itrStart.operator++()
	} 

	cout<<endl; 
	return 0;
}
