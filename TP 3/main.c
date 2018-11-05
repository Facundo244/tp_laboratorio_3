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
/*
printf("\n      **************************************************************************************");
printf("\n      ||                                                                                  ||");
printf("\n      ||      1.Cargar datos de los empleados desde archivo data.csv (modo texto)         ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||      2.Cargar datos de los empleados desde archivo data.csv (modo binario)       ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||      3. ALTA                                                                     ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||      4. MODIFICACION                                                              ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||      5. BAJA                                                                     ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||      6. INFORMAR  LISTA                                                          ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||      7.ORDENAR EMPLEADOS                                                         ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||      8.Guardar datos de los empleados en el archivo data.csv (modo texto).       ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||      9.Guardar datos de los empleados en el archivo data.csv (modo binario).     ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||                                                                                  ||");
printf("\n      ||   10.Salir                                                                        ||");
printf("\n      **************************************************************************************");
printf("\n                                                    ");
printf("\n");
printf("\n          Ingrese una opcion (1/10): ");
scanf("%d" , & opcion);

*/
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    return 0;
}
