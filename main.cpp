#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class IRezervare {
public:
    virtual int calculeazaDurata() const = 0;
    virtual double calculeazaPret() const = 0;
    virtual void afiseazaDetalii() const = 0;
    virtual ~IRezervare() {}
};

class Rezervare : public IRezervare {
protected:
    string numeClient;
    string dataOraRezervare;
    int nrPersoane;

public:
    Rezervare(string nume, string dataOra, int nrPers)
        : numeClient(nume), dataOraRezervare(dataOra), nrPersoane(nrPers) {}

    int getNrPersoane() const { return nrPersoane; }
    string getDataOra() const { return dataOraRezervare; }
    string getNumeClient() const { return numeClient; }

    virtual int calculeazaDurata() const override {
        return 2;
    }

    virtual double calculeazaPret() const override = 0;
};

class RezervareZilnica : public Rezervare {
public:
    RezervareZilnica(string nume, string dataOra, int nrPers)
        : Rezervare(nume, dataOra, nrPers) {}

    double calculeazaPret() const override {
        if (nrPersoane <= 2) return 50;
        return 50 + (nrPersoane - 2) * 20;
    }

    void afiseazaDetalii() const override {
        cout << "[Zilnica] " << numeClient << ", " << dataOraRezervare
             << ", persoane: " << nrPersoane << ", pret: " << calculeazaPret() << " lei\n";
    }
};

class RezervareEvenimentSpecial : public Rezervare {
public:
    RezervareEvenimentSpecial(string nume, string dataOra, int nrPers)
        : Rezervare(nume, dataOra, nrPers) {}

    int calculeazaDurata() const override {
        return 4;
    }

    double calculeazaPret() const override {
        double pretFix = 200;
        if (nrPersoane > 10) pretFix += (nrPersoane - 10) * 15;
        return pretFix;
    }

    void afiseazaDetalii() const override {
        cout << "[Eveniment Special] " << numeClient << ", " << dataOraRezervare
             << ", persoane: " << nrPersoane << ", pret: " << calculeazaPret() << " lei\n";
    }
};

class RezervareGrupMare : public Rezervare {
public:
    RezervareGrupMare(string nume, string dataOra, int nrPers)
        : Rezervare(nume, dataOra, nrPers) {}

    double calculeazaPret() const override {
        double pret = 500;
        if (nrPersoane > 20)
            pret += (nrPersoane - 20) * 10;
        return pret;
    }

    void afiseazaDetalii() const override {
        cout << "[Grup Mare] " << numeClient << ", " << dataOraRezervare
             << ", persoane: " << nrPersoane << ", pret: " << calculeazaPret() << " lei\n";
    }
};

Rezervare* creeazaRezervare(const string& tip, const string& nume, const string& dataOra, int nrPers) {
    if (tip == "RezervareZilnica")
        return new RezervareZilnica(nume, dataOra, nrPers);
    else if (tip == "RezervareEvenimentSpecial")
        return new RezervareEvenimentSpecial(nume, dataOra, nrPers);
    else if (tip == "RezervareGrupMare")
        return new RezervareGrupMare(nume, dataOra, nrPers);
    else
        return nullptr;
}

int main() {
    vector<Rezervare*> rezervari;
    ifstream fin("rezervari.txt");
    string linie;

    while (getline(fin, linie)) {
        istringstream iss(linie);
        string tip, nume, data, ora;
        int nrPers;
        iss >> tip >> nume >> data >> ora >> nrPers;
        string dataOra = data + " " + ora;

        Rezervare* r = creeazaRezervare(tip, nume, dataOra, nrPers);
        if (r) rezervari.push_back(r);
    }

    for (Rezervare* r : rezervari) {
        r->afiseazaDetalii();
    }

    for (Rezervare* r : rezervari) delete r;
    return 0;
}
