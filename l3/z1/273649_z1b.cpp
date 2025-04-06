#include<iostream>
using namespace std;

unsigned long long Fib(unsigned long long n, unsigned long long a = 1, unsigned long long b = 1)
{
	if (n==1) return a;
	if (n==0) return b;
	
	return Fib(n-1, b, a+b);
}


int main()
{
	unsigned long long a;
	cin >> a;
	cout << Fib(a);
	return 0;
}