/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:54:40 by rerayyad          #+#    #+#             */
/*   Updated: 2024/01/12 08:35:24 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_player
{
	int		m_f;
	int		m_b;
	int		m_r;
	int		m_l;
	int		t_r;
	int		t_l;
	int		direction;
	float	fov;
	float	x;
	float	y;
	float	r;
	float	turn;
	float	walk;
	float	spd;
	float	rot;
	float	rot_spd;
}	t_player;

typedef struct s_rays
{
	int		up;
	int		right;
	char	s;
	int		door;
	char	heading;
	float	rays_num;
	float	ray_angle;
	float	ray_size;
	float	hit_x;
	float	hit_y;
	float	diff[2];
	float	colision_distance;
}	t_rays;	

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_img
{
	void	*img;
	char	*id;
	int		endian;
	int		bpp;
	int		len;
	int		width;
}	t_img;

#endif
