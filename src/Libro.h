#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

typedef struct
{
    int id;
    char editorial[128];

}eEditorial;


typedef struct
{
    int id;
    char titulo[128];
    char autor[10];
    int precio;
    eEditorial editorialId;
}eLibro;

eLibro* libro_new(void);
int criterioAutor(void* libro1, void* libro2);
int editorialById(LinkedList* pArrayLibros, eEditorial* editorial, int len);
void descuentoLibro(void* libro);
void setLibroEditorialId(eEditorial* editorial, int len, LinkedList* libro);
void setId(eLibro* libro, int id);
int getId(eLibro* libro,int* id);
void setTitulo(eLibro* libro, char* titulo);
int getTitulo(eLibro* libro, char* titulo);
void setAutor(eLibro* libro, char* autor);
int getAutor(eLibro* libro, char* autor);
void setPrecio(eLibro* libro, int precio);
int getPrecio(eLibro* libro, int* precio);
void setEditorial(eLibro* libro, char* editorial);
int getEditorial(eLibro* libro, char* editorial);
int getEditorialId(eLibro* libro, int* id);





#endif // LIBRO_H_INCLUDED

