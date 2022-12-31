#include <stdio.h>
#include <stdlib.h>

struct articulo
{
	int clave;
	char desc[50];
	int ext;
	float costo;
	float precio;
	char unidad[15];
};

int j = 0, k = 0;

void crear();
void mostrar();
void cargar();
void mostrarI(); //poner despues las funciones para buscarlas y mostrarlas dependiendo de su clave
void mostrarP();

void agregar();

struct articulo art[100]={0," ",0,0.00,0.00," "};

int main()
{
	int i, num;

	cargar();
	crear();
	mostrar();
	/*printf("\nCuantos articulos agregara?");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		agregar();
	}mostrar();
	modificar();*/
	mostrarI();
	mostrarP();
}

void crear()
{

	FILE *fichero;

	fichero = fopen("inventario.txt", "a");

	if (fichero == NULL)
	{
		/* Imprimimos un mensaje para indicar que no existe. */
		printf("El inventario no se ha podido abrir, no existe.");
	}
	else
	{
		fclose(fichero);
	}
}

void agregar()
{
	FILE *fichero;
	fichero = fopen("inventario.txt", "at");

	if (fichero == NULL)
	{
		/* Imprimimos un mensaje para indicar que no existe. */
		printf("El inventario no se ha podido abrir, no existe.");
	}
	else
	{
		int n;
		fflush(stdin);

		printf("\nClave:  ");
		// validar para que no se repita�?
		scanf("%d", &art[j].clave);

		printf("\nDescripcion:  ");
		scanf("%s", art[j].desc);

		printf("\nExistencia:  ");
		scanf("%d", &art[j].ext);

		printf("\nCosto:  ");
		scanf("%f", &art[j].costo);

		printf("\nPrecio:  ");
		scanf("%f", &art[j].precio);

		printf("\nUnidad:  ");
		scanf("%s", art[j].unidad);

		fprintf(fichero, "%d\t%s\t%d\t%.2f\t%.2f\t%s\n", art[j].clave, art[j].desc, art[j].ext, art[j].costo, art[j].precio, art[j].unidad);
		// fputc('\n', fichero);
		// fwrite(&art,sizeof(art),1,fichero);

		/* Cerramos*/
		fclose(fichero);
		printf("\n________________________________________________________________________________________\n");
	}
}

void mostrar()
{
	char caracter;
	FILE *fichero;
	fichero = fopen("inventario.txt", "r");
	printf("________________________________________________________________________________________\n");
	printf("\t\tINVENTARIO\n");
	printf("________________________________________________________________________________________\n");
	if (fichero == NULL)
	{
		printf("\nError: No se ha podido abrir el inventario\n");
	}
	else
	{
		printf("\nClave\tDesc\tStock\tCosto\tPrecio\tUnidad\n");
		while (feof(fichero) == 0)
		{
			caracter = fgetc(fichero);
			printf("%c", caracter);
		}

		fclose(fichero);
	}
	printf("________________________________________________________________________________________\n");
}

void mostrarI(){
	//printf("____________________________________Insumos____________________________________________________\n");
	printf("________________________________________________________________________________________\n");
	printf("\t\t\t\t\tINZUMOS\n");
	printf("________________________________________________________________________________________\n");
	int i;
	printf("\n\t\tClave\tDesc\tStock\tCosto\tPrecio\tUnidad\n");
	
	for(i=0;i<100;i++){
		if((art[i].clave>0 ) && (art[i].clave<200)){
			printf("\t\t%d\t%s\t%d\t%.2f\t%.2f\t%s\n",art[i].clave,art[i].desc,art[i].ext,art[i].costo,art[i].precio,art[i].unidad);
		}
	}
	
	printf("________________________________________________________________________________________\n");
}
void mostrarP(){
	printf("________________________________________________________________________________________\n");
	printf("\t\t\t\t\tPRODUCTOS\n");
	printf("________________________________________________________________________________________\n");
	int i;
	printf("\n\t\tClave\tDesc\tStock\tCosto\tPrecio\tUnidad\n");
	
	for(i=0;i<100;i++){
		if((art[i].clave>200 ) && (art[i].clave<300)){
			printf("\t\t%d\t%s\t%d\t%.2f\t%.2f\t%s\n",art[i].clave,art[i].desc,art[i].ext,art[i].costo,art[i].precio,art[i].unidad);
		}
	}
	
	printf("________________________________________________________________________________________\n");
}

void cargar()
{
	FILE *fichero;
	fichero = fopen("inventario.txt", "rt");
	if (fichero == NULL)
	{
		printf("Error: No se ha podido abrir el inventario");
	}
	else
	{
		while (feof(fichero) == 0)
		{
			fscanf(fichero, "%d", &art[j].clave);
			printf("%d|",art[j].clave);
			// fgets(art.desc,50,fichero);
			fscanf(fichero, "%s", art[j].desc);
			printf("%s|",art[j].desc);
			fscanf(fichero, "%d", &art[j].ext);
			printf("%d|",art[j].ext);
			fscanf(fichero, "%f", &art[j].costo);
			//printf("%.2f|",art[j].costo);
			fscanf(fichero, "%f", &art[j].precio);
			//printf("%.2f|",art[j].precio);
			fscanf(fichero, "%s", art[j].unidad);
			//printf("%s|\n",art[j].unidad);
			// fgets(art.unidad,15,fichero);
			//fread(&art[j], sizeof(art[j]), 1, fichero);
			
			
			//printf("%d\t%s\t%d\t%.2f\t%.2f\t%s\n",art[j].clave,art[j].desc,art[j].ext,art[j].costo,art[j].precio,art[j].unidad);
			j++;
		}
		fclose(fichero);
	}
}
