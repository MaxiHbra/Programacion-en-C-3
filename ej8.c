/*Ejercicio 8: Dada una cantidad no determinada de fracciones, de la forma “A/B”, convertir cada fracción
en irreductible e indicar si la fracción originalmente ingresada sufrió transformación.
Nota: reutilizar el modulo generado en el inciso 4*/
#include <stdio.h>

void ingresar(int*,int*);
void reduccion(int*, int*);
void muestra(int*,int*);
int verificar(int,int,int,int);

int main() {
	int num,den;
	ingresar(&num,&den);
	return 0;
}
void ingresar(int *a,int *b){
	while(*a!=0 && *b!=0){
		printf("\nPor favor ingresar el numerador: ");
		scanf("%d",a);
		printf("\nPor favor ingresar el denominador: ");
		scanf("%d",b);
		if(*b!=0)muestra(a,b);
		else printf("\nEl denominador no puede ser 0");
	}
}

void muestra(int *a,int *b){
	int auxA=*a,auxB=*b;
	reduccion(a,b);
	if(verificar(*a,*b,auxA,auxB))
		printf("\nLa fraccion no sufrio modificaciones: %d/%d",auxA,auxB);
	else printf("\nLa fraccion reducida es: %d/%d",*a,*b);
}
	
int verificar(int a, int b, int c, int d){
		int band=0;
		if(a==c && b==d) band=1;
		return band;
}
void reduccion(int *a, int *b){
	int i;
	i=2;
	while(i!=10){
		if(*a%i==0 && *b%i==0){
			*a=*a/i;
			*b=*b/i;
		}
		i++;
	}
}
