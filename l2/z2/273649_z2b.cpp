#include <iostream>
using namespace std;


int funkcja(unsigned int tablica[],unsigned int x, int high, int low)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (tablica[mid] == x)
            return mid;

        if (tablica[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
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
	
	int high = sizeof(liczby) / sizeof(liczby[0]) - 1;
	int low = 0;
	
	for (int i=0;i<n;i++)
	{
		cin >> liczby[i];
	}
	cout << "Twoje liczby to: " << n << " ";
	for (int i=0; i<n; i++)
	{
		cout << liczby[i] << " ";
	}
	cout << "\n";
	if (funkcja(liczby, szukana, high, low)!=-1)
	{
		cout << "Znajduje sie na miejscu:" << funkcja(liczby, szukana, high, low);
	}
	else cout << "Nie znajduje sie na liscie";
	return 0;
}