#include<cstring>
#include<iostream> 
#include<stack> 

using namespace std;

int priority(char oprtor)
{
    switch (oprtor)
    {
    case '+':

    case '-': 
       return 1; 

    case '*': 

    case '/': 
    return 2;        
       
    }

    return 0; 
}


void strrev(char str[])
{
    int frontIndex = 0;
    int backIndex = strlen(str) - 1; 

while(frontIndex < backIndex)
    swap(str[frontIndex++],str[backIndex--]);
}




int calculate(int num1, int num2, char op)
{

switch (op)
{
case '+': return num1 + num2; 
case '-': return num1 - num2; 
case '*': return num1 * num2;    
case '/': return num1 / num2; 

}

return 0;
}



void convert_infix_to_postfix(char infix[], char postfix[])
{
    stack<char> stk;
     int j = 0; 

     for (int i = 0; i < strlen(infix); ++i)
{ 
    if(isdigit(infix[i]))
    {
        postfix[j ++] = infix[i]; 

    }else if(infix[i] == '(')
     stk.push(infix[i]); 
     else if (infix[i] == ')')
     {

         while(stk.top() != '(')
         {
             postfix[j ++] = stk.top(); 
             stk.pop(); 

         }
         stk.pop(); 
     } else
     {
         while(!stk.empty() && (priority(stk.top()) >= priority(infix[i])))
         {
             postfix[j ++] = stk.top(); 
             stk.pop(); 
         }
         stk.push(infix[i]); 
     }
     
         

}

while(!stk.empty())
{
    postfix[ j ++] = stk.top(); 
    stk.pop(); 

}
postfix[j] = '\0'; 
     
}

int evaluate_postfix_expression(char postfix[])
{
    int result = 0; 
    stack<int> stk; 
    for(int index = 0; index < strlen(postfix); ++ index)
    {
        if(isdigit(postfix[index]))
         stk.push(postfix[index] - '0'); 
        else
        {
            int num2 = stk.top(); stk.pop();
            int num1 = stk.top(); stk.pop(); 
           result = ::calculate(num1,num2,postfix[index]) ; 
           stk.push(result); 

        }

         
    }

    result = stk.top(); stk.pop(); 
    return result; 
}

int main( void )
{
	char postfix[ 30 ];
	char infix[ 30 ] = "5+3*9/(7-4)-6*2";
	cout<<"Infix Form	:	"<<infix<<endl;		//5+3*9/(7-4)-6*2
	convert_infix_to_postfix( infix, postfix );
	cout<<"Postfix Form	:	"<<postfix<<endl;	//539*74-/+62*-
	int result =  evaluate_postfix_expression( postfix );
	cout<<"Result	:	"<<result<<endl;
	return 0;
}


