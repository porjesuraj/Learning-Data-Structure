#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
namespace collection
{
	class Exception
	{
	private:
		string message;
	public:
		Exception( string messgae ) throw( ) : message( messgae )
		{	}
		string getMessage( void )const throw( )
		{
			return this->message;
		}
	};
	class BSTree;	//Forward declaration
	class Node
	{
	private:
		Node *left;
		int data;
		Node *right;
	public:
		Node( int data  = 0 ) : left( NULL ) ,data( data ), right( NULL )
		{	}
		friend class BSTree;
	};
	class BSTree
	{
	private:
		Node *root;
	public:
		BSTree( void ) throw( ) : root( NULL )
		{	}
		bool empty( void )const throw( )
		{
			return this->root == NULL;
		}
		void addNode( int data )
		{
			Node *newNode = new Node( data );
			if( this->empty( ) )
				this->root = newNode;
			else
			{
				Node *trav = this->root;
				while( true )
				{
					if( data < trav->data )
					{
						if( trav->left == NULL )
						{
							trav->left = newNode;
							break;
						}
						trav = trav->left;
					}
					else
					{
						if( trav->right == NULL )
						{
							trav->right = newNode;
							break;
						}
						trav = trav->right;
					}
				}
			}
		}
		Node* search( int data, Node *&parent )throw( )
		{
			Node *trav = this->root;
			parent = NULL;
			while( trav != NULL )
			{
				if( data == trav->data )
					return trav;
				parent = trav;
				if( data < trav->data )
					trav = trav->left;
				else
					trav = trav->right;
			}
			parent = NULL;
			return NULL;
		}
		void deleteNode( int data )throw( Exception )
		{
			Node *parent;
			Node *target = this->search( data, parent );
			if( target != NULL )
			{
				if( target->left != NULL && target->right != NULL )
				{
					parent = target;
					Node *successor = target->right;
					while( successor->left != NULL )
					{
						parent = successor;
						successor = successor->left;
					}
					target->data = successor->data;
					target = successor;
				}
				if( target->left == NULL )
				{
					if( target == this->root )
						this->root = target->right;
					else if( target == parent->left )
						parent->left = target->right;
					else
						parent->right = target->right;
				}
				else
				{
					if( target == this->root )
						this->root = target->left;
					else if( target == parent->left )
						parent->left = target->left;
					else
						parent->right = target->left;
				}
				delete target;
			}
			else
				throw Exception("Node not found");
		}



		void nonRecursivePreorder( void )
		{
			stack<Node*> stk;
			stk.push( this->root );
			while( !stk.empty( ) )
			{
				Node *trav = stk.top();	stk.pop( );
				if( trav != NULL )
					cout<<trav->data<<"	";
				if( trav->right != NULL )
					stk.push(trav->right );
				if( trav->left != NULL )
					stk.push( trav->left );
			}
			cout<<endl;
		}
		void nonRecursiveInorder( void )
		{
			stack<Node*> stk;
			Node *trav = this->root;
			while( trav != NULL || !stk.empty( ) )
			{
				while( trav != NULL )
				{
					stk.push( trav );
					trav = trav->left;
				}
				trav = stk.top();	stk.pop();
				if( trav != NULL )
					cout<<trav->data<<"	";
				trav = trav->right;
			}
			cout<<endl;
		}
		void nonRecursivePostOrder( void )
		{
			stack<Node*> stk;
			Node *trav = this->root;
			do
			{
				while( trav != NULL )
				{
					if( trav->right != NULL )
						stk.push(trav->right);
					stk.push(trav);
					trav = trav->left;
				}
				trav = stk.top(); stk.pop();
				if( trav != NULL && !stk.empty( ) && trav->right == stk.top( ) )
				{
					stk.pop( );
					stk.push( trav );
					trav = trav->right;
				}
				else
				{
					cout<<trav->data<<"	";
					trav = NULL;
				}
			}while( !stk.empty( ) );
			cout<<endl;
		}
		
		
		void levelOrder( void )
		{
			queue<Node*> que;
			que.push( this->root );
			while( !que.empty( ) )
			{
				Node *trav = que.front();	que.pop();
				if( trav != NULL )
					cout<<trav->data<<"	";
				if( trav->left != NULL )
					que.push(trav->left);
				if( trav->right != NULL )
					que.push(trav->right );
			}
			cout<<endl;
		}
		void preOrder( void)
		{
			this->preOrder( this->root );
			cout<<endl;
		}
		void inOrder( void)
		{
			this->inOrder( this->root );
			cout<<endl;
		}
		void postOrder( void )
		{
			this->postOrder(this->root );
			cout<<endl;
		}
		~BSTree( void )
		{
			this->clear( this->root );
			this->root = NULL;
		}
	private:
		void preOrder( Node *trav )
		{
			if( trav == NULL )
				return;
			cout<<trav->data<<"	";
			this->preOrder( trav->left );
			this->preOrder( trav->right );
		}
		void inOrder( Node *trav )
		{
			if( trav == NULL )
				return;
			this->inOrder(trav->left);
			cout<<trav->data<<"	";
			this->inOrder(trav->right);
		}
		void postOrder( Node *trav )
		{
			if( trav == NULL )
				return;
			this->postOrder( trav->left );
			this->postOrder( trav->right );
			cout<<trav->data<<"	";
		}
		void clear( Node *trav )
		{
			if( trav == NULL )
				return;
			this->clear( trav->left );
			this->clear( trav->right );
			delete trav;
		}
	};
}
int main( void )
{
	using namespace collection;
	BSTree tree;
	tree.addNode( 150 );
	tree.addNode( 80 );
	tree.addNode( 180 );
	tree.addNode( 50 );
	tree.addNode( 135 );
	tree.addNode( 175 );
	tree.addNode( 200 );
	tree.addNode( 30 );
	tree.addNode( 120 );
	tree.addNode( 145 );
	tree.addNode( 100 );
	tree.addNode( 125 );
	tree.addNode( 115 );

	//tree.preOrder( );	//150	80	50	30	135	120	100	115	125	145	180	175	200
	tree.nonRecursivePreorder( );

	tree.inOrder( );	//30	50	80	100	115	120	125	135	145	150	175	180	200
	//tree.nonRecursiveInorder( );

	tree.postOrder( );	//30	50	115	100	125	120	145	135	80	175	200	180	150
	//tree.nonRecursivePostOrder( );

	tree.levelOrder( );
	return 0;
}
