package com.company;
import java.util.Random;

public class Sorting {

    //--------------------------------------------------------------------------------------Selection Sort--------------
    static int[] selectionSort(int arr[])
    {
        int n = arr.length;

        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first
            // element
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }

        // Finally return the array back sorted
        return arr;
    }

    //------------------------------------------------------------------------------------Insertion Sort----------------

    //static int[] insertionSort(int arr[])
    //{

    //}


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Prints the array
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }

    public static void main(String[] args) {
        // write your code here
        System.out.println("Hello world");
        System.out.println();
        System.out.println();

        //Lets Start Sorting
        Sorting test = new Sorting();

        int[] unsortedArray = new Random().ints(10, 0, 10).toArray();
        int[] sortedArray   = selectionSort(unsortedArray);

        System.out.println("Unsorted Array :");
        printArray(unsortedArray);

        System.out.println("Selection Sorted Array :");
        printArray(sortedArray);


    }


}