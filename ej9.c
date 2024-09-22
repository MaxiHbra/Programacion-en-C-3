/*Ejercicio 9: Dada una cantidad no determinada de n�meros naturales, para cada n�mero natural primo,
calcular su n�mero invertido y para cada n�mero natural no primo (compuesto) modificarlo eliminando
todos sus d�gitos primos. */
#include <stdio.h>

void ingreso(int*);
int primo(int);
void modificar(int*);
void invertir(int*);
void mostrar(int);


int main() {
	int x;
	ingreso(&x);
	while(x!=0){
		if(primo(x)==1)invertir(&x);
		else modificar(&x);
		mostrar(x);
		ingreso(&x);
	}
	return 0;
}
void ingreso(int *x){
	printf("\nIngresar X: ");
	scanf("%d",x);
}

int primo(int x){
	int pd=2,b=0;
	while(pd<= x/2 && x%pd!=0) pd++;
	if(pd>x/2 && x!=1)
		b=1;
	return b;
}
void modificar(int *x){
	int aux=*x,dig;
	*x=0;
	while(aux!=0){
		dig=aux%10;
		if(primo(dig)!=1) *x=(*x)*10+dig;
		aux=aux/10;
	}
	invertir(x);
}

void invertir(int *x){
	int aux=*x,dig;
	*x=0;
	while(aux!=0){
		dig=aux%10;
		*x=(*x)*10+dig;
		aux=aux/10;
	}
}

void mostrar(int x){
	printf("\nEl numero operado resulta: %d",x);
}
