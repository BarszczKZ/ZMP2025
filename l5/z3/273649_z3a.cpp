#include <iostream>

using namespace std;

void BubbleSort(int *tab, int n)
{
	bool stop = false;
	for(int i= 1; i<n; i++)
	{
		stop = false;
		for (int k = 0; k<n-i;k++)
		{
			if (tab[k]>tab[k+1])
			{
				swap(tab[k],tab[k+1]);
				stop = true;
			}
		}
		if (stop==false) break;
	}
}

int MaxDiff(int *tab, int n)
{
	BubbleSort(tab, n);
	return tab[n-1]- tab[0];
	
} 

int main()
{
	int *tab , n;
	tab = new int [n];
	cin >> n;
	for (int i = 0; i<n;i++)
		cin >> tab[i];
	cout << MaxDiff(tab,n);
	
	return 0;
}
