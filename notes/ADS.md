# ADS syllabus
## Data Structure 
* it is a branch of Computer science in which
+ is used to organize data efficiently in RAM

* Types of data strcuture
1. Linear Data structure
+ 1. Array 
   * Single 
   * Multi 
+ 2. Stack
+ 3. QUeue
+ 4. DeQUe
+ 5. Linear 


2. Non Linear Data Structure

## ALgorithm
*it is branch og computer science, which is used to process data in data structure
* i.e for data stored in data structure , to perform some operation on it. 
* Classification 
1. Searching A 
  + 1. Linear
  + 2. Binary
  + 2. Hashing

2. Sorting Algorithm
  + 1. Bubble    
  + 2. Selection
  + 3. Insertion 
  + 4. Merge
  + 5. Quick
  + 6. Shell
  + 7. Radix 
  + 8. Heap         



# day1


## to do 
1. menu driven program for vcector function 

## notes

1. Arrays
 + array is a linear data structue, or collection
 + in which we can store element of same type in continous memory location
     +  where value or data stored in data structure is called element   
 + if we want to access elements from array, then we should use integer index
 + Array index always begins with 0. 
* 2. Array BOunds 
 + min index and max index 
 + Min index : 0
 + Max index : SIZE - 1
* in C/C++ , checkign array bounds checking is job of a programmer
* types of Array": 
 1. Single Dimensional Array
 2. Multi Dimensional Array

* Advantages of array: 
 1. random access
 + if we know index of element, then we can access it, very fast

* Limitation of Array: 
 1. we cannot resize array.
 2. it requires continuous memory . 
 3. Compiler do not check array bounds 
 4. element isnertioon and deletion takes more time in a array
 5. using assignment operator, we cannot copy one array into another arra
 +  need memcpy() in c++ or loop to copy one array to another    
 + to overcome, Array, we can use Linked list 

2. Vector

### 3. Linked List : data structure
 + linked list is a linear data strucure,which is collection of elements
   + where each element is called a node
* 1. Node 
  + here node, is a element, which can have 
    + object of node class has 2 part or 3 part,where
    + 2 parts are int data and node* next
    + 3 parts are node* prev, int data ,node* next  
  + where , 
    + data --> data stored for number is of type integer
    + next,prev, --->  contain address of next node object, so type of node is node*   
  + node is a object which may contain either 2 parts /3 parts depending on type of linked list
```c++

Class Node 
{
Node* prev ;
int data; 
Node* next;

}

// OR
Class Node 
{
int data; 
Node* next;

}

```
* 2. Types of linked list
 1. Singly LinkedList(SLL)
  + in a linked  list, if node(element) contains two part
   1. a element(data) 
   2. a pointer which is address of next node object 
   + is callled singly LL 
 2. Doubly Linked List(DLL)
 + in a linked listm if node contains three parts
  1. a pointer which contains address of previous node object(prev)
  2. a element(data)
  3. a pointer which contains address of next node object(next)
  + is called doubly linked list
* 3. Node Object
  1. Head
   + In a LL, head is a pointer, which is designed to store address of first node object
   + if value of head is null, then LL is considered as empty
   ```c++
    bool empty(){
       return head == NULL
    }
   ``` 
   2. Tail
   + In a LL, tail is a pointer which is designed to store address of last node object    
* 4. Singly and DOubly LL are further classified into two types: 
  1. Linear LL 
  2. Circular LL 

!['L-SLL_1.2']()
* 5. Linear Singly Linked List ( L-SLL)
  +  if next pointer of tail node , contains NULL is call singly list
  +  in a SLL, if next pointer of last node object contains NULL value, then such a LL is called L-SLL      

!['C-SLL_1.3']()
* 6. Circular Singly Linked List(C-SLL)
  +  in a SLL, if next pointer of last node object contains address of first node, then such a LL is called C-SLL

!['L-DLL_1.4']()
* 7. Liner Doubly Linked List(L-DLL)
  + in a DLL, if prev pointer of first node and next pointer of last node contains NULL values then it is called as L-DLL 
!['C_DLL_1.5']
* 8. Circular Doubly Linked List(C-DLL)   
  +  in a DLL, if prev pointer of first node contains address of last  and next pointer of last node contains address of first node then it is called as C-DLL

### 4. we can perform following Operations on Linked List
1. bool empty()
2. void addFirst(int data) throw(bad_alloc)
3. void addLast(int data) throw(bad_alloc)
4. int addAtPosition(int position,int data) throw(bad_alloc, Exception)
5. void removeFirst() throw(Exception)
6. void removeLast() throw(Exception)
7. removeFromPosition(int position) throw(Exception)
8. iterate/print linked list
9. void clear() throw()

