/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:54:38 by vgauther          #+#    #+#             */
/*   Updated: 2020/01/13 12:31:10 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define MV_FORWARD 0
# define MV_BACKWARD 1
# define MV_LEFT 2
# define MV_RIGHT 3

# define SCREEN_ID_MENU 0
# define SCREEN_ID_SELECTMAP 1
# define SCREEN_ID_OPTION 2
# define SCREEN_ID_GAME 3

# define SIZE_X 900
# define SIZE_Y 600

# define hfov (0.73f * SIZE_Y)
# define vfov (.2f * SIZE_Y)

# define RAD 3.14159265 / 180

# define MAX_QUEUE 32

#endif
