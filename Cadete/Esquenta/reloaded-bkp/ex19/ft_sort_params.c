/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:24:02 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/22 12:08:48 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_swap(char **a, char **b);

int	main(int c, char **v)
{
	int	i;
	int	j;

	if (c != 1)
	{
		i = 1;
		while (i < c)
		{
			j = i + 1;
			while (j < c)
			{
				if (ft_strcmp(v[i], v[j]) > 0)
					ft_swap(&v[i], &v[j]);
				j++;
			}
			ft_putstr(v[i++]);
			ft_putchar('\n');
		}
	}
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
