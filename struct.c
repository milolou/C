#include <math.h>
#include <stdio.h>

struct point {
		int x;
	    int y;
    };

struct rect {
    	struct point pt1;
    	struct point pt2;
    };

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);

int main(int argc, char const *argv[])
{
	int area;
    struct rect re;
    struct point origin, *pp;
    double dist, sqrt(double);

    pp = &origin;
    re.pt1 = makepoint(0, 0);
    re.pt2 = makepoint(320, 200);
    origin = addpoint(re.pt1, re.pt2);

    area = (re.pt2.x - re.pt1.x) * (re.pt2.y - re.pt1.y);
    dist = sqrt((double) pp->x * pp->x + (double) pp->y * pp->y);
    printf("%d\n", area);
    /*printf("origin is (%d, %d)\n", (*pp).x, (*pp).y); */
    printf("origin is (%d, %d)\n", pp->x, pp->y);
    printf("origin is %.5g away from zero point\n", dist);
	return 0;
}

struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a): (b))
#define max(a, b) ((a) > (b) ? (a): (b))

struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}

