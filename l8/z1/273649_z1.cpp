#include <iostream>
#include <string>

using namespace std;

class Pojazd {
private:
    string marka;
    string model;
    int rok_produkcji;

public:
    Pojazd(const string& m, const string& mo, int rok)
        : marka(m), model(mo), rok_produkcji(rok) {}

    virtual void wyswietl() const {
        cout << "Marka: " << marka << "\n";
        cout << "Model: " << model << "\n";
        cout << "Rok produkcji: " << rok_produkcji << "\n";
    }

    virtual ~Pojazd() {}
};

class Samochód : public Pojazd {
private:
    int liczba_drzwi;

public:
    Samochód(const string& m, const string& mo, int rok, int drzwi)
        : Pojazd(m, mo, rok), liczba_drzwi(drzwi) {}

    void wyswietl() const override {
        cout << "=== Samochód ===\n";
        Pojazd::wyswietl();
        cout << "Liczba drzwi: " << liczba_drzwi << "\n";
    }
};

class Rower : public Pojazd {
private:
    int liczba_przerzutek;

public:
    Rower(const string& m, const string& mo, int rok, int przerzutki)
        : Pojazd(m, mo, rok), liczba_przerzutek(przerzutki) {}

    void wyswietl() const override {
		cout << "=== Rower ===\n";
        Pojazd::wyswietl();
        cout << "Liczba przerzutek: " << liczba_przerzutek << "\n";
    }
};

int main() {
    string marka1, model1, marka2, model2;
    int rok1, drzwi, rok2, przerzutki;

	cin >> marka1 >> model1 >> rok1 >> drzwi;
    cin >> marka2 >> model2 >> rok2 >> przerzutki;

    Samochód s(marka1, model1, rok1, drzwi);
    Rower r(marka2, model2, rok2, przerzutki);

    s.wyswietl();
    cout << "\n";
    r.wyswietl();

    return 0;
}
