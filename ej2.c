/*Ejercicio 2: Diseñe módulos (prototipo más implementación) para cada uno de los casos que se enuncian
a continuación, con el propósito de utilizarlos en problemas posteriores:
a) Calcule y retorne la cantidad de horas, minutos y segundos que existen en una cantidad de segundos
ingresada por el usuario.
b) Manipule dos números enteros quitando la última cifra del primero y añadiéndola al final del segundo.
c) Reciba dos variables enteras e intercambie sus valores. .*/
# include <stdio.h>

void calculo_tiempo(int,int*,int*,int*);
void maniular_enteros(int*,int*);
void intercambiar(int*,int*);

int main() {
	int a,b;
	int x,seg,min,hora;
	printf("\nIngresar cantidad de segundos a calcular: ");scanf("%d",&x);
	calculo_tiempo(x,&seg,&min,&hora);
	printf("\nLa cantidad de %d segundos equivale a: %d horas, %d minutos y %d segundos.",x,hora,min,seg);
	printf("\nIngresar el primer entero: ");scanf("%d",&a);
	printf("\nIngresar el segundo entero: ");scanf("%d",&b);
	maniular_enteros(&a,&b);
	printf("\nLuego de ser manipulados A=%d y B=%d",a,b);
	printf("\nIngresar el primer entero: ");scanf("%d",&a);
	printf("\nIngresar el segundo entero: ");scanf("%d",&b);
	intercambiar(&a,&b);
	printf("\nLuego de ser cambiados A=%d y B=%d",a,b);
	return 0;
	}
void calculo_tiempo(int x,int* seg,int* min,int* hora){
	*hora=x/3600;
	*min=(x%3600)/60;
	if(*min==0) *seg=x%3600;
	else *seg=(x%3600)%60;
}
void maniular_enteros(int* a,int *b){
	int dig=*a%10;
	*a=*a / 10;
	*b=*b * 10 + dig;
}
void intercambiar(int* a,int* b){
	int aux=*a;
	*a=*b;
	*b=aux;
}
