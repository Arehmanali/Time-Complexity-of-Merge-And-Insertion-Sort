#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
#include<fstream>
using namespace std;
void InsertionSort(int array[], int startIndex, int endIndex);
void RandomArray(int array[], int size);
int sizeOfArray = 0;			
int main()
{
		cout << "Enter the size of Array: ";
		cin >> sizeOfArray;
		int* array = new int[sizeOfArray];			// array for storing the numbers
		RandomArray(array, sizeOfArray);			// fills the array with random generated numbers

		clock_t startTime = clock();									// returns the start time before the function call
		InsertionSort(array, 0, sizeOfArray - 1);				
		clock_t stopTime = clock();										// returns the start time after the function call
		float duration = float(stopTime - startTime) / float(CLOCKS_PER_SEC);			// calculate the time consumed by function
		cout << "Time taken by function : "
			<< duration << " seconds" << endl;
	
	
	ofstream output;
	output.open("SortedInsertionSort.csv");				// save the sorted array in csv file
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

void InsertionSort(int array[], int startIndex, int endIndex)
{
	int key, i, j;
	for (j = startIndex; j <endIndex; ++j)
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

void RandomArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % sizeOfArray;
	}
}
