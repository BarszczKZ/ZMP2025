#include <iostream>
using namespace std;

int funkcja_euklidesa(unsigned int z, unsigned int k)
{
		while (z!=k)
		{
			if (z<k) k-=z;
			else z-=k;
		}
	return z;
}
int NWD(unsigned int n, unsigned int tablica[])
{
	int nwd = funkcja_euklidesa(tablica[0],tablica[1]);
	for (int i = 2; i<n;i++)
	{
		nwd = funkcja_euklidesa(nwd,tablica[i]);
	}
	return nwd;
}
int main()
{
	unsigned int n;
	cin >> n;
	unsigned int liczby[n];
	for (int i=0;i<n;i++)
	{
		cin >> liczby[i];
	}
	cout << "Twoje liczby to" << n << " ";
	for (int i=0; i<n; i++)
	{
		cout << liczby[i] << " ";
	}
	
	cout << "Ich NWD to:" << NWD(n, liczby);
}