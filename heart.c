#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	const int N = 66, M = 73;
	int i, j;
	float x, y;
	float s=0, v=0;

	printf("\033[01;31m");
	for (int t = 0; t < 86; t++){
	    s = 0.045*sin(0.5*t)+0.1;
	    if (t != 0) puts("\033[23A");
		for (i=0; i < N; i += 3)
			for (j=0; j<M; j++){
				x = (j - M/2)*s;
				y = (N/2 - i)*s;
				if ( pow(x*x + y*y - 1, 3) - x*x*y*y*y <= 0) putchar('$');
				else putchar(' ');
				if (j==M-1) putchar('\n');
			}
		usleep(50000);
	}
	printf("\033[00m");
}
