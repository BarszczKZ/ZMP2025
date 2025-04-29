#include <iostream>

using namespace std;

int inwersje(int *tab, int n)
{
	int count = 0;
	bool stop = false;
	for(int i= 1; i<n; i++)
	{
		stop = false;
		for (int k = 0; k<n-i;k++)
		{
			if (tab[k]>tab[k+1])
			{
				swap(tab[k],tab[k+1]);
				count++;
				stop = true;
			}
		}
		if (stop==false) break;
	}
	return count;
}


int main()
{
	int *tab , n;
	tab = new int [n];
	cin >> n;
	for (int i = 0; i<n;i++)
		cin >> tab[i];
	cout << inwersje(tab,n);
	
	return 0;
}
