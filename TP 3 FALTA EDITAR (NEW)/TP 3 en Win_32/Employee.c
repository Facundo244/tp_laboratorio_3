#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "BibliotecaFunciones.h"
#include <string.h>

static int isValidNombre(char* name);
static int isValidHorasTrabajadas(char* horasTrabajadas);
static int isValidSueldo(char* sueldo);
static int isValidId(char* id);


Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = NULL;
    this = employee_new();
    if(this == NULL || employee_setId(this, idStr) || employee_setNombre(this, nombreStr) || employee_setHorasTrabajadas(this, horasTrabajadasStr) ||employee_setSueldo(this, sueldoStr))
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



int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre) == 0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}



int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}



static int isValidNombre(char* nombre)
{
    int retorno = -1;
    if(isLetra(nombre) == -1)
    {
        printf("\nNombre invalido\n");
        printf("\n%s\n", nombre);
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}



int employee_setHorasTrabajadas(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas) == 0)
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}



int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int retorno = -1;
    if(isInt(horasTrabajadas) == -1)
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



int employee_setSueldo(Employee* this, char* sueldo)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(sueldo) == 0)
    {
        this->sueldo = atoi(sueldo);
        retorno = 0;
    }
    return retorno;
}



int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}



static int isValidSueldo(char* sueldo)
{
    int retorno = -1;
    if(isInt(sueldo) == -1)
    {
        printf("   ----------------------------------------------   \n");
        printf("            EL SUELDO NO ES VALIDO                  \n");
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
    if(isIntConGuiones(id) == -1)
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
    char auxNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    int size;
    size = ll_len(pArrayListEmployee);
    Employee* auxEmployee;

    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if( employee_getId(auxEmployee, &auxId) == 0 && employee_getNombre(auxEmployee, auxNombre) == 0 && employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas) == 0 &&
                employee_getSueldo(auxEmployee, &auxSueldo) == 0)
            {
                printf("ID: %d **** Nombre: %s **** Horas Trabajadas: %d **** Sueldo: %d \n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            }
            else
            {
                printf("\nNo se pudo mostrar la lista.\n");
            }
        }
         printf("\nLa cantidad de empleados es: %d.", size);
    }
    else
    {
        printf("   ----------------------------------------------   \n");
        printf("             NO SE ENCUENTRA UNA LISTA                      \n");
        printf("   ----------------------------------------------    \n");
    }
}



int employee_cargarEmployee(LinkedList* pArrayEmployee)
{
    int retorno = -1;
    char auxNombre[1024];
    char auxID[1024] = "-1";
    int auxHorasTrabajadas;
    int auxSueldo;
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Employee* auxPunteroEmployee;
    if( library_getNombre(auxNombre, "\nIngrese el nombre del empleado: \n","\nEl nombre ingresado es invalido\n") == 0 &&library_getEnteroSinLimites(&auxHorasTrabajadas, 10, "\nIngrese las horas trabajadas del empleado: \n","\nError, horas de trabajo invalidas\n") == 0 &&
        library_getEnteroSinLimites(&auxSueldo, 10, "\nIngrese el sueldo del empleado: \n","\nError, sueldo invalido\n") == 0)
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


int employee_modificarEmployee(LinkedList* pArrayEmployee)
{
    int retorno = -1;
    int idEmployee;
    int indice;
    char auxNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxPEmployee;
    if(pArrayEmployee != NULL && library_getEnteroSinLimites(&idEmployee, 10, "\nIngrese el ID del empleado a modificar: \n", "\nEl id ingresado es invalido\n") == 0)
    {
        indice = employee_buscarPorId(pArrayEmployee, idEmployee);
        if(indice >= 0)
        {
            auxPEmployee = ll_get(pArrayEmployee, indice);
            if( library_getNombre(auxNombre, "\nIngrese el nuevo nombre del empleado: \n","\nEl nombre ingresado es invalido\n")==0 &&
                library_getEnteroSinLimites(&auxHorasTrabajadas, 10, "\nIngrese la nueva cantidad de horas trabajadas: \n", "\nLas horas de trabajo ingresadas son invalidas\n") == 0 &&
                library_getEnteroSinLimites(&auxSueldo, 10,"\nIngrese el nuevo sueldo: \n", "\nEl sueldo ingresado es invalido\n") == 0)
            {
                auxPEmployee->horasTrabajadas = auxHorasTrabajadas;
                auxPEmployee->sueldo = auxSueldo;
                strcpy(auxPEmployee->nombre, auxNombre);
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
    if(pArrayEmployee != NULL && library_getEnteroSinLimites(&idEmployee, 10, "\nIngrese el ID del empleado a borrar: \n", "\nEl Id ingresado es invalido\n") == 0)
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



int employee_ordenarPorNombre(void* thisA,void* thisB)
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
            fprintf(pFile, "%d,%s,%d,%d\n", auxPEmployee->id, auxPEmployee->nombre, auxPEmployee->horasTrabajadas, auxPEmployee->sueldo);
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



