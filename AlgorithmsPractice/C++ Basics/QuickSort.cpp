#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap( int *a, int *b)
{
	int t = *a;
	*a  = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot  = arr[high];   //setting pivot element here
	int i = (low -1);			// Index of pivot

	for(int j = low; j <= high -1; j++)
	{

		if(arr[j] <= pivot) 	// If element is <=pivot, then increment index of smaller element and swap i,j
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i + 1 );

}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}