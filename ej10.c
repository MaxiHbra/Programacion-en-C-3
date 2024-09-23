/*Ejercicio 10: Dada una lista de N fechas ingresadas por el usuario, representadas como números enteros
con el formato (AAAADDMM), se pide indicar cuántas fechas son válidas y cuántas no lo son. Se debe
tener en cuenta los años bisiestos.
Nota: un año será bisiesto si es divisible entre 4, sin embargo, no puede ser divisible entre 100, a menos
que también lo sea por 400. Se debe crear un módulo que separe la fecha en día, mes y año. */
#include <stdio.h>

void ingreso(long*);
void separar(long,int*,int*,int*);
int bisiesto(int);
int verificar(int,int,int);
void contar(int*,int,int,int);

int main() {
	int i,N,D,M,A,cont;
	long fecha;
	printf("\nPor favor ingresar N: ");
	scanf("%d",&N);
	cont=0;
	for(i=1;i<=N;i++){
		ingreso(&fecha);
		separar(fecha,&D,&M,&A);
		contar(&cont,D,M,A);
	}
	printf("\nDe las fechas ingresadas %d son validas.",cont);
	return 0;
}

void ingreso(long *fecha){
	printf("\nPor favor ingrese una fecha en formato AAAADDMM: ");
	scanf("%ld",fecha);
}
void separar(long fecha,int *D,int *M,int *A){
	*M=fecha%100;
	fecha=fecha/100;
	*D=fecha%100;
	fecha=fecha/100;
	*A=fecha;
}
void contar(int *cont,int D,int M,int A){
	if(verificar(D,M,A)==1){
		*cont=*cont+1;
		printf("\nLa fecha es valida.");
	}
	else printf("\nLa fecha es invalida.");
}
int bisiesto(int Anio){
	int b=0;
	if((Anio%4==0) || (Anio%400==0)) b=1;
	return b;
}
int verificar(int D,int M,int A){
	int b=0;
	switch(M){
	case 1 : if(D>=1 && D<=31) b=1;;break;
	case 2 : if(bisiesto(A)){
		if(D>=1 && D<=29) b=1;}
		else if(D>=1 && D<=29) b=1;
	break;
	case 3 : if(D>=1 && D<=31) b=1;break;
	case 4 : if(D>=1 && D<=30) b=1;break;
	case 5 : if(D>=1 && D<=31) b=1;break;
	case 6 : if(D>=1 && D<=30) b=1;break;
	case 7 : if(D>=1 && D<=31) b=1;break;
	case 8 : if(D>=1 && D<=31) b=1;break;
	case 9 : if(D>=1 && D<=30) b=1;break;
	case 10 : if(D>=1 && D<=31) b=1;break;
	case 11 : if(D>=1 && D<=30) b=1;break;
	case 12 : if(D>=1 && D<=31) b=1;;break;
	}
	return b;
}
