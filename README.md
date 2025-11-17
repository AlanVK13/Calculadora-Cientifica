# 🧮 5- Calculadora Científica en C++

Este es un proyecto universitario para la materia de **Programación Dinámica (IS25)**. Es una calculadora por consola escrita en C++ que demuestra la implementación de varios conceptos fundamentales del lenguaje.

---

## 🚀 Funcionalidades

El programa presenta un menú interactivo que permite al usuario elegir entre las siguientes operaciones:

* **Operaciones Básicas:**
    * Suma
    * Resta
    * Multiplicación
    * División
* **Operaciones Avanzadas:**
    * Potencia (base y exponente)
    * Factorial
    * Raíz Cuadrada

---

## 🛠️ Requisitos Técnicos Implementados

Este proyecto fue diseñado para poner en práctica los siguientes requisitos del lenguaje C++:

* **Funciones:** Todo el código está modularizado en funciones para una mejor organización y reutilización.
* **Sobrecarga de Funciones (Overloading):**
    * La función `sumar()` está sobrecargada. Existe una versión que acepta dos parámetros (`sumar(a, b)`) y otra que acepta tres (`sumar(a, b, c)`).
* **Parámetros por Omisión:**
    * La función `potencia(base, exponente)` tiene un valor por omisión para el exponente. Si el usuario no lo proporciona (usando la opción "Calcular Cuadrado" del menú), el programa asume `exponente = 2.0` y calcula el cuadrado de la base.
* **Recursividad:**
    * La función `factorial()` se calcula utilizando un algoritmo recursivo, con un caso base para `n=0` y `n=1`.
* **Manejo de Excepciones (try-catch):**
    * El programa es robusto y no se cierra inesperadamente ante entradas inválidas. Se implementaron bloques `try-catch` para manejar los siguientes errores en tiempo de ejecución:
        1.  **División entre cero:** (Lanza `runtime_error`).
        2.  **Raíz cuadrada de números negativos:** (Lanza `domain_error`).
        3.  **Factorial de números negativos:** (Lanza `domain_error`).
        4.  **Entrada no numérica:** Se valida que la entrada del menú sea un número.

---

## 💻 Cómo Compilar y Ejecutar

Si tienes un compilador de C++ como `g++`, puedes compilar y ejecutar el programa de la siguiente manera:

```bash
# 1. Clona el repositorio (o descarga el .cpp)
# git clone [https://github.com/AlanVK13/Calculadora-Cientifica.git](https://github.com/AlanVK13/Calculadora-Cientifica.git)
# cd Calculadora-Cientifica

# 2. Compila el programa
g++ calculadora.cpp -o calculadora.exe

# 3. Ejecuta el programa
./calculadora.exe
