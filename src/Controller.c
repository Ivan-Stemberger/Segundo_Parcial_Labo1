#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Libro.h"


/** \brief Carga los datos de los corredors desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListLibro)
{
    int load = 0;

    printf("%s\n",path);

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        load = parser_LibroFromText(pFile, pArrayListLibro);
    }
    else
    {
        printf("El archivo no existe\n\n");
        fflush(stdout);
        system("pause");
    }

    return load;
}

int newLibro_params(eLibro* libro, int id, char* titulo, char* autor, int precio, char* editorial)
{
    int returned = 0;

    if(libro != NULL)
    {
        setId(libro, id);
        setTitulo(libro,titulo);
        setAutor(libro,autor);
        setPrecio(libro,precio);
        setEditorial(libro,editorial);
        returned = 1;
    }

    return returned;
}


/** \brief Listar corredors
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListLibro(LinkedList* pArrayListLibro)
{
    printf("Entro al listado");

    eLibro* libro;
    int indice= ll_len(pArrayListLibro);
    int i;

    printf("\n ID ||                      TITULO                       ||         AUTOR       || PRECIO ||   EDITORIAL\n");
    fflush(stdout);


    for (i=0;i<indice;i++)
    {
        libro = ll_get(pArrayListLibro,i);

        printf(" %-3d|| %-50s||   %-18s||  %-6d||   %s \n",libro->id,libro->titulo,libro->autor,libro->precio,libro->editorialId.editorial);
        fflush(stdout);
    }


    return 1;
}


/** \brief Guarda los datos de los corredors en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char path[] , LinkedList* pArrayListLibro)
{
    FILE* archivo = fopen(path, "w");
    int len = ll_len(pArrayListLibro);
    eLibro* libro = libro_new();
    int saved = 0;

    if(pArrayListLibro != NULL )
    {
        fprintf(archivo, "id,titulo,autor,precio,editorial\n");
        for(int i=0; i<len; i++)
        {
                libro = ll_get(pArrayListLibro,i);
                fprintf(archivo, "%d,%s,%s,%d,%s\n", libro->id, libro->titulo, libro->autor, libro->precio, libro->editorialId.editorial);
        }
        fclose(archivo);
        return 1;
        printf("\nLos datos han sid_libroo almacenados.\n");
        fflush(stdout);
        saved = 1;

    }
    return saved;
}

