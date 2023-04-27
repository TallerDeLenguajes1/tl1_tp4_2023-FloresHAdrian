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
void mostrarTarea(tarea tarea);
void mostrar( tarea ** tareas, int n);
tarea buscarTarea( tarea **tareasPendientes, tarea **tareasRealizadas,int n);

int main(int argc, char const *argv[])
{
    int n;
    tarea ** tareasPendientes;
    tarea ** tareasRealizadas;
    tarea tareaBuscada;
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
    // buscarTarea(tareasPendientes,tareasRealizadas,n);
    tareaBuscada = buscarTarea(tareasPendientes,tareasRealizadas,n);
    mostrarTarea(tareaBuscada);

    //*** Libero la memoria dinamica?***
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

void mostrarTarea( tarea tarea){

    printf("\nDescripcion: %s",tarea.Descripcion);
    printf("\nDuracion: %d",tarea.Duracion);
}

void mostrar(tarea ** tareas, int n){
    for (int i = 0; i < n; i++)
    {
        if(tareas[i]!=NULL){
            printf("%s\n",tareas[i]->Descripcion);
        }
    }
    
}


tarea buscarTarea( tarea ** tareasPendients, tarea ** tareasRealizas, int n){
    int id=0;
    printf("\n\n --Ingresar el id que se busca entre 0 y %d: ",n-1);
    scanf("%d",&id);
    for (int i = 0; i < n; i++)
    {
        if(tareasPendients[i]!=NULL &&  tareasPendients[i]->TareaId == id){
            return *tareasPendients[i];
            
        }
        if(tareasRealizas[i]!=NULL &&  tareasRealizas[i]->TareaId == id){
            return *tareasRealizas[i];        }
    }
    tarea aux;
    aux.TareaId = -1;
    return aux;
    
}