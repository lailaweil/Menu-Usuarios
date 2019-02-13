#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define TAMANO 30

typedef struct {
	char nombre[TAMANO];
	char apellido[TAMANO];
	int edad;
	char sexo[10];
	char legajo[10];
} datos_t;
struct nodo {
	datos_t * data;
	struct nodo * prox;
};
typedef struct nodo nodo_t;

int inserta_usuario ( nodo_t ** p, datos_t usuario);
int ingresa_usuario (nodo_t ** p);
int lee_usuarios ( nodo_t ** p, char * datos);
void bubble_sort(nodo_t *p, int (*fcomp)(char *x, char *y), void(*fswap)(datos_t **m, datos_t **n));
void imprimir_usuarios ( nodo_t ** p);
int elimina_usuario (nodo_t ** p, char * legajo);
int salva_usuarios ( nodo_t ** p, char * datos);
void liberar_lista ( nodo_t ** p);
int comp_ascendente(char *x, char *y);
int comp_descendente(char *x, char *y);
void swap(datos_t **p, datos_t **q);