#include<iostream>


using namespace std;

namespace collection{

class LinkedList; 
class Node{
private: 
int data;
Node* next;

public: 
Node(int data): data(data),next(NULL)
{ }

friend class LinkedList; 

};

class LinkedList{
private: 
Node *head; 

Node *tail; 

public : 
LinkedList(void) : head(NULL),tail(NULL)
{ }

 bool empty(void) const 
{
    return this->head == NULL; 
}

void add_first(int data) throw(bad_alloc)
{
     
     Node *newNode = new Node(data); 
     if(this->empty())
     {
       
         this->tail = newNode; 
        
     }else 
     {
        newNode->next = this->head;  

     }
         this->head = newNode;
}

void add_last(int data) throw(bad_alloc)
{
     Node *newNode = new Node(data); 
     if(this->empty())
     {
        this->head = newNode;
       
        
     }else 
     {
       this->tail->next = newNode;
      

     }
        
  this->tail = newNode; 
}
 
 void add_at_position(int data,int position) throw(bad_alloc)
 {
     Node *newNode = new Node(data); 

     if(position <= 0)
     {
         throw exception(); 
     }
     else if(position == 1)
     this->add_first(data); 
     else if ( position > this->node_count() )
        this->add_last(data); 
     else
     {
         Node *trav = this->head;
      
      for (int index = 1; index < position - 1; index++)
      {
          trav = trav->next; 
      }
      
         newNode->next = trav->next; 

         trav->next = newNode; 

     }
        

 }


 void remove_first() 
{
     
   
     if(this->empty())
     {

         throw exception(); 
        
     }else if(this->head == this->tail)
     {
         delete this->head; 
        this->head = this->tail = NULL;

     }else
     {
         Node *ptrNode = this->head; 

         this->head = this->head->next;

         delete ptrNode; 

         ptrNode = NULL; 
     }
     
         
}

void remove_last() 
{
     
     if(this->empty())
     {
      
         throw exception(); 
     }else if(this->head == this->tail)
     {
       delete this->tail ;
       this->head = this->tail = NULL; 

     } else
     {
         Node *trav = this->head; 

         while(trav->next != this->tail)
         {

             trav = trav->next; 
         }

       
           delete this->tail; 
         this->tail = trav; 
         this->tail->next = NULL; 
     }
     
        
   
}

void remove_from_position(int position) 
{
       if(position <= 0)
       throw exception(); 
       else if(position == 1)
       this->remove_first();
       else if(position >= this->node_count())
       this->remove_last(); 
       else
       {
           Node *trav = this->head;
           
           for (int index = 1; index < position - 1; index++)
           {
               trav = trav->next; 

               
           }

           Node *ptrNode = trav->next;

           trav->next = trav->next->next; 

           delete ptrNode; 
           
       }
       

}

void print_list()
{
    if(this->empty())
    throw exception(); 
    else
    {
        Node *trav = this->head; 

        while(trav != NULL)
        {

            cout <<trav->data <<" " ; 

            trav = trav->next; 

        }

        cout<<endl; 
    }
    
}

 int node_count() const{

    int count = 0; 
  Node *trav = this->head; 
    while(trav != NULL)
    {
        ++ count;
        trav = trav->next;  
    }
    return count; 

 }

~LinkedList(void)
{
    if(!this->empty())
      this->remove_first(); 
} 

}; 


}

int main()
{
    using namespace collection; 

    LinkedList list; 

    list.add_first(10); 

    list.add_first(20); 

    list.add_first(30);

    list.add_first(40);

    list.add_first(50);


    list.print_list(); 


list.remove_last(); 
list.print_list();
list.remove_from_position(2); 
list.print_list();
list.remove_first(); 
list.print_list();
}