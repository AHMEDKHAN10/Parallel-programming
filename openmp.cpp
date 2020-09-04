#include <iostream>  
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <thread>

#define MAX 2000

using namespace std::chrono; 
using namespace std;  

int multiplication(int m, int n, int p, float a[MAX][MAX], float b[MAX][MAX], float c[MAX][MAX])
{
   int i,j,k;
   #pragma omp parallel shared(a,b,c) private(i,j,k) 
   {
      #pragma omp for  schedule(static)
         for (i=0; i<m; i=i+1)
         {
            for (j=0; j<n; j=j+1)
            {
               a[i][j]=0.;
               for (k=0; k<p; k=k+1)
               {
                  a[i][j]=(a[i][j])+((b[i][k])*(c[k][j]));
               }
            }
         }
   }
   return 0;
}
int main()
{
   float matA[MAX][MAX]; 
   float matB[MAX][MAX]; 
   float matC[MAX][MAX];

   for(int i=0;i<MAX;i++)    
   {    
      for(int j=0;j<MAX;j++)    
      {     
         matA[i][j] = rand() % 10; 
      }    
   }    
   for(int i=0;i<MAX;i++)    
   {    
      for(int j=0;j<MAX;j++)    
      {     
         matB[i][j] = rand() % 10; 
      }    
   }   

   auto start = high_resolution_clock::now();  

   multiplication(MAX, MAX, MAX, matA, matB, matC);
   
   auto stop = high_resolution_clock::now(); 
   auto duration = duration_cast<microseconds>(stop - start); 
   cout << "Duration: " << duration.count() << " microseconds for ROWS: " << MAX << endl;

   return 0;
}