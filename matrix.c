#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix * new_matrix (int x, int y)
{
    matrix *mnew;
    mnew = (matrix*)malloc(sizeof(matrix));
    mnew->x = x;
    mnew->y = y;
    mnew->v = x*y;
    int i;
    mnew->data = (int**)malloc(mnew->v*sizeof(int*));
    for (i=0; i<mnew->v; i++)
    {
        mnew->data[i] = (int*)malloc(mnew->v*sizeof(int));
    }
    return mnew;
}

void clear_matrix (matrix *m)
{
    int i, j;
    for (i=0; i<m->v; i++)
    {
        for (j=0; j<m->v; j++)
        {
            m->data[i][j] = -1;
        }
    }
}

void delete_matrix (matrix *m)
{
    int i;
    for (i=0; i<m->v; i++)
    {
        free(m->data[i]);
    }
    free(m);
}

matrix * adjacent_matrix (int x, int y, int e, int *vec)
{
    matrix *adj = new_matrix(x,y);
    clear_matrix(adj);
    int i, j, k, n, i0, j0, i1, j1;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    for (i=0; i<2*e; i=i+2)
    {
        n = (vec[i]-1)*y + (vec[i+1]-1);
        for (j=0; j<adj->v; j++)
        {
            adj->data[n][j] = 0;
            adj->data[j][n] = 0;
        }
    }
    for (i=0; i<adj->v; i++)
    {
        adj->data[i][i] = 0;
        i0 = i/y;
        j0 = i%y;
        for (k=0; k<4; k++)
        {
            i1 = i0 + dx[k];
            j1 = j0 + dy[k];
            n = i1*y + j1;
            if (adj->data[i][n]!=0 && (i1>=0 && i1<x)&&(j1>=0 && j1<y)!=0)
            {
                adj->data[i][n] = 1;
            }
        }
        for (j=0; j<adj->v; j++)
        {
            if (adj->data[i][j]==-1)
            {
                adj->data[i][j] = 0;
            }
        }
    }
    return adj;
}