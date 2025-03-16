#include <iostream>
using namespace std;

int funkcja(unsigned int n) {
    int zera = 0;

    for (int k = 5; k <= n; k *= 5)
	{
        zera += n / k;
    }

    return zera;
}

int main()
{
	int n;
	cin >> n;
	cout << funkcja(n);
	return 0;
}