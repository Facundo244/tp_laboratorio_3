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
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
    {
         printf("           ----------------------------------------------               \n");
        printf("           LA CARGA DE DATOS DE TIPO TEXTO SE REALIZO CON EXITO          \n");
        printf("            ----------------------------------------------               \n");
        retorno = 0;
    }
    else
    {
        printf("             ----------------------------------------------               \n");
        printf("                NO SE ENCONTRO UN ARCHIVO DE TEXTO                      \n");
        printf("            ----------------------------------------------               \n");
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
        printf("             ----------------------------------------------              \n");
        printf("                SE CARGARON LOS DATOS CORRECTAMENTE                      \n");
        printf("            ----------------------------------------------               \n");
        retorno = 0;
    }
    else
    {
        printf("            ----------------------------------------------              \n");
        printf("                NO SE PUDIERON CARGAR LOS DATOS                          \n");
        printf("            ----------------------------------------------               \n");
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
         printf("            ----------------------------------------------              \n");
        printf("                EL NUEVO EMPLEADO SE REGISTRO CORRECTAMENTE              \n");
        printf("            ----------------------------------------------               \n");
        retorno = 0;
    }
    else
    {
        printf("            ----------------------------------------------              \n");
        printf("              EL NUEVO EMPLEADO NO SE PUDO REGISTRAR CORRECTAMENTE              \n");
        printf("            ----------------------------------------------               \n");
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
        system("cls");
        printf("            ----------------------------------------------              \n");
        printf("                EL EMPLEADO HA SIDO MODIFICADO CON EXITO               \n");
        printf("            ----------------------------------------------               \n");
        retorno = 0;
    }
    else
    {
        printf("            ----------------------------------------------              \n");
        printf("                    EL EMPLEADO NO SE PUDO MODIFICAR                        \n");
        printf("            ----------------------------------------------               \n");
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
        printf("            ----------------------------------------------              \n");
        printf("                EL EMPLEADO SE BORRO CON EXITO                           \n");
        printf("            ----------------------------------------------               \n");
        retorno=0;
    }
    else
    {
        printf("            ----------------------------------------------              \n");
        printf("                EL EMPLEADO NO SE PUEDO ELIMINAR                         \n");
        printf("            ----------------------------------------------               \n");
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
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    Employee* auxPunteroEmpleado;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {

             if(i%23==0)
            {

            system("pause");
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getName(auxPunteroEmpleado,nombre);
            employee_getSalary(auxPunteroEmpleado,&sueldo);
            employee_getHoursWorked(auxPunteroEmpleado,&horasTrabajadas);

            printf("\n*************\n");
            printf("\nID: %d",id);
            printf("\n*************\n");
            printf("\nNombre: %s",nombre);
            printf("\n*************\n");
            printf("\nSueldo: %d",sueldo);
            printf("\n*************\n");
            printf("\nHoras trabajadas: %d",horasTrabajadas);
            printf("\n*************\n");
            printf("\n");
            }
            else
            {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getName(auxPunteroEmpleado,nombre);
            employee_getSalary(auxPunteroEmpleado,&sueldo);
            employee_getHoursWorked(auxPunteroEmpleado,&horasTrabajadas);

            printf("\nID: %d",id);
            printf("\n*************\n");
            printf("\nNombre: %s",nombre);
            printf("\n*************\n");
            printf("\nSueldo: %d",sueldo);
            printf("\n*************\n");
            printf("\nHoras trabajadas: %d",horasTrabajadas);
            printf("\n*************\n");
            printf("\n");


            }
        }
    }
    system("pause");
    return retorno;
}


/** \brief Ordenar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
/*
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee,employee_ordenarPorName,1);
        printf("            ----------------------------------------------              \n");
        printf("                lOS EMPLEADO HAN SIDO ORDENADOS                       \n");
        printf("            ----------------------------------------------               \n");
        retorno = 0;
    }
    else
    {
         printf("            ----------------------------------------------              \n");
        printf("                NO SE PUDO ORDENAR LOS EMPLEADO                        \n");
        printf("            ----------------------------------------------               \n");
    }
    return retorno;
}
*/

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
        printf("            ----------------------------------------------        \n");
        printf("               LOS DATOS DE HAN GUARDADO CORRECTAMENTE            \n");
        printf("            ----------------------------------------------         \n");
        retorno = 0;
    }
    else
    {
         printf("            ----------------------------------------------        \n");
        printf("               LOS DATOS NO SE HAN GUARDADO CORRECTAMENTE            \n");
        printf("            ----------------------------------------------         \n");
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
        printf("            ----------------------------------------------        \n");
        printf("               LOS DATOS DE HAN GUARDADO CORRECTAMENTE            \n");
        printf("            ----------------------------------------------         \n");
        retorno = 0;
    }
    else
    {
        printf("            ----------------------------------------------        \n");
        printf("               LOS DATOS NO SE HAN GUARDADO CORRECTAMENTE            \n");
        printf("            ----------------------------------------------         \n");
    }
    return retorno;
}

