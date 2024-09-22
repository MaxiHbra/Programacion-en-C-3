/*Ejercicio 4: Cree un programa que ingrese una fracción de la forma A/B y que a continuación devuelva
la fracción irreductible equivalente. ejemplo se A= 6 y B= 8; ( 6 / 8 )entonces Ar= 3 y Br= 4 ( 3 / 4 )
Nota: Generar un procedimiento que reciba A y B, que devuelva Ar y Br*/
#include <stdio.h>

void reduccion(int*, int*);
void mostrar(int, int);
void ingreso(int*,int*);

int main() {
	int a,b;
	ingreso(&a,&b);
	reduccion(&a, &b);
	mostrar(a, b);
	return 0;
}

void ingreso(int *a, int*b){
	printf("\n Por favor ingrese el valor del numerador A: ");
	scanf("%d",a);
	printf("\n Por favor ingrese el valor del denominador B: ");
	scanf("%d",b);
	printf("\nLa fraccion sin reducir es: %d/%d ",*a,*b);
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
void mostrar(int a, int b){
	printf("\nLa fraccion reducida es: %d/%d ",a,b);
}
