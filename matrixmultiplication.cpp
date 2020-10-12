#include <iostream>
#include<omp.h>
#include<time.h>
using namespace std;

#define r1 5
#define c1 5
#define r2 5
#define c2 5
int main()
{
    int a[r1][c1], b[r1][c2], mult[r1][c2];

    clock_t start = clock();
    if (c2!=r1)
    {
        cout<<"Cannot multiply";
        return 0;
    }
    
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c1; ++j)
        {
             a[i][j]=rand()%100;
        }
        
    for(int i = 0; i < r2; ++i)
        for(int j = 0; j < c2; ++j)
        {
             b[i][j]=rand()%100;
        }

   //  #pragma imp parallel for private(j,k)   
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
            for(int k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
        }  
    clock_t end=clock();
    
    double diff=double(end-start);
    cout << endl << "Result Matrix: " << endl;
    for(int i = 0; i < r1; ++i)
    {   cout<<endl;
        for(int j = 0; j < c2; ++j)
        {
            cout << " " << mult[i][j];
          
        }
    }
    cout << endl << "Time diff: " << diff;

    return 0;
}
