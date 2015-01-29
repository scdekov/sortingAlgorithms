#include <iostream>
using namespace std;


int* merge(int* arr1,int size1, int* arr2,int size2)
{
	int counter1=0,counter2=0;
	int* result = new int[size1+size2];
	while(counter1<size1 && counter2<size2)
	{
		if (arr1[counter1]>=arr2[counter2])
		{
			result[counter1+counter2]=arr2[counter2];
			counter2++;
		}else 
		{
			result[counter1+counter2]=arr1[counter1];
			counter1++;
		}
	}

	if (counter1<size1)
	{
		while(counter1<size1)
		{
			result[counter1+counter2]=arr1[counter1];
			counter1++;
		}
	}else
	{
		while(counter2<size2)
		{
			result[counter1+counter2]=arr2[counter2];
			counter2++;
		}
	}
	
	return result;
}


int* mergeSort(int* arr,int size)
{
	if (size == 1)
	{
		return arr;
	}
	int size1 = size/2, size2 = size-size1;
    int* left = mergeSort(arr, size1);
    int* right = mergeSort(arr+size1, size2);
    return merge(left, size1,right, size2);
}


int main()
{
	
	int size=15;
	int arr[]={8,11,1,25,0,2,2131,4,7,8,4324,0,1,2,3};
	int* result = mergeSort(arr,size);
	for (int i = 0; i < size; ++i)
	{
		cout<<result[i]<<", ";
	}
	cout<<endl;
	return 0;
}
