#include "stdio.h"
#include "stdarg.h"

/*double topla(double,double);

int main(){
	int x = 10, y =25;
	printf("%lf",topla(x,y));
}

double topla(double a , double b){
	return a + b;
}*/

/*void tersCevir(int *dizi,int uzunluk) {
	int tmp,i;
	for(i=0;i<uzunluk/2;i++){
		tmp = dizi[uzunluk-i-1];
		dizi[uzunluk-i-1] = dizi[i];
		dizi[i] = tmp;
	}
}

int main(){
	int sayilar[] = {15,7,36,1,93,24};
	tersCevir(sayilar,6);
	int i = 0;
	for(;i<6;i++){
		printf("\n%d",sayilar[i]);
	}
}*/

typedef enum BOOL{false,true} boolean;
boolean asalmi(int parametreSayisi,...) {
	va_list valist;
	va_start(valist,parametreSayisi);
	int sayi = va_arg(valist,int);
	
	if(parametreSayisi == 1) {
		va_end(valist);
		return asalmi(2,sayi,2);
	}
	int bolen = va_arg(valist,int);
	va_end(valist);
	if(sayi == bolen) return true;
	if(sayi %bolen == 0) return false;
	return asalmi(2,sayi,bolen+1);
}
int main(){
	int sayi;
	if(asalmi(1,83)) printf("asaldir");
	else printf("asal degildir");
}