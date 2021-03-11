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
		Exception( string message ) throw( ) : message( message )
		{	}
		string getMessage( void )const throw( )
		{
			return this->message;
		}
	};
	class Queue
	{
	private:
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
			return this->rear == -1;
		}
		bool full( void )const throw( )
		{
			return ( this->rear + 1 ) % this->size == this->front;
		}
		void enqueue( int element )throw( Exception )
		{
			if( this->full( ) )
				throw Exception("Queue is full");
			if( this->rear == -1 )
				this->front = 0;
			this->rear = ( this->rear + 1 ) % this->size;
			this->arr[ this->rear ] = element;
		}
		int peek( void )const throw( Exception )
		{
			if( this->empty( ) )
				throw Exception("Queue is empty");
			return this->arr[ this->front ];
		}
		void dequeue( void )
		{
			if( this->empty( ) )
				throw Exception("Queue is empty");
			if( this->rear == this->front )
				this->rear = -1;
			else
				this->front = ( this->front + 1 ) % this->size;
		}
		~Queue( void )
		{
			if( this->arr != NULL )
			{
				delete[] this->arr;
				this->arr = NULL;
			}
		}
	};
}
void accept_record( int &element )
{
	cout<<"Enter element	:	";
	cin>>element;
}
void print_record( const int &element )
{
	cout<<"Popped element is	:	"<<element<<endl;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Enqueue"<<endl;
	cout<<"2.Dequeue"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	int choice, element;
	using namespace collection;
	Queue que;
	while( ( choice = ::menu_list( ) ) != 0 )
	{
		try
		{
			switch( choice )
			{
			case 1:
				::accept_record(element);
				que.enqueue( element );
				break;
			case 2:
				element = que.peek( );
				::print_record(element);
				que.dequeue( );
				break;
			}
		}
		catch( Exception &ex )
		{
			cout<<ex.getMessage( )<<endl;
		}
	}
	return 0;
}
