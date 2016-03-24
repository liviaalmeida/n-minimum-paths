#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED

#include "matrix.h"
#include "queue_stack.h"

/**********************************************************************************************
 * Breadth-first search
 *
 * Takes a adjacency matrix m, node source and vector distance
 * Fills vector distance in which every element i represents distance from source to node i
 **********************************************************************************************/
void breadth_search (matrix *m, int source, int *distance);

/**********************************************************************************************
 * Minimum Paths
 *
 * Returns new adjacency matrix containing only edges that are part of minimum paths
 **********************************************************************************************/
matrix * minimum_paths (matrix *adj, int target, int d, int *d_s, int *d_t);

/**********************************************************************************************
 * Find P
 *
 * Returns number of minimum paths after performing Depth-first search
 **********************************************************************************************/
int find_p (matrix *m, int s, int target);

/**********************************************************************************************
 * Find P
 *
 * Function that uses all functions above to return number of minimum paths
 **********************************************************************************************/
int count_paths (int x, int y, int e, int *vector_e, int target);

#endif // PATH_H_INCLUDED