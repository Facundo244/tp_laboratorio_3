#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr , char* salaryStr);
int employee_delete(Employee* this);

int employee_setId(Employee* this,char id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,char sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_saveDataInBinary(LinkedList* pArrayEmployee , char* path);
int employee_saveDataInText(LinkedList* pArrayEmployee , char* path);

int employee_criterioNombre(void* thisA,void* thisB);
int employee_deleteEmployee(LinkedList* pArrayEmployee);

int employee_buscarPorId(LinkedList* pArrayEmployee, int idEmployee);
void employee_mostrar(LinkedList* pArrayListEmployee);

int employee_buscarPorId(LinkedList* pArrayEmployee, int idEmployee);

#endif // employee_H_INCLUDED
