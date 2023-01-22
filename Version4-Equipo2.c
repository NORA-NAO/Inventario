#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

time_t t;
struct tm *tm;

struct
{
    int clave;
    char desc[50];
    int ext;
    float costo;
    float precio;
    char unidad[15];
} typedef articulo;

struct
{
    int num;
    char *date;
    int clave;
    int cantidad;
    int costo;
} typedef compra;

struct
{
    int num;
    char *date;
    int clave;
    int cantidad;
    int costo;
    float precio;
} typedef venta;

int j = 0, k = 0;

void crear();
void mostrar();
void cargar(int *cont);
void mostrarI(); // poner despues las funciones para buscarlas y mostrarlas dependiendo de su clave
void mostrarP();
int Compra(int canti, int vc);
int mostrarCompra(int canti);
int TXTcompra(int canti);
int Venta(int canti, int vc);
int mostrarVenta(int canti);
int TXTVenta(int canti);
int binario(int tam, int elemento, articulo art[100]);
void eliminarTXT();
void menuE(int cont);
void menuV(int cont);
void menuP(int cont);
void agregarProductos();

void agregar(int *cont);

articulo art[100] = {0, " ", 0, 0.00, 0.00, " "};
compra compras[100];
venta ventas[100];
int i, op = 0, opcV = 0, canti = 0, vc = 0, opV = 0;
char confirm;
int main()
{
    int cont;
    cargar(&cont);
    crear();
    menuP(cont);
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

void agregarProductos()
{
    FILE *fichero;
    fichero = fopen("inventario.txt", "at");
    j = 0;
    do
    {
        fprintf(fichero, "%d\t%s\t%d\t%.2f\t%.2f\t%s\n", art[j].clave, art[j].desc, art[j].ext, art[j].costo, art[j].precio, art[j].unidad);
        j++;
    } while (art[j].clave != 0);
    fclose(fichero);
}

void agregar(int *cont)
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
        int n = 0;
        fflush(stdin);

        printf("\nClave:  ");
        // validar para que no se repita?

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
        /*for (int f=0; f<100; f++){
            if (art[f].clave==0){
                n=f-1;
                printf("Si entre");
            }
        }
        j = 0;
        do
        {
            fprintf(fichero, "%d\t%s\t%d\t%.2f\t%.2f\t%s\n", art[j].clave, art[j].desc, art[j].ext, art[j].costo, art[j].precio, art[j].unidad);
            j++;
        } while (art[j].clave != 0);
        Cerramos*/
        fclose(fichero);
        printf("\n________________________________________________________________________________________\n");
    }
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

void cargar(int *cont)
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
            (*cont)++;
        }
        fclose(fichero);
    }
}

int Compra(int canti, int vc)
{
    j = 0;
    int clave, i, cantidad = 0, date, num = 300;
    char fecha[100];
    FILE *fichero;
    fichero = fopen("Compra.txt", "rt");
    if (fichero == NULL)
    {
        printf("No hay fichero\n");
        num++;
    }
    else
    {
        while (feof(fichero) == 0)
        {
            fscanf(fichero, "%d", &compras[j].num);
            printf("%d|", compras[j].num);
            compras[j].date = (char *)malloc(sizeof(char) * 100);
            fscanf(fichero, "%s", compras[j].date);
            // printf("%s|", compras[j].date);
            fscanf(fichero, "%d", &compras[j].clave);
            // printf("%d|", compras[j].clave);
            fscanf(fichero, "%d", &compras[j].cantidad);
            // printf("%d|", compras[j].cantidad);
            fscanf(fichero, "%d", &compras[j].costo);
            // printf("%d|\n", compras[j].costo);
            j++;
        }
        num = compras[j - 2].num;
        num++;
    }
    for (int k = 0; k < vc; k++)
    {
        printf("________________________________________________________________________________________\n");

        printf("Que quiere actualizar? (Ingresa la clave del producto)\t");
        scanf("%i", &clave);
        while (clave <= 100 || clave > 199)
        {
            printf("\nClave incorrecta, ingrese una nueva: ");
            scanf("%i", &clave);
        }
        for (i = 0; i < 100; i++)
        {
            if (clave == art[i].clave)
            {
                do
                {
                    printf("Que cantidad quiere actualizar de %s?\n", art[i].desc);
                    scanf("%i", &cantidad);
                    while (cantidad > 1000)
                    {
                        printf("Lo sentimos esa cantidad excede el almacenamiento disponible, ingrese otra cantidad por favor:\n");
                        scanf("%i", &cantidad);
                    }
                    printf("Actuzlizara %s con la cantidad %i\n", art[i].desc, cantidad);
                    printf("Es correcto? (Y/N)");
                    fflush(stdin);
                    scanf("%c", &confirm);
                } while (confirm == 'N' || confirm == 'n');

                t = time(&t);
                tm = localtime(&t);
                strftime(fecha, 100, "%d/%m/%Y", tm);
                printf("Hoy es: %s\n", fecha);

                printf("________________________________________________________________________________________\n");
                compras[canti].num = num;
                compras[canti].date = (char *)malloc(sizeof(char) * 100);
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
                num++;

                art[i].ext = art[i].ext + cantidad;
                mostrarCompra(canti);
                
                
            }
        }
       eliminarTXT();
       crear();
       agregarProductos(); 
    }
    fclose(fichero);
    TXTcompra(canti);
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

    // fputs("\tNO.COMPRA\tFECHA\t\tCLAVE\tCANTIDAD\tCOSTO\n", fichero);
    if (fichero == NULL)
    {
        printf("Error! al crear txt compra");
        exit(1);
    }

    for (int i = 0; i < canti; i++)
    {
        fprintf(fichero, "%i\t", compras[i].num);
        fprintf(fichero, "%s\t", compras[i].date);
        fprintf(fichero, "%i\t", compras[i].clave);
        fprintf(fichero, "%i\t", compras[i].cantidad);
        fprintf(fichero, "%i\n", compras[i].costo);
    }
    fclose(fichero);
    return canti;
}

int Venta(int canti, int vc)
{
    j = 0;
    int clave, i, cantidad = 0, date, num = 400;
    char fecha[100];
    FILE *fichero;
    fichero = fopen("Venta.txt", "rt");
    if (fichero == NULL)
    {
        printf("No hay fichero\n");
        num++;
    }
    else
    {
        while (feof(fichero) == 0)
        {
            fscanf(fichero, "%d", &ventas[j].num);
            // printf("%d|", ventas[j].num);
            ventas[j].date = (char *)malloc(sizeof(char) * 100);
            fscanf(fichero, "%s", ventas[j].date);
            // printf("%s|", ventas[j].date);
            fscanf(fichero, "%d", &ventas[j].clave);
            // printf("%d|", ventas[j].clave);
            fscanf(fichero, "%d", &ventas[j].cantidad);
            // printf("%d|", ventas[j].cantidad);
            fscanf(fichero, "%d", &ventas[j].costo);
            // printf("%d|", ventas[j].costo);
            fscanf(fichero, "%f", &ventas[j].precio);
            // printf("%.2f|\n", ventas[j].precio);
            j++;
        }
        num = ventas[j - 2].num;
        num++;
    }
    for (int k = 0; k < vc; k++)
    {
        printf("________________________________________________________________________________________\n");
        printf("Que quiere actualizar? (Ingresa la clave del producto)\t");
        scanf("%i", &clave);
        while (clave <= 200 || clave > 299)
        {
            printf("\nClave incorrecta, ingrese una nueva: ");
            scanf("%i", &clave);
        }
        for (i = 0; i < 100; i++)
        {
            if (clave == art[i].clave)
            {
                if (art[i].ext == 0)
                {
                    printf("Lo sentimos ya no tenemos en existencia este producto");
                    return 0;
                }
                else
                {
                    do
                    {
                        printf("Que cantidad quiere actualizar de %s?\n", art[i].desc);
                        scanf("%i", &cantidad);
                        while (cantidad > art[i].ext)
                        {
                            printf("Esa cantidad excede el stock disponible, ingrese otra cantidad por favor:\n");
                            scanf("%i", &cantidad);
                        }
                        printf("Actuzlizara %s con la cantidad %i\n", art[i].desc, cantidad);
                        printf("Es correcto? (Y/N)");
                        fflush(stdin);
                        scanf("%c", &confirm);
                    } while (confirm == 'N' || confirm == 'n');

                    t = time(&t);
                    tm = localtime(&t);
                    strftime(fecha, 100, "%d/%m/%Y", tm);
                    printf("Hoy es: %s\n", fecha);

                    printf("________________________________________________________________________________________\n");
                    ventas[canti].num = num;
                    ventas[canti].date = (char *)malloc(sizeof(char) * 100);
                    int cont = 0;
                    while (fecha[cont] != '\0')
                    {
                        ventas[canti].date[cont] = fecha[cont];
                        cont++;
                    }
                    ventas[canti].date[cont] = '\0';
                    ventas[canti].clave = clave;
                    ventas[canti].cantidad = cantidad;
                    ventas[canti].costo = art[i].costo;
                    ventas[canti].precio = art[i].precio;
                    canti++;
                    num++;

                    art[i].ext = art[i].ext - cantidad;
                    eliminarTXT();
                    crear();
                    agregarProductos();
                }
            }
        }
        mostrarVenta(canti);
    }
    fclose(fichero);
    TXTVenta(canti);
    return canti;
}

int mostrarVenta(int canti)
{

    printf("\t\t\t\t\tVENTA\n");
    printf("________________________________________________________________________________________\n");
    printf("\tNO.VENTA\tFECHA\t\tCLAVE\tCANTIDAD\tCOSTO\tPRECIO\n");
    for (int i = 0; i < canti; i++)
    {
        printf("\t%i\t\t%s\t%i\t%i\t\t%i\t%.2f\n", ventas[i].num, ventas[i].date, ventas[i].clave, ventas[i].cantidad, ventas[i].costo, ventas[i].precio);
    }
    return canti;
}

int TXTVenta(int canti)
{
    FILE *fichero;
    fichero = fopen("Venta.txt", "a");

    // fputs("\tNO.COMPRA\tFECHA\t\tCLAVE\tCANTIDAD\tCOSTO\n", fichero);
    if (fichero == NULL)
    {
        printf("Error! al crear txt venta");
        exit(1);
    }

    for (int i = 0; i < canti; i++)
    {
        fprintf(fichero, "%i\t", ventas[i].num);
        fprintf(fichero, "%s\t", ventas[i].date);
        fprintf(fichero, "%i\t", ventas[i].clave);
        fprintf(fichero, "%i\t", ventas[i].cantidad);
        fprintf(fichero, "%i\t", ventas[i].costo);
        fprintf(fichero, "%.4f\n", ventas[i].precio);
    }
    fclose(fichero);
    return canti;
}

void eliminarTXT()
{
    FILE *archivo;

    if (remove("inventario.txt") == -1)
    {
        printf("Error al eliminar el archivo txt");
    }
    /*else
    {
        printf("Archivo eliminado con exito\n");
    }*/
}

int binario(int tam, int elemento, articulo art[100])
{
    printf("se busca: %i\n", elemento);
    int posIzq = 0;
    int posDer = tam - 1;
    int mitad = 0;

    // Se repite hasta que ya no se pueda dividir
    while (posIzq <= posDer)
    {
        // encontramos la mitad del arreglo
        mitad = (posIzq + posDer) / 2;

        // Si encuentra el elemento a buscar, entonces ya lo encontró

        if (art[mitad].clave == elemento)
        {

            return mitad;
            break;
            // Si el elemento buscado es mayor, entonces ya no está en la derecha e ignora la parte izquierda desde la mitad
        }
        else if (elemento > art[mitad].clave)
        {
            posIzq = mitad + 1;

            // Si no, entonces está en la derecha y se ignora la derecha
        }
        else
        {
            posDer = mitad - 1;
        }
        // al final si se vuelve a repetir el while, entonces se vuelve a calcular la mitad
        // si sale del while, entonces no lo encontró y regresa un dato inválido para el manejo del error en el main
    }

    return -1;
}

void menuE(int cont)
{
    system("clear");
    printf("HOLA ENCARGADO\n");
    mostrarI();
    printf("Que quiere hacer?\n");
    printf("1.- Agregar\t2.-Compras\n");
    printf("3.-Buscar\t4.-Salir\n");
    scanf("%i", &opV);
    int indiceEncontrado = 0, clave;
    switch (opV)
    {
    case 1:
        agregar(&cont);
        menuE(cont);
        break;
    case 2:
        printf("________________________________________________________________________________________\n");
        printf("Cuantos compras vas a registrar?");
        scanf("%i", &vc);
        while (vc <= 0 || vc > 10)
        {
            printf("\nNo se pueden ingresar mas de 10 elementos, ingrese la cantidad de nuevo porfavor: ");
            scanf("%i", &vc);
        }
        Compra(canti, vc);
        fflush(stdin);
        printf("\nDesea ir al menu? (Y/N)\n");
        scanf("%c", &confirm);
        if (confirm == 'y' || confirm == 'Y')
        {
            menuE(cont);
            system("clear");
        }
        else
        {
            exit(1);
        }
        break;
    case 3:
        printf("________________________________________________________________________________________\n");
        printf("Que quiere Buscar? (Ingresa la clave del producto)\t");
        scanf("%i", &clave);
        while (clave <= 100 || clave > 199)
        {
            printf("\nClave incorrecta, ingrese una nueva: ");
            scanf("%i", &clave);
        }
        indiceEncontrado = binario(cont, clave, art);
        printf("El producto es: %s\n", art[indiceEncontrado].desc);
        printf("Stock: %i\n", art[indiceEncontrado].ext);
        printf("Precio: %.2f\n", art[indiceEncontrado].precio);
        printf("Costo: %.2f\n", art[indiceEncontrado].costo);
        printf("________________________________________________________________________________________\n");
        fflush(stdin);
        printf("\nDesea ir al menu? (Y/N)\n");
        scanf("%c", &confirm);
        if (confirm == 'y' || confirm == 'Y')
        {
            menuE(cont);
            system("clear");
        }
        else
        {
            exit(1);
        }
        break;
    case 4:

        menuP(cont);
        break;
    default:
        puts("Ups paso algo con la compra");
        break;
    }
}

void menuV(int cont)
{
    system("clear");
    printf("Hola vendedor\n");
    mostrarP();
    printf("Que quiere hacer?\n");
    printf("1.- Ventas\t2.-Buscar\n");
    printf("3.-Salir\n");
    scanf("%i", &opcV);
    int indiceEncontrado, claveV = 0;
    switch (opcV)
    {
    case 1:
        printf("Cuantas ventas va a registrar?");
        scanf("%i", &vc);
        while (vc <= 0 || vc > 10)
        {
            printf("\nNo se pueden ingresar mas de 10 elementos, ingrese la cantidad de nuevo porfavor: ");
            scanf("%i", &vc);
        }
        Venta(canti, vc);
        fflush(stdin);
        printf("\nDesea ir al menu? (Y/N)\n");
        scanf("%c", &confirm);
        if (confirm == 'y' || confirm == 'Y')
        {
            menuV(cont);
            system("clear");
        }
        else
        {
            exit(1);
        }
        break;
    case 2:
        printf("________________________________________________________________________________________\n");
        printf("Que quiere Buscar? (Ingresa la clave del producto)\t");
        scanf("%i", &claveV);
        while (claveV <= 200 || claveV > 299)
        {
            printf("\nClave incorrecta, ingrese una nueva: ");
            scanf("%i", &claveV);
        }
        indiceEncontrado = binario(cont, claveV, art);
        printf("%i\n", indiceEncontrado);
        printf("El producto es: %s\n", art[indiceEncontrado].desc);
        printf("Stock: %i\n", art[indiceEncontrado].ext);
        printf("Precio: %.2f\n", art[indiceEncontrado].precio);
        printf("Costo: %.2f\n", art[indiceEncontrado].costo);
        printf("________________________________________________________________________________________\n");
        fflush(stdin);
        printf("\nDesea ir al menu? (Y/N)\n");
        scanf("%c", &confirm);

        if (confirm == 'y' || confirm == 'Y')
        {
            menuV(cont);
            system("clear");
        }
        else
        {
            exit(1);
        }
        break;
    case 3:
        menuP(cont);
        break;

    default:
        printf("No existe esta opcion");
        break;
    }
}

void menuP(int cont)
{
    system("clear");
    printf("\n___________________________________________\n");
    printf("\t\tQUE USUARIO ERES?\n");
    printf("___________________________________________\n");
    puts("\t\t1.- Encargado\n\t\t2.- Vendedor\n\t\t3.- Salir");
    scanf("%i", &op);
    switch (op)
    {
    case 1:
        menuE(cont);
        break;
    case 2:
        menuV(cont);
        break;
    case 3:
        exit(1);
        break;
    default:
        printf("No existe esta opcion");
        menuP(cont);
        break;
    }
}