#include<iostream>
#include<string>
using namespace std; 
namespace collection
{

class Exception
{
  private: 
   string message;
  public : 
  Exception(string message) throw() : message(message)
  { }
  
  string getMessage(void) const throw()
  {
      return this->message;
  }

}; 

class BSTree; 
class Node 
{
  private: 
  Node *left; 
  int data; 
  Node *right;
  public : 
   Node (int data = 0): data(data), left(NULL),right(NULL)
   { }
  
  friend class BSTree; 
};

class BSTree
{ 
    private: 
    Node* root; 
    public: 

    BSTree(void) throw() : root(NULL)
    { }
    
    bool empty(void) const throw()
    {
        return this->root == NULL; 
         
    }

    void addNode(int data)
    {
        Node *newNode = new Node(data);

        if(this->empty())
        this->root = newNode; 
        else 
        {
            Node *trav = this->root; 
            while(true)
            { 
                if(data < trav->data )
                {  
                    if(trav->left == NULL )
                    {
                     trav->left = newNode; 
                      break; 
                    }
                   trav = trav->left; 
                } else
                {
                    if(trav->right == NULL)
                    {
                        trav->right = newNode;
                        break; 
                    }
                    trav = trav->right; 
                }
                
               

            } 

        }
    }

    void preOrder(void)
    {
        this->preOrder(this->root); 
    }
    void InOrder(void)
    {
        this->InOrder(this->root); 
    }
     void postOrder(void)
    {
        this->postOrder(this->root); 
    }

     ~BSTree(void)
    {
        this->clear(this->root);
        this->root = NULL; 
    }

    private: 
    void preOrder(Node *trav)
    {
          if(trav  == NULL )
          return; 
        cout<<trav->data <<" "; 
        this->preOrder(trav->left); 
        this->preOrder(trav->right);  
    }

    void InOrder(Node *trav)
    {
          if(trav  == NULL )
          return; 
        
        this->InOrder(trav->left); 
         cout<<trav->data <<" ";
        this->InOrder(trav->right);  
    }
     void postOrder(Node *trav)
    {
          if(trav  == NULL )
          return; 
     
        this->postOrder(trav->left); 
        this->postOrder(trav->right);  
           cout<<trav->data <<" "; 
    }

   
  
     void clear(Node *trav)
    {
          if(trav  == NULL )
          return; 
     
        this->clear(trav->left); 
        this->clear(trav->right);  
         
           delete trav;  
    }

   

};



}

int main(void)
{
  
 using namespace collection; 
 BSTree tree; 
  tree.addNode(70);
    tree.addNode(50);
    tree.addNode(40);
    tree.addNode(60);
    tree.addNode(55);
    tree.addNode(90);
    tree.addNode(80);
    tree.addNode(100);
cout<<" Pre order" <<endl; 
    tree.preOrder( );
     cout<<endl; 
    cout<< " in order"<<endl; 
    tree.InOrder( );
     cout<<endl;
    cout << "post order"<<endl; 
    tree.postOrder();
     cout<<endl;
    return 0; 
}