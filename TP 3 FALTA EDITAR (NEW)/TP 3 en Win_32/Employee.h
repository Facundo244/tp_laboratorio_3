#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char Name[128];
    int HoursWorked;
    int Salary;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* NameStr,char* HoursWorkedStr, char* SalaryStr);
int employee_delete();

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* Name);
int employee_getName(Employee* this,char* Name);

int employee_setHoursWorked(Employee* this,char* HoursWorked);
int employee_getHoursWorked(Employee* this,int* HoursWorked);

int employee_setSalary(Employee* this,char* Salary);
int employee_getSalary(Employee* this,int* Salary);

int employee_cargarEmployee(LinkedList* pArrayEmployee);
int employee_modificarEmployee(LinkedList* pArrayEmployee);
int employee_buscarPorId(LinkedList* pArrayEmployee, int idEmployee);
int employee_borrarEmployee(LinkedList* pArrayEmployee);
void employee_mostrarEmployee(LinkedList* pArrayListEmployee);
int employee_ordenarPorNombre(void* thisA,void* thisB);
int employee_guardarDatosenTexto(LinkedList* pArrayEmployee, char* path);
int employee_guardarDatosenBinario(LinkedList* pArrayEmployee, char* path);

#endif // employee_H_INCLUDED
