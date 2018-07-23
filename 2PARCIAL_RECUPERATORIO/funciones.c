#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eEmpleado.h"
#include "funciones.h"

void guardarArchivo(ArrayList* empleados)

{
    FILE* miArchivo;
    miArchivo = fopen("sueldos.csv","w");
    char n[50];
    char d[50];

    fprintf(miArchivo,"NOMBRE,DIRECCION,ID,HORAS,SUELDO\n");
    for(int i=0;i<al_len(empleados);i++)
    {
        eEmpleado* tmp=al_get(empleados,i);
        get_Empleado_nombre(tmp,n);
        get_Empleado_direccion(tmp,d);

        fprintf(miArchivo,"%s,%s,%d,%d,%.2f\n",n,d,get_Empleado_id(tmp),get_Empleado_hora(tmp),get_Empleado_sueldo(tmp)); // aca cambiaste f por d
    }

    fclose(miArchivo);
}

int consulta(char* dato) //retorna 0 si esta todo bien, -1 si hubo error
{
    if(dato!=NULL)
    {
        fflush(stdin);
        fgets(dato,100,stdin);
    int largo=0;
    while (*(dato+largo)!='\n')
        {
        largo++;
        }
    *(dato+largo)='\0';
    return 0;
    }
    else return -1;
}


int buscarMaxId(ArrayList* empleados)

{
    eEmpleado* aux;
    int id;
    int maxId=-1;
    if (al_len(empleados)!=0)
        {
        for (int i=0; i<al_len(empleados); i++ )
                {
                    aux=(eEmpleado*)al_get(empleados,i);
                    id=get_Empleado_id(aux);
                    if(id>maxId){maxId=id;}
                }
        maxId++;
        }

return maxId;
}

int validarHora(char* hora)

{
    int auxHora = -1;
    int largo=0;
    while (*(hora+largo)!='\0')
        {
        if((*(hora+largo)) >='0' && (*(hora+largo))<='9'){largo++;}
        else {printf("Ha ingresado una hora incorrecta");LP();return auxHora;}
        }
    auxHora =atoi(hora);
    if(auxHora>240){auxHora=-1;}
    return auxHora;


}

int altaManual(ArrayList* pArrayListEmpleado)
{
    char campoIngresar[100];
    int horas;
    eEmpleado *auxEmpleado = neweEmpleado();

                printf("\nIngresar nombre: ");
                consulta(campoIngresar);
                set_Empleado_nombre(auxEmpleado,campoIngresar);

                printf("\nIngresar direccion: ");
                consulta(campoIngresar);
                set_Empleado_domicilio(auxEmpleado,campoIngresar);


                printf("\nIngresar horas trabajadas: ");
                consulta(campoIngresar);
                horas = validarHora(campoIngresar);


                while(horas==-1)
                    {

                        printf("\nIngresar horas trabajadas: ");
                        consulta(campoIngresar);
                        horas = validarHora(campoIngresar);
                    }


                set_Empleado_hora(auxEmpleado,horas);

                set_Empleado_id(auxEmpleado,buscarMaxId(pArrayListEmpleado));
                al_add(pArrayListEmpleado,auxEmpleado);
}

void guardarArchivo_20(ArrayList* empleados)

{
    FILE* miArchivo;
    miArchivo = fopen("sueldos20.csv","w");
    char n[50];
    char d[50];

    fprintf(miArchivo,"NOMBRE,DIRECCION,ID,HORAS,SUELDO\n");
    for(int i=0;i<al_len(empleados);i++)
    {
        eEmpleado* tmp=al_get(empleados,i);
        get_Empleado_nombre(tmp,n);
        get_Empleado_direccion(tmp,d);

        fprintf(miArchivo,"%s,%s,%d,%d,%.2f\n",n,d,get_Empleado_id(tmp),get_Empleado_hora(tmp),get_Empleado_sueldo(tmp)); // aca cambiaste f por d
    }

    fclose(miArchivo);
}
