/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:37:28 by aobshatk          #+#    #+#             */
/*   Updated: 2025/06/06 12:14:08 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*read_input(t_main_dat *main_data)
{
	char	*input;

	input = readline(main_data->input_data.prompt);
	if (input && *input)
		add_history(input);
	return (input);
}

int	run_input_processor(t_main_dat *main_data)
{
	rl_catch_signals = 0;
	while (1)
	{
		seg_init(SIGINT, sigint_handler);
		seg_init(SIGQUIT, sigquit_handler);
		main_data->input_data.prompt = init_prompt();
		main_data->input_data.input = read_input(main_data);
		if (!main_data->input_data.input)
		{
			rl_clear_history();
			clear_all(main_data);
			write(1, "exit\n", 5);
			return (0);
		}
		main_data->line_counter += 1;
		run_command_processor(main_data);
		if (main_data->input_data.input)
			free(main_data->input_data.input);
		if (main_data->input_data.prompt)
			free(main_data->input_data.prompt);
	}
	return (0);
}
