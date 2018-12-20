#include <stdio.h>
#include <math.h>

#define XMIN 0
#define YMIN 0

#define XMAX 1920
#define YMAX 1080

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct point{
	int x;
	int y;
}pt;
//struct point pt; //Also defines a structure of type point as pt (just like the previous line)

struct rect{
	struct point pt1;
	struct point pt2;
}screen;

// A função makepoint retorna uma estrutura. No caso, atribui valores à x e y
//struct point makepoint(int, int);
struct point makepoint(int x, int y){
	struct point temp;
	
	temp.x = x;
	temp.y = y;
	return temp;
}

// a função addpoint retorna a soma de dois pontos
//struct point addpoint(struct point, struct point);
struct point addpoint(struct point p1, struct point p2){
	p1.x += p2.x;
	p1.y += p2.y;
	
	return p1;
}

// ptinrect: return 1 if p in r, 0 if not
int ptinrect(struct point p, struct rect r){
	
	return p.x >= r.pt1.x && p.x < r.pt2.x 
		&& p.y >= r.pt1.y && p.y < r.pt2.y;
}
/* Deixar as coordenadas do retângulo em forma canônica*/
struct rect temp(struct rect r){
	struct rect temp;
	
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt2.y, r.pt2.y);
	return temp;		
}

/* Working with Pointers */
struct point origin, *pp=&origin; // Declara *pp apontando para estrutura origin do tipo point 

/*******************************************************
*************************MAIN***************************
*******************************************************/
int main(){
//	double dist;
	screen.pt1.x = XMAX;
	screen.pt2.x = XMIN;
	screen.pt1.y = YMIN;
	screen.pt2.y = YMAX;

/************* Working with pointers ****************/
	pp->x=10;
	pp->y=22;
	printf("Origin is (%d,%d)\n", pp->x, pp->y);

/****************************************************/
	
/************* Utilizando a função temp *************/
	
	pt = makepoint(10, 10);	
//	printf("%d\n", ptinrect(pt, temp(screen)));

/****************************************************/

/************* Utilizando a função ptinrect *************/
	pt.x = 10;
	pt.y = 1000;
	
//	printf("%d\n", ptinrect(pt, screen));
	
/************* END *************/
	
/************* Utilizando a função addpoint *************/
	struct point ponto1;
	struct point ponto2;
	ponto1.x=1;
	ponto1.y=2;
	ponto2.x=3;
	ponto2.y=4;
	
	pt = addpoint(ponto1,ponto2);
//	printf("%d", pt.y);

/************* END *************/
	
	/*pt.x = 5;
	pt.y = 3;
	printf("%d\n",pt.x);
	
	dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
	printf("%d\n", dist);*/
/************* Utilizando a função makepoint *************/
	pt = makepoint(5,3); //chama a função e atribui os valores 5 e 3 à estrutura pt.
//	printf("%d\n", pt.x);
	
	struct point middle; // estrutura middle do tipo point é utilizada para achar um ponto médio
	
	screen.pt1 = makepoint(0,0);
	screen.pt2 = makepoint(XMAX, YMAX);
	middle = makepoint((screen.pt1.x+screen.pt2.x)/2,(screen.pt1.y+screen.pt2.y)/2);
	
//	printf("%d\n", middle.x);
/************* END *************/


	return 0;
}