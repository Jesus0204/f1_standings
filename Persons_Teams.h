#ifndef PERSONS_TEAMS_H_
#define PERSONS_TEAMS_H_

#include <iostream>

using namespace std;

class Persona {
    protected:
        string nombre;
        string nacionalidad;
        string escuderia;
        int activo;
    public:
        Persona(): nombre(""), nacionalidad(""), escuderia(""), activo(0){};
        Persona(string nom, string nacio, string esc, int acti): nombre(nom), nacionalidad(nacio), escuderia(esc), activo(acti){};
        string get_nombre();
        string get_escuderia();
        void print_data();
};

string Persona :: get_nombre(){
    return nombre;
}

string Persona :: get_escuderia(){
    return escuderia;
}

void Persona :: print_data(){
    cout << "\nSu nombre es: " << nombre;
    cout << "\nSu nacionalidad es: " << nacionalidad;
    cout << "\nEstá en la escudería: " << escuderia;
    cout << "\nLleva " << activo << " años en la Fórmula 1";
}


class Driver: public Persona {
    private:
        float puntos;
    public:
        Driver(): puntos(0.0), Persona(){};
        Driver(string nom, string nacio, string esc, int acti, float pun): Persona(nom, nacio, esc, acti), puntos(pun){};
        float get_puntos();
        void setpuntos_carrera_driver(float);
        void sumar_puntos_carrera(float);
        void print_driver();
};

float Driver :: get_puntos(){
    return puntos;
}

void Driver :: setpuntos_carrera_driver(float pun_nuevo){
    puntos = pun_nuevo;
}

void Driver :: sumar_puntos_carrera(float pun_nuevo){
    puntos += pun_nuevo;
}

void Driver :: print_driver(){
    print_data();
    cout << "\nY actualmente tiene " << puntos << " puntos.\n\n";
}



class Team_Principal: public Persona {
    private:
    /* Triunfos como team principal */
        int triunfos_tp;
    public:
        Team_Principal(): Persona(), triunfos_tp(0){};
        Team_Principal(string nom, string nacio, string esc, int acti, int wins): Persona(nom, nacio, esc, acti), triunfos_tp(wins){};
        void print_team_tp();
        void sumar_win();
};

void Team_Principal :: print_team_tp(){
    print_data();
    cout << "\nY actualmente tiene " << triunfos_tp << " carreras ganadas como Team principal.\n\n";
}

void Team_Principal :: sumar_win(){
    triunfos_tp += 1;
}


class Team {
    private:
        string nombre_eq_completo;
        Driver piloto1;
        Driver piloto2;
        Team_Principal name_tp;
        float puntos_totales;
    public:
        Team(): nombre_eq_completo(""), piloto1(Driver()), piloto2(Driver()), name_tp(Team_Principal()), puntos_totales(0){};
        Team(string, Driver, Driver, Team_Principal);
        string get_nombre_eq();
        float get_puntos_totales();
        void win_tp();
        void actualizar_driver1(Driver);
        void actualizar_driver2(Driver);
        void print_team();
};

Team :: Team(string nombre, Driver pil1, Driver pil2, Team_Principal teamp){
    nombre_eq_completo = nombre;
    piloto1 = pil1;
    piloto2 = pil2;
    name_tp = teamp;
    float punt_dri1 = piloto1.get_puntos();
    float punt_dri2 = piloto2.get_puntos();
    puntos_totales = punt_dri1 + punt_dri2;
}

string Team :: get_nombre_eq(){
    return nombre_eq_completo;
}

float Team :: get_puntos_totales(){
    float punt_dri1 = piloto1.get_puntos();
    float punt_dri2 = piloto2.get_puntos();
    puntos_totales = punt_dri1 + punt_dri2;
    return puntos_totales;
}

void Team :: win_tp(){
    name_tp.sumar_win();
}

void Team :: actualizar_driver1(Driver nuevo){
    piloto1 = nuevo;
}

void Team :: actualizar_driver2(Driver nuevo){
    piloto2 = nuevo;
}

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