#include<iostream>
#include<bits/stdc++.h>


using namespace std;


void selectionsort(int *array, int size)
{
    for(int startI = 0; startI < size; startI++)
    {
        int smallestI = startI;
        for (int currentI = startI+1; currentI< size; ++currentI )
        {
            if(array[smallestI]>array[currentI])
            {
                smallestI = currentI;
            }
        }
        std::swap(array[startI], array[smallestI]);
    }
}

int main()
{
    int A[] = {1,3,4,5,5};

    selectionsort(A,5);

    int n = 5;
    while(--n)
    {
        cout<<A[n]<<" ";
    }




    
}