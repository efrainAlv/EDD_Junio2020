// Proyecto1[EDD].cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include "Matrix.h"
#include "string.h"

#include "AVL_Tree.h"

int main()
{
    std::cout << "Hello World!\n";

   /* 
    User user("Helmut", "Admin", "123");
    User user1("user1", "Admin", "123");
    User user2("user2", "Admin", "123");
    User user3("user3", "Admin", "123");
    User user4("user4", "Admin", "123");
    User user5("user5", "Admin", "123");
    User user6("user6", "Admin", "123");
    User user7("user7", "Admin", "123");
    
    Matrix matrix ("admin", "123");

    matrix.addUser(user1, "Guatemala", "Max");
    matrix.addUser(user2, "Jalapa", "Gas");
    matrix.addUser(user3, "Zacapa", "OroMaya");
    matrix.addUser(user4, "Zacapa", "Nesttle");
    matrix.addUser(user5, "Escuintla", "Gas");

    matrix.addUser(user6, "Zacapa", "Max");
    matrix.addUser(user7, "Zacapa", "Gas");

    matrix.addUser(user, "Jalapa", "Nesttle");


    
    MatrixNode* ejemplo = matrix.getExistingNode(4, 3);
    
    std::cout << ejemplo;

    */

    AVL_Tree tree("PRIMER ARBOL");

    if (std::strcmp("aaabc500x-a", "aaabc500x-b") > 0) {
        std::cout << "a50 es mayor";
    }
    else {
        std::cout << "a130 es mayo";
    }


    

    tree.add("20");
    tree.add("10");
    tree.add("60");
    tree.add("70");
    tree.add("80");
    tree.add("90");
    


    std::cout << tree.name;
    std::cout << "ALTURA DEL ARBOL: " << tree.root->height;
 


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
