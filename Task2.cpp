#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
#include<fstream>
using namespace std;
void MergeSort(int array[], int startIndex, int endIndex);
void Merge(int array[], int startIndex, int midIndex, int endIndex);
void RandomArray(int array[], int size);
int sizeOfArray = 0;
int main()
{
    
        cout << "Enter the size of Array: ";
        cin >> sizeOfArray;
        int* array = new int[sizeOfArray];			// array to store the numbers for sorting
        RandomArray(array, sizeOfArray);			// fill the array with random generated numbers 

        clock_t startTime = clock();     			 // returns the time before function call
        MergeSort(array, 0, sizeOfArray - 1);
        clock_t stopTime = clock();       			 // return the time after function call
        float duration = float(stopTime - startTime) / float(CLOCKS_PER_SEC);       // calculate the time in seconds the function takes

        cout << "Time taken by function : ";
        cout << duration << " seconds" << endl;

        ofstream output;
        output.open("SortedMergeSort.csv");					// save the sorted array in csv file
        if (output.is_open())
        {
            for (int i = 0; i < sizeOfArray; ++i)
            {
                output << array[i] << endl;
            }
        }
        output.close();
    
    return 0;
}

/* Sorting function for the array of numbers */
void MergeSort(int array[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)       					//while startIndex is less than endIndex
    {
        int midIndex = (startIndex + endIndex) / 2; 
        MergeSort(array, startIndex, midIndex);          		//Sort from start to mid
        MergeSort(array, midIndex + 1, endIndex);      			 //Sort from mid+1 to end
        Merge(array, startIndex, midIndex, endIndex);   		 //merge the sorted array
    }
}

/* Combine the sorted array */
void Merge(int array[], int startIndex, int midIndex, int endIndex)
{
    int i, j, k;
    int n1 = midIndex - startIndex + 1;
    int n2 = endIndex - midIndex;

    /* create temp arrays */
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    /* Copy data to temp arrays leftAray[] and rightArray[] */
    for (i = 0; i < n1; i++)
        leftArray[i] = array[startIndex + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = array[midIndex + 1 + j];

    /* Merge the temp arrays back into array[startIndex..endIndex]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = startIndex; // Initial index of merged subarray 
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of leftArray[], if there
       are any */
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of rightArray[], if there
       are any */ 
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

/* random array function for generating a array of random numbers */
void RandomArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % sizeOfArray;
    }
}
