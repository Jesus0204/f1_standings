/*
 * Proyecto Calculadora Campeonato de Formula 1
 * Jesús Alejandro Cedillo Zertuche
 * A01705442
 * 2/11/2022
 */

/*
 * Clase Standings con lista de pilotos y equipos
 * Clase Race que tiene un objeto Standings por agregación y tiene la información de una carrera
 * Por último clase Championship que hereda de Standings para tener su lista de pilotos y equipos y poder actualizar campeonato
 * Tiene una lista de carreras que ocurrieron en la pelea por el campeonato
 */

#ifndef RACE_STANDINGS_H_
#define RACE_STANDINGS_H_

#include <iostream>
#include "Persons_Teams.h"

using namespace std;

// Clase Standings
class Standings {
    protected:
        // Atributos de la clase
        Driver drivers[50];
        Team equipo[25];
        int tam_driver;
        int tam_equipo;
    public:
        // Contructores
        Standings();

        // Agregadores
        void agregar_driver(Driver);
        void agregar_team(Team);

        // Getter
        Driver get_driver(int);

        // Métodos
        void print_drivers();
        void consultar_standing();
        void update_order_drivers();
        void update_order_teams();
        void set_puntos_carrera();
        void actualizar_drivers_equipo();
};

/**
 * Constructor único y default
 * @return
*/
Standings :: Standings(){
    tam_driver = 0;
    tam_equipo = 0;
}

/**
 * Agrega un piloto a la lista de drivers
 * @param Driver nuevo: piloto a agregar a la lista
 * @return
*/
void Standings :: agregar_driver(Driver nuevo){
    // Usar el tamaño actual, ya que los indices de listas se le resta 1
    drivers[tam_driver] = nuevo;
    // Actualizar el tamaño
    tam_driver += 1;
}

/**
 * Agrega un equipo a la lista de teams
 * @param Team nuevo: equipo a agregar a la lista
 * @return
*/
void Standings :: agregar_team(Team nuevo){
    // Usar el tamaño actual, ya que los indices de listas se le resta 1
    equipo[tam_equipo] = nuevo;
    // Actualizar el tamaño
    tam_equipo += 1;
}

/**
 * getter driver
 * @param int pos: posición del piloto en la lista
 * @return Driver: piloto en la lista
 */
Driver Standings :: get_driver(int pos){
    return drivers[pos];
}

/**
 * Imprime los nombres de la lista de pilotos
 * @return 
*/
void Standings :: print_drivers(){
    for (int i = 0; i < tam_driver; i++){
        cout << i+1 << ". " << drivers[i].get_nombre();
        cout << "\n";
    }
    cout << "\n";
}

/**
 * Imprime a los pilotos y equipos con sus puntos
 * @return 
 */
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

/**
 * Cambiar el orden de la lista (no los puntos) conforme a los puntos de cada piloto
 * @return 
 */
void Standings :: update_order_drivers(){
    // Crear una lista temporal para no borrar la original
    Driver temp[50];

    // Agregar los pilotos y equipos a una lista temporal para ir borrando
    for (int i = 0; i < tam_driver; i++){
        temp[i] = drivers[i];
    }

    /* PILOTOS */
    int tam_updated_d = tam_driver;
    for (int i = 0; i < tam_driver; i++){
        // Volver a iniciar el máximo para cuando lista sea más chica 
        int index_max = 0;
        float max = temp[0].get_puntos();
        // Sacar el puntaje máximo y el indice de la lista de ese puntaje
        for (int j = 0; j < tam_updated_d; j++){
            if (temp[j].get_puntos() > max){
                max = temp[j].get_puntos();
                index_max = j;
            }
        }
        // Agregar el indice donde se encontre el puntaje máximo
        drivers[i] = temp[index_max];

        // Actualizar el tamaño de la lista temporal
        tam_updated_d -= 1;
        // Borras el piloto que fue el máximo para repetir el ciclo
        for (int k = index_max; k <= tam_updated_d; k++){
            temp[k] = temp[k+1];
        }
    }
}

/**
 * Cambiar el orden de la lista (no lo puntos) conforme a los puntos de cada equipo
 * @return 
 */
void Standings :: update_order_teams(){

    Team temp_team[25];

    for (int i = 0; i < tam_equipo; i++){
        temp_team[i] = equipo[i];
    }
    /* EQUIPOS */
    int tam_updated_e = tam_equipo;
    for (int i = 0; i < tam_equipo; i++){
         // Volver a iniciar el máximo para cuando lista sea más chica
        int index_max = 0;
        float max = temp_team[0].get_puntos_totales();
        // Sacar el puntaje máximo y el indice de la lista de ese puntaje
        for (int j = 0; j < tam_updated_e; j++){
            if (temp_team[j].get_puntos_totales() > max){
                max = temp_team[j].get_puntos_totales();
                index_max = j;
            }
        }
        // Agregar el indice donde se encontre el puntaje máximo
        equipo[i] = temp_team[index_max];

        // Actualizar el tamaño de la lista temporal
        tam_updated_e -= 1;
        // Borras el piloto que fue el máximo para repetir el ciclo
        for (int k = index_max; k <= tam_updated_e; k++){
            temp_team[k] = temp_team[k+1];
        }
    }
}

/**
 * De acuerdo al orden que el usuario ingrese, sumar puntos a los pilotos por el lugar en el que estan
 * @return 
 */
void Standings :: set_puntos_carrera(){
    Driver temp[50];
    // Agregar los pilotos y equipos a una lista temporal para ir guardando ahí
    for (int i = 0; i < tam_driver; i++){
        temp[i] = drivers[i];
    }

    int tam_driver_temp = tam_driver;
    for (int count = 0; count < tam_driver_temp; count++){
        // Pedir el lugar del piloto
        int pil_op;
        bool check = true;

        // Asegurar que el número que se escribe está en la lista
        while (check == true){
            print_drivers();
            cout << "\nPor favor checa que el número que escribiste sea una opción antes de escribir algo. \n";
            cout << "\nEscribe el numero del piloto que quedo en lugar " << count +1 << ": ";
            cin >> pil_op;
            cout << "\n";

            if (pil_op <= tam_driver && pil_op > 0) {
                check = false;
            }
        }
        // Pasar ese piloto a la lista temp
        temp[count] = drivers[pil_op - 1];

        // Actualizar el tamaño de la lista drivers
        tam_driver -= 1;
        // Borras el piloto que fue agregaste para repetir el ciclo 
        for (int k = pil_op - 1; k <= tam_driver; k++){
            drivers[k] = drivers[k+1];
        }
    }

    // Volver a pasar lo que está en temp como los drivers 
    for (int i = 0; i < tam_driver_temp; i++){
        drivers[i] = temp[i];
    }
    tam_driver = tam_driver_temp;
    
    // Como estas iniciando carrera, poner puntos en 0
    for (int i = 0; i < tam_driver; i++){
        drivers[i].setpuntos_carrera_driver(0.0);
    }

    // Ya que está la lista en orden, sumar puntos de carrera
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

/**
 * Actualiza los puntos de los equipos de acuerdo a la lista de pilotos
 * @return 
 */
void Standings :: actualizar_drivers_equipo(){

    // Mete a los pilotos que esta en drivers al equipo para las carreras
    for (int i = 0; i < tam_equipo; i++){
        // Volver iniciar la lista para cada equipo
        Driver pil[2];
        int count = 0;
        for (int j = 0; j < tam_driver; j++){
            // Agregar a los dos pilotos
            if (equipo[i].get_nombre_eq() == drivers[j].get_escuderia()){
                pil[count] = drivers[j];
                count += 1;
            }
        }   
        // Actualizar los pilotos de objetos teams
        equipo[i].actualizar_driver1(pil[0]);
        equipo[i].actualizar_driver2(pil[1]);
    }

    // Cambiar el orden de los equipos para impresión después de haber cambiado los puntos
    update_order_teams();
}



class Race {
    private:
        // Atributos de la clase
        string country;
        string circuit_name;
        int race_num;
        int laps;
        float circuit_len;
        Standings carrera_st;
    public:
        // Constructor por default
        Race(): country(""), circuit_name(""), race_num(0), laps(0), circuit_len(0.0), carrera_st(Standings()){};
        Race(string coun, string cir_name, int ra_num, int lap, float cir_len, Standings sta);

        // Otros métodos y getters
        Standings get_carrera_st();
        void print_datos();

};

/**
 * Constructor donde recibe valores para llenar las atributos
 * @param string coun: País de la carrera
 * @param string cir_name: Nombre del circuito
 * @param int ra_num: Número de carrera
 * @param int lap: Número de vueltas
 * @param float cir_len: Longitud del circuito
 * @param Standings sta: objeto de los luagres de los equipos y los pilotos
 * @return 
*/
Race :: Race(string coun, string cir_name, int ra_num, int lap, float cir_len, Standings sta){
    country = coun;
    circuit_name = cir_name;
    race_num = ra_num;
    laps = lap;
    circuit_len = cir_len;
    carrera_st = sta;
    carrera_st.set_puntos_carrera();
}

/**
 * getter Standing
 * @return Standing carrera_st: standing de la carrera
 */
Standings Race :: get_carrera_st(){
    return carrera_st;
}

/**
 * Imprime los datos de la carrera
 * @return 
*/
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
        // Constructor por default
        Championship(): Standings(), tam_races(0){};

        // Getters y setters
        int get_tam_races();
        void agregar_race(Race);

        // Otros métodos
        void print_races();
        void consultar_race(int);
        void print_teams();
        void consultar_team(int);
        void consultar_driver(int);
        void sumar_win_tp(Race);
        void carrera_championship(Race);
};

/**
 * getter tam_races
 * @return int tam_races: tamaño de la lista de carreras
 */
int Championship :: get_tam_races(){
    return tam_races;
}

/**
 * Agregar una carrera a la lista
 * @param Race car: Carrera con los datos recien insertados
 * @return 
 */
void Championship :: agregar_race(Race car) {
    races[tam_races] = car;
    tam_races += 1;
}

/**
 * Imprimir la lista de carreras
 * @return 
 */
void Championship :: print_races(){
    for (int count = 0; count < tam_races; count++){
        races[count].print_datos();
        cout << "\n\n";
    }
}

/**
 * Consulta e imprime los datos de una carrera si existe
 * @param int race_num: Número de carrera en la lista
 * @return 
 */
void Championship :: consultar_race(int race_num){
    // Quitarle uno para consultar la lista
    race_num -= 1;
    if (race_num >= 0 && race_num < tam_races){
        races[race_num].print_datos();
    }
    else {
        cout << "\nEl numero que carrera que ingresó no existe. Favor de intentar de nuevo.\n";
    }
}

/**
 * Imprimir los nombres de los equipos en la lista
 * @return 
 */
void Championship :: print_teams(){
    for (int i = 0; i < tam_equipo; i++){
        cout << i+1 << ". " << equipo[i].get_nombre_eq();
        cout << "\n";
    }
    cout << "\n";
}

/**
 * Consulta e imprime los datos de un equipo si existe
 * @param int nom: Número del equipo (en la lista)
 * @return 
 */
void Championship :: consultar_team(int nom){
    if (nom > 0 && nom <= tam_equipo){
        equipo[nom-1].print_team();
    }
    else {
        cout << "\nEl equipo que elegiste no existe. Favor de elegir otro.\n";
    }
}

/**
 * Consulta e imprime los datos de un piloto si existe
 * @param int nom: Número del piloto (en la lista)
 * @return 
 */
void Championship :: consultar_driver(int nom){
    if (nom > 0 && nom <= tam_driver){
        drivers[nom-1].print_driver();
    }
    else {
        cout << "\nEl piloto que elegiste no existe. Favor de elegir otro.\n";
    }
}

/**
 * Actualiza el número de race wins del team principal del equipo que ganó la carrera
 * @param Race car: Carrera recién ocurrida
 * @return 
 */
void Championship :: sumar_win_tp(Race car){
    // Sacar al piloto que ganó la carrera y su escuderia
    Standings carrera_win = car.get_carrera_st();
    Driver ganador = carrera_win.get_driver(0);
    string escuderia_win = ganador.get_escuderia();

    // Iterar por cada equipo para buscarlo y actualizar el team principal
    for (int i = 0; i < tam_equipo; i++){
        if (equipo[i].get_nombre_eq() == escuderia_win){
            equipo[i].win_tp();
        }
    }
}

/**
 * Sumar los puntos al campeonato de una carrera recién ocurrida
 * @param Race car: Carrera reién ocurrida
 * @return 
 */
void Championship :: carrera_championship(Race car){
    Standings carrera_actualizar = car.get_carrera_st();
    for (int i = 0; i < tam_driver; i++){
        for (int j = 0; j < tam_driver; j++){
            // Sacar la información del objeto standings de la carrera
            if (carrera_actualizar.get_driver(i).get_nombre() == drivers[j].get_nombre()){
                // Con esa información comparar con drivers de championship y sumar puntos
                drivers[j].sumar_puntos_carrera(carrera_actualizar.get_driver(i).get_puntos());
            }
        }
    }
    // Actualizar la información de los equipos
    actualizar_drivers_equipo();

    // Sumar el win al team principal
    sumar_win_tp(car);
}

#endif