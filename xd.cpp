#include <iostream>
using namespace std;
//importamos para usar la entrada y salida de datos(cin,cout)
int main() {
//inicio de la lista de ternas de datos
//declaro el tipo de dato: como jugadores, juegos y calificaciones.
    const int jugadores = 30;
	const int juegos = 7;
    const int calificaciones = 10;
//declaro vector de premios, declaro matriz de calificaciones y un valor 
//para los que no calificaron
    int premios[juegos];
	int m_calificaciones[jugadores][juegos] = {0};
	int no_calificados = 0;

// Insertamos los datos en el vector de premios 
    cout << "Ingrese los premios en pesos para cada juego:" << endl;
    for (int i = 0; i < juegos; i++) {
        cout << "Premio para el juego " << i + 1 << ": ";
        cin >> premios[i];
        //guardamos en el vector de premios 
    }
   //Insertamos datos en la matriz de calificaciones
    cout << endl << "Ingrese las calificaciones de los jugadores en cada juego:" << endl;
    int jugador, juego, calificacion;

	while (true) {
        cout << "Ingrese el numero de jugador (0 para finalizar): ";
        cin >> jugador;
        if (jugador == 0) {
            break;
        //si el numero de jugador es 0 salimos de la matriz de 
        //calificaciones y vamos con el ingreso de los numeros de juego
        }
        cout << "Ingrese el numero de juego: ";
        cin >> juego;
        cout << "Ingrese la calificacion obtenida por el jugador en el juego: ";
        cin >> calificacion;
        //guardamos los valores 

        m_calificaciones[jugador - 1][juego - 1] = calificacion;
    }

    // Calculamos puntaje final y monto por cada jugador
    int puntajefin[jugadores] = {0};
    int monto[jugadores] = {0};
    int jug_calificados = 0;
    //mientras i sea menor a jugadores creamos un bool donde cambia el valor dependiendo si 
   //jugadores estan clasificados o no con sus respectivos puntajes (ciclo anidado)
    for (int i = 0; i < jugadores; i++) {
        bool jugador_calificado = false;
        for (int j = 0; j < juegos; j++) {
            puntajefin[i] += m_calificaciones[i][j];
            if (m_calificaciones[i][j] > 0) {
                jugador_calificado = true;
                if (m_calificaciones[i][j] > 8) {
                    monto[i] += premios[j];
                }
            }
        }
        if (jugador_calificado) {
            jug_calificados++;
        }
    }
    // Calculamos el porcentaje de jugadores no calificados
    double porcentajenocalificado = (static_cast<double>(jugadores - jug_calificados) / jugadores) * 100;

    // Devolvemos puntaje final obtenido por cada jugador en cada juego (ciclo anidado)
    cout << endl << "Puntaje final obtenido por cada jugador en cada juego calificado:" << endl;
    for (int i = 0; i < jugadores; i++) {
        for (int j = 0; j < juegos; j++) {
            if (m_calificaciones[i][j] > 0) {
                cout << "Jugador " << i + 1 << ", juego " << j + 1 << ": " << m_calificaciones[i][j] << endl;
            }
        }
    }
}
//Fin de la lista de ternas de datos
   


