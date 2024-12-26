/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <ranavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:00:12 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/27 00:51:29 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, unsigned int n)
{
	char			*str;
	unsigned int	i;

	str = (char *) s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
