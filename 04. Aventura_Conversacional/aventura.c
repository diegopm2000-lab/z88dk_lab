#include "datos.h"

#include <stdio.h>
#include <string.h>

void inicializarHabitaciones(THabitacion habitaciones[]) {

    habitaciones[0].id = 1;
    strcpy(habitaciones[0].descripcion,"Te encuentras en la entrada de la taberna de Melee Island. Desde aqui puedes oler los vomitos de los borrachos que vas a encontrar en su interior.");
    habitaciones[0].direcciones[0] = 4;
    habitaciones[0].direcciones[1] = 2;
    habitaciones[0].direcciones[2] = 0;
    habitaciones[0].direcciones[3] = 0;
 
    habitaciones[1].id = 2;
    strcpy(habitaciones[1].descripcion,"Las sombras del callejon en el que te encuentras te sobrecogen. Estas rodeado de montones de basura.");
    habitaciones[1].direcciones[0] = 0;
    habitaciones[1].direcciones[1] = 0;
    habitaciones[1].direcciones[2] = 0;
    habitaciones[1].direcciones[3] = 1;
 
    habitaciones[2].id = 3;
    strcpy(habitaciones[2].descripcion,"Estas en uno de los dormitorios de la taberna. Varias literas estan alineadas, permitiendo a muchos piratas dormir juntos en una misma habitacion.");
    habitaciones[2].direcciones[0] = 0;
    habitaciones[2].direcciones[1] = 0;
    habitaciones[2].direcciones[2] = 0;
    habitaciones[2].direcciones[3] = 4;
 
    habitaciones[3].id = 4;
    strcpy(habitaciones[3].descripcion,"El salon principal de la taberna. Decenas de piratas se encuentran aquí bebiendo, cantando, peleandose, vomitando, y metiendo mano a las doncellas del lugar. Si te diriges al norte, este u oeste podras visitar varias de las habitaciones del local.");
    habitaciones[3].direcciones[0] = 6;
    habitaciones[3].direcciones[1] = 3;
    habitaciones[3].direcciones[2] = 1;
    habitaciones[3].direcciones[3] = 5;
 
    habitaciones[4].id = 5;
    strcpy(habitaciones[4].descripcion,"Una gran cantidad de pucheros sucios estan amontonados en la cocina. Platos a medio comer, jarras medio llenas, y cubiertos sucios les hacen compania.");
    habitaciones[4].direcciones[0] = 0;
    habitaciones[4].direcciones[1] = 4;
    habitaciones[4].direcciones[2] = 0;
    habitaciones[4].direcciones[3] = 0;
 
    habitaciones[5].id = 6;
    strcpy(habitaciones[5].descripcion,"Tras apartar una cortina accedes a un reservado. Es una zona exclusiva de la taberna a donde muy pocos piratas pueden acceder.");
    habitaciones[5].direcciones[0] = 0;
    habitaciones[5].direcciones[1] = 0;
    habitaciones[5].direcciones[2] = 4;
    habitaciones[5].direcciones[3] = 0;
}

void escribirDescripcion(THabitacion habitaciones[], int habitacion, TObjeto objetos[]) {

    printf(habitaciones[habitacion].descripcion);
    printf("\n\n");

    printf("Salidas:");
    if (habitaciones[habitacion].direcciones[0] != 0)
        printf(" %c[4mNorte%c[24m",27,27);
    if (habitaciones[habitacion].direcciones[1] != 0)
        printf(" %c[4mEste%c[24m",27,27);
    if (habitaciones[habitacion].direcciones[2] != 0)
        printf(" %c[4mSur%c[24m",27,27);
    if (habitaciones[habitacion].direcciones[3] != 0)
        printf(" %c[4mOeste%c[24m",27,27);
    printf("\n\n");

    printf("En la habitacion puedes ver:");
    int hayObjetos = 0;
    int i=0;
	for (i=0;i<4;i++) {
		if (objetos[i].localizacion == habitaciones[habitacion].id) {
			printf(" %s",objetos[i].nombre);
			hayObjetos = 1;
        }
    }
	if (hayObjetos == 0)
		printf(" nada");
      
	printf("\n\n");	
}

void inicializarObjetos(TObjeto objetos[]) {

	strcpy(objetos[0].nombre,"una espada");
	objetos[0].localizacion = 5;
	objetos[0].peso = 5;
 
	strcpy(objetos[1].nombre,"una jarra");
	objetos[1].localizacion = -1;
    objetos[1].peso = 3;

    char c[2];
    
    c[0] = 27;
    c[1] = '\0';
    strcpy(objetos[2].nombre,"una antorcha ");
    strcat(objetos[2].nombre,c);
    strcat(objetos[2].nombre,"[44mapagada"); 
    strcat(objetos[2].nombre,c);
    strcat(objetos[2].nombre,"[47m");
    objetos[2].localizacion = 2;
    objetos[2].peso = 2;
     
    strcpy(objetos[3].nombre,"una antorcha ");
    strcat(objetos[3].nombre,c);
    strcat(objetos[3].nombre,"[43mencendida"); 
    strcat(objetos[3].nombre,c);
    strcat(objetos[3].nombre,"[47m");
    objetos[3].localizacion = -2;
    objetos[3].peso = 2;
}

void main(void) {
    
    int habitacion = 0;
    int final = 0; // Cuando valga 1, indica que la aventura ha terminado
    char comando[250];
    int i;
    int hayObjetos = 0;
    char palabra[50];
    int pesoTransportado;
    
    THabitacion habitaciones[6];
    TObjeto objetos[4];   

    inicializarHabitaciones(habitaciones);
    inicializarObjetos(objetos);
    pesoTransportado = objetos[1].peso;
    
    escribirDescripcion(habitaciones, habitacion, objetos);
    
    while (final == 0) {

        printf("Que hago ahora? - ");
        gets(comando);
    
        if (strcmp(comando,"m") == 0 || strcmp(comando,"mirar") == 0) {
            
            for (i=0;i<32;i++) {
                printf("\n");
            }
        
            escribirDescripcion(habitaciones, habitacion, objetos);

        } else if (strcmp(comando,"n") == 0 || strcmp(comando,"norte") == 0) {

            if (habitaciones[habitacion].direcciones[0] != 0) {
                habitacion = habitaciones[habitacion].direcciones[0] - 1;
                printf("\n\n");
                escribirDescripcion(habitaciones, habitacion, objetos);
            } else {
                printf("\n\nNo puedo ir en esa direccion\n\n");
            }
        } else if (strcmp(comando,"e") == 0 || strcmp(comando,"este") == 0) {

            if (habitaciones[habitacion].direcciones[1] != 0) {
                habitacion = habitaciones[habitacion].direcciones[1] - 1;
                printf("\n\n");
                escribirDescripcion(habitaciones, habitacion, objetos);
            } else {
                printf("\n\nNo puedo ir en esa direccion\n\n");
            }
        } else if (strcmp(comando,"s") == 0 || strcmp(comando,"sur") == 0) {
            if (habitaciones[habitacion].direcciones[2] != 0) {
                habitacion = habitaciones[habitacion].direcciones[2] - 1;
                printf("\n\n");
                escribirDescripcion(habitaciones, habitacion, objetos);
            } else {
                printf("\n\nNo puedo ir en esa direccion\n\n");
            }
        } else if (strcmp(comando,"o") == 0 || strcmp(comando,"oeste") == 0) {
            if (habitaciones[habitacion].direcciones[3] != 0) {
                habitacion = habitaciones[habitacion].direcciones[3] - 1;
                printf("\n\n");
                escribirDescripcion(habitaciones, habitacion, objetos);
            } else {
                printf("\n\nNo puedo ir en esa direccion\n\n");
            }
        } else if (strcmp(comando,"i") == 0 || strcmp(comando,"inventario") == 0) {
            hayObjetos = 0;
            printf("\n\nLlevas:");
            for (i = 0; i<4;i++)
                if (objetos[i].localizacion == -1)
                {
                    printf(" %s",objetos[i].nombre);
                    hayObjetos = 1;
                }
            if (hayObjetos == 0)
                printf(" nada");
            printf("\n\n");	
        } else if (strcmp(comando,"coger una antorcha") == 0) {
            if (objetos[2].localizacion == habitacion + 1)
            {
                if (objetos[2].peso + pesoTransportado <= 6)
                {
                    objetos[2].localizacion = -1;
                    printf("\n\nHe cogido %s\n\n",objetos[2].nombre);
                    pesoTransportado += objetos[2].peso;
                }
                else
                    printf("\n\nNo puedo transportar mas peso\n\n");
            }
            else if (objetos[3].localizacion == habitacion + 1)
            {
                if (objetos[3].peso + pesoTransportado <= 6)
                {
                    objetos[3].localizacion = -1;
                    printf("\n\nHe cogido %s\n\n",objetos[3].nombre);
                    pesoTransportado += objetos[3].peso;
                }
                else
                    printf("\n\nNo puedo transportar mas peso\n\n");
            }
            else
                printf("\n\nNo puedo hacer eso\n\n");
        } else if (strcmp(comando,"dejar una antorcha") == 0) {
            if (objetos[2].localizacion == -1) {
                objetos[2].localizacion = habitacion + 1;
                pesoTransportado -= objetos[2].peso;
                printf("\n\nHe dejado %s\n\n",objetos[2].nombre);
            }
            else if (objetos[3].localizacion == -1) {
                objetos[3].localizacion = habitacion + 1;
                pesoTransportado -= objetos[3].peso;
                printf("\n\nHe dejado %s\n\n",objetos[3].nombre);
            } else
                printf("\n\nNo puedo hacer eso\n\n");
        } else if (strcmp(comando,"encender antorcha") == 0) {
            if (objetos[2].localizacion == -1)
            {
                objetos[2].localizacion = -2;
                objetos[3].localizacion = -1;
                printf("\n\nHe encendido la antorcha\n\n");
            }
            else
                printf("\n\nNo puedo hacer eso\n\n");
        } else if (strcmp(comando,"apagar antorcha") == 0) {
            if (objetos[3].localizacion == -1)
            {
                objetos[3].localizacion = -2;
                objetos[2].localizacion = -1;
                printf("\n\nHe apagado la antorcha\n\n");
            }
            else
                printf("\n\nNo puedo hacer eso\n\n");
        } else {

            // Comandos con más de una palabra

            strcpy(palabra,strtok(comando," "));
            if (strcmp(comando,"coger") == 0) {
                strcpy(palabra,strtok(0,"\0"));
                if (palabra == 0)
                    printf("\n\nNecesito que me digas que tengo que coger\n\n");
                else {
                    hayObjetos = 0;
                    i = 0;
                    while (hayObjetos == 0 && i<4) {
                        if (strcmp(objetos[i].nombre,palabra) == 0 && 
                            objetos[i].localizacion == habitacion+1) {
                            objetos[i].localizacion = -1;
                            hayObjetos = 1;
                            if (objetos[i].peso + pesoTransportado <= 6) {
                                objetos[i].localizacion = -1;
                                printf("\n\nHe cogido %s\n\n",palabra);
                                pesoTransportado += objetos[i].peso;
                            }
                            else
                                printf("\n\nNo puedo transportar mas peso\n\n");
                        }
                        i++;
                    }
                    if (hayObjetos == 0)
                        printf("\n\nNo puedo hacer eso\n\n");
                }
            } else if (strcmp(comando,"dejar") == 0) {
                strcpy(palabra,strtok(0,"\0"));
                if (palabra == 0)
                    printf("\n\nNecesito que me digas que tengo que dejar\n\n");
                else {
                    hayObjetos = 0;
                    i = 0;
                    while (hayObjetos == 0 && i<4) {
                        if (strcmp(objetos[i].nombre,palabra) == 0 
                            && objetos[i].localizacion == -1) {
                            objetos[i].localizacion = habitacion+1;
                            hayObjetos = 1;
                            printf("\n\nHe dejado %s\n\n",palabra);
                            pesoTransportado -= objetos[i].peso;
                        }
                        i++;
                    }
                    if (hayObjetos == 0)
                        printf("\n\nNo puedo hacer eso\n\n");
                }
            } else
                printf("\n\nNo entiendo lo que dices\n\n");
        }
    }
}
