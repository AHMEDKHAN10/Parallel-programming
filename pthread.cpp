#include <iostream>  
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <thread>
#define MAX 100
#define THREAD 4

using namespace std::chrono; 
using namespace std;  

int matA[MAX][MAX]; 
int matB[MAX][MAX]; 
int matC[MAX][MAX];

void *multiplication(void* arg) 
{
    long size = (MAX + 1) / THREAD; //how many rows in each thread to process
    long start_point =  (long) arg * size;  //starting point
    long end_point   = start_point + size; //end point
    if ( end_point > MAX ) end_point = MAX;
    
  
    for (int i = start_point; i < end_point; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            for (int k = 0; k < MAX; k++)
            {
                matC[i][j] += matA[i][k] * matB[k][j];
            }  
        }      
    }  
        
} 


void init(int MatA[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            MatA[i][j] = rand() % 10; 
        }         
    }  
        
}

//Driver code 

void pthread_func()
{
  
    init(matA); init(matB);
         
    pthread_t *threads; 
    threads = (pthread_t*)malloc(MAX*sizeof(pthread_t)); 
      
    int count = 0; 
    int* data = NULL; 

    auto start = high_resolution_clock::now();

    for (long i = 0; i < THREAD; i++)
    {
        pthread_create(&threads[i], NULL,  multiplication, (void*)(i)); 
    }
    
    // printf("RESULTANT MATRIX IS :- \n"); 
    
    for (long i = 0; i < THREAD; i++)  
    {
        pthread_join(threads[i], NULL); 
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Duration: " << duration.count() << " microseconds for ROWS: " << MAX << " and THREADS: " << THREAD << endl;
      
}

int main() 
{ 
    pthread_func();
    return 0;
} 