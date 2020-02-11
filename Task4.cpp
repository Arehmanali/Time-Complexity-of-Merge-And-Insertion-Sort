#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
#include<fstream>
using namespace std;
void InsertionSort(int array[], int startIndex, int endIndex);
void MergeSort(int array[], int startIndex, int endIndex);
void Merge(int array[], int startIndex, int midIndex, int endIndex);
void RandomArray(int array[], int size);
void HybridMergeSort(int array[], int startIndex, int endIndex);
int sizeOfArray = 0;

int main()
{
        cout << "Enter the size of Array: ";
        cin >> sizeOfArray;
        int* array = new int[sizeOfArray];          // array for storing the numbers
        RandomArray(array, sizeOfArray);            // fill the array with random numbers

        clock_t startTime = clock();              		 	 // return the start time before function call
        HybridMergeSort(array, 0, sizeOfArray - 1);
        clock_t stopTime = clock();                 		// return the start time after function call
        float duration = float(stopTime - startTime) / float(CLOCKS_PER_SEC);           // return the time of function call
        cout << "Time taken by function : "
            << duration << " seconds" << endl;

	ofstream output;
	output.open("SortedHybridSort.csv");               		 // save the sorted array in csv file 
	if (output.is_open())
	{
		for (int i = 0; i < sizeOfArray; ++i)
		{
			output << array[i] << endl;
		}
	}
	output.close();							// close the opened input file 
	return 0;
}

// insertion sort function for sorting the numbers
void InsertionSort(int array[], int startIndex, int endIndex)
{
	int key, i, j;
	for (j = startIndex; j < endIndex; ++j)
	{
		key = array[j];
		i = j - 1;
		while (i >= 0 && array[i] > key)
		{
			array[i + 1] = array[i];
			--i;
		}
		array[i + 1] = key;
	}
}

/* create the random numbers in array */
void RandomArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % sizeOfArray;
	}
}

/* hybrid function works on basis of best performance of functions */
void HybridMergeSort(int array[], int startIndex, int endIndex)
{
    if (endIndex - startIndex > 1200)                   // call the MergeSort if numbers are greater than 1200
    {
        MergeSort(array, startIndex, endIndex);
    }
    // call the InsertionSort if numbers are lesser than 1200
    else
    {
        InsertionSort(array, startIndex, endIndex);
    }
}
void MergeSort(int array[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)       //while startIndex is less than endIndex
    {
        int midIndex = (startIndex + endIndex) / 2;
        MergeSort(array, startIndex, midIndex);          //Sort from start to mid
        MergeSort(array, midIndex + 1, endIndex);       //Sort from mid+1 to end
        Merge(array, startIndex, midIndex, endIndex);    //merge the sorted array
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
