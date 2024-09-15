/*Ejercicio 1: Dado el siguiente programa modular, realice el seguimiento de los valores de las direcciones
	de memoria y de los datos almacenados en las variables a y b, declaradas en el main.*/
# include <stdio.h>
void muestra_parametros(int, int*); /*Declaracion de procedimiento definido por el programador*/
void incrementa_parametros(int, int*); /*Parametros formales, uno pasado por valor y otro por referencia*/
int main() {
	int a,b;
	printf("a = "); scanf("%d",&a); /*Pide el ingreso del valor de A*/
	printf("b = "); scanf("%d",&b); /*Pide el ingreso del valor de B*/
	printf("\nDATOS DEL MAIN\n");
	printf("valor de a: %d\n",a); /*Imprime el valor que guarda el espacio de memoria de A*/
	printf("direccion de memoria de a: %p\n",&a); /*La cadena de control utilizada para punteros, y el "&"da el lugar de memoria de la variable*/
	printf("valor de b: %d\n",b); /*Imprime el valor que guarda el espadio de memoria de B*/
	printf("direccion de memoria de b: %p\n",&b); /*Imprime la direccion de memoria que guardamos para B*/
	muestra_parametros(a,&b); /*Invocación del procedimiento muestra_parametros con parametros actuales*/
	incrementa_parametros(a,&b); /*el "&" apunta a la direccion de memoria de la variable B*/
	muestra_parametros(a,&b);
	return 0;
	}
void muestra_parametros(int x, int *y) {
	printf("\nDATOS DEL MODULO\n");
	printf("valor de x: %d\n",x); /*Como es un parametro pasado por valor, se muestra una copia de su contenido*/
	printf("direccion de memoria de x: %p\n",&x); /*Muestra a direccion de memoria de LA COPIA de la variable A en esta funcion*/
	printf("valor de y: %d\n",*y); /*Muestra el valor de B pasado por referencia, apuntado a la direccion de memoria*/
	printf("direccion de memoria de y: %p\n",y); /*Muestra la direccion de B, como la vble Y la tiene guardada*/
	}
void incrementa_parametros(int x, int *y) {
	x=x+1; /*incrementa el valor de A de manera local en esta función*/
	*y=*y+1; /*incrementa el valor de B guardada en la función main*/
	}
