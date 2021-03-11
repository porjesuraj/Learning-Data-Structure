#include<iostream>
#include<string>
using namespace std;
namespace collection
{
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
	void clear( Node *trav )
		{
			if( trav == NULL )
				return;
			this->clear( trav->left );
			this->clear( trav->right );
			delete trav;
		}
    	~BSTree( void )
		{
			this->clear( this->root );
			this->root = NULL;
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

        	void preOrder( void)
		{
			this->preOrder( this->root );
		}
		void inOrder( void)
		{
			this->inOrder( this->root );
		}
		void postOrder( void )
		{
			this->postOrder(this->root );
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

         Node* searchNode(int data,Node *&parent)
    {
        Node * trav = this->root;
        parent = NULL; 
        while(trav != NULL)
        {
            if(data == trav->data)
            return trav; 
           parent = trav; 
            if(data < trav->data)
            trav = trav->left; 
            else
            {
                trav->right; 
            }
            
        }

        parent = NULL;
        return NULL; 
    }

  void deleteNode(int data)
    {
        Node *parent; 
       Node* target =  this->searchNode(data, parent) ;
        
      if(target->left != NULL && target->right != NULL  )
      {
          parent = target; 
          Node * successor = target->right;

          while(successor->left != NULL)
          {
              parent = successor; 
              successor = successor->left;
               
          }
          target->data = successor->data;
          target = successor;  


        
      }



        if(target != NULL)
        {
            if(target->left == NULL)
            {
                if(target == this->root)
                { 
                    this->root = target->right; 

                } else if(target == parent->left)
                {
                    parent->left = target->right; 


                } else
                {
                    parent->right = target->right; 
                }
                
            } else
            {
                if(target == this->root)
                { 
                   this->root = target->left; 

                } else if(target == parent->left)
                {
                  parent->left = target->left; 


                } else
                {
                    parent->right = target->left; 
                }

            }
            

        }
      delete target; 
    }
}       