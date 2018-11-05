#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>

//el modificar y el cargar employee

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr , char* salaryStr)
{
    Employee* this = NULL;
    this = employee_new();

    if(this == NULL || employee_setId(this, idStr) || employee_setNombre(this, nombreStr) ||employee_setSueldo(this, salaryStr) || employee_setHorasTrabajadas(this, horasTrabajadasStr))
    {
        employee_delete(this);
        this = NULL;
    }
    return this;
}


int employee_delete(Employee* this)
{
    int estado =-1;
    if(this != NULL)
    {
        free(this);
        estado=0;
    }
    return estado;
}

int employee_getNombre(Employee* this , char* nombre)
{
    int estado =-1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre , this -> nombre);
        estado =0;
    }
    return estado;
}

int employee_setNombre(Employee* this , char* nombre)
{
    int estado = -1;
    if(this != NULL && nombre == 0)
    {
        strcpy(this ->nombre , nombre);
        estado=0;
    }
    return estado;
}

int employee_setSueldo(Employee* this , char sueldo)
{
    int estado = -1;
    if(this != NULL && sueldo == 0)
    {
        this->sueldo = atoi(sueldo);
        return 0;
    }
    return estado;
}

int employee_getSueldo(Employee* this , int* sueldo)
{
    int estado = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this -> sueldo;
        estado = 0;
    }
    return estado;
}

int employee_setHorasTrabajadas(Employee* this, char* horasTrabajadas)
{
    int estado = -1;
    if(this != NULL && horasTrabajadas == 0)
    {
        this -> horasTrabajadas = atoi(horasTrabajadas);
    }
    return estado;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int estado = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
    }
    return estado;
}

int employee_setId(Employee* this,char id)
{
    int estado = 0;
    if(this != NULL)
    {
        this->id  = id++;
    }
    return estado;
}

int employee_getId(Employee* this , int* id)
{
    int estado = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        return estado;
    }
    return estado;
}

int employee_buscarPorId(LinkedList* pArrayEmployee, int idEmployee)
{
    int estado = -1;
    int i;
    int limite = ll_len(pArrayEmployee);
    Employee* auxPunteroEmployee;
    if(pArrayEmployee != NULL)
    {
        for(i = 0; i < limite; i++)
        {
            auxPunteroEmployee = (Employee*)ll_get(pArrayEmployee, i);
            if(auxPunteroEmployee != NULL && auxPunteroEmployee->id == idEmployee)
            {
                estado = i;
                break;
            }
        }
    }
    return estado;
}

void employee_mostrar(LinkedList* pArrayListEmployee)
{
    int i;
    int auxId;
    char auxName[1024];
    int auxWorkedHours;
    int auxSalary;
    int size;
    size = ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if( employee_getId(auxEmployee, &auxId) == 0 && employee_getNombre(auxEmployee, auxName) == 0 && employee_getSueldo(auxEmployee, &auxSalary) == 0 &&
                employee_getHorasTrabajadas(auxEmployee, &auxWorkedHours) == 0)
            {
                printf("ID: %d - Name: %s - Salary: %d - Worked Hours: %d \n", auxId, auxName, auxSalary, auxWorkedHours);
            }
            else
            {
                    printf("    *--------------------------------------*     \n");
                    printf("  HUBO UN ERROR EN CARGAR LA LISTA DE EMPLEADOS  \n");
                    printf("    *--------------------------------------*     \n");
            }
        }
         printf("\nLa candidad de empleados es: %d.", size);

            printf("    *--------------------------------------*     \n");
            printf("                LISTA TERMINADA                 \n");
            printf("    *--------------------------------------*     \n");
    }
    else
    {
        printf("    *--------------------------------------*     \n");
        printf("   NO EXISTE NINGUNA LISTA EN LOS PARAMETROS  \n");
        printf("    *--------------------------------------*     \n");
    }
}

/*
int employee_deleteEmployee(LinkedList* pArrayEmployee)
{
    int retorno = -1;
    int idEmployee;
    int ID;
    Employee* auxPEmployee;

    if(pArrayEmployee != NULL && (&idEmployee , 10 , "Ingrese el ID del empleado que desea eliminar: " , "ID Invalido") == 0)
    {
        ID = employee_buscarPorId(pArrayEmployee , idEmployee);
        if(ID >= 0)
        {
            auxPEmployee = ll_get(pArrayEmployee , ID);
            if(employee_delete(auxPEmployee)==0)
            {
                retorno = 0;
                ll_remove(pArrayEmployee , ID);
            }
        }
        else
        {
            printf("    *--------------------------------------*     \n");
            printf("      EL ID NO EXISTE EN LA BASE DE DATOS        \n");
            printf("    *--------------------------------------*     \n");

        }
    }
    return retorno;
}e
*/
int employee_criterioNombre(void* thisA,void* thisB)
{
    int retorno = 0;
    char nombreA[1024];
    char nombreB[1024];
    employee_getNombre((Employee*)thisA,nombreA);
    employee_getNombre((Employee*)thisB,nombreB);
    if(strcmp(nombreA,nombreB) > 0)
    {
        retorno = 1;
    }else if(strcmp(nombreA,nombreB) < 0)
    {
        retorno = -1;
    }
    return retorno;
}


int employee_saveDataInText(LinkedList* pArrayEmployee , char* path)
{
    int estado = -1;
    int i;
    int tam;
    FILE* pArchivo;
    pArchivo = fopen(path , "w");
    tam = ll_len(pArrayEmployee);
    Employee* auxPEmployee;

    if(pArchivo != NULL)
    {
        estado = 0;
        for(i=0 ; i<tam ; i++)
        {
            auxPEmployee = ll_get(pArrayEmployee, i);
            fprintf(pArchivo , "%d,%s,%d,&d\n" , auxPEmployee->id , auxPEmployee->nombre , auxPEmployee->sueldo , auxPEmployee->horasTrabajadas);
        }
    }
    fclose(pArchivo);
    return estado;

}

int employee_saveDataInBinary(LinkedList* pArrayEmployee , char* path)
{
    int estado = -1;
    FILE* pArchivo;
    Employee* auxPEmployee;
    int i;
    int tam = ll_len(pArrayEmployee);
    pArchivo = fopen(path , "wb");


    if(pArchivo != NULL)
    {
        estado = 0;
        for(i = 0 ; i< tam ; i++)
        {
            auxPEmployee = ll_get(pArrayEmployee , i);
            fwrite(auxPEmployee , sizeof(Employee), 1 , pArchivo);

        }
    }
    fclose(pArchivo);

    return estado;

}
/*
int employee_loadEmployee(LinkedList* pArrayEmployee)
{
    int estado = -1;
    char auxID[1024] = "-1";
    char auxWorkedHours;
    int auxSalary;
    char auxName[1024];
    char buffHoursWorked[1024];
    char buffSalaty[1024]
    Employee* auxPEmployee;

    if(pArrayEmployee != NULL && )

}

int employee_cargarEmpleado(LinkedList* pArrayEmployee)
{
    int retorno = -1;
    char auxNombre[1024];
    char auxID[1024] = "-1";
    int auxHorasTrabajadas;
    int auxSueldo;
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Employee* auxPunteroEmployee;
    if( utn_getNombre(auxNombre, "\nIngrese el nombre del empleado: \n","\nError, nombre invalido\n") == 0 &&
        utn_getEnteroSinLimites(&auxHorasTrabajadas, 10, "\nIngrese las horas trabajadas del empleado: \n","\nError, horas de trabajo invalidas\n") == 0 &&
        utn_getEnteroSinLimites(&auxSueldo, 10, "\nIngrese el sueldo del empleado: \n","\nError, sueldo invalido\n") == 0)
    {
        itoa(auxHorasTrabajadas, bufferHorasTrabajadas, 10);
        itoa(auxSueldo, bufferSueldo, 10);
        auxPunteroEmployee = employee_newParametros(auxID, auxNombre, bufferHorasTrabajadas, bufferSueldo);
        if(auxPunteroEmployee != NULL)
        {
            ll_add(pArrayEmployee, auxPunteroEmployee);
        }
        retorno=0;
    }
    return retorno;
}
*/
