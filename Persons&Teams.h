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
        float get_puntos();
        void setpuntos_carrera_driver(float);
        void sumar_puntos_carrera(float);
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

float Driver :: get_puntos(){
    return puntos;
}

void Driver :: setpuntos_carrera_driver(float pun_nuevo){
    puntos = pun_nuevo;
}

void Driver :: sumar_puntos_carrera(float pun_nuevo){
    puntos += pun_nuevo;
}



class Team_Principal: public Persona {
    private:
    /* Triunfos como team principal */
        int triunfos_tp;
    public:
        Team_Principal();
        Team_Principal(string, string, string, int, int);
        int get_triunfos();
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

int Team_Principal :: get_triunfos(){
    return triunfos_tp;
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
        Driver get_piloto1();
        Driver get_piloto2();
        Team_Principal get_name_tp();
        float get_puntos_totales();
        void actualizar_driver1(Driver);
        void actualizar_driver2(Driver);
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

void Team :: actualizar_driver1(Driver nuevo){
    piloto1 = nuevo;
}

void Team :: actualizar_driver2(Driver nuevo){
    piloto2 = nuevo;
}
