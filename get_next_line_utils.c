/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:31:32 by daafonso          #+#    #+#             */
/*   Updated: 2024/10/30 16:32:40 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_total;

	len_total = ft_strlen(s1);
	len_total += ft_strlen(s2);
	str = malloc(sizeof(char) * (len_total + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_total + 1);
	ft_strlcat(str, s2, len_total + 1);
	return (str);
}