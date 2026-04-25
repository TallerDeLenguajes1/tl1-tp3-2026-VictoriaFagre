#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void MostrarPersonas(char *vAux[], int tamaAux);
char* BuscaNombrePorPalabra (char *claveAux, char *vAux[], int tamaAux);
void liberarMemoria(char *vAux[], int tamaAux);
void BuscaNombrePorId(int idAux, char *vAux[], int tamaAux);

int main (){
    srand(time(NULL));
    char nombre[50];
    int tama = 5;
    char *V[tama];
    for(int i = 0; i < tama; i++){
        printf("Ingrese el nombre de la persona %d:", i + 1);
        scanf("%s",nombre);

        int tamaNombre = strlen(nombre);
        char *cadena = (char*)malloc(tamaNombre * sizeof(char) + 1); 
        strcpy(cadena,nombre);

        V[i] = cadena;
    }

    MostrarPersonas(V, tama);
    int ID;
    ID = 1 + rand()%(7);
    printf("\nID generado(para verificar): %d", ID);
    BuscaNombrePorId(ID,V,tama);
    
    char *cadenaAux[50];
    printf("\nEscriba una palabra clave para ser buscada en frase:");
    scanf("%s",cadenaAux);

    int tamCadena = strlen(cadenaAux);
    char *clave1 = (char *) malloc (tamCadena * sizeof(char) + 1);

    strcpy(clave1,cadenaAux);

    char *resultado = BuscaNombrePorPalabra(clave1,V,tama);

    if(resultado != NULL){
        printf("La 1era palabra encontrada fue: %s\n", resultado);
    }else{
        printf("No se encontro nignuna palabra: %d",-1);
    }

    liberarMemoria(V, tama);

    return 0;
}

void MostrarPersonas(char *vAux[], int tamaAux){
    printf("Los nombres alojados en el vector son:");
    printf("[");
    for(int i = 0; i < tamaAux; i++){
        
        if(i != 4){
            printf("%s, ", vAux[i]);
        }else{
             printf("%s", vAux[i]);
        }
        
    }
    printf("]");
}
/*En este branch, implementar una función BuscarNombre que reciba un número entero 
positivo de ID (índice del vector) como entrada y Escribir por pantalla el nombre 
ubicado en esa posición dentro del vector. Si el número ingresado no pertenece al 
vector escribir “no se encontró el valor buscado”. */

void BuscaNombrePorId(int idAux, char *vAux[], int tamaAux){
    int bandera = 0;
    for(int i = 0; i < tamaAux; i++){
        if(i == (idAux-1)){
            printf("\nEl nombre ubicado en la posicion %d del vector es: %s", i+1,vAux[i]);
            bandera = 1;
        }
    }
    if(bandera == 0){
        printf("\nNo se encontro el valor buscado");
    }
}

/*Implementar una nueva versión de la función BuscarNombre. 
Esta versión deberá recibir una palabra clave como argumento y retornar el 
primer nombre dentro del vector que contenga dicha palabra. Si no existe, 
debería devolver -1. 
(Investigá el uso de la función strstr para esta implementación.)*/

char* BuscaNombrePorPalabra(char *claveAux, char *vAux[], int tamaAux){

    for(int i = 0; i < tamaAux; i++){
        if(strstr(vAux[i],claveAux) != NULL){
            return vAux[i];
        }
    }
    return NULL; //si no encontro nada que haga retornar, entonces la devolución final es NULL
}


void liberarMemoria(char *vAux[], int tamaAux) {
    for (int i = 0; i < tamaAux; i++) {
        free(vAux[i]);
    }
}