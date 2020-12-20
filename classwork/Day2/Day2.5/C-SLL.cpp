# include <iostream> 
# include<string>
using namespace std;

namespace collection
{
class Exception
{

 private: 
    string message; 
public: 
    Exception(string message = "") : message(message)
    { }
    

    string what(void) const throw()
    {
        return this->message;
    }

}; 

class LinkedList; 

class Node{

private: 
 int data;
 Node *next; 
public: 


 Node (int data = 0) : data(data), next(NULL)
 {}

 friend class LinkedList; 

};

class LinkedList{

private: 
Node *head;
Node *tail; 

public: 
 LinkedList(void) throw() :head(NULL), tail(NULL) 
 { }

bool empty(void) const throw()
{
    return this->head == NULL;   
}

void addFirst(int data) throw(bad_alloc)
{
    // add data to LL , using node, by creating a node object 
    Node *newNode = new Node(data); 
   
    if(this->empty())
     {
     this->tail = newNode; 
     

        // for liner
        // this->tail = newNode; 
        //  this->head = newNode; 
         
     } else
      { newNode->next = this->head; 
        //for linear
        //newNode->next = this->head; 
       // this->head = newNode; 
      }
       this->head = newNode;      
         this->tail->next = this->head; 
    // for linear
     // this->head = newNode; 
}
void addLast(int data) throw(bad_alloc)
{
  
    Node *newNode = new Node(data); 
   
    if(this->empty())
    {
        this->head = newNode; 
       // for linear

        // this->tail = newNode; 
       //  this->head = newNode;  
    }
    else{
        this->tail->next = newNode;      
        // for linear
       //  this->tail->next = newNode;
     // use tail pointer to add node at last and upate tail
    }
    this->tail = newNode; 
       this->tail->next = this->head; 
    // for linear
    // this->tail = newNode; 
}

void addAtPosition(int position,int data) throw(bad_alloc)
{                        
   
  if(position <= 0 )
  {
    throw Exception("Invalid Position"); 
  }else if(position == 1)
  this->addFirst(data); 
  else if(position > this->nodeCount())
  this->addLast(data); 
  else{

      Node *trav = this->head; 

      for(int count = 1; count < position - 1; ++ count)
      { 
          trav = trav->next;         
      }

      Node *newNode = new Node(data); 
      
      newNode->next = trav->next; 
      trav->next = newNode; 

  }

                 
                                 
}      

void removeFirst(void) throw(Exception )
{
    if(this->empty())
    {
        throw Exception("LinkedList is empty"); 
    }else if(this->head == this->tail)
    { 
            delete this->head; 
            this->head = this->tail = this->tail->next = NULL; 

       // for linear 
        //delete this->head; 
        //this->head = this->tail = NULL; 
    }else
    {
      Node *ptrNode = this->head; 
      this->head = this->head->next; 
      delete ptrNode;
      this->tail->next = this->head;  
     

// for linear
       // Node *ptrNode = this->head; 
       // this->head = this->head->next; 
       // delete ptrNode; 
      // notrequired as pointer has local spoce, no need for null
      // ptrNode = NULL;
        
    }
    
 
}

void removeLast() throw(Exception )
{
 
     if(this->empty())
    {
        throw Exception("LinkedList is empty"); 
    }else if(this->head == this->tail)
    { 
          delete this->head; 
         this->head = this->tail = this->tail->next =  NULL; 
       
        
    }else
    {
       Node *trav = this->head; 

       while(trav->next != this->tail)
       {
           trav = trav->next; 
       }
        delete this->tail; 
        this->tail = trav; 
        this->tail->next = this->head; 
    }
}

void removeFromPosition(int position) throw(Exception) 
{
    if(position < 0 )
    {
        throw Exception("Invalid address "); 
    }else if(position == 1)
    this->removeFirst();
    else if(position >= this->nodeCount())
    this->removeLast(); 
    else
    {
        Node *trav = this->head; 
        for(int count = 1; count < position - 1;++ count)
        {
              trav = trav->next; 
        }
         Node *ptrNode = trav->next; 

        trav->next = ptrNode->next; 
        delete ptrNode; 
        
    }
    

}


void printList(void){


    if(this->empty())
    throw Exception("LinkedList is empty"); 
    else{

        Node *trav = this->head;

       do
       {  
            cout<<trav->data <<" " ; 
          trav = trav->next;  
       } while (trav != this->head);

       cout<<endl; 
       
    }
}

int nodeCount() const throw() 
{
  int count = 0;
  if(!this->empty())
  {
     Node *trav = this->head; 
     do
     {
         ++ count; 
         trav = trav->next; 
     } while (trav != this->head);
  }

 return count; 
}

~LinkedList(void)
{
    while(!this->empty())
    {
        this->removeFirst();
    }
}
        
  };
}

int main1(void)
{
   // Node newNode; 
   // Node newNode(10); 
   int data = 10; 
   //Node *newNode = new Node(data); 

  // delete newNode;
    return 0; 
}


int menu_list(void){
   int choice; 
    cout<<"0. Exit"<<endl;
    
    cout<<"1. Add First"<<endl;
    cout<<"2. Add last"<<endl;
    cout<<"3. Add to position"<<endl;
    cout<<"4. Remove First"<<endl;
    cout<<"5. Remove Last"<<endl;
    cout<<"6. remove from position"<<endl;
    cout<<"7. Print List"<<endl;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    return choice;
}

void accept_record(string message,int& data)
{
    cout<<message; 
    cin>>data; 

}

int main(void)
{
   
   int choice,data,position; 
  using namespace collection; 
  LinkedList list; 
  
   while ( (choice = ::menu_list()) != 0)
   {

       try{

       
       switch (choice)
       {
       case 1:  // Add first
        accept_record("Enter data: ", data ); 
          list.addFirst(data); 
           break;
       case 2: // add last
       accept_record("Enter data",data); 
       list.addLast(data); 

       break; 
       case 3: // add at position
         accept_record("Enter position",position);
          accept_record("Enter data",data);  
           list.addAtPosition(position,data); 
       break; 
       case 4: // remove first 
         list.removeFirst(); 
       break; 

       case 5: // removeLast
       list.removeLast();  

       break;
        case 6: // remove from position
         accept_record("Enter Postion",position); 

         list.removeFromPosition(position); 
       break; 

       case 7: //print list
          list.printList(); 
       break;
       default:
           break;
       }
       } catch(Exception& ex)
       {
         cout<<ex.what() <<endl; 
       } 
       catch(bad_alloc &ex )
       {
           cout<<ex.what()<<endl; 
       }
   }

    return 0; 
}


