#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pArchivo , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pAux;
    char bufferID[1024];
    char bufferName[1024];
    char bufferWorkedHours[1024];
    char bufferSalary[1024];
    int bandera = 1;

    while(!feof(pArchivo))
    {
        if(bandera)
        {
            fscanf(pArchivo, "%s \n" , bufferID);
            bandera = 0;
        }
        else if(fscanf(pArchivo , "%[^,],%[^,],%[^,],%[^\n]\n" , bufferID , bufferName , bufferWorkedHours , bufferSalary))
        {
            pAux = employee_newParametros(bufferID, bufferName, bufferWorkedHours, bufferSalary);
            if(pAux != NULL)
            {
                ll_add(pArrayListEmployee , pAux);
                retorno =0;
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
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pArchivo, LinkedList* pArrayListEmployee)
{
    Employee* auxPunteroEmployee;
    int cantL;
    int retorno = -1;
    do
    {
        auxPunteroEmployee = employee_new();
        cantL = fread(auxPunteroEmployee , sizeof(Employee), 1 , pArchivo);
        if(auxPunteroEmployee != NULL && cantL == 1)
        {
            ll_add(pArrayListEmployee , auxPunteroEmployee);
            retorno = 0;

        }
    }
    while(!feof(pArchivo));
    return retorno;
}
