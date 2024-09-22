/*Ejercicio 6: Dados N números reales, con 4 dígitos decimales de precisión, cree un programa que, para
cada número real, cambie cada uno de sus dígitos impares por el dígito par anterior. Ejemplo A= 741,3478
entonces modificado A= 640,2468
Nota: reutilizar el modulo generado en el inciso 5*/
#include <stdio.h>

void ingreso(float*);
void ent_dec(int*,int*,float);
void mostrar(int,int);
void cambiar_impar(int*);
void invertir(int*);

int main() {
	int a,b;
	float x;
	ingreso(&x);
	ent_dec(&a,&b,x);
	cambiar_impar(&a);
	cambiar_impar(&b);
	mostrar(a,b);
	return 0;
}

void ingreso(float *x){
	printf("\n Por favor ingrese el valor de X: ");
	scanf("%f",x);
}

void ent_dec(int *ent, int *dec, float x){
	*ent=(int)x;
	*dec=(x-(*ent))*10000;
}
	
void mostrar(int a, int b){
	printf("\nEl numero modificado es: %d,%d ",a,b);
}
void cambiar_impar(int *y){
	int aux=*y;
	*y=0;
	while(aux!=0){
		if(aux%10 %2 !=0)
			*y=(*y)*10+(aux%10)-1;
		else *y=(*y)*10+(aux%10);
		aux=aux/10;
	}
	invertir(y);
}
void invertir(int *y){
	int aux=*y,dig;
	*y=0;
	while(aux!=0){
		dig=aux%10;
		*y=(*y)*10+dig;
		aux=aux/10;
	}
}
