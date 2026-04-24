#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void MostrarPersonas(char *vAux[], int tamaAux);
char* BuscarNombre(char *claveAux, char *vAux[], int tamaAux);
void liberarMemoria(char *vAux[], int tamaAux);

int main (){

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

    char *cadenaAux[50];
    printf("\nEscriba una palabra clave para ser buscada en frase:");
    scanf("%s",cadenaAux);

    int tamCadena = strlen(cadenaAux);
    char *clave1 = (char *) malloc (tamCadena * sizeof(char) + 1);

    strcpy(clave1,cadenaAux);

    char *resultado = BuscarNombre(clave1,V,tama);

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

/*Implementar una nueva versión de la función BuscarNombre. 
Esta versión deberá recibir una palabra clave como argumento y retornar el 
primer nombre dentro del vector que contenga dicha palabra. Si no existe, 
debería devolver -1. 
(Investigá el uso de la función strstr para esta implementación.)*/

char* BuscarNombre(char *claveAux, char *vAux[], int tamaAux){

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