#include <iostream>

using namespace std;

#include "Race_Standings.h"

int main(){
    /* Buscar el nombre de cada piloto */
    Driver driver1("Sergio Perez", "Mexicano", "Red Bull", 11, 500);
    cout << endl << driver1.get_nombre() << endl;

    Driver driver2("Max Verstappen", "Neerlandes", "Red Bull", 7, 617.6);
    cout << driver2.get_nombre() << endl;

    Driver driver3("Sebasian Vettel", "Alemán", "Aston Martin", 15, 217.6);
    cout << driver3.get_nombre() << endl;
    
    Driver driver4("Charles Leclerc", "Monagesque", "Ferarri", 6, 445.8);
    cout << driver4.get_nombre() << endl << endl;

    Team_Principal tp1("Cristian Horner", "Inglesa", "Red Bull Racing", 17, 84);

    /* Buscar el nombre del piloto #1 del equipo*/
    Team team1("Oracle Red Bull Racing", driver1, driver2, tp1 , 0.0);
    /* Como aquí regresa un Driver en el get piloto, tienes que definir que quieres del Driver */
    cout << team1.get_piloto1().get_nombre() << endl << endl;

    Driver list[4] = {driver1, driver2, driver3, driver4};
    
    /* Crear el objeto con la lista sin los puntajes */
    Standings standing1(list, 4);

    Driver driver5("Carlos Sainz", "Español", "Ferarri", 5, 323.5);
    cout << driver5.get_nombre() << endl << endl; 

    /* Agregar piloto para probar el método */
    standing1.agregar_driver(driver5);

    cout << "Pilotos sin ordenar por puntos:" << endl;
    standing1.consultar_driver_standing();
    cout << endl;

    /* En base a los puntos ordenar la lista del mismo objeto */
    standing1.update_driver_championship();
    cout << "Pilotos ordenado con puntos:" << endl;
    standing1.consultar_driver_standing();
    
    return 0;
}