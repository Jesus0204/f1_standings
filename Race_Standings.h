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
        void consultar_standing();
        void init_puntos_carrera();
        void puntos_carrera();

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
    tam_equipo = 0;
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

void Standings :: consultar_standing(){
    for (int i = 0; i < tam_driver; i++){
        string nom_d = drivers[i].get_nombre();
        float pun_d = drivers[i].get_puntos();
        cout << i+1 << ". " << nom_d << ": " << pun_d << " puntos" << endl;
    }
    cout << endl;
    for (int i = 0; i < tam_equipo; i++){
        string nom_e = equipo[i].get_nombre_eq();
        float pun_e = equipo[i].get_puntos_totales();
        cout << i+1 << ". " << nom_e << ": " << pun_e << " puntos" << endl;
    }
}

void Standings :: init_puntos_carrera(){
    for (int i = 0; i < tam_driver; i++){
        drivers[i].puntos_carrera_driver(0.0);
    }
}

void Standings :: puntos_carrera(){
    int pun = 25;
    for (int i = 0; i < tam_driver; i++){
        if (i == 0){
            drivers[i].puntos_carrera_driver(pun);
        }
        else if (i == 1){
            pun -= 7;
            drivers[i].puntos_carrera_driver(pun);
        }
        else if (i >= 2 && i <= 3){
            pun -= 3;
            drivers[i].puntos_carrera_driver(pun);
        }
        else if (i >= 4 && i <= 8){
            pun -= 2;
            drivers[i].puntos_carrera_driver(pun);
        }
        else if (i == 9){
            pun -=1;
            drivers[i].puntos_carrera_driver(pun);
        }
    }
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
        Race(): country(""), circuit_name(""), race_num(0), laps(0), circuit_len(0.0), carrera_st(Standings()){};
        Race(string coun, string cir_name, int ra_num, int lap, float cir_len, Standings sta);

        /* Getters */
        string get_country();
        string get_cricuit_name();
        int get_race_num();
        int get_laps();
        float get_circuit_len();
        Standings get_carrera_st();
        void agregar_driver(Driver);
        void agregrar_team(Team);
        void puntos_carrera();

};

Race :: Race(string coun, string cir_name, int ra_num, int lap, float cir_len, Standings sta){
    country = coun;
    circuit_name = cir_name;
    race_num = ra_num;
    laps = lap;
    circuit_len = cir_len;
    carrera_st = sta;
    carrera_st.init_puntos_carrera();
}

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

Standings Race :: get_carrera_st(){
    return carrera_st;
}

void Race :: agregar_driver(Driver nuevo){
    carrera_st.agregar_driver(nuevo);
}

void Race :: agregrar_team(Team nuevo){
    carrera_st.agregrar_team(nuevo);
}

void Race :: puntos_carrera(){
    carrera_st.puntos_carrera();
}