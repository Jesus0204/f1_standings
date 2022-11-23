#include <iostream>

using namespace std;

#include "Race_Standings.h"

void menu(){
    /* Imprimir el menu */
    cout << "\nMenu:\n";
    cout << "1. Agregar carrera.\n";
    cout << "2. Consultar campeonato.\n";
    cout << "3. Consultar todos los datos de un equipo\n";
    cout << "4. Consultar todos los datos de un piloto\n";
    cout << "5. Consultar carrera.\n";
    cout << "6. Consultar cada carrera del campeonato. \n";
    cout << "7. Salir.\n\n";
}

int main(){

    Championship championship_2022;

    /* Buscar el nombre de cada piloto */
    Driver driver1("Sergio Perez", "Mexicano", "Oracle Red Bull Racing", 11, 500);
    Driver driver2("Max Verstappen", "Neerlandes", "Oracle Red Bull Racing", 7, 617.6);
    Driver driver3("Sebasian Vettel", "Alemán", "Aston Martin", 15, 217.6);
    Driver driver4("Charles Leclerc", "Monagesque", "Ferrari", 6, 445.8);
    Driver driver5("Carlos Sainz", "Español", "Ferrari", 5, 323.5);

    Team_Principal tp1("Cristian Horner", "Inglesa", "Red Bull Racing", 17, 84);
    Team_Principal tp2("Mattia Binotto", "Suizo", "Ferrari", 7, 15);

    /* Buscar el nombre del piloto #1 del equipo*/
    Team team1("Oracle Red Bull Racing", driver1, driver2, tp1);
    Team team2("Ferrari", driver4, driver5, tp2);
    Driver list[5] = {driver1, driver2, driver3, driver4, driver5};
    
    /* Crear el objeto con la lista sin los puntajes */
    Standings standing_limpio(list, 5);
    standing_limpio.agregar_team(team1);
    /* Agregar piloto y equipo para probar el método */
    standing_limpio.agregar_team(team2);

    Race ra1("Mexico", "Autodromo Hermanos Rodriguez", 1, 71, 4.304, standing_limpio);
    championship_2022.agregar_race(ra1);
    championship_2022.agregar_team(team1);
    championship_2022.agregar_team(team2);

    championship_2022.agregar_driver(driver1);
    championship_2022.agregar_driver(driver2);
    championship_2022.agregar_driver(driver3);
    championship_2022.agregar_driver(driver4);
    championship_2022.agregar_driver(driver5);

    cout << "\nBienvenido a la calculadora oficial de campeonatos de F1©! Comenzemos!!\n";

    int opcion = 1;
    string pais, nom_cir;
    int ra_num = 0, lap = 0;
    float cir_len;
    while (opcion >= 1 && opcion <= 6){
        menu();
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion){
            case 1: {
                // Checar porque no funiona string con espacios!!!!
                cout << "\nEscribe el país donde se corrió: ";
                /* Solución para sacar input con espacio sacado de https://www.geeksforgeeks.org/problem-with-getline-after-cin/ */
                getline(cin >> ws, pais);
                cout << "\nEscribe el nombre del circuito: ";
                getline(cin >> ws, nom_cir);
                cout << "\nEscribe el número de vueltas del circuito: ";
                cin >> lap;
                cout << "\nEscribe la longitud del circuito: ";
                cin >> cir_len;

                cout << "\nAhora, para especificar los lugares que quedaron los pilotos, favor de escribir el numero a lado del piloto";
                cout << "\nEsta lista no representa los lugares de la carrera, solo fueron acomodados por orden de campeonato actual.\n\n";

                Race ra(pais, nom_cir, championship_2022.get_tam_races() + 1, lap, cir_len, standing_limpio);
                championship_2022.agregar_race(ra);

                championship_2022.carrera_championship(ra);

                cout << "\nListo!! Ya quedó agregada la carrera!\n";
                break;
            }

            case 2:
                /* Actualizar la lista en base a los puntos e imprimirlo con la función */
                championship_2022.update_order_drivers();
                championship_2022.update_order_teams();
                championship_2022.consultar_standing();
                break;

            case 3: 
                cout << "\nEstos son los equipos que puedes elegir. Por favor escoge el numero de dicho equipo. \n";
                championship_2022.print_teams();

                int eq;
                cout << "Opción: ";
                cin >> eq;
                championship_2022.consultar_team(eq);
                break;

            case 4: 
                cout << "\nEstos son los pilotos que puedes elegir. Por favor escoge el número de dicho piloto. \n";
                championship_2022.print_drivers();

                int pil;
                cout << "Opción: ";
                cin >> pil;
                championship_2022.consultar_driver(pil);
                break;

            case 5: {
                /* Pedir el numero de carrera para consutar sus datos */
                cout << "\nEscribe el número de carrera que quieres buscar: ";
                int carrera_num;
                cin >> carrera_num;

                /* Imprimir los datos de la carrera */
                championship_2022.consultar_race(carrera_num);
                break;
            }
            case 6:
                /* Imprimir todos los datos de todas las carreras */
                championship_2022.print_races();
        }
    }

    cout << "Gracias por usar el programa!!! \n";

    return 0;

    // Checar si funcionan los constructores por default cuando los uso en otra clase
}