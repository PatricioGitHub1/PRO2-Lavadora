# include "Lavadora.hh"

Lavadora::Lavadora() {};

void Lavadora::inicializar(int pmax, bool col) {
    cout << "hello" << endl;
    pesmax = pmax;
    col = col;
}

void Lavadora::anadir_prenda(const Prenda& p) {

}

void Lavadora::lavado() {}

bool Lavadora::esta_inicializada() const {
    return ini;
};

bool Lavadora::consultar_color() const {
    return col;
};

int Lavadora::consultar_peso() const {
    return pes;
};

int Lavadora::consultar_peso_maximo() const {
    return pesmax;
};

void Lavadora::escribir() const {};