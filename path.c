#include <stdio.h>
#include <stdlib.h>
#include "path.h"

void breadth_search (matrix *m, int source, int *distance)
{
    int *visited;
    int i, j, k, c;
    c = 0;
    visited = (int*)malloc(m->v*sizeof(int));
    for (i=0; i<m->v; i++)
    {
        visited[i] = 0;
    }
    queue_ *vert = new_queue(m->v);
    put_in_queue(source,m->v,vert);
    visited[source] = 1;
    distance[source] = 0;
    while (!empty_queue(*vert)!=0)
    {
        i = remove_from_queue(m->v,vert);
        c = distance[i]+1;
        for (j=0; j<m->v; j++)
        {
            k = m->data[i][j];
            if (k==1 && visited[j]==0)
            {
                put_in_queue(j,m->v,vert);
                visited[j] = 1;
                distance[j] = c;
            }
        }
    }
    free(visited);
    delete_queue(vert);
}

matrix * minimum_paths (matrix *adj, int target, int d, int *d_s, int *d_t)
{
    matrix *n = new_matrix(adj->x,adj->y);
    clear_matrix(n);
    int i, j;
    for (i=0; i<n->v; i++)
    {
        for (j=0; j<n->v; j++)
        {
            if (adj->data[i][j]==1 && (d_s[i]+d_t[j]+1)==d)
            {
                n->data[i][j] = 1;
            }
            else
            {
                n->data[i][j] = 0;
            }
        }
    }
    return n;
}

int find_p (matrix *m, int s, int target)
{
	int *p, i, j, n;
	p = (int*)malloc(m->v*sizeof(int));
	for (i=0; i<m->v; i++)
    {
        p[i] = 0;
    }
	stack_ *vert = new_stack(m->v);
	push(target,m->v,vert);
	while (!empty_stack(*vert))
	{
		j = pop(m->v,vert);
		p[j]++;
		for (i=0; i<m->v; i++)
		{
			if (m->data[i][j]==1)
			{
				push(i,m->v,vert);
			}
		}
	}
	n = p[s];
	free(p);
	delete_stack(vert);
	return n;
}

int count_paths (int x, int y, int e, int *vector_e, int target)
{
    int p, i, j, k, d_min;
    p = 0;
    matrix *adj = adjacent_matrix(x,y,e,vector_e);
    int *d_s, *d_t;
    d_s = (int*)malloc(adj->v*sizeof(int));
    d_t = (int*)malloc(adj->v*sizeof(int));
    for (i=0; i<adj->v; i++)
    {
        d_s[i] = -1;
        d_t[i] = -1;
    }
    breadth_search(adj,0,d_s);
    breadth_search(adj,target,d_t);
    d_min = d_s[target];
    matrix *minimal = minimum_paths(adj,target,d_min,d_s,d_t);
    delete_matrix(adj);
    p = find_p(minimal,0,target);
    return p;
}