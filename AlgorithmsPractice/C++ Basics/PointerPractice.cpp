#include <iostream>

using namespace std;


int SumOfElements(int A[])
{

	int i, sum = 0;
	 int size  = sizeof(A)/sizeof(A[0]);
	cout<<"Function size of A: "<<sizeof(A)<<" size of A[0] :"<<sizeof(A[0])<<endl;
	for ( i = 0; i< size; i++)
	{
		sum += A[i];
	}
	return sum;

 }


int main()
{
	int A[] = { 2,1,2,3,4};
	cout<<A<<endl;
	cout<<&A[0]<<endl;
	cout<<&A[1]<<endl;
	cout<<A[0]<<endl;
	cout<<*A<<endl;
	cout<<&A<<endl;
	cout<<++*A<<endl;

	cout<<"Main size of A: "<<sizeof(A)<<" size of A[0] :"<<sizeof(A[0])<<endl;
	int size = sizeof(A)/sizeof(A[0]);
	int total =  SumOfElements(A);

	cout<<"total = "<<total<<" Size : "<<size<<endl;
}