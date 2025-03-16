#include <iostream>

using namespace std;

void funkcja(unsigned long long int a){
	int k = 1;
	cout << a << " ";
	while(a!=1)
	{
		if (a%2==0)
		{
			a=a/2;
			k++;
			cout << a << " ";
		}
		else
		{
			a=3*a+1;
			k++;
			cout << a << " ";
		}
		
	}
	cout << ":: " << k;	
}
int main()
{
	int a;
	cin >> a;
	funkcja(a);
	return 0;
}

// Wydaje mi sie, że zawsze sie skonczy, zakładajac ze zawsze w koncu trafi na 2^n dla dowolnego n