#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Restaurant {
private:
    string* nume;
    int capacitate;
    static int numarRestaurante;
    const int idRestaurant;

public:
    // Constructori
    Restaurant(string nume, int capacitate) : idRestaurant(numarRestaurante + 1), capacitate(capacitate) {
        this->nume = new string(nume);
        numarRestaurante++;
    }
    Restaurant(const Restaurant& src) : idRestaurant(src.idRestaurant), capacitate(src.capacitate) {
        nume = new string(*src.nume);
    }

    // Destructor
    ~Restaurant() {
        delete nume;
    }

    // Metode de acces
    string getNume() const {
        return *nume;
    }
    void setNume(string nouNume) {
        *nume = nouNume;
    }
    int getCapacitate() const {
        return capacitate;
    }
    void setCapacitate(int nouaCapacitate) {
        capacitate = nouaCapacitate;
    }

    // Metoda statica
    static int getNumarRestaurante() {
        return numarRestaurante;
    }

    // Functia prieten (exemplu)
    friend void afiseazaDetaliiRestaurant(const Restaurant& r);
};

int Restaurant::numarRestaurante = 0;

void afiseazaDetaliiRestaurant(const Restaurant& r) {
    cout << "Restaurantul " << *r.nume << " are o capacitate de " << r.capacitate << " persoane." << endl;
}

class Meniu {
private:
    string* tip;
    vector<string> listaPreparate;
    static int numarMeniuri;
    const int idMeniu;

public:
    Meniu(string tip, vector<string> listaPreparate) : idMeniu(numarMeniuri + 1), listaPreparate(listaPreparate) {
        this->tip = new string(tip);
        numarMeniuri++;
    }
    Meniu(const Meniu& src) : idMeniu(src.idMeniu), listaPreparate(src.listaPreparate) {
        tip = new string(*src.tip);
    }

    ~Meniu() {
        delete tip;
    }

    string getTip() const {
        return *tip;
    }
    void setTip(string nouTip) {
        *tip = nouTip;
    }

    static int getNumarMeniuri() {
        return numarMeniuri;
    }

    friend void printMeniu(const Meniu& m);
};

int Meniu::numarMeniuri = 0;

void printMeniu(const Meniu& m) {
    cout << "Meniul " << *m.tip << " contine: ";
    for (auto& preparat : m.listaPreparate) {
        cout << preparat << ", ";
    }
    cout << endl;
}

class Uniforma {
private:
    string* model;
    int marime;
    static int numarUniforme;
    const int idUniforma;

public:
    Uniforma(string model, int marime) : idUniforma(numarUniforme + 1), marime(marime) {
        this->model = new string(model);
        numarUniforme++;
    }
    Uniforma(const Uniforma& src) : idUniforma(src.idUniforma), marime(src.marime) {
        model = new string(*src.model);
    }

    ~Uniforma() {
        delete model;
    }

    string getModel() const {
        return *model;
    }
    void setModel(string nouModel) {
        *model = nouModel;
    }

    int getMarime() const {
        return marime;
    }
    void setMarime(int nouaMarime) {
        marime = nouaMarime;
    }

    static int getNumarUniforme() {
        return numarUniforme;
    }

    friend void printUniforma(const Uniforma& u);
};

int Uniforma::numarUniforme = 0;

void printUniforma(const Uniforma& u) {
    cout << "Uniforma modelul " << *u.model << " are marimea " << u.marime << endl;
}

int main() {
    Restaurant r1("La Placinte", 100);
    Meniu m1("Vegetarian", { "Salata", "Supa de legume" });
    Uniforma u1("Casual", 40);

    afiseazaDetaliiRestaurant(r1);
    printMeniu(m1);
    printUniforma(u1);

    cout << "Numar restaurante: " << Restaurant::getNumarRestaurante() << endl;
    cout << "Numar meniuri: " << Meniu::getNumarMeniuri() << endl;
    cout << "Numar uniforme: " << Uniforma::getNumarUniforme() << endl;

    return 0;
}
