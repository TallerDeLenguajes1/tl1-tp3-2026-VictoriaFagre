#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void MostrarPersonas(char *vAux[], int tamaAux);
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

void liberarMemoria(char *vAux[], int tamaAux) {
    for (int i = 0; i < tamaAux; i++) {
        free(vAux[i]);
    }
}