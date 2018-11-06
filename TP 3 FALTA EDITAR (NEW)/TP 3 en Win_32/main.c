#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "BibliotecaFunciones.h"

int main()
{
    int opcion = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

    printf("\n                                  MENU:                                       ");
    printf("\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)  ");
    printf("\n                                                                              ");
    printf("\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    printf("\n                                                                              ");
    printf("\n 3. Alta de empleado                                                          ");
    printf("\n                                                                              ");
    printf("\n 4. Modificar datos de empleado                                               ");
    printf("\n                                                                              ");
    printf("\n 5. Baja de empleado                                                          ");
    printf("\n                                                                              ");
    printf("\n 6. Listar empleados                                                          ");
    printf("\n                                                                              ");
    printf("\n 7. Ordenar empleados                                                         ");
    printf("\n                                                                              ");
    printf("\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)    ");
    printf("\n                                                                              ");
    printf("\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)  ");
    printf("\n                                                                              ");
    printf("\n 10. Salir                                                                    ");

    printf("\n          Ingrese una opcion (1/10): ");
    scanf("%d" , & opcion);

    switch(opcion)
    {
        case 1:
            system("cls");
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            system("cls");
            controller_loadFromBinary("data.bin", listaEmpleados);
            break;
        case 3:
            system("cls");
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            system("cls");
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            system("cls");
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            system("cls");
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            system("cls");
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            system("cls");
            controller_saveAsText("data.csv", listaEmpleados);
            break;
        case 9:
            system("cls");
            controller_saveAsBinary("data.bin", listaEmpleados);
            break;
        case 10:
            system("cls");
            ll_deleteLinkedList(listaEmpleados);
        break;
        }
    }while(opcion != 10);

    return 0;
}
