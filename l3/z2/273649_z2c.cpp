#include <iostream>
using namespace std;

const int MAX_N = 20;

void wypiszPodzbior(int T[], int n, int mask) {
    bool pusty = true;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            cout << T[i] << " ";
            pusty = false;
        }
    }
    if (pusty) {
        cout << "empty";
    }
    cout << endl;
}

int liczElementy(int mask, int n) {
    int licznik = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            licznik++;
        }
    }
    return licznik;
}

int main() {
    int T[MAX_N];
    int n, k;
	cout << "Podaj liczbe elementow:" << " ";
    cin >> n;
	cout << "Podaj elementy:" << " ";
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
	cout << "Podaj rozmiar podzbiorow:" << " ";
    cin >> k;

    int ile = 1 << n;
    for (int mask = 0; mask < ile; mask++) {
        if (liczElementy(mask, n) == k) {
            wypiszPodzbior(T, n, mask);
        }
    }

    return 0;
}
