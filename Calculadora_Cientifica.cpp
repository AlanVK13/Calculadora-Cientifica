#include <iostream> // Para entrada (cin) y salida (cout)
#include <cmath>     // Para operaciones matemáticas (pow, sqrt)
#include <stdexcept> // Para las clases de excepción estándar (runtime_error, domain_error)
#include <limits>    // Para limpiar el buffer de entrada (cin.ignore)

// Usamos el espacio de nombres std para no tener que escribir std::cout, std::cin, etc.
using namespace std;

/*
 * --- Prototipos de Funciones ---
 * Es una buena práctica declarar las funciones antes de 'main' 
 * para que 'main' sepa que existen.
 */

// Operaciones Básicas
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b); // Lanzará excepción

// REQUISITO: Sobrecarga de funciones
// Creamos una segunda versión de 'sumar' que acepta tres parámetros.
double sumar(double a, double b, double c);

// Operaciones Avanzadas
// REQUISITO: Parámetros por omisión
// Si el usuario no da un exponente, por defecto será 2 (calculará el cuadrado).
double potencia(double base, double exponente = 2.0);

// REQUISITO: Raíz (lanzará excepción)
double raizCuadrada(double n);

// REQUISITO: Factorial (Recursivo)
// Usamos 'unsigned long long' para poder manejar números más grandes.
unsigned long long factorial(int n); // Lanzará excepción y será recursiva


/*
 * --- Función Principal (main) ---
 * Este es el punto de entrada de nuestro programa.
 * Contiene el menú y la lógica para llamar a las funciones.
 */
int main() {
    int opcion;
    double num1, num2, num3;
    int num_fact;

    // Un bucle 'while(true)' mantiene el programa corriendo hasta que el usuario elija salir.
    while (true) {
        cout << "\n---  Calculadora Cientifica (IS25 Prog. Dinamica) ---" << endl;
        cout << "1. Sumar (2 numeros)" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "--- Operaciones Avanzadas ---" << endl;
        cout << "5. Potencia (base y exponente)" << endl;
        cout << "6. Factorial (Recursivo)" << endl;
        cout << "7. Raiz Cuadrada" << endl;
        cout << "--- Demostracion de Requisitos ---" << endl;
        cout << "8. Sumar (3 numeros)  (DEMO: Sobrecarga)" << endl;
        cout << "9. Calcular Cuadrado    (DEMO: Parametros por Omision)" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Elige una opcion: ";

        // Validamos la entrada para que solo acepte números
        if (!(cin >> opcion)) {
            cout << "\n¡Error! Debes ingresar un numero." << endl;
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            continue; // Vuelve al inicio del bucle
        }

        // Usamos un 'try-catch' general para las operaciones que pueden fallar
        try {
            switch (opcion) {
                case 1: // Suma (2 números)
                    cout << "Ingresa numero 1: "; cin >> num1;
                    cout << "Ingresa numero 2: "; cin >> num2;
                    cout << "Resultado: " << sumar(num1, num2) << endl;
                    break;
                case 2: // Resta
                    cout << "Ingresa numero 1: "; cin >> num1;
                    cout << "Ingresa numero 2: "; cin >> num2;
                    cout << "Resultado: " << restar(num1, num2) << endl;
                    break;
                case 3: // Multiplicación
                    cout << "Ingresa numero 1: "; cin >> num1;
                    cout << "Ingresa numero 2: "; cin >> num2;
                    cout << "Resultado: " << multiplicar(num1, num2) << endl;
                    break;
                case 4: // División
                    cout << "Ingresa numerador: "; cin >> num1;
                    cout << "Ingresa denominador: "; cin >> num2;
                    // La función 'dividir' puede lanzar una excepción
                    cout << "Resultado: " << dividir(num1, num2) << endl;
                    break;
                case 5: // Potencia
                    cout << "Ingresa la base: "; cin >> num1;
                    cout << "Ingresa el exponente: "; cin >> num2;
                    cout << "Resultado: " << potencia(num1, num2) << endl;
                    break;
                case 6: // Factorial
                    cout << "Ingresa un numero (entero >= 0): "; cin >> num_fact;
                    // La función 'factorial' puede lanzar una excepción
                    cout << "Resultado: " << factorial(num_fact) << endl;
                    break;
                case 7: // Raíz Cuadrada
                    cout << "Ingresa un numero: "; cin >> num1;
                    // La función 'raizCuadrada' puede lanzar una excepción
                    cout << "Resultado: " << raizCuadrada(num1) << endl;
                    break;
                
                // --- Casos de Demostración ---
                case 8: // Suma (3 números) - DEMO SOBRECARGA
                    cout << "Ingresa numero 1: "; cin >> num1;
                    cout << "Ingresa numero 2: "; cin >> num2;
                    cout << "Ingresa numero 3: "; cin >> num3;
                    cout << "Resultado (sobrecarga): " << sumar(num1, num2, num3) << endl;
                    break;
                case 9: // Cuadrado - DEMO PARÁMETRO POR OMISIÓN
                    cout << "Ingresa la base: "; cin >> num1;
                    // Llamamos a 'potencia' solo con un número.
                    // El compilador usará el valor por omisión (2.0) para el exponente.
                    cout << "Resultado (param. por omision): " << potencia(num1) << endl;
                    break;
                
                case 0: // Salir
                    cout << "Saliendo del programa. ¡Adios!" << endl;
                    return 0; // Termina el programa
                default:
                    cout << "\n¡Opcion no valida! Intenta de nuevo." << endl;
            }
        }
        // REQUISITO: Manejo de Excepciones
        // Capturamos las excepciones por tipo. 'domain_error' es para errores matemáticos lógicos
        // (ej. raíz negativa), 'runtime_error' es para errores que ocurren en tiempo de ejecución (ej. div/0).
        catch (const domain_error& e) {
            cout << "\nERROR MATEMATICO: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "\nERROR EN EJECUCION: " << e.what() << endl;
        }
        // Un 'catch' genérico para cualquier otra excepción
        catch (const exception& e) {
            cout << "\nERROR INESPERADO: " << e.what() << endl;
        }
    } // Este es el cierre del 'while(true)'

    return 0; // Aunque el bucle es infinito, es buena práctica tener un return

} // <-- CORRECCIÓN: Este es el '}' que faltaba (cierre de int main())


/*
 * --- Implementación de Funciones ---
 */

// --- BÁSICAS ---
double sumar(double a, double b) {
    return a + b;
}

double restar(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

// REQUISITO: Excepción de división por cero
double dividir(double a, double b) {
    if (b == 0) {
        // 'throw' detiene la función y "lanza" un objeto de error
        throw runtime_error("Division por cero no permitida.");
    }
    return a / b;
}

// --- AVANZADAS Y REQUISITOS ---

// REQUISITO: Sobrecarga (implementación)
double sumar(double a, double b, double c) {
    cout << "(Usando funcion sobrecargada de 3 parametros) ";
    return a + b + c;
}

// REQUISITO: Parámetro por omisión (implementación)
double potencia(double base, double exponente) {
    return pow(base, exponente); // 'pow' es de <cmath>
}


// REQUISITO: Excepción de raíz negativa
double raizCuadrada(double n) {
    if (n < 0) {
        // Usamos 'domain_error' que es específico para argumentos matemáticos inválidos
        throw domain_error("No se puede calcular la raiz cuadrada de un numero negativo.");
    }
    return sqrt(n); // 'sqrt' es de <cmath>
}

// REQUISITO: Recursividad y Excepción
unsigned long long factorial(int n) {
    // Excepción primero (buena práctica)
    if (n < 0) {
        throw domain_error("Factorial no esta definido para numeros negativos.");
    }

    // --- Inicio de la Recursividad ---
    // 1. Caso Base: El punto donde la recursión se detiene.
    // El factorial de 0 (y de 1) es 1.
    if (n <= 1) {
        return 1;
    }
    
    // 2. Paso Recursivo: La función se llama a sí misma con un problema más pequeño.
    // n! = n * (n-1)!
    return n * factorial(n - 1);
}

//probando codigo
