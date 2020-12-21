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
		Exception( string message = "" ) throw( ) : message( message )
		{	}
		string getMessage( )const throw( )
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
		int **arr;
	public:
		Queue( void ) throw( bad_alloc ) : rear( -1 ), front( -1 ), size( 5 )
		{
			this->arr = new int*[ size ];
		}
		Queue( int size ) throw( bad_alloc ) : rear( -1 ), front( -1 ), size( 5 )
		{
			this->arr = new int*[ size ];
		}
		bool empty( void )const throw( )
		{
			return this->rear == -1 || this->front > this->rear;
		}
		bool full( void )const throw( )
		{
			return this->rear == this->size - 1 ;
		}
		void enqueue( int element )
		{
			if( this->full( ) )
				throw Exception("Queue is full");
			if( this->rear == -1 )
				this->front = 0;
			this->rear = this->rear + 1;
			this->arr[ this->rear ] = new int( element );
		}
		int peek( void )const throw( Exception )
		{
			if( this->empty( ) )
				throw Exception("Queue is empty");
			return *this->arr[ this->front ];
		}
		void dequeue( void )
		{
			if( this->empty( ) )
				throw Exception("Queue is empty");
			delete this->arr[ this->front ];
			this->arr[ this->front ] = NULL;
			this->front = this->front + 1;
		}
		~Queue( void )
		{
			while( ! this->empty())
				this->dequeue();
			delete[] this->arr;
			this->arr = NULL;
		}
	};
}
void accept_record( int &element )
{
	cout<<"Enter element	:	";
	cin>>element;
}
void print_record( int &element )
{
	cout<<"Removed element is	:	"<<element<<endl;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit."<<endl;
	cout<<"1.Enqueue."<<endl;
	cout<<"2.Dequeue."<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	int choice, element;
	using namespace collection;
	Queue que( 5 );
	while( ( choice = ::menu_list( ) ) != 0 )
	{
		try
		{
			switch( choice )
			{
			case 1:
				::accept_record(element);
				que.enqueue(element);
				break;
			case 2:
				element = que.peek();
				::print_record(element);
				que.dequeue();
				break;
			}
		}
		catch( Exception &ex )
		{
			cout<<ex.getMessage()<<endl;
		}
	}
	return 0;
}
