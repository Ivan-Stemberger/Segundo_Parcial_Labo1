#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Controller.h"

int main()
{
    char path[20];
    LinkedList* pArrayLibros = ll_newLinkedList();

    printf("Por favor introduzca el nombre del archivo que desea cargar.\n");
    fflush(stdout);
    scanf("%s",path);

    controller_loadFromText(path,pArrayLibros);
    printf("El archivo se ha cargado exitosamente.\n");

    if(ll_sort(pArrayLibros,criterioAutor,1) == 0)
    {
        controller_ListLibro(pArrayLibros);
    }

    if(ll_map(pArrayLibros,descuentoLibro))
    {
    	controller_saveAsText("mapeado.csv",pArrayLibros);
    	printf("El archivo se ha guardado exitosamente.\n");
    }

    return 0;
}
