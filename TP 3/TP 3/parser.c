#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    char bufferId[1024];
    char bufferName[1024];
    char bufferHoursWorked[1024];
    char bufferSalary[1024];
    int bandera = 1;
    int retorno = -1;

    while(!feof(pFile))
    {
        if(bandera)
        {
            fscanf(pFile,"%s\n", bufferId);
            bandera = 0;
        }
        else if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferHoursWorked, bufferSalary)==4)
        {
            pAux = employee_newParametros(bufferId, bufferName, bufferHoursWorked, bufferSalary);
            if(pAux != NULL)
            {
                ll_add(pArrayListEmployee, pAux);
                retorno = 0;
            }
        }
        else
        {
            break;
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxPEmpleado;
    int retorno = -1;
    int cantLineas;
    do
    {
        auxPEmpleado = employee_new();
        cantLineas = fread(auxPEmpleado, sizeof(Employee), 1, pFile);
        if(auxPEmpleado != NULL && cantLineas == 1)
        {
            ll_add(pArrayListEmployee, auxPEmpleado);
            retorno = 0;
        }
    }while(!feof(pFile));
    return retorno;
}
