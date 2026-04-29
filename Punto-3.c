#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"}; 
typedef struct Producto { 
    int ProductoID; //Numerado en ciclo iterativo 
    int Cantidad;  //entre 1 y 10 
    char *TipoProducto; // Algún valor del arreglo TiposProductos       
    float PrecioUnitario; // entre 10 - 100 
}Prod;


typedef struct Cliente{
    int ClienteID;  // Numerado en el ciclo iterativo              
    char *NombreCliente; //  Ingresado por usuario 
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5) 
    Prod *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”  
}Clien;

void limpioBuffer(){ 
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}

float calcularCosto(char *tipo, Prod *prodAux, int cantAux){

    for (int i = 0; i < cantAux; i++){
        if (strcmp(prodAux[i].TipoProducto,tipo) == 0){
            return prodAux[i].PrecioUnitario * prodAux[i].Cantidad;
        }
    }
    return 0; //si no encontro nada al final
}

void liberarPuntero(Clien *clienAux, int cantCliente){
    for(int i = 0; i < cantCliente; i++){
        free(clienAux[i].NombreCliente);
        free(clienAux[i].Productos);
    }
    free(clienAux);
}



int main(){

    srand(time(NULL));

    int cantidadCliente;
    printf("Ingrese la cantidad de clientes:");
    scanf("%d",&cantidadCliente);
    //obligatorio luego de scanf y antes de fgets
    limpioBuffer();

    //Clien cliente[cantidadCliente];
    Clien *cliente = (Clien*)malloc(cantidadCliente*sizeof(Clien)); 
    
    for(int i = 0; i < cantidadCliente; i++){
        cliente[i].ClienteID = i+1;
        printf("ID cliente: %d\n", cliente[i].ClienteID);
        
        char nombreAux[50];
        printf("Ingrese el nombre del cliente %d:", i+1);
        fgets(nombreAux, 50, stdin);

        nombreAux[strcspn(nombreAux, "\n")] = '\0'; //saco el /0 (por si uso strcmp)

        int longNombre = strlen(nombreAux);
        char *nombre = (char*)malloc(longNombre * sizeof(char)+1); //liberar desp
        strcpy(nombre,nombreAux);

        cliente[i].NombreCliente = nombre;
        printf("Nombre del cliente %d: %s\n", i+1,cliente[i].NombreCliente);

        cliente[i].CantidadProductosAPedir = 1 + rand() % 5;
        int cantidadAux = cliente[i].CantidadProductosAPedir;
        printf("Cantidad de productos: %d\n", cantidadAux);

        // Prod prod[cantidadAux];
        Prod *prod = (Prod*)malloc(cantidadAux*sizeof(Prod));

        for(int j = 0; j < cantidadAux; j++){
            prod[j].ProductoID = j+1;
            //pongo el id del cliente seguidon del id del producto 
            printf("ID del producto: %d.%d\n",cliente[i].ClienteID,prod[j].ProductoID);

            prod[j].Cantidad = 1 + rand()%10;
            printf("Cantidad: %d\n", prod[j].Cantidad);

           int indiceAux = rand() % 4;

           prod[j].TipoProducto = TiposProductos[indiceAux];
           printf("Tipo: %s\n",prod[j].TipoProducto);

            //liminf+rand()%(limsup-liminf+1)
           prod[j].PrecioUnitario = 10 + rand() % (100-10+1);
           printf("Precio unitario: %.2f\n",prod[j].PrecioUnitario);
        }

        /*Hago que el campo puntero del struct cliente apunte al inicio de la dirección
         de memoria de mi estructura de datos definida a partir de la cantidad de productos*/ 

        cliente[i].Productos = prod; 

        char tipoAux[20];
        
        printf("Ingrese el tipo de producto a calcular el precio:");
        fgets(tipoAux,20,stdin);
        // int longtipoAux = strlen(tipoAux);
        // char *tipo = (char*)malloc(longtipoAux*sizeof(char)+1);

        // strcpy(tipo,tipoAux);

        tipoAux[strcspn(tipoAux, "\n")] = '\0';
        
        float costo = calcularCosto(tipoAux, prod, cantidadAux);
        printf("El costo del producto es: %.2f\n", costo);
        
    }

    liberarPuntero(cliente, cantidadCliente);

    return 0;
}
 
