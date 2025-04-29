#include <iostream>

using namespace std;

void Merge(int *tab, int start, int mid, int end)
{
	
	int n1 = mid-start+1;
	int n2 = end -mid;
	int temp_a[n1];
	int temp_b[n2];
	
	for (int i=0; i<n1;i++)
		temp_a[i] =tab[start+i];
	for (int i=0;i<n2;i++)
		temp_b[i]=tab[mid+1+i];
	int i=0;
	int j=0;
	int k = start;
	while (i<n1 && j<n2)
	{
		if (temp_a[i]<temp_b[j])
		{
			tab[k]=temp_a[i];
			i++;
			k++;
			
		}
		else
		{
			tab[k]=temp_b[j];
			j++;
			k++;
		}
		
	}
	while (i<n1)
	{
		tab[k]=temp_a[i];
		i++;
		k++;
		
	}
	while (j<n2)
	{
		tab[k]=temp_b[j];
		j++;
		k++;
		
	}
	
}





void bottomUpMergeSort(int* tab, int n) {
    for (int size = 1; size < n; size *= 2) {
        for (int start = 0; start < n; start += 2 * size) {
            int mid = min(start + size - 1, n - 1);
            int end = min(start + 2 * size - 1, n - 1);
            if (mid < end)
                Merge(tab, start, mid, end);
        }
    }
}

int main()
{
	int *tab, n;
	cin >> n;
	tab = new int [n];
	for(int i=0; i<n; i++)
		cin >> tab[i];
	bottomUpMergeSort(tab, n);
	for(int i=0; i<n; i++)
		cout << tab[i] << " ";
}