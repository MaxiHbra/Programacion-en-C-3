/*Ejercicio 5: Cree un programa que ingrese un número real X, que trabaje con 4 dígitos decimales de
precisión, a partir de este número real obtener la parte entera de X y su parte decimal convertida a un número entero.
Nota: Generar un procedimiento que reciba X y devuelva PentX, PdecX. Ejemplo, si X= 123,5432,
entonces PentX=123 y PdecX= 5432*/
#include <stdio.h>

void ingreso(float*);
void ent_dec(int*,int*,float);
void mostrar(int,int);

int main() {
	int ent,dec;
	float x;
	ingreso(&x);
	ent_dec(&ent,&dec,x);
	mostrar(ent,dec);
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
	printf("\nLa parte sin decimales es:%d \nLa parte decimal es:%d ",a,b);
}
