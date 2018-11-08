#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "BibliotecaFunciones.h"
#include <string.h>

static int isValidName(char* name);
static int isValidHoursWorked(char* HoursWorked);
static int isValidSalary(char* Salary);
static int isValidId(char* id);


Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}



Employee* employee_newParametros(char* idStr,char* NameStr,char* HoursWorkedStr, char* SalaryStr)
{
    Employee* this = NULL;
    this = employee_new();
    if(this == NULL || employee_setId(this, idStr) || employee_setName(this, NameStr) || employee_setHoursWorked(this, HoursWorkedStr) ||employee_setSalary(this, SalaryStr))
    {
        employee_delete(this);
        this = NULL;
    }
    return this;
}


int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}



int employee_setName(Employee* this, char* Name)
{
    int retorno = -1;
    if(this != NULL && isValidName(Name) == 0)
    {
        strcpy(this->Name,Name);
        retorno = 0;
    }
    return retorno;
}



int employee_getName(Employee* this, char* Name)
{
    int retorno = -1;
    if(this != NULL && Name != NULL)
    {
        strcpy(Name,this->Name);
        retorno = 0;
    }
    return retorno;
}



static int isValidName(char* Name)
{
    int retorno = -1;
    if(esLetra(Name) == -1)
    {
        printf("\nName invalido\n");
        printf("\n%s\n", Name);
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}



int employee_setHoursWorked(Employee* this, char* HoursWorked)
{
    int retorno = -1;
    if(this != NULL && isValidHoursWorked(HoursWorked) == 0)
    {
        this->HoursWorked = atoi(HoursWorked);
        retorno = 0;
    }
    return retorno;
}



int employee_getHoursWorked(Employee* this, int* HoursWorked)
{
    int retorno = -1;
    if(this != NULL && HoursWorked != NULL)
    {
        *HoursWorked = this->HoursWorked;
        retorno = 0;
    }
    return retorno;
}


static int isValidHoursWorked(char* HoursWorked)
{
    int retorno = -1;
    if(esEntero(HoursWorked) == -1)
    {
        printf("   ----------------------------------------------   \n");
        printf("           lAS HORAS TRABAJADAS NO SON VALIDAS       \n");
        printf("   ----------------------------------------------    \n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}



int employee_setSalary(Employee* this, char* Salary)
{
    int retorno = -1;
    if(this != NULL && isValidSalary(Salary) == 0)
    {
        this->Salary = atoi(Salary);
        retorno = 0;
    }
    return retorno;
}



int employee_getSalary(Employee* this, int* Salary)
{
    int retorno = -1;
    if(this != NULL && Salary != NULL)
    {
        *Salary = this->Salary;
        retorno = 0;
    }
    return retorno;
}



static int isValidSalary(char* Salary)
{
    int retorno = -1;
    if(esEntero(Salary) == -1)
    {
        printf("   ----------------------------------------------   \n");
        printf("            EL Salary NO ES VALIDO                  \n");
        printf("   ----------------------------------------------    \n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}



int employee_setId(Employee* this, char* id)
{
    int retorno = -1;
    static int proximoId = -1;
    int auxID;
    if(this != NULL && isValidId(id) == 0)
    {
        auxID = atoi(id);
        if(auxID == -1)
        {
            proximoId++;
            this->id = proximoId;
            retorno = 0;
        }else if(auxID > proximoId)
        {
            proximoId = auxID;
            this->id = proximoId;
            retorno = 0;
        }
    }
    return retorno;
}


int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


static int isValidId(char* id)
{
    int retorno = -1;
    if(EnteroConGuiones(id) == -1)
    {
        printf("   ----------------------------------------------   \n");
        printf("             EL ID ES INVALIDO                       \n");
        printf("   ----------------------------------------------    \n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}



void employee_mostrarEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int auxId;
    char auxName[1024];
    int auxHoursWorked;
    int auxSalary;
    int size;
    size = ll_len(pArrayListEmployee);
    Employee* auxEmployee;

    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if( employee_getId(auxEmployee, &auxId) == 0 && employee_getName(auxEmployee, auxName) == 0 && employee_getHoursWorked(auxEmployee, &auxHoursWorked) == 0 &&
                employee_getSalary(auxEmployee, &auxSalary) == 0)
            {
                printf("ID: %d **** Name: %s **** Horas Trabajadas: %d **** Salary: %d \n", auxId, auxName, auxHoursWorked, auxSalary);
            }
            else
            {
                printf("   ----------------------------------------------    \n");
                printf("             NO SE PUDO MOSTRAR LA LISTA             \n");
                printf("   ----------------------------------------------    \n");
            }
        }
         printf("\n   ----------------------------------------------    \n");
         printf("\n          LA CANTIDAD DE EMPLEADOS ES DE: %d         \n" , size);
         printf("\n   ----------------------------------------------    \n");
    }
    else
    {
        printf("   ----------------------------------------------    \n");
        printf("             NO SE ENCUENTRA UNA LISTA               \n");
        printf("   ----------------------------------------------    \n");
    }
}



int employee_cargarEmployee(LinkedList* pArrayEmployee)
{
    int retorno = -1;
    char auxName[1024];
    char auxID[1024] = "-1";
    int auxHoursWorked;
    int auxSalary;
    char bufferHoursWorked[1024];
    char bufferSalary[1024];
    Employee* auxPunteroEmployee;

    if( ObtenerName(auxName, "\nIngrese el Nombre del empleado: \n","\nEl Nombre ingresado es invalido\n") == 0 &&ObtenerNumeroSinLimitacion(&auxHoursWorked, 10, "\nIngrese las horas trabajadas del empleado: \n","\nError, horas de trabajo invalidas\n") == 0 &&
        ObtenerNumeroSinLimitacion(&auxSalary, 10, "\nIngrese el Salario del empleado: \n","\nError, Salario invalido\n") == 0)
    {
        itoa(auxHoursWorked, bufferHoursWorked, 10);
        itoa(auxSalary, bufferSalary, 10);
        auxPunteroEmployee = employee_newParametros(auxID, auxName, bufferHoursWorked, bufferSalary);
        if(auxPunteroEmployee != NULL)
        {
            ll_add(pArrayEmployee, auxPunteroEmployee);
        }
        retorno=0;
    }
    return retorno;
}


int employee_modificarEmployee(LinkedList* pArrayEmployee)
{
    int retorno = -1;
    int idEmployee;
    int indice;
    char auxName[1024];
    int auxHoursWorked;
    int auxSalary;
    Employee* auxPEmployee;
    if(pArrayEmployee != NULL && ObtenerNumeroSinLimitacion(&idEmployee, 10, "\nIngrese el ID del empleado a modificar: \n", "\nEl ID ingresado es invalido\n") == 0)
    {
        indice = employee_buscarPorId(pArrayEmployee, idEmployee);
        if(indice >= 0)
        {
            auxPEmployee = ll_get(pArrayEmployee, indice);
            if( ObtenerName(auxName, "\nIngrese el nuevo Name del empleado: \n","\nEl Name ingresado es invalido\n")==0 && ObtenerNumeroSinLimitacion(&auxHoursWorked, 10, "\nIngrese la nueva cantidad de horas trabajadas: \n", "\nLas horas de trabajo ingresadas son invalidas\n") == 0 &&
                ObtenerNumeroSinLimitacion(&auxSalary, 10,"\nIngrese el nuevo Salary: \n", "\nEl Salary ingresado es invalido\n") == 0)
            {
                auxPEmployee->HoursWorked = auxHoursWorked;
                auxPEmployee->Salary = auxSalary;
                strcpy(auxPEmployee->Name, auxName);
                retorno = 0;
            }
        }else
        {
            printf("\nError, el id no existe\n");
        }
    }
    return retorno;
}



int employee_buscarPorId(LinkedList* pArrayEmployee, int idEmployee)
{
    int retorno = -1;
    int i;
    int limite = ll_len(pArrayEmployee);
    Employee* auxPEmployee;
    if(pArrayEmployee != NULL)
    {
        for(i = 0; i < limite; i++)
        {
            auxPEmployee = (Employee*)ll_get(pArrayEmployee, i);
            if(auxPEmployee != NULL && auxPEmployee->id == idEmployee)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int employee_borrarEmployee(LinkedList* pArrayEmployee)
{
    int retorno=-1;
    int idEmployee;
    int id;
    Employee* auxPEmployee;
    if(pArrayEmployee != NULL && ObtenerNumeroSinLimitacion(&idEmployee, 10, "\nIngrese el ID del empleado a borrar: \n", "\nEl Id ingresado es invalido\n") == 0)
    {
        id = employee_buscarPorId(pArrayEmployee, idEmployee);
        if(id >= 0)
        {
            auxPEmployee = ll_get(pArrayEmployee,id);
            if(employee_delete(auxPEmployee) == 0)
            {
                retorno = 0;
                ll_remove(pArrayEmployee,id);
            }
        }else
        {
            printf("\nEl Id ingresado no existe\n");
        }
    }
    return retorno;
}



int employee_ordenarPorName(void* thisA,void* thisB)
{
    int retorno = 0;
    char NameA[60];
    char NameB[60];

    employee_getName(thisA,NameA);
    employee_getName(thisB,NameB);

    if(strcmp(NameA,NameB) > 0)
    {
        retorno = 1;

    }else if(strcmp(NameA,NameB) < 0)
    {
        retorno = -1;
    }
    return retorno;
}



int employee_guardarDatosenTexto(LinkedList* pArrayEmployee, char* path)
{
    int retorno = -1;
    int i;
    int size;
    FILE* pFile = fopen(path,"w");
    size = ll_len(pArrayEmployee);
    Employee* auxPEmployee;
    if(pFile != NULL)
    {
        retorno = 0;
        for(i = 0; i < size; i++)
        {
            auxPEmployee = ll_get(pArrayEmployee,i);
            fprintf(pFile, "%d,%s,%d,%d\n", auxPEmployee->id, auxPEmployee->Name, auxPEmployee->HoursWorked, auxPEmployee->Salary);
        }
    }
    fclose(pFile);
    return retorno;
}



int employee_guardarDatosenBinario(LinkedList* pArrayEmployee, char* path)
{
    int retorno = -1;
    FILE* pFile = fopen(path,"wb");
    Employee* auxPEmpleado;
    int i;
    int size = ll_len(pArrayEmployee);
    if(pFile != NULL)
    {
        retorno = 0;
        for(i = 0; i < size; i++)
        {
            auxPEmpleado = ll_get(pArrayEmployee, i);
            fwrite(auxPEmpleado, sizeof(Employee), 1, pFile);
        }
    }
    fclose(pFile);
    return retorno;
}



