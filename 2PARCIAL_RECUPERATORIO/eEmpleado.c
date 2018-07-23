#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eEmpleado.h"


//FUNCION UTILIZADA DENTRO DE AL_SORT

int compareeEmpleado(void* pEmployeeA,void* pEmployeeB)
{
    eEmpleado* tmp1=(eEmpleado*)pEmployeeA ;
    eEmpleado* tmp2=(eEmpleado*)pEmployeeB ;

    if(strcmp((tmp1)->nombre,(tmp2)->nombre)> 0)
    {
        return 1;
    }
    if(strcmp((tmp1)->nombre,(tmp2)->nombre)< 0)
    {
        return 0;
    }
    return 0;


}

int compareeEmpleado_sueldo(void* pEmployeeA,void* pEmployeeB)
{
    eEmpleado* tmp1=(eEmpleado*)pEmployeeA ;
    eEmpleado* tmp2=(eEmpleado*)pEmployeeB ;

    if((tmp1->sueldo)>(tmp2->sueldo))
    {
        return 1;
    }
    if((tmp1->sueldo)<(tmp2->sueldo))
    {
        return 0;
    }
    return 0;


}


//FUNCIONES PARA MOSTRAR DATOS

void m_empleado_sueldo(eEmpleado* lEmp)
{
    printf("\n%-20s %-20s %-5s %-10s\n\n","NOMBRE","DIRECCION","ID","SUELDO");
    eEmpleado* aux;
    for (int i=0; i<al_len(lEmp); i++ )
                {
                    aux=(eEmpleado*)al_get(lEmp,i);
                    printeEmpleado_sueldo(aux);
                }
}

void printeEmpleado_sueldo(eEmpleado* p)
{
    char d[51];
    char n[51];
    get_Empleado_nombre(p,n);
    get_Empleado_direccion(p,d);
    printf("%-20s %-20s %-5d %-10.2f\n",n,d,get_Empleado_id(p),get_Empleado_sueldo(p));
}

void m_empleado(eEmpleado* lEmp)
{
    printf("\n%-20s %-20s %-5s \n\n","NOMBRE","DIRECCION","ID");
    eEmpleado* aux;
    for (int i=0; i<al_len(lEmp); i++ )
                {
                    aux=(eEmpleado*)al_get(lEmp,i);
                    printeEmpleado(aux);
                }
}

void printeEmpleado(eEmpleado* p)
{
    char d[51];
    char n[51];
    get_Empleado_nombre(p,n);
    get_Empleado_direccion(p,d);
    printf("%-20s %-20s %-5d\n",n,d,get_Empleado_id(p));
}

//CONSTRUCTOR

eEmpleado* neweEmpleado(void)
{
    eEmpleado* returnAux = NULL;
    eEmpleado* pEmployee = malloc(sizeof(eEmpleado));
    returnAux = pEmployee;
    return returnAux;

}

//SETTERS Y GETTERS

int set_Empleado_id(eEmpleado* p,int id)
{
    if (p!=NULL)
    {
        p->id = id;
        return 1;
    }
    return 0;
}

int set_Empleado_nombre(eEmpleado* p,char* n)
{
if (p!=NULL)
    {
        strcpy(p->nombre,n);
        return 1;
    }
    return 0;
}

int set_Empleado_domicilio(eEmpleado* p,char* d)
{
if (p!=NULL)
    {
        strcpy(p->direccion,d);
        return 1;
    }
    return 0;
}

int get_Empleado_id(eEmpleado* p)
{
    return p->id;
}

 void get_Empleado_nombre(eEmpleado* p,char* nombre)
{
    strcpy(nombre,p->nombre);
}

void get_Empleado_direccion(eEmpleado* p,char* direccion)
{
    strcpy(direccion,p->direccion);
}

int set_Empleado_hora(eEmpleado* p,int h)
{
    if (p!=NULL)
    {
        p->hora = h;
        return 1;
    }
    return 0;
}
int set_Empleado_sueldo(eEmpleado* p,float s)
{
    if (p!=NULL)
    {
        p->sueldo = s;
        return 1;
    }
    return 0;
}

int get_Empleado_hora(eEmpleado* p)
{
    return p->hora;
}

float get_Empleado_sueldo(eEmpleado* p)
{
    return p->sueldo;
}

//FUNCION UTILIZADA DENTRO DE MAP PARA CALCULAR SUELDO

int calc_suel_Empleado(void* empleado)
{
    int returnaux = -1;
    float sueldo=-1.00;
    if(empleado!=NULL)
    {
        returnaux =0;
        eEmpleado *tmp=(eEmpleado*) empleado;

        int horas=get_Empleado_hora(tmp);

        if(horas >79 && horas < 121)
        {
            sueldo = 180.00*horas;
            set_Empleado_sueldo(tmp,sueldo);
        }

            else if(horas >120 && horas < 161)
            {
                sueldo = 120*180.00 + (horas-120)*240;
                set_Empleado_sueldo(tmp,sueldo);
            }
                else if(horas >160 && horas < 241)
                {
                    sueldo=120*180.00+40*240+(horas-240)*350;
                    set_Empleado_sueldo(tmp,sueldo);
                }
    }

    return returnaux;
}

int sueldos_20(void* empleado) // 1 si es mayor a 20000
{
    int returnaux = -1;
    if(empleado!=NULL)
    {
        returnaux =0;
        eEmpleado *tmp=(eEmpleado*) empleado;

        float sueldo = get_Empleado_sueldo(tmp);
        if (sueldo > 20000.00)
        {
          returnaux =1;
        }
        else returnaux =0;
    }

    return returnaux;




}


