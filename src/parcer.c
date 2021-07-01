#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Controller.h"


/** \brief Parsea los datos los datos de los libros desde el archivo de texto pFile.
 *
 * \param pFile FILE* puntero al archivo de texto
 * \param pArrayListLibro LinkedList* listado de libros
 * \return parsed int 1 si funcion�, 0 si no.
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
    int parsed = 0;
	int cantidad = 0;
    char idStr[10];
    char tituloStr[52];
    char autorStr[52];
    char precioStr[52];
    char editorialStr[52];


    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idStr, tituloStr, autorStr, precioStr, editorialStr);
            if(cantidad != 5)
            {
                printf("Error en la carga\n\n");
                system("pause");
            }
            else
            {
                if(strcmp(idStr,"id")!=0)
                {
                    eLibro* libro = libro_new();

                    newLibro_params(libro,atoi(idStr), tituloStr, autorStr, atoi(precioStr), editorialStr);

                    ll_add(pArrayListLibro, libro);
                }

            }
        }
    fclose(pFile);
    parsed = 1;
    }
    else
    {
        printf("No hay archivo.\n");
        system("pause");

    }
    return parsed;
}
