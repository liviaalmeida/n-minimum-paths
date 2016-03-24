#include <stdio.h>
#include <stdlib.h>
#include "path.h"

/**********************************************************************************************
 * MAIN
 *
 * k is the number of tasks
 * x and y are the city dimensions
 * e is the number of blocked corners
 * vector_e stores coordinates to blocked corners
 * c is the number of destinations
 * vector_b stores coordinates to destinations
 *
 **********************************************************************************************/

int main (int argc, char** argv)
{
	int k, i, x, y, e, c, j, t;
	int *vector_e, *vector_b;
	FILE *in, *out;
	in = fopen(argv[1],"r");
	out = fopen(argv[2],"w");
	fscanf(in,"%d",&k);
	for (i=0; i<k; i++)
	{
		fscanf(in,"%d %d",&x,&y);
		fscanf(in,"%d",&e);
		if (e!=0)
		{
			vector_e = (int*)malloc(2*e*sizeof(int));
			for (j=0; j<2*e; j=j+2)
			{
				fscanf(in,"%d %d",&vector_e[j],&vector_e[j+1]);
			}
		}
		fscanf(in,"%d",&c);
		vector_b = (int*)malloc(2*c*sizeof(int));
		for (j=0; j<2*c; j=j+2)
		{
			fscanf(in,"%d %d",&vector_b[j],&vector_b[j+1]);
			t = (vector_b[j]-1)*y + (vector_b[j+1]-1);
			fprintf(out,"%d\n",count_paths(x,y,e,vector_e,t));
		}
        fprintf(out,"\n");
	}
	return 0;
}