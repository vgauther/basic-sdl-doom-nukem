/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:55:39 by vgauther          #+#    #+#             */
/*   Updated: 2020/01/13 12:57:20 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			wait_event(void)
{
	int				stop;
	const Uint8		*inkeys;
	SDL_Event		eve;

	stop = 1;
	while(1)
	{
		inkeys = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&eve))
		{
			if (eve.type == SDL_QUIT)
				return;
			else if (eve.key.keysym.sym == SDLK_ESCAPE)
				return;
		}
	}
}

void quit_sdl_propely(SDL_Window *win, SDL_Renderer *ren, Mix_Music *musique)
{
	Mix_FreeMusic(musique);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	Mix_CloseAudio();
	SDL_Quit();
}

int				main(int ac, char **av)
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	Mix_Music 			*musique;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		return (-1);
	if ((win = SDL_CreateWindow("DOOM NUKEM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_X, SIZE_Y, SDL_WINDOW_SHOWN)) == NULL)
		return (-1);
	if (!(ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED)))
		return (-1);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		return (-1);
	musique = Mix_LoadMUS("./music/music.wav");
	Mix_PlayMusic(musique, -1);
	wait_event();
	quit_sdl_propely(win, ren, musique);
	(void)ac;
	(void)av;
	return (0);
}
