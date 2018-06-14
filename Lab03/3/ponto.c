#include "cab.h"
struct point{
	float x,y;
};

Ponto * generate_point(){
	return (Ponto *) malloc(sizeof(Ponto));
}

void delete(Ponto **p){
	free(*p);
	*p=NULL;
}

void set_value(Ponto *p,int x,int y){
	p->x = x;
	p->y = y;
}

float distancia(Ponto *p,Ponto *r){
	return sqrt(((p->x-r->x)*(p->x-r->x))+((p->y-r->y)*(p->y-r->y)));
}