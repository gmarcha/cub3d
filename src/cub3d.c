/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 01:50:43 by gamarcha          #+#    #+#             */
/*   Updated: 2021/08/19 01:50:43 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	iscub(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 4, ".cub") != 0)
		return (0);
	return (1);
}

static int	invalid_args(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_putendl_fd("Error\nInvalid number of arguments", 2);
		return (-1);
	}
	if (iscub(av[1]) == 0)
	{
		ft_putendl_fd("Error\nInvalid extension to .cub file", 2);
		return (-1);
	}
	return (0);
}

void	print_map(int **map, int nb_lines, int size_line)
{
	int				i;
	int				j;

	i = 0;
	while (++i < nb_lines)
	{
		j = 0;
		while (++j < size_line)
		{
			if (map[i][j] == 1)
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n============================================================\n");
}

int	main(int ac, char *av[])
{
	t_root			*root;

	if (invalid_args(ac, av) == -1)
		return (EXIT_FAILURE);
	root = init(av[1]);
	if (root == 0)
		return (EXIT_FAILURE);
	print_map(root->map, root->nb_lines, root->size_line);
	if (draw_core(root) == 0)
		return (EXIT_FAILURE);
	mlx_do_sync(root->mlx);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, button_destroy, root);
	mlx_loop(root->mlx);
	return (EXIT_SUCCESS);
}
