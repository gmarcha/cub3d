#include "cub3d.h"

void	*free_matrix(int **matrix, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
	return (0);
}
