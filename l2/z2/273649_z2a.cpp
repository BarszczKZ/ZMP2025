#include <iostream>

using namespace std;
int funkcja(unsigned int tablica[], unsigned int szukana, unsigned int rozmiar)
{
	for (int i = 0; i<rozmiar; i++)
	{
		if (szukana==tablica[i]) return i;
	}
	return -1;
}
int main ()
{
	unsigned int szukana;
	cin >> szukana;
	
	unsigned int n;
	cin >> n;
	unsigned int liczby[n];
	for (int i=0;i<n;i++)
	{
		cin >> liczby[i];
	}
	cout << "Twoje liczby to: " << n << " ";
	for (int i=0; i<n; i++)
	{
		cout << liczby[i] << " ";
	}
	cout << endl;
	if (funkcja(liczby, szukana, n)!=-1)
	{
		cout << "Znajduje sie na miejscu:" << funkcja(liczby, szukana,n);
	}
	else cout << "Nie znajduje sie na liscie";
	return 0;
}