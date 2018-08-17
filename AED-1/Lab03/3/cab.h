#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct point Ponto;
Ponto * generate_point();
void delete(Ponto **p);
void set_value(Ponto *p,int x,int y);
float distancia(Ponto *p,Ponto *r);

