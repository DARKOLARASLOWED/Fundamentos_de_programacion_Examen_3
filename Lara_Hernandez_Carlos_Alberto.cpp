// CARLOS ALBERTO LARA HERNANDEZ
// No. de cuenta: 476759
// Tercer Examen Parcial

#include <iostream>
#include <stdlib.h>
#include <locale>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <limits>
#include <iomanip>
#include <stdio.h>


void password ();
void Cconfig ();
void portada();
bool askretorno();
bool replay();
int askmenu ();
void despedida();
void mostrar_valores(struct libro *x);
void libro_mas_antiguo(struct libro *x, struct libro *y);
void imprimir_arr_m3(int x[4][6]);
void detectar_ca(char x[]);

const HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

struct libro // nombre de la estructura
{
char titulo[30];
char autor[25];
char editorial[30];
int anyo;
float precio;
char fecha_compra[12];
};

struct libro programacion_c = {"Programación en C++", "Luis Joyanes A.", "McGrawHill", 2002, 350.0, "02/06/2005"};
struct libro logicamatematica = {"Matemáticas para computación", "José Jiménez", "Alfaomega", 2010, 430.0, "10/03/2008"};

int numeros[4][6]=  {{18,10,00,02,13,11},
                     {50,22,27,31,12,24},
                     {03,29,07,19,81,43},
                     {23,34,47,46,51,39}};

using namespace std;

int main()
{
    char op, cadena[4];
    double gr;
    int mul;
    Cconfig();
    portada();
    do{
    system("cls");
    SetConsoleTextAttribute(hConsole, 13); // cambia de color el texto a morado claro
    cout << "\t\t" << "+-----------------------------------------------------+" << endl;
    cout << "\t\t" << "|---------|| LARA HERNANDEZ CARLOS ALBERTO||----------|" << endl;
    cout << "\t\t" << "+---------++----++------------------++----++----------+" << endl;
    cout << "\t\t" << "|---------------|| MENU DE OPCIONES ||----------------|" << endl;
    cout << "\t\t" << "+----------++---++------------------++---++-----------+" << endl;
    cout << "\t\t" << "|----------|| C) ESTRUCTURA              ||-----------|" << endl;
    cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
    cout << "\t\t" << "|----------|| F) ARREGLO NUMERICO        ||-----------|" << endl;
    cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
    cout << "\t\t" << "|----------|| M) PUNTERO                 ||-----------|" << endl;
    cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
    cout << "\t\t" << "|----------|| Q) SALIR                   ||-----------|" << endl;
    cout << "\t\t" << "+----------++----------------------------++-----------+" << endl << endl;
    switch(tolower(askmenu()))
    {
    case 'c':
        system("cls");
        cout << "\t\t" << "+----------++---++------------------++---++-----------+" << endl;
        cout << "\t\t" << "|----------|| C) ESTRUCTURA              ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
        cout << "\t\t" << "Se mostrara acontinuacion el contenido de las siguientes estructuras" << endl;
        fflush(stdin);
        mostrar_valores(&programacion_c);
        mostrar_valores(&logicamatematica);
        libro_mas_antiguo(&programacion_c, &logicamatematica);
    break;
    case 'f':
    system("cls");
    cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
    cout << "\t\t" << "|----------|| F) ARREGLO NUMEROS         ||-----------|" << endl;
    cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
    imprimir_arr_m3(numeros);

    break;
    case 'm':
        system("cls");
        cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
        cout << "\t\t" << "|----------|| M) PUNTERO                 ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------+" << endl << endl;
        cout << "\t\t" << "Ingrese la cadena de dos caracteres" << endl;
        cout << "\t\t--> ";
        fflush(stdin);
        cin.getline(cadena, 3);
        detectar_ca(cadena);

    break;
    case 'q':
       despedida();
    break;
    default:
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\t\t" << "La opcion seleccionanda no se encuentra en el menú" << endl;
        cout << "\t\t" << "Intente nuevamente" << endl;

    break;

    }
    }while(askretorno() == true);
    return 0;
}

void mostrar_valores(struct libro *x) // Se muestran los contenidos de la estructura por medio de apuntadores
{
    cout << "\t\t" << "*****************************************************" << endl << endl;
    cout << "\t\t" << "Titulo: " << x ->titulo << endl;
    cout << "\t\t" << "Autor: " << x ->autor << endl;
    cout << "\t\t" << "Editorial: " << x ->editorial << endl;
    cout << "\t\t" << "Año: " << x ->anyo << endl;
    cout << "\t\t" << "Precio del libro: " << x ->precio << endl;
    cout << "\t\t" << "Fecha de compra: " << x ->fecha_compra << endl;
    cout << "\t\t" << "*****************************************************" << endl << endl;
    cout << "\t\t"; system("pause");
    cout << endl << endl;
}

void libro_mas_antiguo(struct libro *x, struct libro *y) // Funcion para saber que libro es mas antiguo
{
    if(x ->anyo < y ->anyo){ // Si el x valor del año es menor que el año de y valor
        cout << "\t\t" << "El libro mas antiguo es: " << x->titulo << endl;
        cout << "\t\t" << "Años de antiguedad: " << 2022 - (x ->anyo) << endl;
        // Se calcula e imprime los años de antiguedad  del libro con respecto año que se creo el programa
    }
        else if(x ->anyo == y ->anyo){ // Si el y valor del año es igual que el año de x valor
            cout << "\t\t" << "Los dos titulos fueron publicados el mismo año: " << x->anyo << endl;
            cout << "\t\t" << "Años de antiguedad: " << 2022 - (x ->anyo) << endl;
            // Se calcula e imprime los años de antiguedad  del libro con respecto año que se creo el programa
        }
            else{// Si el y valor del año es menor que el año de x valor
                cout << "\t\t" << "El libro mas antiguo es: " << y->titulo << endl;
                cout << "\t\t" << "Años de antiguedad: " << 2022 - (y ->anyo) << endl;
                // Se calcula e imprime los años de antiguedad  del libro con respecto año que se creo el programa
            }
}

bool askretorno(void)
{
    SetConsoleTextAttribute(hConsole, 9); // Cambia el color de solo el texto seleccionado a fondo negro y texto azul
    char askreturn;

    cout << endl << endl;
    cout << "\t\t" << "¿Usted desea regresar al menu principal?" << endl;
    cout << "\t\t" << "Ingrese S para hacerlo" << endl;
    fflush(stdin); // Limpia el buffer del la entrada
    cout << "\t\t--> "; cin >> askreturn;
    if (toupper(askreturn)== 'S') // Se compara si el caracter ingresado convertido en mayuscula es identico a S
    {
        cout << "\t\t" << "Regresando" << endl;
        return true;
    }
        else
        {
            despedida(); // Se ocupa la funcion para dar la despedida si no se desea regresar al menu

        }
}

void portada(void) // Portada del programa
{
SetConsoleTextAttribute(hConsole, 9); // Cambia el color de solo el texto seleccionado a fondo negro y texto azul
cout << "\t\t" << " :::    :::     :::     :::::::::: :::    ::: " << endl;
cout << "\t\t" << " :+:    :+:   :+: :+:   :+:        :+:    :+: " << endl;
cout << "\t\t" << " +:+    +:+  +:+   +:+  +:+        +:+    +:+ " << endl;
cout << "\t\t" << " +#+    +:+ +#++:++#++: +#++:++#   +#++:++#++ " << endl;
cout << "\t\t" << " +#+    +#+ +#+     +#+ +#+        +#+    +#+ " << endl;
cout << "\t\t" << " #+#    #+# #+#     #+# #+#        #+#    #+# " << endl;
cout << "\t\t" << "  ########  ###     ### ########## ###    ### " << endl << endl;
SetConsoleTextAttribute(hConsole, 12); // Cambia el color de solo el texto seleccionado a fondo negro y texto rojo claro
cout << "\t\t" << "+---------------------------------------------+" << endl;
cout << "\t\t" << "| INSTITUTO DE CIENCIAS BASICAS E INGENIERIA  |" << endl;
cout << "\t\t" << "+---------------------------------------------+" << endl;
cout << "\t\t" << "| LICENCIATURA EN CIENCIAS COMPUTACIONALES    |" << endl;
cout << "\t\t" << "+---------------------------------------------+" << endl;
cout << "\t\t" << "| CARLOS ALBERTO LARA HERNANDEZ               |" << endl;
cout << "\t\t" << "+---------------------------------------------+" << endl;
cout << "\t\t" << "| SEMESTRE: 1          GRUPO: 1               |" << endl;
cout << "\t\t" << "+---------------------------------------------+" << endl;
cout << "\t\t" << "| NO.DE CUENTA: 476759                        |" << endl;
cout << "\t\t" << "+---------------------------------------------+" << endl;
cout << "\t\t" << "Presione cualquier tecla para continuar...    "; getch(); //lee el teclado
system("cls");
}

void Cconfig (void)
{
    setlocale(LC_CTYPE,"Spanish"); // Cambia el idioma en español
    system("cls"); // Limpia la consola
    system("color D"); // Cambia el color de la consola a purpura claro
}

int askmenu()
{
    char x;

    cout << "\t\t" << "Seleccione una opcion... ";
    SetConsoleTextAttribute(hConsole, 12); // Cambia el color de solo el texto seleccionado a fondo negro y texto rojo claro
    fflush(stdin);
    cin >> x;
    SetConsoleTextAttribute(hConsole, 10); // Cambia el color de solo el texto seleccionado a fondo negro y texto verde claro
    if (cin.fail())
    {
        fflush(stdin);
        return 0;
    }
    else
    {
        return x;
    }
}

void despedida(void) // Funcion para terminar un programa
{
    SetConsoleTextAttribute(hConsole, 10); // Cambia el color de solo el texto seleccionado a fondo negro y texto verde claro
    cout << "\t\t" << "Gracias por usar este programa..." << endl;
    cout << "\t\t" << "Creado por Carlos Alberto lara Hernandez" << endl;
    cout << "\t\t" << "Adiosssssss...\n" << endl;
    exit(-1);
}

bool replay(void)
{
    char askreturn;

    SetConsoleTextAttribute(hConsole, 13); // Cambia el color de solo el texto seleccionado a fondo negro y texto vpurpura claro
    cout << "\t\t" << "¿Usted desea reiniciar la seccion?" << endl;
    cout << "\t\t" << "Ingrese 'A' para hacerlo" << endl;
    fflush(stdin);
    cout << "\t\t--> "; cin >> askreturn;
    if (toupper(askreturn)== 'A')
    {
        cout << "\t\t" << "Reiniciando" << endl;
        return true;
    }
        else
        {
            return false;

        }
}

void password (void)
{

    char pass[15]={"Donnie Darko"}; // Varible de cadena que se comparara con la variable magicword
    char magicword[15]; // Variable que almacena la cadena de caracteres por console input
    int conpass = 3; // Contador que esta inicializado en 3

    Cconfig(); // Funcion para la configuracion de la consola

    while(true)
    {
        SetConsoleTextAttribute(hConsole, 9); // Cambia de color el texto a azul oscuro
        cout << "\t\t" << "Ingrese la contraseña ";
        SetConsoleTextAttribute(hConsole, 12); // Cambia de color el texto a rojo claro
        cin.getline(magicword,13); // Toma la linea de entrada de los primeros 13 terminos
        if (strcmp(pass,magicword) == 0) // Se compara la controseña con la palabra ingresada para saber si son identicas
        {
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\t\t" << "Contraseña correcta" << endl;
            SetConsoleTextAttribute(hConsole, 5);
            cout << "\t\t" << "Bienvenido" << endl << endl;
            Sleep(1000); // Delay de un segundo
            break;
        }
            else // Si las cadenas no son identicas el programa se cierra
            {
                SetConsoleTextAttribute(hConsole, 8);
                cout << "\t\t" << "Contraseña incorrecta" << endl;

                conpass --; // El contador dismuye que significa que los intentos son menos
                if (conpass <= 0) // Si se superan los intentos
                {
                    cout << "\t\t" << "Numero de intentos superados" << endl;
                    exit(-1);
                }
                cout << "\t\t" << "Numero de intentos: " << conpass << endl;

                system("cls");
            }
    }
    system("cls");
}

void imprimir_arr_m3(int x[4][6])
{
    int m3=0, nm3=0;
    SetConsoleTextAttribute(hConsole, 13); // Cambia el color de solo el texto seleccionado a fondo negro y texto vpurpura claro
    cout << endl << endl;
    for(int i=0; i<4; i++){ // For que controla las filas del arreglo
        for(int j=0; j<6; j++){ // For que controla las columnas del arreglo
            if(((x[i][j])%3==0) &&((x[i][j]) != 0)){ // Si el modulo del valor que se encuentra en la posicion del arreglo es 0 y el valor es diferente de 0
            SetConsoleTextAttribute(hConsole, 12); // Cambia el color de solo el texto seleccionado a fondo negro y texto rojo claro
            cout << "\t\t" << setfill('0') << setw(2) << x[i][j] << "; "; /* setfill('0') hace que si el valor no cuenta con todos los digitos en setw(2) se coloque un 0
            setw(2) hace que al imprimir ponga el numero de digitos que se ponen adentro de la funcion */
            m3++; // El contador de multiplo de 3 aumenta
            }
            else{
            SetConsoleTextAttribute(hConsole, 13); // Cambia el color de solo el texto seleccionado a fondo negro y texto vpurpura claro
            cout << "\t\t" << setfill('0') << setw(2) << x[i][j] << "; "; /* setfill('0') hace que si el valor no cuenta con todos los digitos en setw(2) se coloque un 0
            setw(2) hace que al imprimir ponga el numero de digitos que se ponen adentro de la funcion */
            nm3++; // El contador de los que no son multiplos de 3 aumente
            }
        }
        SetConsoleTextAttribute(hConsole, 13); // Cambia el color de solo el texto seleccionado a fondo negro y texto vpurpura claro
        cout << endl;
    }
     SetConsoleTextAttribute(hConsole, 12); // Cambia el color de solo el texto seleccionado a fondo negro y texto rojo claro
    cout << endl << "\t\t" << "Los numeros multiplos de 3 son: " << m3 << endl;
    SetConsoleTextAttribute(hConsole, 13); // Cambia el color de solo el texto seleccionado a fondo negro y texto vpurpura claro
    cout << "\t\t" << "Los numeros que no son multiplos de 3 son: " << nm3 << endl;
}

void detectar_ca(char x[])
{
    char *ptr;
    ptr = &x[0];

    for(int i=0; i<strlen(x); i++)
    {
        if(*ptr>=48 && *ptr<=57){
            cout << "\t\t" << "El caracter: " << i+1 << " es digito." << endl;

        }
            else if(*ptr>=97 && *ptr<=122){
                cout << "\t\t" << "El caracter: " << i+1 << " es minuscula." << endl;

            }
                else if(*ptr>='A' && *ptr<='Z'){
                    cout << "\t\t" << "El caracter: " << i+1 << " es mayuscula." << endl;

                }
                    else{
                        cout << "\t\t" << "El caracter: " << i+1 << " es caracter especial." <<  endl;
                    }
    ptr++;

    }

}
