/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:09:32 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/26 18:44:21 by ranavarr         ###   ########.fr       */
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
