#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eEmpleado.h"
#include "funciones.h"

void LP(void);

int main()
{


    ArrayList* lEmpleados;
    ArrayList* lEmpleados_copia;
    ArrayList* lEmpleados_sueldos;
    FILE *fEmpleados;
    eEmpleado *aux;
    int flagmap=0;
    int f_secargo_archivo=0;
    // char datoEntrada[150];


    int seguir=1;
    int opcion;
    int fparce;
    int fsort;

    lEmpleados=al_newArrayList();
    lEmpleados_sueldos = al_newArrayList();

    while(seguir==1)
    {

        printf("\n-------------------------------\n");
        printf("-- MENU PARCIAL --\n");
        printf("-------------------------------\n");
        printf(" 1. Leer archivo data.csv\n");
        printf(" 2. Listar Empleados\n");
        printf(" 3. Ordenar por nombre\n");
        printf(" 4. Calcular Sueldo\n");
        printf(" 5. Generar archivo sueldos\n");
        printf(" 6. Generar archivo con sueldos mayores a 20.000 $\n");
      //  printf(" 6. Alta Manual\n");
      //  printf(" 7. Ordenar por sueldo\n");
        printf(" 0. Salir");
        printf("\n\n\ Ingrese la Opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
        case 1:
            fparce=parsereEmpleado(fEmpleados, lEmpleados);
            if (fparce==0)
            {
                printf("\n COPIA EXITOSA\n");
                lEmpleados_copia=al_clone(lEmpleados);
                f_secargo_archivo=1;


            }
            else
            {
                printf("\n no se pudo copiar el archivo\n");
            }
            LP();
            break;
        case 2:
            if(!al_isEmpty(lEmpleados)) //if(f_secargo_archivo==1)
            {
                if(lEmpleados_copia!=NULL)
            {

                printf("elementos: %d\n", al_len(lEmpleados_copia));
                m_empleado(lEmpleados_copia);

            }

            }
            else{printf("\nNO HAY DATOS PARA GENERAR LISTADO\n");}

            LP();
            break;
        case 3:
            if(!al_isEmpty(lEmpleados))//if(f_secargo_archivo==1)
            {
                if(lEmpleados_copia!=NULL)
            {
                printf("-------------Ordenar por nombre\n\n");
                fsort=al_sort(lEmpleados_copia,compareeEmpleado,1);
            }


            if(fsort==0)
            {
               m_empleado(lEmpleados_copia);
            }
            }
            else{printf("\nNO HAY DATOS PARA GENERAR LISTADO\n");}


            LP();
            break;
        case 4:
            if(!al_isEmpty(lEmpleados))//if(f_secargo_archivo==1)
            {
            lEmpleados_copia->map(lEmpleados_copia,calc_suel_Empleado);
            printf("elementos: %d\n", al_len(lEmpleados_copia));
            m_empleado_sueldo(lEmpleados_copia);

            flagmap=1;
            }
            else{printf("\nNO HAY DATOS PARA GENERAR SUELDOS\n");}
            LP();
            break;
        case 5:
            if(flagmap==1)
            {
                guardarArchivo(lEmpleados_copia);
                printf("\nARCHIVO GENERADO CON EXITO\n");
            }
            else
            {
                printf("\nPRIMERO DEBE CALCULAR SUELDOS PARA GENERAR ARCHIVO. EJECUTE OPCION 4\n");
            }


            LP();
            break;
        case 6:
            if(flagmap==1)
            {
                lEmpleados_copia->filter(lEmpleados_copia,lEmpleados_sueldos,sueldos_20);
                guardarArchivo_20(lEmpleados_sueldos);
                 m_empleado_sueldo(lEmpleados_sueldos);
                 LP();
            break;
            }


       /* case 6:
            if(!al_isEmpty(lEmpleados))
            {
                altaManual(lEmpleados_copia);
            }
            else{printf("\nAUN NO SE HA CARGADO EL ARCHIVO, CARGUE EL MISMO PRIMERO PARA EVITAR NCONSISTENCIAS\n");}
            LP();
            break;
        case 7:
            if(flagmap==1)
            //if(f_secargo_archivo==1)
            {
                if(lEmpleados_copia!=NULL)
            {
                printf("-------------Ordenar por sueldo\n\n");
                fsort=al_sort(lEmpleados_copia,compareeEmpleado_sueldo,1);
            }


            if(fsort==0)
            {
               m_empleado_sueldo(lEmpleados_copia);
            }
            }
            else{printf("\nPRIMERO CALCULE LOS SUELDOS, NO HAY DATOS PARA GENERAR LISTADO\n");}


            LP();
            break;*/

        case 0:
            printf("elementos: %d", al_len(lEmpleados_copia));
            seguir=0;
            LP();
            break;
        default:
            LP();
            break;
        }
    }




    return 0;
}









void LP (void)
{
    printf("\n");
    system ("pause");
    system ("cls");
}
