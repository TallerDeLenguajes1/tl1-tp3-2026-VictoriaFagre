#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void MostrarPersonas(char *vAux[], int tamaAux);
void liberarMemoria(char *vAux[], int tamaAux);
void BuscarNombre(int idAux, char *vAux[], int tamaAux);

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
    BuscarNombre(ID,V,tama);
    
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

void BuscarNombre(int idAux, char *vAux[], int tamaAux){
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

void liberarMemoria(char *vAux[], int tamaAux) {
    for (int i = 0; i < tamaAux; i++) {
        free(vAux[i]);
    }
}