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
/* Node (void){
     this->data = 0;
     this->next = NULL; 
 }

 Node (int data){
     this->data = data;
     this->next = NULL; 
 }*/

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

void addFirst(int data)
{
    // add data to LL , using node, by creating a node object 
    Node *newNode = new Node(data); 
    // NULL in next by default : is value of next 
    // in Linked list, two element : head and tails (with value Null)
    // i.e LINKED LIST EMPTY
    if(this->empty())
    {
         this->tail = newNode; 
        //  this->head = newNode; 
         
    }else
    { 
        newNode->next = this->head; 
       // this->head = newNode; 
    }
     this->head = newNode; 
}
void addLast(int data)
{
    // add data to LL , using node, by creating a node object 
    Node *newNode = new Node(data); 
    // NULL in next by default : is value of next 
    // in Linked list, two element : head and tails (with value Null)
    // i.e LINKED LIST EMPTY
    if(this->empty())
    {
         this->tail = newNode; 
        //  this->head = newNode; 
         
    }else
    { 
     // use tail pointer to add node at last and upate tail
    }
     this->head = newNode; 
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
  
  collection::LinkedList list; 
  
   while ( (choice = ::menu_list()) != 0)
   {
       switch (choice)
       {
       case 1:  // Add first
        accept_record("Enter data: ", data ); 
          
           break;
       case 2: 

       break; 
       default:
           break;
       }
   }

    return 0; 
}


