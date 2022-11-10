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
        Persona(string, string, string, int);
        string get_nombre();
        string get_nacionalidad();
        string get_escuderia();
        int get_activo();
};

Persona :: Persona(string nom, string nacio, string esc, int acti){
    nombre = nom;
    nacionalidad = nacio;
    escuderia = esc;
    activo = acti;
}

string Persona :: get_nombre(){
    return nombre;
}

string Persona :: get_nacionalidad(){
    return nacionalidad;
}

string Persona :: get_escuderia(){
    return escuderia;
}

int Persona :: get_activo(){
    return activo;
}



class Driver: public Persona {
    private:
        float puntos;
    public:
        Driver();
        Driver(string, string, string, int, float);
        string get_nombre();
        string get_nacionalidad();
        string get_escuderia();
        int get_activo();
        float get_puntos();
        void puntos_carrera_driver(float);
};

Driver :: Driver(){
    nombre = "";
    nacionalidad = "";
    escuderia = "";
    activo = 0;
    puntos = 0.0;
}

Driver :: Driver(string nom, string nacio, string esc, int acti, float pun){
    nombre = nom;
    nacionalidad = nacio;
    escuderia = esc;
    activo = acti;
    puntos = pun;
}

string Driver :: get_nombre(){
    return nombre;
}

string Driver :: get_nacionalidad(){
    return nacionalidad;
}

string Driver :: get_escuderia(){
    return escuderia;
}

int Driver :: get_activo(){
    return activo;

}
float Driver :: get_puntos(){
    return puntos;
}

void Driver :: puntos_carrera_driver(float pun_nuevo){
    puntos = pun_nuevo;
}



class Team_Principal: public Persona {
    private:
    /* Triunfos como team principal */
        int triunfos_tp;
    public:
        Team_Principal();
        Team_Principal(string, string, string, int, int);
        string get_nombre();
        string get_nacionalidad();
        string get_escuderia();
        int get_activo();
};

Team_Principal :: Team_Principal(){
    nombre = "";
    nacionalidad = "";
    escuderia = "";
    activo = 0;
    triunfos_tp = 0;
}

Team_Principal :: Team_Principal(string nom, string nacio, string esc, int acti, int wins){
    nombre = nom;
    nacionalidad = nacio;
    escuderia = esc;
    activo = acti;
    triunfos_tp = wins;
}

string Team_Principal :: get_nombre(){
    return nombre;
}

string Team_Principal :: get_nacionalidad(){
    return nacionalidad;
}

string Team_Principal :: get_escuderia(){
    return escuderia;
}

int Team_Principal :: get_activo(){
    return activo;
}


class Team {
    private:
        string nombre_eq;
        Driver piloto1;
        Driver piloto2;
        Team_Principal name_tp;
        float puntos_totales;
    public:
        Team(): nombre_eq(""), piloto1(Driver()), piloto2(Driver()), name_tp(Team_Principal()), puntos_totales(0){};
        Team(string, Driver, Driver, Team_Principal);
        string get_nombre_eq();
        Driver get_piloto1();
        Driver get_piloto2();
        Team_Principal get_name_tp();
        float get_puntos_totales();
};

Team :: Team(string nombre, Driver pil1, Driver pil2, Team_Principal teamp){
    nombre_eq = nombre;
    piloto1 = pil1;
    piloto2 = pil2;
    name_tp = teamp;
    float punt_dri1 = piloto1.get_puntos();
    float punt_dri2 = piloto2.get_puntos();
    puntos_totales = punt_dri1 + punt_dri2;
}

string Team :: get_nombre_eq(){
    return nombre_eq;
}

Driver Team :: get_piloto1(){
    return piloto1;
}

Driver Team :: get_piloto2(){
    return piloto2;
}

Team_Principal Team :: get_name_tp(){
    return name_tp;
}

float Team :: get_puntos_totales(){
    float punt_dri1 = piloto1.get_puntos();
    float punt_dri2 = piloto2.get_puntos();
    puntos_totales = punt_dri1 + punt_dri2;
    return puntos_totales;
}
