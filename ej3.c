/*Ejercicio 3: Cree un programa que ingrese dos valores enteros A y B y que, a través de un menú,
a) muestre el número invertido de A,
b) muestre el invertido de B,
c) modifique y muestre ambos números, dejando en A el mayor y en B el menor.
Utilice, convenientemente, los módulos del ejercicio 2.*/
# include <stdio.h>

void maniular_enteros(int*);
void intercambiar(int*,int*);
int menu();
int main() {
	int a,b,op;
	printf("\nIngresar el primer entero: ");scanf("%d",&a);
	printf("\nIngresar el segundo entero: ");scanf("%d",&b);
	do{op=menu();
	switch(op){
	case 1 : maniular_enteros(&a); break;
	case 2 : maniular_enteros(&b); break;
	case 3 : if(a<b)intercambiar(&a,&b);
	printf("\nEl mayor se guardo en la variable A=%d y el menor B=%d \n",a,b); break;
	default : printf("\nUsted salio del programa.");
	}
	}while(op!=0);
	return 0;
	}
int menu(){
	int op;
	printf("\nPor favor ingresar 1 para mostrar el invertido de A.");
	printf("\nPor favor ingresar 2 para mostrar el invertido de B");
	printf("\nPor favor ingrese 3 para dejar en A el mayor y en B el menor entre ambos.");
	printf("\nPor favor ingresar 0 para salir del programa.\n");
	scanf("%d",&op);
	return op;
}
void maniular_enteros(int* x){
	int dig=0,aux=*x;
	*x=0;
	while(aux!=0){
	dig=aux%10;
	*x=*x*10+dig;
	aux=aux/10;
	}
	printf("\nLuego de ser invertido: %d \n",*x);
}
void intercambiar(int* a,int* b){
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}
