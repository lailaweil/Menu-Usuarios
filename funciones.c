#include "funciones.h"

int inserta_usuario ( nodo_t ** p, datos_t usuario){
	system("clear");
	nodo_t *l;

	l= (nodo_t*)malloc(sizeof(nodo_t));
	l->data=(datos_t*)malloc(sizeof(datos_t));

	if(l->data==NULL || l==NULL){
		if(l->data==NULL){
			free(l->data);
		}
		free(l);
		return -1;
	}

	l->prox = NULL;

	strcpy(l->data->apellido,usuario.apellido);
	strcpy(l->data->nombre,usuario.nombre);
	strcpy(l->data->sexo,usuario.sexo);
	strcpy(l->data->legajo,usuario.legajo);
	l->data->edad = usuario.edad;

	l->prox = *p;
	//ahora modifico el comienzo de la lista
	*p = l;

	return 0;
}
//**********************************************************************************************************
int ingresa_usuario (nodo_t ** p){
	system("clear");
	datos_t datos;

	printf("Ingrese el nombre: ");
	scanf("%s",datos.nombre);

	printf("Ingrese el apellido: ");
	scanf("%s",datos.apellido);

	printf("Ingrese la edad: ");
	scanf("%d",&datos.edad);

	printf("Ingrese el sexo: ");
	scanf("%s",datos.sexo);

	printf("Ingrese el legajo: ");
	scanf("%s",datos.legajo);

	return inserta_usuario(p,datos);
}
//**********************************************************************************************************
int lee_usuarios ( nodo_t ** p, char * datos){
	
	FILE* origen;
	datos_t aux;
	int i,j=0;

	origen = fopen(datos, "r");

	if(origen ==NULL){ //Veo si existe el archivo
		printf("ERROR en origen! Archivo no existe\n");
		return -1;
	}
	while(1){
		i = fscanf(origen,"%[^,],%[^,],%d,%[^,],%s\n",aux.nombre,aux.apellido,&aux.edad,aux.sexo,aux.legajo);
		
		if(i==-1)//Termino el archivo
			break;
			
		if(i<5 || i>5){ //el archivo tiene formato incorrecto
			printf("Error en el archivo. Formato incorrecto!\n");
			fclose(origen);
			return -1;
		}
		inserta_usuario(p,aux)!=-1;
		j++;
			
	}
	fclose(origen);
	return j;
}
//**********************************************************************************************************
void bubble_sort(nodo_t *p, int (*fcomp)(char *x, char *y), void(*fswap)(datos_t **m, datos_t **n)){

    nodo_t * q;

    for(;p->prox; p=p->prox){
        for(q=p->prox; q; q=q->prox){
	    	if(fcomp(p->data->apellido, q->data->apellido))
				swap(&(p->data), &(q->data));
        }
    }

}
void swap(datos_t **p, datos_t **q){
    datos_t * aux;

    aux = *p;
    *p = *q;
    *q = aux;
}

int comp_ascendente(char *x, char *y){
    return strcmp(x,y)>0;
}


int comp_descendente(char *x, char *y){
    return strcmp(x,y)<0;
}

//**********************************************************************************************************
void imprimir_usuarios ( nodo_t ** p){
	system("clear");
	int usuario=1;
	nodo_t * aux = (*p) ; //me guardo el comienzo de la lista

	if(*p==NULL){ //Me fijo si esta vacia la lista
		printf("La lista se encuentra vacia!!\n");
		return;
	}

	do{
		printf("----------------Usuario %d----------------\n",usuario);
		printf("Nombre: %s\n",(*p)->data->nombre);
		printf("Apellido: %s\n",(*p)->data->apellido);
		printf("Edad: %d\n",(*p)->data->edad);
		printf("Sexo: %s\n",(*p)->data->sexo);
		printf("Legajo: %s\n",(*p)->data->legajo);
		usuario++;
		*p = (*p)->prox;
	}while((*p)!=NULL);
	(*p)=aux; //vuelvo al comienzo de la lista
}
//**********************************************************************************************************
int elimina_usuario (nodo_t ** p, char * legajo){
	nodo_t * comienzo = (*p)
	nodo_t * aux ; //me guardo el comienzo de la lista
	int i=0;

	if(*p==NULL){ // si la lista esta vacia
		printf("La lista se encuentra vacia!!\n");
		return -1;
	}
	do{
		if(i==0 && (strcmp((*p)->data->legajo,legajo)==0)){//si es la primera estructura que hay que eliminar 
			*p=(*p)->prox;//solo modifico el comienzo de la lista y libero 
			free(comienzo->data);
			free(comienzo);
			return 0;
			}	
		else if(strcmp((*p)->prox->data->legajo,legajo)==0){//si es culquiera otra estructura la que hay que elimiar
			aux=(*p)->prox;
			(*p)->prox = (*p)->prox->prox; //swap
			free(aux->data);
			free(aux);
			(*p) = comienzo ;//vuelvo al comienzo de la lista
			return 0;                      
		}
		i++;//contador para saber que elemento de la lista es
		*p = (*p)->prox; //me muevo dentro de la lista
		}while((*p)!=NULL);
	(*p) = comienzo ;// si no lo encontro vuelvo al comienzo
	return -1;
}
//**********************************************************************************************************
int salva_usuarios ( nodo_t ** p, char * datos){
	FILE * origen;
	int usuarios = 0;
	nodo_t * aux = (*p) ;//auxiliar para guardar el comienzo de la lista

	origen = fopen(datos,"w");//abro archivo
	
	if(*p==NULL){//no hay nada en la lista para guardar HAY QUE MODIFICAR PARA QUE GUARDE LA LISTA VACIA ENTONCES
		return 0;
	}

	do{
		fprintf(origen,"%s,%s,%d,%s,%s\n",(*p)->data->nombre,(*p)->data->apellido,(*p)->data->edad,(*p)->data->sexo,(*p)->data->legajo );
		usuarios++;
		*p = (*p)->prox;//me muevo en el archivo
	}while((*p)!=NULL);
	
	fclose(origen);//cierro el archivo
	(*p) = aux ;
	return usuarios;
}
//**********************************************************************************************************
void liberar_lista ( nodo_t ** p){
	nodo_t * aux;
	do{
		aux = (*p)->prox;//guardo la proxima estructura en auxiliar
		free((*p)->data);
		free((*p));
		*p = aux;
	}while((*p)!=NULL);
}