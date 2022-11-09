#include <iostream>

using namespace std;

#include "Persons&Teams.h"

/* Clase que sirve para demostrar lugares del campeonato, carreras 
* y también para almacenar a los pilotos y equipos y solo pasar info
*/
class Standings {
    private:
        Driver drivers[20];
        Team equipo[10];
        int tam_driver;
        int tam_equipo;
    public:
        /* Contructores */
        Standings();
        Standings(Driver [], int);

        /* Setter */
        void agregar_driver(Driver);
        void agregrar_team(Team);

        /* Métodos*/
        void update_driver_championship();
        void consultar_driver_standing();
        Driver get_drivers();

};

Standings :: Standings(){
    /* 20 porque normalmente los pilotos son 20 los que compiten */
    tam_driver = 20;
    for (int i = 0; i < tam_driver; i++){
        drivers[i] = Driver();
    }
    /* 10 porque son 10 equipos */
    tam_equipo = 10;
    for (int i = 0; i < tam_equipo; i++){
        equipo[i] = Team();
    }
}

/* Por lo mientras para trabajar con este objeto */
Standings :: Standings(Driver lista[], int ta){
    for (int i = 0; i < ta; i++){
        drivers[i] = lista[i];
    }
    tam_driver = ta;
}

void Standings :: agregar_driver(Driver nuevo){
    /* Usar el tamaño actual, ya que los indices de listas se le resta 1 */
    drivers[tam_driver] = nuevo;
    /* Actualizar el tamaño */
    tam_driver += 1;
}

void Standings :: agregrar_team(Team nuevo){
    /* Usar el tamaño actual, ya que los indices de listas se le resta 1 */
    equipo[tam_equipo] = nuevo;
    /* Actualizar el tamaño */
    tam_equipo += 1;
}

void Standings :: update_driver_championship(){
    /* Crear una lista temporal para no borrar la original */
    Driver temp[20];

    /* Agregar los pilotos a una lista temporal para ir borrando pilotos */
    for (int i = 0; i < tam_driver; i++){
        temp[i] = drivers[i];
    }

    /* Como el tamaño va cambiando, crear una lista temporal */
    int tam_updated = tam_driver;
    /* Repetir esto por cada elemento de la lista de pilotos*/
    for (int i = 0; i < tam_driver; i++){
        /* Volver a iniciar el máximo para cuando lista sea más chica */
        int index_max = 0;
        float max = temp[0].get_puntos();
        /* Sacar el puntaje máximo y el indice de la lista de ese puntaje*/
        for (int j = 0; j < tam_updated; j++){
            if (temp[j].get_puntos() > max){
                max = temp[j].get_puntos();
                index_max = j;
            }
        }
        /* Agregar el indice donde se encontre el puntaje máximo */
        drivers[i] = temp[index_max];

        /* Actualizar el tamaño de la lista temporal */
        tam_updated -= 1;
        /* Borras el piloto que fue el máximo para repetir el ciclo */
        for (int k = index_max; k <= tam_updated; k++){
            temp[k] = temp[k+1];
        }
    }
}

void Standings :: consultar_driver_standing(){
    for (int i = 0; i < tam_driver; i++){
        string nom = drivers[i].get_nombre();
        float pun = drivers[i].get_puntos();
        cout << i+1 << ". " << nom << ": " << pun << " puntos" << endl;
    }
}

/* Solución temporal */
Driver Standings :: get_drivers(){
    return drivers[19];
}



class Race {
    private:
        /* Todas las variables de una pista */
        string country;
        string circuit_name;
        int race_num;
        int laps;
        float circuit_len;
        Standings carrera_st;
    public:
        /* Constructores */
        Race(): country(""), circuit_name(""), race_num(0), laps(0), circuit_len(0.0){};
        Race(string coun, string name, int ra_num, int lap, float cir_len): country(coun), circuit_name(name), race_num(ra_num), laps(lap), circuit_len(cir_len) {};

        /* Getters */
        string get_country();
        string get_cricuit_name();
        int get_race_num();
        int get_laps();
        float get_circuit_len();

        
};

string Race :: get_country(){
    return country;
}

string Race :: get_cricuit_name(){
    return circuit_name;
}

int Race :: get_race_num(){
    return race_num;
}

int Race :: get_laps(){
    return laps;
}

float Race :: get_circuit_len(){
    return circuit_len;
}