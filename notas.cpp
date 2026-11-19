#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    char respuesta = 's';

    // Este while permite repetir el programa para otro grupo
    while (respuesta == 's' || respuesta == 'S')
    {
        int cantidadEstudiantes;
        int aprobados = 0;
        int reprobados = 0;

        double sumaPromedios = 0;
        double promedioGeneral;
        double promedioMayor = -1;

        string nombre;
        string nombreMejor;

        // Solicitar la cantidad de estudiantes y validar que sea mayor que 0
        cout << "Cantidad de estudiantes: ";
        cin >> cantidadEstudiantes;

        while (cantidadEstudiantes <= 0)
        {
            cout << "Cantidad invalida. Ingrese un numero mayor que 0: ";
            cin >> cantidadEstudiantes;
        }

        // Este for permite recorrer todos los estudiantes
        for (int estudiante = 1; estudiante <= cantidadEstudiantes; estudiante++)
        {
            double nota;
            double sumaNotas = 0;
            double promedio;

            cout << "\n--- Estudiante " << estudiante << " ---" << endl;

            cout << "Nombre completo: ";
            getline(cin >> ws, nombre); // Permite leer nombres con espacios

            // Este for permite solicitar las 4 calificaciones
            for (int i = 1; i <= 4; i++)
            {
                cout << "Calificacion " << i << ": ";
                cin >> nota;

                // Este while valida que cada calificacion este entre 0 y 100
                while (nota < 0 || nota > 100)
                {
                    cout << "Nota invalida. Ingrese una nota entre 0 y 100: ";
                    cin >> nota;
                }

                sumaNotas = sumaNotas + nota;
            }

            // Calcular el promedio del estudiante
            promedio = sumaNotas / 4.0;

            cout << fixed << setprecision(2);
            cout << "Promedio: " << promedio;

            // Determinar si el estudiante aprobo o reprobo
            if (promedio >= 70)
            {
                cout << " - Aprobado" << endl;
                aprobados++;
            }
            else
            {
                cout << " - Reprobado" << endl;
                reprobados++;
            }

            // Acumular los promedios de todos los estudiantes
            sumaPromedios = sumaPromedios + promedio;

            // Identificar al estudiante con el promedio mas alto
            if (promedio > promedioMayor)
            {
                promedioMayor = promedio;
                nombreMejor = nombre;
            }
        }

        // Calcular el promedio general del grupo
        promedioGeneral = sumaPromedios / cantidadEstudiantes;

        // Mostrar el resumen final
        cout << "\n========== RESUMEN ==========" << endl;
        cout << fixed << setprecision(2);
        cout << "Aprobados: " << aprobados << endl;
        cout << "Reprobados: " << reprobados << endl;
        cout << "Promedio del grupo: " << promedioGeneral << endl;
        cout << "Mejor promedio: " << nombreMejor
             << " (" << promedioMayor << ")" << endl;

        // Preguntar si desea procesar otro grupo
        cout << "\nDesea procesar otro grupo? (s/n): ";
        cin >> respuesta;
    }

    cout << "\nPrograma finalizado." << endl;

    return 0;
}