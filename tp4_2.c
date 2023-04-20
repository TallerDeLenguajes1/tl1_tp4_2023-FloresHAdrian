#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea
{
    int TareaId;  //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; //entre 10-100
}typedef tarea;


void inicializarTareas( tarea ** tareas, int n);
void ingresarTareas(tarea ** tareas, int n);
void controlTareasRealizadas( tarea ** tareasPendientes, tarea ** tareasRealizadas,int n);
void mostrar( tarea ** tareas, int n);

int main(int argc, char const *argv[])
{
    int n;
    tarea ** tareasPendientes;
    tarea ** tareasRealizadas;
    printf("\n\nIngresar el numero de tareas a realizar: ");
    scanf("%d",&n);
    tareasPendientes =(tarea**) malloc(sizeof(tarea*)*n);//Le hago un sizof poirque el puntero struct es donde es posible que se a estar al estructura
                                                // Va el sizeof va devolver el tamaño de un puntero
    tareasRealizadas= (tarea**) malloc(sizeof(tarea*)*n); 
    inicializarTareas(tareasPendientes,n);
    inicializarTareas(tareasRealizadas,n);
    ingresarTareas(tareasPendientes,n);
    controlTareasRealizadas(tareasPendientes,tareasRealizadas,n);
    mostrar(tareasPendientes,n);
    // mostrar(tareasRealizadas,n);



    // Libero la memoria dinamica?
    for (int i = 0; i < n; i++)
    {
        free(tareasPendientes[i]->Descripcion);
        free(tareasPendientes[i]);
    }

    for (int i = 0; i < n; i++)
    {
        free(tareasRealizadas[i]->Descripcion);
        free(tareasRealizadas[i]);
    }
    free(tareasRealizadas);
    free(tareasPendientes);
    return 0;
}

void inicializarTareas( tarea ** tareas, int n){
    for (int i = 0; i < n; i++)
    {
        tareas[i] = NULL;
    }
}

void ingresarTareas(tarea ** tareas, int n){
    char *Buff;
    int dur=0;

    Buff= (char*)malloc(sizeof(char) * 250);
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        tareas[i] = malloc(sizeof(tarea));
        tareas[i]->TareaId=i;
        printf("\nIngresar duracion:");
        scanf("%d",&dur);
        fflush(stdin);     
        tareas[i]->Duracion=dur;
        printf("\nDescripcion de la Tarea: ");
        gets(Buff);
        fflush(stdin);
        tareas[i]->Descripcion = (char*)malloc(sizeof(char)*strlen(Buff+1));
        strcpy(tareas[i]->Descripcion,Buff);
        

    }
    free(Buff);
    
}


void controlTareasRealizadas( tarea ** tareasPendientes, tarea ** tareasRealizadas,int n){

    int aux=0,j=0;

    for (int i = 0; i < n; i++)
    {
        printf("\nEsta realizada la tarea %d, indique con SI=1 , NO=0: ",tareasPendientes[i]->TareaId+1);
        scanf("%d",&aux);
        if(aux==1){
            tareasRealizadas[j] = tareasPendientes[i];
            tareasPendientes[i]= NULL;
            j++;
        }
    }
}

void mostrar(tarea ** tareas, int n){
    for (int i = 0; i < n; i++)
    {
        if(tareas[i]!=NULL){
            printf("%s\n",tareas[i]->Descripcion);
        }
    }
    
}