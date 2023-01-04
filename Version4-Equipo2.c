#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

time_t t;
struct tm *tm;

struct articulo
{
	int clave;
	char desc[50];
	int ext;
	float costo;
	float precio;
	char unidad[15];
};

struct
{
	int num;
	char *date;
	int clave;
	int cantidad;
	int costo;
} typedef compra;

int j = 0, k = 0;

void crear();
void mostrar();
void cargar();
void mostrarI(); // poner despues las funciones para buscarlas y mostrarlas dependiendo de su clave
void mostrarP();
int Compra(int canti,int num);
int mostrarCompra(int canti);
int TXTcompra(int canti);

void agregar();

struct articulo art[100] = {0, " ", 0, 0.00, 0.00, " "};
compra compras[100];

int main()
{
	int i, op, opV, canti = 0, vc, num = 301;

	printf("___________________________________________\n");
	printf("\t\tQUE USUARIO ERES?\n");
	printf("___________________________________________\n");
	puts("\t\t1.- Encargado\n\t\t2.- Vendedor");
	scanf("%i", &op);
	switch (op)
	{
	case 1:
		printf("HOLA ENCARGADO\n");
		cargar();
		crear();
		mostrarI();
		printf("Que quiere hacer?\n");
		printf("1.- Agregar		2.-Compras\n");
		scanf("%i", &opV);
		switch (opV)
		{
		case 1:
			agregar();
			break;
		case 2:
			printf("Cuantos compras vas a registrar?");
			scanf("%i", &vc);
			for (i = 0; i < vc; i++)
			{
				canti = Compra(canti,num);
				TXTcompra(canti);
				num ++;
			}
			break;
		default:
			puts("Ups paso algo con la compra");
			break;
		}
		break;
	case 2:
		printf("HOLA VENDEDOR\n");
		cargar();
		crear();
		mostrarP();
		break;

	default:
		puts("ups");
		break;
	}

	/*cargar();
	crear();
	mostrar();
	printf("\nCuantos articulos agregara?");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		agregar();
	}mostrar();
	modificar();
	mostrarI();
	mostrarP();*/
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
	int num;

	printf("\nCuantos articulos agregara?");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
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

void mostrarI()
{
	// printf("____________________________________Insumos____________________________________________________\n");
	printf("________________________________________________________________________________________\n");
	printf("\t\t\t\t\tINZUMOS\n");
	printf("________________________________________________________________________________________\n");
	int i;
	printf("\n\t\tClave\tDesc\tStock\tCosto\tPrecio\tUnidad\n");

	for (i = 0; i < 100; i++)
	{
		if ((art[i].clave > 0) && (art[i].clave < 200))
		{
			printf("\t\t%d\t%s\t%d\t%.2f\t%.2f\t%s\n", art[i].clave, art[i].desc, art[i].ext, art[i].costo, art[i].precio, art[i].unidad);
		}
	}

	printf("________________________________________________________________________________________\n");
}
void mostrarP()
{
	printf("________________________________________________________________________________________\n");
	printf("\t\t\t\t\tPRODUCTOS\n");
	printf("________________________________________________________________________________________\n");
	int i;
	printf("\n\t\tClave\tDesc\tStock\tCosto\tPrecio\tUnidad\n");

	for (i = 0; i < 100; i++)
	{
		if ((art[i].clave > 200) && (art[i].clave < 300))
		{
			printf("\t\t%d\t%s\t%d\t%.2f\t%.2f\t%s\n", art[i].clave, art[i].desc, art[i].ext, art[i].costo, art[i].precio, art[i].unidad);
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
			// printf("%d|",art[j].clave);
			//  fgets(art.desc,50,fichero);
			fscanf(fichero, "%s", art[j].desc);
			// printf("%s|",art[j].desc);
			fscanf(fichero, "%d", &art[j].ext);
			// printf("%d|",art[j].ext);
			fscanf(fichero, "%f", &art[j].costo);
			// printf("%.2f|",art[j].costo);
			fscanf(fichero, "%f", &art[j].precio);
			// printf("%.2f|",art[j].precio);
			fscanf(fichero, "%s", art[j].unidad);
			// printf("%s|\n",art[j].unidad);
			//  fgets(art.unidad,15,fichero);
			// fread(&art[j], sizeof(art[j]), 1, fichero);

			// printf("%d\t%s\t%d\t%.2f\t%.2f\t%s\n",art[j].clave,art[j].desc,art[j].ext,art[j].costo,art[j].precio,art[j].unidad);
			j++;
		}
		fclose(fichero);
	}
}

int Compra(int canti, int num)
{

	int clave, i, cantidad = 0, date;
	char confirm;
	char fecha[100];

	printf("________________________________________________________________________________________\n");
	printf("Que quiere actualizar? (Ingresa la clave del producto)\t");
	scanf("%i", &clave);
	for (i = 0; i < 100; i++)
	{
		if (clave == art[i].clave)
		{
			
			do
			{
				printf("Que cantidad quiere actualizar de %s?\n", art[i].desc);
				scanf("%i", &cantidad);
				printf("Actuzlizara %s con la cantidad %i\n", art[i].desc, cantidad);
				printf("Es correcto? (Y/N)");
				fflush(stdin);
				scanf("%c", &confirm);
			} while (confirm == 'N' || confirm == 'n');
			printf("Que fecha ingresara para la compra?\n");
			printf("1.-Hoy		2.-Otra fecha\n");
			scanf("%i", &date);
			switch (date)
			{
			case 1:
				t = time(&t);
				tm = localtime(&t);
				strftime(fecha, 100, "%d/%m/%Y", tm);
				printf("Hoy es: %s\n", fecha);
				break;
			case 2:
				// validar fecha
				printf("Ingrese la fecha:");
				scanf("%s", fecha);
				break;

			default:
				printf("Ups");
				break;
			}

			printf("________________________________________________________________________________________\n");
			compras[canti].num = num;
			compras[canti].date = (char*)malloc(sizeof(char)*100);
			int cont = 0;
			while (fecha[cont] != '\0')
			{
				compras[canti].date[cont] = fecha[cont];
				cont++;
			}
			compras[canti].date[cont] = '\0';
			compras[canti].clave = clave;
			compras[canti].cantidad = cantidad;
			compras[canti].costo = art[i].costo;
			canti++;
		}
	}
	mostrarCompra(canti);
	return canti;
}

int mostrarCompra(int canti)
{

	printf("\t\t\t\t\tCOMPRA\n");
	printf("________________________________________________________________________________________\n");
	printf("\tNO.COMPRA\tFECHA\t\tCLAVE\tCANTIDAD\tCOSTO\n");
	for (int i = 0; i < canti; i++)
	{
		printf("\t%i\t\t%s\t%i\t%i\t\t%i\n", compras[i].num, compras[i].date, compras[i].clave, compras[i].cantidad, compras[i].costo);
	}
	return canti;
}

int TXTcompra(int canti)
{
	FILE *fichero;
	fichero = fopen("Compra.txt", "a");

	fputs("\tNO.COMPRA\tFECHA\t\tCLAVE\tCANTIDAD\tCOSTO\n",fichero);
	if (fichero == NULL)
	{
		printf("Error! al crear txt compra");
		exit(1);
	}

	for (int i = 0; i < canti; i++)
	{
		fprintf(fichero, "\t%i\t", compras[i].num);
		fprintf(fichero,"\t%s\t", compras[i].date);
		fprintf(fichero, "%i\t", compras[i].clave);
		fprintf(fichero,"%i\t",compras[i].cantidad);
		fprintf(fichero,"\t%i\n",compras[i].costo);
	}
	return canti;
}