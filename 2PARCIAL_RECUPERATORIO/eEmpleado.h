#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{
    int id;
    char nombre[51];
    char direccion[51];
    int hora;
    float sueldo;

}typedef eEmpleado;
#endif // __EMPLOYEE

//FUNCION COMPARA UTILIZADA DENTRO DEL SORT

/** Compara nombre de empleados
 *
 * \param pEmployeeA void*
 * \param pEmployeeB void*
 * \return int
 *
 */
int compareeEmpleado(void* pEmployeeA,void* pEmployeeB);
/** Compara sueldo de empleados
 *
 * \param pEmployeeA void*
 * \param pEmployeeB void*
 * \return int
 *
 */
int compareeEmpleado_sueldo(void* pEmployeeA,void* pEmployeeB);

//FUNCIONES PARA IMPRIMIR DATOS

/** Prepara listado mostrando sueldos
 *
 * \param p eEmpleado*
 * \return void
 *
 */
void printeEmpleado_sueldo(eEmpleado* p);
/** Genera listado mostrando sueldos
 *
 * \param eEmpleado*
 * \return void
 *
 */
void m_empleado_sueldo(eEmpleado*);
/** Genera listado sin campo sueldo
 *
 * \param lEmp eEmpleado*
 * \return void
 *
 */
void m_empleado(eEmpleado* lEmp);
/** Prepara listado sin campo sueldos
 *
 * \param p eEmpleado*
 * \return void
 *
 */
void printeEmpleado(eEmpleado* p);

//CONTRUCTOR

/**Constructor de eEmpleado
 *
 * \return eEmpleado*
 *
 */
eEmpleado* neweEmpleado();

//SETTERS 1 OK 0 NO SETEO

int set_Empleado_id(eEmpleado* p,int id);
int set_Empleado_nombre(eEmpleado* p,char* n);
int set_Empleado_domicilio(eEmpleado* p,char* d);
int set_Empleado_hora(eEmpleado* p,int h);
int set_Empleado_sueldo(eEmpleado* p,float s);

//GETTERS

int get_Empleado_id(eEmpleado*);
int get_Empleado_hora(eEmpleado*);
float get_Empleado_sueldo(eEmpleado*); // cambiaste esta funcion retorna float, antes retornaba int
void get_Empleado_nombre(eEmpleado* ,char* );
void get_Empleado_direccion(eEmpleado*,char* );

//CALCULA SUELDO PARA FUNCION MAP

/** Funcion para calcular sueldo de empleados
 *
 * \param empleado void*
 * \return int
 *
 */
int calc_suel_Empleado(void* empleado);

int sueldos_20(void* empleado);

