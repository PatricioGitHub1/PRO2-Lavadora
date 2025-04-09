/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 *
 *
 * En este ejemplo se construye un programa modular que ofrece un menú de opciones para
 * gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y
 * <em>Prenda</em>.
 *
 * Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo de proyecto
 * completamente documentado, incluyendo los elementos privados.
 */

/**
 * @file pro2_s8.cc
 *
 * @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
 */

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Cubeta.hh"
#include "Lavadora.hh"
#include "Prenda.hh"
#ifndef NO_DIAGRAM  // explicado en Prenda.hh
#include "readbool.hh"
#endif

void processInicialize(Lavadora & lav) {
    int pmax;
    bool color;
    cin >> pmax >> color;
    lav.inicializar(pmax, color);
}

void processAddCloth(Lavadora & lav) {
    int pes;
    bool color;
    cin >> pes >> color;
    //Prenda cloth = Prenda(pes, color);

    lav.anadir_prenda(Prenda(pes, color));
}

void processAddToBucket(Cubeta & cub) {
    int pes;
    bool color;
    cin >> pes >> color;
    //Prenda cloth = Prenda(pes, color);

    cub.anadir_prenda(Prenda(pes, color));
}

void processCompleteWashingMachine(Lavadora & lav, Cubeta & cub) {
    cub.completar_lavadora(lav);
}

void processStartWashing(Lavadora & lav) {
    lav.lavado();
}

void writeBucket(Cubeta & cub) {
    cub.escribir();
}

void writeWashingMachine(Lavadora & lav) {
    lav.escribir();
}

void start(Lavadora & lav, Cubeta & cub) {
    int comm;
    cin >> comm;

    while (comm != -8) {
        switch (comm)
        {
        case -1:
            processInicialize(lav);
            cout << "done" << endl;
            break;
        case -2:
            processAddCloth(lav);
            break;
        case -3:
            processAddToBucket(cub);
            break;
        case -4:
            processCompleteWashingMachine(lav, cub);
            break;
        case -5:
            processStartWashing(lav);
            break;
        case -6:
            writeBucket(cub);
            break;
        case -7:
            writeWashingMachine(lav);
            break;
        
        default:
            break;
        }

        cin >> comm;
    }
}

/**
 * @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
 */
int main() {
    Lavadora lav = Lavadora();
    Cubeta cub = Cubeta();
    start(lav, cub);
}
