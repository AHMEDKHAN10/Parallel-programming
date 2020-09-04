#include <iostream>  
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#define MAX 200
using namespace std::chrono; 
using namespace std; 


int main()  
{  

    int matA[MAX][MAX];  
    int matB[MAX][MAX]; 
    int matC[MAX][MAX];  
    int r1=MAX,c1=MAX,r2=MAX,c2=MAX,i,j,k; 

    //random first matrix
    for(i=0;i<r1;i++)    
    {    
        for(j=0;j<c1;j++)    
        {     
            matA[i][j] = rand() % 10; 
        }    
    }    
    // cout << "First Matrix\n"; 
    // //display first matrix
    // for (i = 0; i < r1; i++)
    // { 
    //     for(j = 0; j < c1; j++) 
    //         printf("%d ",matA[i][j]); 
    //     printf("\n"); 
    // } 

    //random second matrix
    for(i=0;i<r1;i++)    
    {    
        for(j=0;j<c1;j++)    
        {     
            matB[i][j] = rand() % 10; 
        }    
    }   
    // cout << "Second Matrix\n";  
    //display second matrix
    // for (i = 0; i < r2; i++)
    // { 
    //     for(j = 0; j < c2; j++) 
    //         printf("%d ",matB[i][j]); 
    //     printf("\n"); 
    // } 

auto start = high_resolution_clock::now();  
// cout<<"multiply of the matrix=\n";    
for(i=0;i<r1;i++)    
{    
    for(j=0;j<c2;j++)    
    {    
        matC[i][j]=0;    
        for(k=0;k<c1;k++)    
        {    
            matC[i][j]+=matA[i][k]*matB[k][j];    
        }    
    }    
}  
auto stop = high_resolution_clock::now(); 
auto duration = duration_cast<microseconds>(stop - start); 
cout << "Duration: " << duration.count() << " microseconds for ROWS: " << MAX << endl; 
//for printing result 
// cout << "Resultant Matrix\n";  
// for(i=0;i<r1;i++)    
// {    
//     for(j=0;j<c1;j++)    
//     {    
//         cout<<matC[i][j]<<" ";    
//     }    
//     cout<<"\n";    
// } 
 
 
return 0;  
}    