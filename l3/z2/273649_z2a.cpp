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

int main() {
    int T[MAX_N];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    int ile = 1 << n; // 2^n podzbiorów
    for (int mask = 0; mask < ile; mask++) {
        wypiszPodzbior(T, n, mask);
    }

    return 0;
}
