#include<iostream>
#include <string>
using namespace std;
#define SIZE 5
int get_hash_code(int data)
{
   const int Prime = 151;
  int result = 1; 

  result = result * data + Prime; 

  return result;
}


int main(void)
{


int a = 10; 
int data = a; 
for (int count = 1; count <= 5; ++ count)
{
    int data = count; 
    int hashcode = ::get_hash_code(data); 

     int slot = hashcode % SIZE; 

     cout << data <<" " << hashcode << " " <<slot << endl; 
}


    return 0; 
}


int main2(void)
{
  int a = 10; 
    int data ;
    data = a; 
    int hashcode = ::get_hash_code(data); 

     int slot = hashcode % SIZE; 

     cout << data <<" " << hashcode << " " <<slot << endl;


       int b = 50000; 
    data = b; 
     hashcode = ::get_hash_code(data); 

      slot = hashcode % SIZE; 

     cout << data <<" " << hashcode << " " <<slot << endl;
     return 0; 

}
int main1(void)
{

int num1 = 10; 
   int hashCode = ::get_hash_code(num1);
   cout << "NUm 1 "<<num1 << "  "<< &num1 << " " <<hashCode<<endl; 

   int num2 = 20; 
    hashCode = ::get_hash_code(num2);
   cout << "NUm 1 "<<num2 << "  "<<&num2 << " "<<hashCode<<endl; 

    return 0; 
}
