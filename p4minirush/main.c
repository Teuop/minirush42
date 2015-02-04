/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/27 16:13:55 by gallard           #+#    #+#             */
/*   Updated: 2015/02/04 15:06:53 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <setjmp.h>

#define NB_GAMES	5
#define TIMEOUT_NS	2 * 1000 * 1000

#define MALLOC_ERR "copy_grid(): malloc() failed.\n"

jmp_buf env_buffer;

static void sig_handler_jmp(int signum)
{
	longjmp(env_buffer, signum);
}

int		p4_player1(t_grid *grid, t_case color, int turn_count);
int		p4_player2(t_grid *grid, t_case color, int turn_count);

t_grid	*copy_grid(t_grid *grid)
{
	t_grid	*ret;

	ret = (t_grid*)malloc(sizeof(t_grid));
	if (ret)
	{
		memcpy(ret, grid, sizeof(t_grid));
	}
	else
	{
		write(2, MALLOC_ERR, sizeof(MALLOC_ERR) - 1);
		exit(1);
	}
	return (ret);
}

int		main()
{
	t_grid		grid;
	t_grid		*copy;
	int			move;
	int			turn_count;
	int			i;

	int			score_p1;
	int			legal_err1;
	int			to_1;

	int			score_p2;
	int			legal_err2;
	int			to_2;
	
	int			sig;
	int			pastoolate;

	signal(SIGALRM, sig_handler_jmp);

	score_p1 = 0;
	score_p2 = 0;
	legal_err1 = 0;
	legal_err2 = 0;
	to_1 = 0;
	to_2 = 0;
	// PLAYER1 PLAYS FIRST
	i = 0;
	while (i < NB_GAMES)
	{
		srand(time(0));
		p4_init(&grid);
		turn_count = 0;
		//p4_disp(&grid);
		while (1)
		{
			// PLAYER1 TURN
			copy = copy_grid(&grid);
			pastoolate = 0;
			if (!(sig = setjmp(env_buffer)))
			{
				ualarm(TIMEOUT_NS, 0);
				move = p4_player1(copy, JAUNE, turn_count);
				pastoolate = 1;
			}
			if (sig  == SIGALRM && !pastoolate)
			{
				score_p2++;
				to_1++;
				break ;
			}
			free(copy);
			if (!p4_legal(&grid, move))
			{
				legal_err1++;
				score_p2++;
				break ;
			}
			p4_play(&grid, move, JAUNE);
			if (p4_won(&grid, move))
			{
				score_p1++;
				break ;
			}
			turn_count++;

			// PLAYER2 TURN
			copy = copy_grid(&grid);
			pastoolate = 0;
			if (!(sig = setjmp(env_buffer)))
			{
				ualarm(TIMEOUT_NS, 0);
				move = p4_player2(copy, ROUGE, turn_count);
				pastoolate = 1;
			}
			if (sig  == SIGALRM && !pastoolate)
			{
				score_p1++;
				to_2++;
				break ;
			}
			free(copy);
			if (!p4_legal(&grid, move))
			{
				legal_err2++;
				score_p1++;
				break ;
			}
			p4_play(&grid, move, ROUGE);
			if (p4_won(&grid, move))
			{
				score_p2++;
				break ;
			}
			turn_count++;
		}
		p4_disp(&grid);puts("");
		i++;
	}
	printf("Player1: %d (illegal moves: %d / timeout: %d)\n", score_p1, legal_err1, to_1);
	printf("Player2: %d (illegal moves: %d / timeout: %d)\n", score_p2, legal_err2, to_2);
	if (score_p2 != score_p1)
		printf("Winner: %s !\n", score_p2 > score_p1 ? "Player2" : (score_p1 > score_p2 ? "Player1" : ""));
	else
		puts("Draw !");
	return (0);
}
