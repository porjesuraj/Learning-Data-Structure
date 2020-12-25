#include<iostream>

using namespace std;

#define MAX 10

#define INF 999
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
                mat[i][j] = INF; 
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
            int weight; 
            cout <<"enter edge (from to) : ";
            cin >> from >> to >> weight; 

            mat[from][to] = weight; 
           mat[to][from] = weight; // comment this line, for this Directed graph  

        }
        
     }

     void display()
     {
         for (int i = 0; i < vertCount; ++i)
         {
             for (int j = 0; j < vertCount; ++j)
             {
                 if(mat[i][j] != INF)
                 cout << mat[i][j] << "\t";
                 else
                 {
                     cout <<"#" << "\t"; 
                 }
                  

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

6 
7
0 1 7
0 2 4
0 3 8
1 2 9
1 4 5
3 4 6
3 5 2
*/


