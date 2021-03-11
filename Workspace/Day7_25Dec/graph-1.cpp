#include<iostream>

using namespace std;

#define MAX 10

class AdjMatNonWeightedGraph
{
    private:
    
    int mat[MAX][MAX]; 
    int vertCount,edgeCount; 
 

    public: 
     AdjMatNonWeightedGraph(int vertCount) : vertCount(vertCount)
     {
         int i,j; 
             this->edgeCount = 0; 
         for (i = 0; i < vertCount; i++)
         {
            for ( j = 0; j < vertCount; j++)
            {
                mat[i][j] = 0; 
            }
            
         }
         

      }

     void accept()
     {
         cout<<"enter number of edges:  "; 
        cin >> edgeCount; 

        for (int c = 0; c < edgeCount; c++)
        {
            int from,to;

            cout <<"enter edge (from to) : ";
            cin >> from >> to; 

            mat[from][to] = 1; 
            mat[to][from] = 1; // comment this line, for this Directed graph  

        }
        
     }

     void display()
     {
         for (int i = 0; i < vertCount; ++i)
         {
             for (int j = 0; j < vertCount; ++j)
             {
                 cout << mat[i][j] << "\t"; 

             }
             cout << endl; 
         }
         

     }
 
}; 

int main()
{

int vertCount; 
cout <<"Enter number of vertices"; 
cin >> vertCount; 

AdjMatNonWeightedGraph g(vertCount); 
g.accept();
g.display(); 
    return 0; 
}

/*
V -6 
E - 7

0 1 
0 2
0 3 

*/