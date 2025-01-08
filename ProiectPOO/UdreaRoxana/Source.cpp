#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Proiect - Faza 1
//Roxana Maria Udrea, clase alese Restaurant, Meniu, Uniforme

class Restaurant {
public:
    string* nume;
    int capacitate;
    static int numarRestaurante;
    const int idRestaurant;

    Restaurant(string nume, int capacitate) : idRestaurant(1), capacitate(capacitate) {
        this->nume = new string(nume);
        numarRestaurante++;
    }
    Restaurant(string nume) : idRestaurant(2), capacitate(50) {
        this->nume = new string(nume);
        numarRestaurante++;
    }
    Restaurant() : nume(new string("Nedefinit")), capacitate(0), idRestaurant(3) {
        numarRestaurante++;
    }

    ~Restaurant() {
        delete nume;
    }

    static void afiseazaNumarRestaurante() {
        cout << "Numarul total de restaurante: " << numarRestaurante << endl;
    }
};

int Restaurant::numarRestaurante = 0;

class Meniu {
public:
    string* tip;
    vector<string> listaPreparate;
    static int numarMeniuri;
    const int idMeniu;

    Meniu(string tip, vector<string> listaPreparate) : idMeniu(101), listaPreparate(listaPreparate) {
        this->tip = new string(tip);
        numarMeniuri++;
    }
    Meniu(string tip) : idMeniu(102), listaPreparate({ "Fel principal", "Desert" }) {
        this->tip = new string(tip);
        numarMeniuri++;
    }
    Meniu() : tip(new string("General")), listaPreparate({ "Băutură", "Aperitiv", "Desert" }), idMeniu(103) {
        numarMeniuri++;
    }

    ~Meniu() {
        delete tip;
    }

    static void afiseazaNumarMeniuri() {
        cout << "Numarul total de meniuri: " << numarMeniuri << endl;
    }
};

int Meniu::numarMeniuri = 0;

class Uniforma {
public:
    string* model;
    int marime;
    static int numarUniforme;
    const int idUniforma;

    Uniforma(string model, int marime) : idUniforma(201), marime(marime) {
        this->model = new string(model);
        numarUniforme++;
    }
    Uniforma(string model) : idUniforma(202), marime(50) {
        this->model = new string(model);
        numarUniforme++;
    }
    Uniforma() : model(new string("Standard")), marime(42), idUniforma(203) {
        numarUniforme++;
    }

    ~Uniforma() {
        delete model;
    }

    static void afiseazaNumarUniforme() {
        cout << "Numarul total de uniforme: " << numarUniforme << endl;
    }
};

int Uniforma::numarUniforme = 0;

int main() {
    Restaurant r1("La Bucurie", 100), r2("Gustos"), r3;
    Meniu m1("Vegetarian", { "Salata", "Supa" }), m2("Carnivor"), m3;
    Uniforma u1("Casual", 36), u2("Elegant"), u3;

    Restaurant::afiseazaNumarRestaurante();
    Meniu::afiseazaNumarMeniuri();
    Uniforma::afiseazaNumarUniforme();

    return 0;
}
