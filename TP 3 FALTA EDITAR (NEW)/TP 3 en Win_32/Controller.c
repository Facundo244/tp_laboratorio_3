#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "BibliotecaFunciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path,"r");
    if(parser_EmployeeFromText(pArchivo, pArrayListEmployee) == 0) //Esta devolviendo -1
    {
        printf("   ----------------------------------------------    \n");
        printf("         SE CARGARON CON EXITO LOS EMPLEADOS...         \n");
        printf("   ----------------------------------------------    \n");
        retorno = 0;
    }
    else
    {
        printf("   ----------------------------------------------    \n");
        printf("        ERROR EN LA CARGA DE EMPLEADOS...         \n");
        printf("   ----------------------------------------------    \n");
    }
    fclose(pArchivo);

    system("pause");
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path, "rb");
    if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
    {
        printf("\nSe cargaron los datos correctamente.\n");
        retorno = 0;
    }
    else
    {
        printf("\nNo se pudieron cargar los datos.\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    if(employee_cargarEmployee(pArrayListEmployee) == 0)
    {
        printf("\nEl nuevo empleado ha sido agregado correctamente.\n");
        retorno = 0;
    }
    else
    {
        printf("\nEl nuevo empleado no ha podido ser agregado correctamente..\n");
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_modificarEmployee(pArrayListEmployee) == 0)
    {
        printf("/nEl empleado se ha modificado exitosamente./n");
        retorno = 0;
    }
    else
    {
        printf("/nEl empleado no ha podido ser modificado correctamente./n");
    }
    return retorno;
}

/** \brief Baja de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =- 1;
    if(employee_borrarEmployee(pArrayListEmployee) == 0)
    {
        printf("\nEl empleado se ha borrado correctamente.\n");
        retorno=0;
    }
    else
    {
        printf("\nEl empleado no se ha podido borrar correctamente.\n");
    }
    return retorno;
}

/** \brief Listar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    employee_mostrarEmployee(pArrayListEmployee);
    system("pause");
    return 1;
}

/** \brief Ordenar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee,employee_ordenarPorNombre,1);
        printf("/nLos empleados han sido ordenados exitosamente./n");
        retorno = 0;
    }
    else
    {
        printf("/nLos empleados no han podido ser ordenados como corresponde./n");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosenTexto(pArrayListEmployee, path) == 0)
    {
        printf("/nLos datos han sido guardados correctamente./n");
        retorno = 0;
    }
    else
    {
        printf("/nLos datos no se han guardaron, intente nuevamente./n");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosenBinario(pArrayListEmployee, path)==0)
    {
        printf("/nLos datos han sido guardados correctamente./n");
        retorno = 0;
    }
    else
    {
        printf("/nLos datos no se han guardado, intente nuevamente./n");
    }
    return retorno;
}

