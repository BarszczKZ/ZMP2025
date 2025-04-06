#include<iostream>
using namespace std;

unsigned long long Fib(unsigned long long n)
{
	unsigned long long fib[n]={0};
	fib[0] = 1;
	fib[1] = 1;
	if (n==1 || n==0) return 1;
	for(unsigned long long i=2; i<n; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	return fib[n-1];
	
}
int main()
{
	unsigned long long a;
	cin >> a;
	cout << Fib(a);
	
	return 0;
}