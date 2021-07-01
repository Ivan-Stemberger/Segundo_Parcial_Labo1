#include "Libro.h"


int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int newLibro_params(eLibro* libro, int id, char* titulo, char* autor, int precio, char* editorial);
int controller_ListLibro(LinkedList* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
