#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno =0;

    pArchivo = fopen(path , "r");

    if(parser_EmployeeFromText(pArchivo , pArrayListEmployee)== 0)
    {
        printf("\n Carga de datos existosas.\n");
        retorno = 0;
    }
    else
    {
        printf("\n Error en la carga de datos. \n");

    }
    fclose(pArchivo);

    system("pause");

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int estado= -1;
    pArchivo = fopen(path , "rb");

    if(pArchivo != NULL && parser_EmployeeFromBinary(pArchivo , pArrayListEmployee) == 0)
    {
       printf("Se cargaron con exito los datos\n");
       estado = 0;
    }
    fclose(pArchivo);
    return estado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int estado = -1;
    if(employee_deleteEmployee(pArrayListEmployee)== 0)
    {
        printf("    *--------------------------------------*     \n");
        printf(" SE BORRO CORRECTAMENTE EL EMPLEADO SELECCIONADO  \n");
        printf("    *--------------------------------------*     \n");
        estado = 0;
    }
    else
    {
        printf("    *--------------------------------------*     \n");
        printf("  HUBO UN ERROR Y NO SE PUDO BORRAR EL EMPLEADO \n");
        printf("    *--------------------------------------*     \n");
    }
    return estado;
}
*/

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    employee_mostrar(pArrayListEmployee);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int estado =-1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee , employee_criterioNombre , 1);
        printf("    *--------------------------------------*     \n");
        printf("        SE ORDENO CORRECTAMENTE LA LISTA        \n");
        printf("    *--------------------------------------*     \n");
    }
    else
    {
        printf("    *--------------------------------------*     \n");
        printf("    HUBO UN ERROR Y NO SE PUDO ORDENAR LA LISTA  \n");
        printf("    *--------------------------------------*     \n");
    }
    return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int estado = -1;
    if(employee_saveDataInText(pArrayListEmployee , path)==0)
    {
        printf("         *--------------------------------------*            \n");
        printf("    SE GUARDARON CORRECTAMENTE LOS DATOS EN EL ARCHIVO TXT \n");
        printf("         *--------------------------------------*            \n");
    }
    else
    {
        printf("        *--------------------------------------*     \n");
        printf("     HUBO UN ERROR Y NO SE PUDO GUARDAD LOS DATOS   \n");
        printf("        *--------------------------------------*     \n");
    }
    return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int estado = -1;
    if(employee_saveDataInBinary(pArrayListEmployee, path) == 0)
    {
        printf("         *--------------------------------------*            \n");
        printf("    SE GUARDARON CORRECTAMENTE LOS DATOS EN EL ARCHIVO BIN \n");
        printf("         *--------------------------------------*            \n");
        estado = 0;
    }
    else
    {
        printf("        *--------------------------------------*     \n");
        printf("     HUBO UN ERROR Y NO SE PUDO GUARDAD LOS DATOS   \n");
        printf("        *--------------------------------------*     \n");
    }
    return estado;
}



