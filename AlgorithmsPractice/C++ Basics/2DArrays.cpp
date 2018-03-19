#include <iostream>

using namespace std;

int main()
{

	int A[5] ; // 5 diffent integers variables as one contiguous source of information.
	int b[2][3];   // 2 1D arrays of 3 inntegers each

	//int *p = B will give error as B returns pointer to 1D array of 3 integers
	int (*p)[3] = b;
	// *(B+1) is same as B[1] or &B[1][0]


	// for a 2d array, B[i][j] = *(B[i] + j) = *(*(B + i) + j);
	 

  
}