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

/* Poner la lista de los pilotos aquí*/
Driver lista_driver(int num){
    Driver driver1("Sergio Perez", "Mexicano", "Oracle Red Bull Racing", 12, 0);
    Driver driver2("Max Verstappen", "Neerlandes", "Oracle Red Bull Racing", 8, 0);
    Driver driver3("Sebasian Vettel", "Alemán", "Aston Martin", 16, 0);
    Driver driver4("Lance Stroll", "Canadiense", "Aston Martin", 6, 0);
    Driver driver5("Charles Leclerc", "Monagesque", "Ferrari", 5, 0);
    Driver driver6("Carlos Sainz", "Español", "Ferrari", 8, 0);
    Driver driver7("Lewis Hamilton", "Inglés", "Mercedes", 15, 0);
    Driver driver8("George Russell", "Inglés", "Mercedes", 4, 0);
    Driver driver9("Lando Norris", "Inglés", "McLaren", 4, 0);
    Driver driver10("Daniel Ricciardo", "Australiano", "McLaren", 12, 0);
    Driver driver11("Esteban Ocon", "Francés", "Alpine", 7, 0);
    Driver driver12("Fernando Alonso", "Español", "Alpine", 19, 0);
    Driver driver13("Yuki Tsunoda", "Japonés", "AlphaTauri", 2, 0);
    Driver driver14("Pierre Gasly", "Francés", "AlphaTauri", 6, 0);
    Driver driver15("Zhou Guanyu", "Chino", "Alfa Romeo", 1, 0);
    Driver driver16("Valtteri Bottas", "Finés", "Alfa Romeo", 10, 0);
    Driver driver17("Kevin Magnussen", "Danés", "Haas", 8, 0);
    Driver driver18("Mick Schumacher", "Alemán", "Haas", 2, 0);
    Driver driver19("Nicholas Latifi", "Canadiense", "Williams", 3, 0);
    Driver driver20("Alexander Albon", "Tailandés", "Williams", 3, 0);

    Driver lista[20] = {driver1, driver2, driver3, driver4, driver5, driver6, driver7, driver8, driver9, driver10,
    driver11, driver12, driver13, driver14, driver15, driver16, driver17, driver18, driver19, driver20};

    return lista[num];
}

/* La lista de team principals que regresa un elemento de la lista */
Team_Principal lista_team_tp(int num){
    /* Los datos fueron investigados en Internet y son recientes */
    Team_Principal tp1("Cristian Horner", "Inglesa", "Oracle Red Bull Racing", 18, 84);
    Team_Principal tp2("Mike Krack", "Luxemburgués", "Aston Martin", 1, 0);
    Team_Principal tp3("Mattia Binotto", "Suizo", "Ferrari", 28, 7);
    Team_Principal tp4("Toto Wolff", "Autriaco", "Mercedes", 10, 114);
    Team_Principal tp5("Otmar Szafnauer", "Rumano", "Alpine", 1, 0);
    Team_Principal tp6("Andreas Seidl", "Alemán", "McLaren", 4, 1);
    Team_Principal tp7("Franz Tost", "Austriaco", "AlphaTauri", 18, 2);
    Team_Principal tp8("Frederic Vasseur", "Francés", "Alfa Romeo", 6, 0);
    Team_Principal tp9("Gunther Steiner", "Italiano/Americano", "Haas", 9, 0);
    Team_Principal tp10("Jost Capito", "Alemán", "Williams", 3, 0);

    Team_Principal lista[10] = {tp1, tp2, tp3, tp4, tp5, tp6, tp7, tp8, tp9, tp10};

    return lista[num];
}

Team lista_team(int num){
    /* Crear los equipos con las funciones que estan arriba */
    Team team1("Oracle Red Bull Racing", lista_driver(0), lista_driver(1), lista_team_tp(0));
    Team team2("Aston Martin", lista_driver(2), lista_driver(3), lista_team_tp(1));
    Team team3("Ferrari", lista_driver(4), lista_driver(5), lista_team_tp(2));
    Team team4("Mercedes", lista_driver(6), lista_driver(7), lista_team_tp(3));
    Team team5("Alpine", lista_driver(8), lista_driver(9), lista_team_tp(4));
    Team team6("McLaren", lista_driver(10), lista_driver(11), lista_team_tp(5));
    Team team7("AlphaTauri", lista_driver(12), lista_driver(13), lista_team_tp(6));
    Team team8("Alfa Romeo", lista_driver(14), lista_driver(15), lista_team_tp(7));
    Team team9("Haas", lista_driver(16), lista_driver(17), lista_team_tp(8));
    Team team10("Williams", lista_driver(18), lista_driver(19), lista_team_tp(9));

    Team lista[10] = {team1, team2, team3, team4, team5, team6, team7, team8, team9, team10};

    return lista[num];
}

int main(){

    Championship championship_2022;

    /* Crear el objeto con la lista sin los puntajes */
    Standings standing_limpio;

    /* Agregar todos los pilotos a championship y al standing */
    for (int i = 0; i < 20; i++){
        championship_2022.agregar_driver(lista_driver(i));
        standing_limpio.agregar_driver(lista_driver(i));
    }

    /* Agregrar todos los equipos a championship y al standing */
    for (int i = 0; i < 10; i++){
        championship_2022.agregar_team(lista_team(i));
        standing_limpio.agregar_team(lista_team(i));
    }

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
}