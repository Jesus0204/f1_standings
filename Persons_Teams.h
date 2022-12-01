/*
 * Proyecto Calculadora Campeonato de Formula 1
 * Jesús Alejandro Cedillo Zertuche
 * A01705442
 * 2/11/2022
 */

/*
 * Clase Persona contiene métodos y datos para una persona
 * Tiene 2 clases hijas con diferentes tipos de atributos: Drivers y Team_Principal
 * También clase Equipo (clase más compleja), que tiene a 2 Drivers, y a un Team_Principal por agregación
 */

#ifndef PERSONS_TEAMS_H_
#define PERSONS_TEAMS_H_

#include <iostream>

using namespace std;

class Persona {
    protected:
        // Atributos de la clase
        string nombre;
        string nacionalidad;
        string escuderia;
        int activo;
    public:
        // Constructor por default
        Persona(): nombre(""), nacionalidad(""), escuderia(""), activo(0){};
        // Constructor parametrizado
        Persona(string nom, string nacio, string esc, int acti): nombre(nom), nacionalidad(nacio), escuderia(esc), activo(acti){};
        // Métodos de la clase
        string get_nombre();
        string get_escuderia();
        void print_data();
};

/**
 * getter nombre
 * @return string: nombre de persona
 */
string Persona :: get_nombre(){
    return nombre;
}

/**
 * getter escuderia
 * @return string: escuderia de persona
 */
string Persona :: get_escuderia(){
    return escuderia;
}

/**
 * Imprime los datos de la persona
 * @return 
 */
void Persona :: print_data(){
    cout << "\nSu nombre es: " << nombre;
    cout << "\nSu nacionalidad es: " << nacionalidad;
    cout << "\nEstá en la escudería: " << escuderia;
    cout << "\nLleva " << activo << " años en la Fórmula 1";
}

// Clase Driver que hereda de persona
class Driver: public Persona {
    private:
        // Atributos de la clase
        float puntos;
    public:
        // Constructor por default
        Driver(): puntos(0.0), Persona(){};
        // Constructor parametrizado
        Driver(string nom, string nacio, string esc, int acti, float pun): Persona(nom, nacio, esc, acti), puntos(pun){};
        // Métodos de la clase
        float get_puntos();
        void setpuntos_carrera_driver(float);
        void sumar_puntos_carrera(float);
        void print_driver();
};

/**
 * getter puntos
 * @return int: puntos de Driver
 */
float Driver :: get_puntos(){
    return puntos;
}

/**
 * setter puntos
 * @param float pun_nuevo: puntos nuevos de driver
 * @return 
 */
void Driver :: setpuntos_carrera_driver(float pun_nuevo){
    puntos = pun_nuevo;
}

/**
 * suma los puntos para una carrera
 * @param float pun_nuevo: puntos para sumar de driver
 */
void Driver :: sumar_puntos_carrera(float pun_nuevo){
    puntos += pun_nuevo;
}

/**
 * Imprime los datos del Driver
 * @return 
*/
void Driver :: print_driver(){
    print_data();
    cout << "\nY actualmente tiene " << puntos << " puntos.\n\n";
}


// Clase Team_Pricipal que hereda de Persona
class Team_Principal: public Persona {
    private:
        // Atributos de la clase
        int triunfos_tp;
    public:
        // Constructores por default
        Team_Principal(): Persona(), triunfos_tp(0){};
        // Constructor parametrizado
        Team_Principal(string nom, string nacio, string esc, int acti, int wins): Persona(nom, nacio, esc, acti), triunfos_tp(wins){};
        // Métodos de la clase
        void print_team_tp();
        void sumar_win();
};

/**
 * Imprime los datos del Team_Principal
 * @return 
*/
void Team_Principal :: print_team_tp(){
    print_data();
    cout << "\nY actualmente tiene " << triunfos_tp << " carreras ganadas como Team principal.\n\n";
}

/**
 * Imprime los datos del Driver
 * @return 
*/
void Team_Principal :: sumar_win(){
    triunfos_tp += 1;
}

// Clase Team que tiene a dos Drivers y un Team_Principal por agregación
class Team {
    private:
        // Atributos de la clase
        string nombre_eq_completo;
        Driver piloto1;
        Driver piloto2;
        Team_Principal name_tp;
        float puntos_totales;
    public:
        // Constructor por default
        Team(): nombre_eq_completo(""), piloto1(Driver()), piloto2(Driver()), name_tp(Team_Principal()), puntos_totales(0){};
        Team(string, Driver, Driver, Team_Principal);
        // Métodos de la clase
        string get_nombre_eq();
        float get_puntos_totales();
        void win_tp();
        void actualizar_driver1(Driver);
        void actualizar_driver2(Driver);
        void print_team();
};

/**
 * Constructor donde recibe valores para llenar las atributos
 * @param string nombre: Nombre del equipo
 * @param Driver pil1: Piloto 1 del equipo
 * @param Driver pil2: Piloto 2 del equipo
 * @param Team_Principal teamp: El team principal del equipo
 * @return 
*/
Team :: Team(string nombre, Driver pil1, Driver pil2, Team_Principal teamp){
    nombre_eq_completo = nombre;
    piloto1 = pil1;
    piloto2 = pil2;
    name_tp = teamp;
    float punt_dri1 = piloto1.get_puntos();
    float punt_dri2 = piloto2.get_puntos();
    puntos_totales = punt_dri1 + punt_dri2;
}

/**
 * getter nombre equipo
 * @return string: nombre del equipo
 */
string Team :: get_nombre_eq(){
    return nombre_eq_completo;
}

/**
 * getter puntos_totales
 * @return int puntos_totales: puntos del equipo
 */
float Team :: get_puntos_totales(){
    float punt_dri1 = piloto1.get_puntos();
    float punt_dri2 = piloto2.get_puntos();
    puntos_totales = punt_dri1 + punt_dri2;
    return puntos_totales;
}

/**
 * Sumar el win del team principal
 * @return 
 */
void Team :: win_tp(){
    name_tp.sumar_win();
}

/**
 * Actualizar el piloto #1 con los nuevos puntos
 * @param Driver nuevo: piloto con info actualizada
 * @return 
 */
void Team :: actualizar_driver1(Driver nuevo){
    piloto1 = nuevo;
}

/**
 * Actualizar el piloto #2 con los nuevos puntos
 * @param Driver nuevo: piloto con info actualizada
 * @return 
 */
void Team :: actualizar_driver2(Driver nuevo){
    piloto2 = nuevo;
}

/**
 * Imprime los datos del Equipo
 * @return 
*/
void Team :: print_team(){
    cout << "\nEl nombre completo del equipo es: " << nombre_eq_completo;
    cout << "\n\nLos datos del piloto #1:";
    piloto1.print_driver();
    cout << "\nLos datos del piloto #2:";
    piloto2.print_driver();
    cout << "\nLos datos del Team Principal son:";
    name_tp.print_team_tp();
    cout << "\nY los puntos totales del equipo son: " << puntos_totales << "\n\n";
}

#endif