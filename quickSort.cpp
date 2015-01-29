#include <iostream>
using namespace std;

void quickSortHelper(int* arr, int left, int right) {
	int leftItter = left, rightIterr = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	while (leftItter <= rightIterr) 
	{
		while (arr[leftItter] < pivot)
		{
			leftItter++;
		}	
		while (arr[rightIterr] > pivot)
		{
			rightIterr--;
		}
		if (leftItter <= rightIterr) 
		{
		swap(arr[leftItter],arr[rightIterr]);
		leftItter++;
		rightIterr--;
		}
	}
	if (left < rightIterr)
	{
		quickSortHelper(arr, left, rightIterr);
	}
	if (leftItter < right)
	{
		quickSortHelper(arr, leftItter, right);
	}
}

void quickSort(int* arr,int size)
{
	quickSortHelper(arr,0,size);
}


int main()
{
	int arr[]={1,12,5,26,7,14,3,20,2};
	int size = 9;
	quickSort(arr,size);
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}