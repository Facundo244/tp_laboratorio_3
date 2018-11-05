#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
do{
    system("cls");
    printf("\n                                  MENU:                                       ");
    printf("\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    printf("\n                                                                             ");
    printf("\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    printf("\n                                                                             ");
    printf("\n 3. Alta de empleado                                                         ");
    printf("\n                                                                             ");
    printf("\n 4. Modificar datos de empleado                                              ");
    printf("\n                                                                             ");
    printf("\n 5. Baja de empleado                                                         ");
    printf("\n                                                                             ");
    printf("\n 6. Listar empleados                                                         ");
    printf("\n                                                                            ");
    printf("\n 7. Ordenar empleados                                                        ");
    printf("\n                                                                             ");
    printf("\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)   ");
    printf("\n                                                                             ");
    printf("\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario) ");
    printf("\n                                                                             ");
    printf("\n 10. Salir                                                                   ");

    printf("\n          Ingrese una opcion (1/10): ");
    scanf("%d" , & opcion);


        switch(opcion)
        {
            case 1:
                controller_loadFromText("data.csv" , listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin" , listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;

        }
    }while(opcion != 10);
    return 0;
}
