#include <iostream>

using namespace std;

int koder(bool klucz[], bool wiadomosc[])
{
	int szyfr[8];
	for (int i = 0; i<8; i++ )
	{
		szyfr[i]=klucz[i]^wiadomosc[i];
		cout << szyfr[i] << " ";
	}
	
	return 0;
}
int main()
{
	bool wiadomosc[8];
	bool klucz[8];
	cout << "Wprowadz klucz: ";
	for (int i = 0; i<8; i++ )
	{
		cin >> klucz[i];
	}
	cout << "Wprowadz wiadomosc: ";
	for (int i=0; i<8; i++)
	{
		cin >> wiadomosc[i];
	}
	koder(klucz, wiadomosc);
}