#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libro.h"

/** \brief Crea un puntero a un nuevo elemento
 *
 * \return libro eLibro* Regresa un puntero al nuevo elemento creado.
 *
 */
eLibro* libro_new(void)
{
    eLibro* libro = (eLibro*)malloc(sizeof(eLibro));

    if(libro == NULL)
    {
        printf("No hay espacio para un nuevo empleado.\n");
        fflush(stdout);
        return 0;
    }
    else
    {
        libro->id = 0;
        strcpy(libro->titulo, "");
        strcpy(libro->autor, "");
        libro->precio = 0;
        strcpy(libro->editorialId.editorial,"");
    }
    return libro;

}

/** \brief Función criterio utilizada por la función ll_sort para ordenar la lista por autor.
 *
 * \param libro1 void* puntero al elemento 1
 * \param libro2 void* puntero al elemento 2
 * \return mayor int 1 si el elemento 1 es mayor que el 2, 0 si no.
 *
 */

int criterioAutor(void* libro1, void* libro2)
{
    int mayor = 0;

    if(strcmp(((eLibro*)libro1)->autor,((eLibro*)libro2)->autor)>0)
    {
        mayor = 1;
    }

    return mayor;
}

/** \brief realiza el descuento en función de la editorial del libro.
 *
 * \param libro void* puntero al elemento libro
 *
 */
void descuentoLibro(void* libro)
{
    int precio;
    char editorial[52];
    eLibro* libroAux = libro;

    if(libro!=NULL)
    {


        if(getEditorial(libroAux,editorial),getPrecio(libroAux,&precio))
        {

            if(strcmp(editorial,"Planeta") == 0)
            {
                if(precio>=300)
                {
                    precio = precio * 8/10;
                    setPrecio(libroAux,precio);
                }
            }
            else if(strcmp(editorial,"SIGLO XXI EDITORES") == 0)
            {
                if(precio>=200)
                {
                    precio = precio * 9/10;
                    setPrecio(libroAux,precio);

                }
            }
        }
    }
}

void setId(eLibro* libro, int id)
{
    libro->id = id;
}

int getId(eLibro* libro,int* id)
{
    int gotten = 0;

    if(libro != NULL)
    {
        id = &libro->id;
        gotten = 1;
    }
    return gotten;
}


void setTitulo(eLibro* libro, char* titulo)
{
    strcpy(libro->titulo,titulo);
}

int getTitulo(eLibro* libro, char* titulo)
{
    int gotten = 0;

    if(libro != NULL)
    {
        strcpy(titulo,libro->titulo);
        gotten = 1;
    }
    return gotten;
}

void setAutor(eLibro* libro, char* autor)
{
    strcpy(libro->autor,autor);
}

int getAutor(eLibro* libro, char* autor)
{
    int gotten = 0;

    if(libro != NULL)
    {
        strcpy(autor,libro->autor);
        gotten = 1;
    }
    return gotten;
}

void setPrecio(eLibro* libro, int precio)
{
    libro->precio = precio;
}

int getPrecio(eLibro* libro, int* precio)
{
    int gotten = 0;

    if(libro != NULL)
    {
       *precio = libro->precio;
       gotten = 1;
    }
    return gotten;
}

void setEditorial(eLibro* libro, char* editorial)
{

    strcpy(libro->editorialId.editorial,editorial);

}

int getEditorial(eLibro* libro, char* editorial)
{
    int gotten = 0;

    if(libro != NULL)
    {
       strcpy(editorial,libro->editorialId.editorial);
       gotten = 1;
    }
    return gotten;
}


