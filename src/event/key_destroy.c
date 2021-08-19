/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamarcha <gamarcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:37:44 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 19:33:51 by gamarcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_destroy(int keycode, t_root *root)
{
	(void)keycode;
	destroy(root, 0, 0);
	exit(0);
}