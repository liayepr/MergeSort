#include <iostream>
using namespace std;

void Merge(int A[], int p, int q, int r )
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = p; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	/* Copy the remaining elements of L[], if there
	  are any */
	while (i < n1)
	{
		A[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}

}

void Merge_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		Merge_sort(A, p, q);
		Merge_sort(A, q + 1, r);
		Merge(A, p, q, r);
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
	int A[] = { 1, 9, 5, 12, 78, 98, 4, 321, 65, 198 };
	int p = 0, r = 9;
	int size = r - p;
	cout << "Array before soting: " << endl;
	printArray( A, size);
	    cout << "Array after soting: " << endl;
		Merge_sort(A, p, r);
		printArray(A, size);
		system("pause");
}


