/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <ranavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:49:27 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/26 20:21:03 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalpha(int v)
{
	if ((v < 'A') || (v > 'z'))
		return (0);
	if ((v > 'Z') && (v < 'a'))
		return (0);
	return (1);
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return (1);
	}
	return (0);
}

int	ft_isalnum(int v)
{
	if ((ft_isdigit(v) != 0) || (ft_isalpha(v) != 0))
		return (1);
	return (0);
}
