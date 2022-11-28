#ifndef RACE_STANDINGS_H_
#define RACE_STANDINGS_H_

#include <iostream>

using namespace std;

#include "Persons_Teams.h"

class Standings {
    protected:
        Driver drivers[50];
        Team equipo[25];
        int tam_driver;
        int tam_equipo;
    public:
        /* Contructores */
        Standings();

        Driver get_driver(int);

        /* Setter */
        void agregar_driver(Driver);
        void agregar_team(Team);

        /* Métodos*/
        void update_order_drivers();
        void update_order_teams();
        void print_drivers();
        void consultar_standing();
        void set_puntos_carrera();
        void actualizar_drivers_equipo();
};

Standings :: Standings(){
    tam_driver = 0;
    tam_equipo = 0;
}

void Standings :: agregar_driver(Driver nuevo){
    /* Usar el tamaño actual, ya que los indices de listas se le resta 1 */
    drivers[tam_driver] = nuevo;
    /* Actualizar el tamaño */
    tam_driver += 1;
}

Driver Standings :: get_driver(int pos){
    return drivers[pos];
}

void Standings :: agregar_team(Team nuevo){
    /* Usar el tamaño actual, ya que los indices de listas se le resta 1 */
    equipo[tam_equipo] = nuevo;
    /* Actualizar el tamaño */
    tam_equipo += 1;
}

void Standings :: print_drivers(){
    for (int i = 0; i < tam_driver; i++){
        cout << i+1 << ". " << drivers[i].get_nombre();
        cout << "\n";
    }
    cout << "\n";
}

void Standings :: consultar_standing(){
    cout << "\n";
    cout << "Pilotos: \n";
    for (int i = 0; i < tam_driver; i++){
        string nom_d = drivers[i].get_nombre();
        float pun_d = drivers[i].get_puntos();
        cout << i+1 << ". " << nom_d << ": " << pun_d << " puntos" << endl;
    }
    cout << endl << "Equipos: " << endl;
    for (int i = 0; i < tam_equipo; i++){
        string nom_e = equipo[i].get_nombre_eq();
        float pun_e = equipo[i].get_puntos_totales();
        cout << i+1 << ". " << nom_e << ": " << pun_e << " puntos" << endl;
    }
}

void Standings :: update_order_drivers(){
    /* Crear una lista temporal para no borrar la original */
    Driver temp[50];

    /* Agregar los pilotos y equipos a una lista temporal para ir borrando */
    for (int i = 0; i < tam_driver; i++){
        temp[i] = drivers[i];
    }

    /* PILOTOS */
    int tam_updated_d = tam_driver;
    for (int i = 0; i < tam_driver; i++){
        /* Volver a iniciar el máximo para cuando lista sea más chica */
        int index_max = 0;
        float max = temp[0].get_puntos();
        /* Sacar el puntaje máximo y el indice de la lista de ese puntaje */
        for (int j = 0; j < tam_updated_d; j++){
            if (temp[j].get_puntos() > max){
                max = temp[j].get_puntos();
                index_max = j;
            }
        }
        /* Agregar el indice donde se encontre el puntaje máximo */
        drivers[i] = temp[index_max];

        /* Actualizar el tamaño de la lista temporal */
        tam_updated_d -= 1;
        /* Borras el piloto que fue el máximo para repetir el ciclo */
        for (int k = index_max; k <= tam_updated_d; k++){
            temp[k] = temp[k+1];
        }
    }
}

void Standings :: update_order_teams(){

    Team temp_team[25];

    for (int i = 0; i < tam_equipo; i++){
        temp_team[i] = equipo[i];
    }
    /* EQUIPOS */
    int tam_updated_e = tam_equipo;
    for (int i = 0; i < tam_equipo; i++){
         /* Volver a iniciar el máximo para cuando lista sea más chica */
        int index_max = 0;
        float max = temp_team[0].get_puntos_totales();
        /* Sacar el puntaje máximo y el indice de la lista de ese puntaje */
        for (int j = 0; j < tam_updated_e; j++){
            if (temp_team[j].get_puntos_totales() > max){
                max = temp_team[j].get_puntos_totales();
                index_max = j;
            }
        }
        /* Agregar el indice donde se encontre el puntaje máximo */
        equipo[i] = temp_team[index_max];

        /* Actualizar el tamaño de la lista temporal */
        tam_updated_e -= 1;
        /* Borras el piloto que fue el máximo para repetir el ciclo */
        for (int k = index_max; k <= tam_updated_e; k++){
            temp_team[k] = temp_team[k+1];
        }
    }
}

void Standings :: set_puntos_carrera(){
    Driver temp[50];
    /* Agregar los pilotos y equipos a una lista temporal para ir guardando ahí */
    for (int i = 0; i < tam_driver; i++){
        temp[i] = drivers[i];
    }

    int tam_driver_temp = tam_driver;
    for (int count = 0; count < tam_driver_temp; count++){
        /* Pedir el lugar del piloto */
        int pil_op;
        bool check = true;

        /* Asegurar que el número que se escribe está en la lista */
        while (check == true){
            print_drivers();
            cout << "\nPor favor checa que el número que escribiste sea una opción antes de escribir algo. \n";
            cout << "\nEscribe el piloto que quedo en lugar " << count +1 << ": ";
            cin >> pil_op;
            cout << "\n";

            if (pil_op <= tam_driver && pil_op > 0) {
                check = false;
            }
        }
        /* Pasar ese piloto a la lista temp */
        temp[count] = drivers[pil_op - 1];

        /* Actualizar el tamaño de la lista drivers */
        tam_driver -= 1;
        /* Borras el piloto que fue agregaste para repetir el ciclo */
        for (int k = pil_op - 1; k <= tam_driver; k++){
            drivers[k] = drivers[k+1];
        }
    }

    /* Volver a pasar lo que está en temp como los drivers */
    for (int i = 0; i < tam_driver_temp; i++){
        drivers[i] = temp[i];
    }
    tam_driver = tam_driver_temp;
    
    /* Como estas iniciando carrera, poner puntos en 0 */
    for (int i = 0; i < tam_driver; i++){
        drivers[i].setpuntos_carrera_driver(0.0);
    }

    /* Ya que está la lista en orden, sumar puntos de carrera */
    int pun = 25;
    for (int i = 0; i < tam_driver; i++){
        if (i == 0){
            drivers[i].setpuntos_carrera_driver(pun);
        }
        else if (i == 1){
            pun -= 7;
            drivers[i].setpuntos_carrera_driver(pun);
        }
        else if (i >= 2 && i <= 3){
            pun -= 3;
            drivers[i].setpuntos_carrera_driver(pun);
        }
        else if (i >= 4 && i <= 8){
            pun -= 2;
            drivers[i].setpuntos_carrera_driver(pun);
        }
        else if (i == 9){
            pun -=1;
            drivers[i].setpuntos_carrera_driver(pun);
        }
    }
    actualizar_drivers_equipo();
}

void Standings :: actualizar_drivers_equipo(){

    /* Mete a los pilotos que esta en drivers al equipo para las carreras */
    for (int i = 0; i < tam_equipo; i++){
        /* Volver iniciar la lista para cada equipo*/
        Driver pil[2];
        int count = 0;
        for (int j = 0; j < tam_driver; j++){
            /* Agregar a los dos pilotos */
            if (equipo[i].get_nombre_eq() == drivers[j].get_escuderia()){
                pil[count] = drivers[j];
                count += 1;
            }
        }   
        /* Actualizar los pilotos de objetos teams */
        equipo[i].actualizar_driver1(pil[0]);
        equipo[i].actualizar_driver2(pil[1]);
    }

    /* Cambiar el orden de los equipos para impresión después de haber cambiado los puntos */
    update_order_teams();
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

        Standings get_carrera_st();
        /* Otros métodos */
        void print_datos();

};

Race :: Race(string coun, string cir_name, int ra_num, int lap, float cir_len, Standings sta){
    country = coun;
    circuit_name = cir_name;
    race_num = ra_num;
    laps = lap;
    circuit_len = cir_len;
    carrera_st = sta;
    carrera_st.set_puntos_carrera();
}

Standings Race :: get_carrera_st(){
    return carrera_st;
}

void Race :: print_datos(){
    cout << "\nCarrera #" << race_num << " del año";
    cout << "\nPaís: " << country;
    cout << "\nNombre del circuito: " << circuit_name;
    cout << "\nLongitud del circuito: " << circuit_len << " km";
    cout << "\nNumero de vueltas: " << laps;
    cout << "\n\nPuntos por carrera: \n";

    carrera_st.consultar_standing();
}


class Championship: public Standings {
    private:
        int tam_races;
        Race races[30];
    public:
        /* Constructor, getters y setters */
        Championship(): Standings(), tam_races(0){};
        int get_tam_races();
        void agregar_race(Race);

        /* Otros métodos */
        void print_races();
        void consultar_race(int);
        void print_teams();
        void consultar_team(int);
        void consultar_driver(int);
        void sumar_win_tp(Race);
        void carrera_championship(Race);
};

int Championship :: get_tam_races(){
    return tam_races;
}

void Championship :: agregar_race(Race car) {
    races[tam_races] = car;
    tam_races += 1;
}

void Championship :: print_races(){
    for (int count = 0; count < tam_races; count++){
        races[count].print_datos();
        cout << "\n\n";
    }
}

void Championship :: consultar_race(int race_num){
    /* Quitarle uno para consultar la lista */
    race_num -= 1;
    if (race_num >= 0 && race_num < tam_races){
        races[race_num].print_datos();
    }
    else {
        cout << "\nEl numero que carrera que ingresó no existe. Favor de intentar de nuevo.\n";
    }
}

void Championship :: print_teams(){
    for (int i = 0; i < tam_equipo; i++){
        cout << i+1 << ". " << equipo[i].get_nombre_eq();
        cout << "\n";
    }
    cout << "\n";
}

void Championship :: consultar_team(int nom){
    if (nom > 0 && nom <= tam_equipo){
        equipo[nom-1].print_team();
    }
    else {
        cout << "\nEl equipo que elegiste no existe. Favor de elegir otro.\n";
    }
}

void Championship :: consultar_driver(int nom){
    if (nom > 0 && nom <= tam_driver){
        drivers[nom-1].print_driver();
    }
    else {
        cout << "\nEl piloto que elegiste no existe. Favor de elegir otro.\n";
    }
}

void Championship :: sumar_win_tp(Race car){
    /* Sacar al piloto que ganó la carrera y su escuderia */
    Standings carrera_win = car.get_carrera_st();
    Driver ganador = carrera_win.get_driver(0);
    string escuderia_win = ganador.get_escuderia();

    /* Iterar por cada equipo para buscarlo y actualizar el team principal */
    for (int i = 0; i < tam_equipo; i++){
        if (equipo[i].get_nombre_eq() == escuderia_win){
            equipo[i].win_tp();
        }
    }
}

void Championship :: carrera_championship(Race car){
    Standings carrera_actualizar = car.get_carrera_st();
    for (int i = 0; i < tam_driver; i++){
        for (int j = 0; j < tam_driver; j++){
            /* Sacar la información del objeto standings de la carrera*/
            if (carrera_actualizar.get_driver(i).get_nombre() == drivers[j].get_nombre()){
                /* Con esa información comparar con drivers de championship y sumar puntos */
                drivers[j].sumar_puntos_carrera(carrera_actualizar.get_driver(i).get_puntos());
            }
        }
    }
    /* Actualizar la información de los equipos */
    actualizar_drivers_equipo();

    /* Sumar el win al team principal */
    sumar_win_tp(car);
}

#endif