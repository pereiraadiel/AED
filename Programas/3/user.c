#include "ponto.c"
#include <math.h>

int main(int argc, char const *argv[])
{
	Ponto *A,*B;
	float x,y;
	A=generate_point();
	B=generate_point();
	printf("Digite as coordenadas dos pontos:\n");
	printf("ponto A:\n");
	printf("X: "); scanf("%f",&x);
	printf("Y: "); scanf("%f",&y);
	set_value(A,x,y);
	printf("ponto B:\n");
	printf("X: "); scanf("%f",&x);
	printf("Y: "); scanf("%f",&y);
	set_value(B,x,y);
	printf("A distancia entre os pontos eh de: %.2f\n\n",distancia(A,B));
	return 0;
}