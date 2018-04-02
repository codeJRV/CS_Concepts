// CPP code to compute average of two numbers
#include <bits/stdc++.h>
using namespace std;
 
// Function to compute average of two numbers
int compute_average(int a, int b)
{
    return (a / 2) + (b / 2) + ((a % 2 + b % 2) / 2);   // this is the value
}
 
// Driver code
int main()
{
    // Assigning maximum integer value
    int a = INT_MAX, b = INT_MAX;
 
    // Average of two equal numbers is the same number
    cout << "Actual average : " << INT_MAX << endl;
 
    // Function to get the average of 2 numbers
    cout << "Computed average : " << compute_average(a, b);
 
    return 0;
}
