#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Libro.h"


/** \brief Carga los datos de los libros desde el path (modo texto).
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

/** \brief Toma los parametros y los setea en el Libro.
 *
 * \param libro eLibro* entidad a cargar con los datos
 * \param id int id del libro
 * \param titulo char* titulo del libro
 * \param autor char* nombre del autor
 * \param precio int precio del libro
 * \param editorial char* editorial del libro
 * \return returned int regresa 1 si salió bien. 0 si no.
 *
 */

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


/** \brief Muestra por pantalla todos los libros.
 *
 * \param pArrayListLibro LinkedList* Listado de libros
 * \return int 1 si salió bien. 0 si no.
 *
 */
int controller_ListLibro(LinkedList* pArrayListLibro)
{
	int listed = 0;
    int indice= ll_len(pArrayListLibro);
    int i;

	if(pArrayListLibro!=NULL && ll_len(pArrayListLibro)>0)
	{
	    eLibro* libro;

	    printf("\n ID ||                      TITULO                       ||         AUTOR       || PRECIO ||   EDITORIAL\n");
	    fflush(stdout);

	    for (i=0;i<indice;i++)
	    {
	        libro = ll_get(pArrayListLibro,i);

	        printf(" %-3d|| %-50s||   %-18s||  %-6d||   %s \n",libro->id,libro->titulo,libro->autor,libro->precio,libro->editorialId.editorial);
	        fflush(stdout);
	    }

	    listed = 1;
	}


    return listed;
}


/** \brief Guarda los datos de los libros en el archivo mapeado.csv (modo texto).
 *
 * \param path char* path del archivo
 * \param pArrayListLibro LinkedList* Listado de libros
 * \return saved int 1 si funciona, 0 si no
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

