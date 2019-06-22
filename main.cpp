#include <iostream>
using namespace std;

void Merge(int A[], int start, int end, int mid)
{
	int i, j, k;
	int temp[end - start + 1];
	i = start;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (A[i] < A[j])
		{
			temp[k] = A[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = A[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = A[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= end)
	{
		temp[k] = A[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = start; i <= end; i++)
	{
		A[i] = temp[i - start];
	}
}

void Merge_sort(int A[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Merge_sort(A, start, mid);
		Merge_sort(A, mid + 1, end);
		Merge(A, start, end, mid);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	int A[] = { 1, 98, 5, 12, 78, 19, 4, 321, 65, 8 };
	int start = 0, end = 9;
	int size = end - start + 1;
	cout << "Array before soting: " << endl;
	printArray(A, size);
	cout << "Array after soting: " << endl;
	Merge_sort(A, start, end);
	printArray(A, size);
	system("pause");
}
