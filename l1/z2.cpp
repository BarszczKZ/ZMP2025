#include <iostream>

using namespace std;

int funkcja_eulera(unsigned int z){
	int i=0;
	for (int k=1; k<z; k++){
		int b=k;
		int a=z;
		while (b!=a){
			if (b<a) a-=b;
			else b-=a;
		}
		if (b==1){ 
			i++;
		}	
	}
	
	return i;
}
void suma_fun_eulera(unsigned int n){
	int k=0;
	for (int i=1; i<=n; i++){
		if(n%i==0) k+=funkcja_eulera(i);
	}
	cout << "Wartosc funkcji z czesci b wynosi dla "<< n <<":"<< k;
}
int main() {
	unsigned int a;
	cin >> a;
	cout << "\n" << "Wartosc funkcji Eulera w " << a << " wynosi: "<< funkcja_eulera(a) << "\n";
	suma_fun_eulera(a);
	return 0;
	}
