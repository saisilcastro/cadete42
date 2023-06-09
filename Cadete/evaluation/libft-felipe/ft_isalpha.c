/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P1-01.ft_isalpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:21 by fde-alen          #+#    #+#             */
/*   Updated: 2023/05/08 18:29:20 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) * 1024);
}
