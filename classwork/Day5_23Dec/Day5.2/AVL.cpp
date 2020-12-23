#include<iostream>
#include<string>
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
			balance(this->root, NULL);
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
		int height( void )
		{
			return BSTree::height( this->root );
		}
		~BSTree( void )
		{
			this->clear( this->root );
			this->root = NULL;
		}
	private:
		static int height( Node *trav )
		{
			if( trav == NULL )
				return -1;
			int leftHeight = height( trav->left );
			int rightHeight = height( trav->right );
			if( leftHeight > rightHeight )
				return leftHeight + 1;
			return rightHeight + 1;
		}
		static int balanceFactor( Node *node )
		{
			return BSTree::height( node->left ) - BSTree::height( node->right );
		}
		Node* llCase( Node *node, Node *parent )
		{
			Node *leftSubTree = node->left;
			node->left = leftSubTree->right;
			leftSubTree->right = node;
			if( node == this->root )
				this->root = leftSubTree;
			else if( node == parent->left)
				parent->left  = leftSubTree;
			else
				parent->right = leftSubTree;
			return leftSubTree;
		}
		Node* rrCase( Node *node, Node *parent)
		{
			Node *rightSubTree = node->right;
			node->right = rightSubTree->left;
			rightSubTree->left = node;
			if( node == this->root )
				this->root = rightSubTree;
			else if( node == parent->left)
				parent->left  = rightSubTree;
			else
				parent->right = rightSubTree;
			return rightSubTree;
		}
		Node* lrCase( Node *node, Node *parent )
		{
			node->left = rrCase(node->left, node);
			node = llCase(node, parent);
			return node;
		}
		Node* rlCase( Node *node, Node *parent )
		{
			node->right = llCase(node->right, node);
			node = rrCase(node, parent);
			return  node;
		}
		void balance( Node *node, Node *parent )
		{
			if( node == NULL )
				return;
			balance(node->left, node);
			balance(node->right, node);

			int balanceFactor =  BSTree::balanceFactor(node);
			if( balanceFactor > 1 )	//Consider Left SubTree
			{
				if( BSTree::balanceFactor(node->left ) > 0 )
					llCase( node, parent );
				else
					lrCase( node, parent );
			}
			else if( balanceFactor < -1 )	//Consider RightSubTree
			{
				if( BSTree::balanceFactor(node->right ) > 0 )
					rlCase( node, parent );
				else
					rrCase( node, parent );
			}
		}
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
	tree.addNode( 21 );
	tree.addNode( 26 );
	tree.addNode( 30 );
	tree.addNode( 9 );
	tree.addNode( 4 );
	tree.addNode( 14 );
	tree.addNode( 28 );
	tree.addNode( 18 );
	tree.addNode( 15 );
	tree.addNode( 10 );
	tree.addNode( 2 );
	tree.addNode( 3 );
	tree.addNode( 7 );

	//cout<<"Height of Tree	:	"<<tree.height()<<endl;
	tree.levelOrder();
	return 0;
}
