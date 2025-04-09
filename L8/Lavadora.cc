# include "Lavadora.hh"
# include <iostream>

const string LAVADORA_OFF = "Lavadora no inicializada";

Lavadora::Lavadora() {};

void Lavadora::inicializar(int pmax, bool col) {
    pesmax = pmax;
    col = col;
    pes = 0;
}

void Lavadora::anadir_prenda(const Prenda& p) {
    if (Lavadora::esta_inicializada()) {
        if (Lavadora::consultar_peso_maximo() < (Lavadora::consultar_peso() + p.consul_peso())) {
            cout << "Lavadora FULL" << endl;
        } else {
            Lavadora::anadir_prenda(p);
            Lavadora::pes += p.consul_peso();
        }

    } else {
        cout << LAVADORA_OFF << endl;
    }
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

void Lavadora::escribir() const {
    cout << "\tLavadora:" << endl;
    if (!Lavadora::esta_inicializada()) {
        cout << LAVADORA_OFF << endl;
    } else {
        cout << "Lavadora de ";

        if (Lavadora::consultar_color()) {
            cout << "color";
        } else {
            cout << "blanco";
        }

        cout << ", con peso actual " << Lavadora::consultar_peso() 
            << " y peso maximo " << Lavadora::consultar_peso_maximo() 
            << ";" << endl << "sus prendas son";

        for (Prenda p : prendas) {
            cout << p.consul_peso() << ' ' << p.consul_color() << endl;
        }
    }
};