#include <iostream>

using namespace std;

#include "Race_Standings_Championship.h"

int main(){
    /* Buscar el nombre de cada piloto */
    Driver driver1("Sergio Perez", "Mexicano", "Oracle Red Bull Racing", 11, 500);
    cout << endl << driver1.get_nombre() << endl;

    Driver driver2("Max Verstappen", "Neerlandes", "Oracle Red Bull Racing", 7, 617.6);
    cout << driver2.get_nombre() << endl;

    Driver driver3("Sebasian Vettel", "Alemán", "Aston Martin", 15, 217.6);
    cout << driver3.get_nombre() << endl;
    
    Driver driver4("Charles Leclerc", "Monagesque", "Ferrari", 6, 445.8);
    cout << driver4.get_nombre() << endl << endl;

    Team_Principal tp1("Cristian Horner", "Inglesa", "Red Bull Racing", 17, 84);
    Team_Principal tp2("Mattia Binotto", "Suizo", "Ferrari", 7, 15);

    /* Buscar el nombre del piloto #1 del equipo*/
    Team team1("Oracle Red Bull Racing", driver1, driver2, tp1);
    /* Como aquí regresa un Driver en el get piloto, tienes que definir que quieres del Driver */
    cout << team1.get_piloto1().get_nombre() << endl << endl;

    Driver list[4] = {driver1, driver2, driver3, driver4};
    
    /* Crear el objeto con la lista sin los puntajes */
    Standings standing1(list, 4);

    standing1.agregrar_team(team1);

    Driver driver5("Carlos Sainz", "Español", "Ferrari", 5, 323.5);
    cout << driver5.get_nombre() << endl << endl; 

    /* Crear equipo para comparar */
    Team team2("Ferrari", driver4, driver5, tp2);
    /* Agregar piloto y equipo para probar el método */
    standing1.agregar_driver(driver5);
    standing1.agregrar_team(team2);

    cout << "Pilotos sin ordenar por puntos:" << endl;
    standing1.consultar_standing();
    cout << endl;

    /* En base a los puntos ordenar la lista del mismo objeto */
    standing1.update_championship();
    cout << "Pilotos ordenado con puntos:" << endl;
    standing1.consultar_standing();
    cout << endl;

    /* Crear una carrera para probar igual*/
    Race race1("Mexico", "Autodromo Hermanos Rodriguez", 20, 71, 4.304, standing1);
    cout << race1.get_cricuit_name() << endl;

    /* Agregar un pioto pero solo a la carrera */
    Driver driver6("Mick Schumacher", "Alemán", "Haas", 2, 0);
    race1.agregar_driver(driver6);

    cout << endl << "Puntos hechos en una carrera:" << endl;
    race1.puntos_carrera();
    race1.get_carrera_st().consultar_standing();

    Championship champ;
    champ.get_carrera_st().consultar_standing();
    return 0;
}