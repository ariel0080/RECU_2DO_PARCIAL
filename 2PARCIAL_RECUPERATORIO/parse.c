
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eEmpleado.h"


int parsereEmpleado(FILE* pFile, ArrayList* pArrayListEmpleado)

{
    eEmpleado *auxEmpleado;

    char nombre[51];
    char direccion[51];
    char horas[50];
    char id[10];
    //int i=0;
    int idi;
    int ihoras;


    pFile=fopen("data.csv","r");

    if(pFile== NULL)
    {
        return 1;
    }
    else
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", nombre, direccion, id, horas); //DESCARTO PRIMERA FILA DEL ARCHIVO POR CONTENER NOMBRES DE COLUMNAS


        while(!(feof(pFile)))
        {




                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", nombre, direccion, id, horas);

                idi = atoi(id);
                ihoras = atoi(horas);

                auxEmpleado= neweEmpleado();

                if(auxEmpleado!=NULL)
                {

                set_Empleado_id(auxEmpleado,idi);
                set_Empleado_domicilio(auxEmpleado,direccion);
                set_Empleado_nombre(auxEmpleado,nombre);
                set_Empleado_hora(auxEmpleado,ihoras);

                //set_Empleado(auxEmpleado,idi,nombre,direccion);

                al_add(pArrayListEmpleado,auxEmpleado);

                //i++;
                }


    }
    }
    fclose(pFile);


    printf("----cant de registros %d", al_len(pArrayListEmpleado));


    return 0;
}

