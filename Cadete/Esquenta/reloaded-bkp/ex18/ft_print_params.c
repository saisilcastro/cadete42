/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:17:14 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/17 17:23:38 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int c, char **v)
{
	char	*command;
	int		i;

	if (c != 1)
	{
		i = 1;
		while (i < c)
		{
			command = v[i];
			while (*command)
				ft_putchar(*command++);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
