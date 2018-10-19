#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno{
	char nombre[256];
	char apellido[256];
	float promedio_parciales;
	float examen_final;
	int nota;
}alumnos[100];

int main(){
	FILE * archivo;
	int i, contador;
	float aux;
	char linea[1024];

	archivo  = fopen("alumnos.txt", "r"); //abrimos el archivo
	contador = 0;

	while (!feof(archivo)) {   //leemos hasta el fin final
		fgets(linea, 1024, archivo);  //leemos una linea

		strcpy(alumnos[contador].nombre,  strtok( linea, "," )); //comenzamos a parsear
		strcpy(alumnos[contador].apellido,  strtok( NULL, "," ));
		alumnos[contador].promedio_parciales = atof( strtok( NULL, "," ));
		alumnos[contador].examen_final = atof( strtok( NULL, "," ));

		aux = 0.4 * alumnos[contador].promedio_parciales + 0.6 * alumnos[contador].examen_final;  //calculamos de la nota
		if(aux <= 60 ) alumnos[contador].nota=1;
		else if(aux >= 61 && aux <= 70) alumnos[contador].nota=2;
		else if(aux >= 71 && aux <= 80) alumnos[contador].nota=3;
		else if(aux >= 81 && aux <= 90) alumnos[contador].nota=4;
		else alumnos[contador].nota=5;
		
		contador++; //incrementamos el contador
	}

	fclose(archivo); //cerramos el archivo

	//imprimimos
	for(i=0;i<contador;i++){
		printf("%s %s, %f %f %d", alumnos[i].nombre, alumnos[i].apellido, alumnos[i].promedio_parciales, alumnos[i].examen_final, alumnos[i].nota);
		printf("\n-----------------------------------\n");
	}

	return 0;
}