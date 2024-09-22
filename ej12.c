
#include <stdio.h>

int validar(long); /*modulo del tipo funcion para validar el numero que se ingresa*/
void ingresar(long*); /*modulo del tipo procedimiento para ingresar un entero largo sobre una variable de main*/
void codificar(long*); /*modulo del tipo procedimiento para convertir de binario a numero resumido*/
void decodificar(long*); /*modulo del tipo procedimiento para convertir de un numero resumido a binario*/
int invertir(long); /*funcion para invertir un numero ya tratado*/
int menu(); /*funcion para mostrar opciones de menu y retornar la opcion elegida*/


int main() {
	int opc;
	long mensaje; /*tipo de dato entero mas extenso posible para este enunciado*/
	do{
		opc=menu(); /*menu tradicional*/
		switch(opc){						/*ACLARACIÓN: El mensaje que se manda al espacio se ingresa en BINARIO y el que se recibe se ingresa en GRUPO DE BITS*/
		case 1 : ingresar(&mensaje);
		if(validar(mensaje)){  /*si la funcion valida retorna 1=verdadero*/
			codificar(&mensaje); /*se codifica el mensaje ingresado*/
			printf("\nEl mensaje que envio es: %ld \n",mensaje);
		}
		else printf("\nEl mensaje que se quiere mandar es invalido.\n");
		break;
		case 2 : ingresar(&mensaje);
		decodificar(&mensaje);
		if(validar(mensaje))
		printf("\nEl mensaje que recibio es: %ld \n",mensaje);
		else printf("\nIngreso un mensaje invalido.");
		break;
		default : printf("\nUsted salio del programa.\n");
		}
	}while(opc!=0);
	return 0;
}
int menu(){ /*menu tradicional*/
	int opc;
	printf("\nPresione 1 para enviar un mensaje EN BINARIO.");
	printf("\nPresione 2 para decodificar un mensaje que recibio EN GRUPO DE BITS.");
	printf("\nPresione 0 para salir del programa. \n");
	scanf("%d",&opc);
	return opc;
}
void ingresar(long *mensaje){ /*procedimiento de ingreso*/
	printf("\nMENSAJE: ");
	scanf("%ld",mensaje);
}
int validar(long mensaje){ /*funcion de validacion: comprueba si el numero esta compuesto por solamente ceros y unos*/
	int dig,b;
	b=1;
	while(mensaje!=0){
		dig=mensaje%10;
		if(dig!=1 && dig!=0)b=0;
		mensaje=mensaje/10;
	}
	return b;
}
void codificar(long *mensaje){
	long aux=*mensaje;
	int cont,dig;
	*mensaje=0;
	cont=0;
	while(aux!=0){ /*repetir hasta la ultima cifra*/
		dig=aux%10; /*sacar ultimo digito del numero y contar*/
		cont++; 
		if(dig!=((aux/10)%10)){ /*si el digito es distinto al siguiente, se acaba este grupo de bits*/
			if(dig==0)
			*mensaje=*mensaje*10+9;  /*convierte los 0 en 9 para que no haya error de representacion interna*/
			else *mensaje=*mensaje*10+dig;
			*mensaje=*mensaje*10+cont;  /*se agrega la cantidad de veces que se repite*/
			cont=0;  /*se reinicia el contador para el sig grupo de bits*/
		}
		aux=aux/10; 
	}
	*mensaje=invertir(*mensaje); /*ya que el mensaje se trata de derecha a izquierda, invertirlo*/
}
void decodificar(long *mensaje){
	long aux=*mensaje;
	*mensaje=0;
	int dig,num; 
	while(aux!=0){ /*mismo while que el anterior pero con otro ciclo dentro para armar*/
		dig=aux%10; 
		num=(aux/10)%10;  /*sacar DIG=digito a tratar y NUM=veces que se repitio*/
		while(num!=0){ 
			if(dig==0) /*herramienta reutilizada, convierte los 0 en 9 para que no se borren al invertir*/
			*mensaje=*mensaje*10+9; /*se inserta tantas veces el digito como NUM lo indique*/
			else *mensaje=*mensaje*10+dig;
			num--;
		}
		aux=aux/100;
	}
	*mensaje=invertir(*mensaje); /*al igual que el anterior, tambien se trabaja de derecha a izq y se invierte*/
}
int invertir(long mensaje){ /*funcion de invertir reutilizada, convierte los 9 en 0 para que haya errores de interpretacion interna*/
	int dig;
	long aux=0;
	while(mensaje!=0){
		dig=mensaje%10;
		if(dig==9) aux=aux*10;
		else aux=aux*10+dig;
		mensaje=mensaje/10;
	}
	return aux;
}
