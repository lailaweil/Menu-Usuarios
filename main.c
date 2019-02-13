#include "funciones.h"

int main()
{	
	system("clear");
	int opcion, tipo_ordenamiento, error = 0, cant_usuarios = 0,back=0;
	nodo_t * usuarios = NULL;
	char archivo[30],legajo_a_eliminar[10];
	
	while(1){
		printf("------------------------------MENU------------------------------\n");
		printf("1) Ingresar usuario\n2) Leer archivo\n3) Imprimir usuarios\n4) Ordenar usuarios\n5) Eliminar usuario\n6) Salvar usuario\n7) Exit\n");
		scanf("%d",&opcion);

		switch(opcion){
			case 1:
				error = ingresa_usuario(&usuarios);
				if(error==-1){
					printf("Se produjo un ERROR!!\n");
					return 0;
				}
				cant_usuarios++;
				break;
			case 2:
				system("clear");
				printf("Ingrese el nombre del archivo: ");
				scanf("%s",archivo);
				error = lee_usuarios(&usuarios,archivo);
				if(error<0)
					return 0;
				cant_usuarios += error;
				break;
			case 3:
				imprimir_usuarios (&usuarios);
				printf("\n\n1)ATRAS\n");
				scanf("%d",&back);
				if(back==1){
					system("clear");
					break;
				}
				else{
					sleep(1000);
					break;
				}	
			case 4:
				system("clear");
				printf("Seleccione el tipo de ordenamiento:\n1)Ascendente\n2)Descendente\n");
				scanf("%d",&tipo_ordenamiento);

				if(tipo_ordenamiento==1){
					bubble_sort(usuarios, comp_ascendente, swap);
					system("clear");
					break;
				}
				else if(tipo_ordenamiento==2){
					bubble_sort(usuarios, comp_descendente, swap);
					system("clear");
					break;
				}
				break;
			case 5:
				system("clear");
				printf("Ingrese el legajo del usuario a eliminar: ");
				scanf("%s",legajo_a_eliminar);
				if(elimina_usuario(&usuarios,legajo_a_eliminar)==-1){
					printf("ERROR! no se pudo eliminar el usuario\n");
					return 0;
				}
				cant_usuarios -= 1;
				system("clear");
				break;
				
			case 6:
				system("clear");
				printf("Ingrese el nombre del archivo: ");
				scanf("%s",archivo);
				salva_usuarios (&usuarios,archivo);
				system("clear");
				break;
			case 7:
				liberar_lista(&usuarios);
				return 0;	
			default:
				system("clear");
				printf("Ingrese una opción válida\n");
				sleep(2);
				system("clear");
				break;
		}
	}
	
	return 0;
}