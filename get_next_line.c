/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:00:47 by daafonso          #+#    #+#             */
/*   Updated: 2024/10/30 17:37:35 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(text);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		text = ft_strjoin(text, buffer);
		//free(text) a voir dans ft_strjoin
		if (ft_strchr(text, '\n'))
			break ;
	}
	free(buffer);
	return (text);
}

char	*get_next_line(int fd)
{
	static char		*text;
	char			*line;

	text = read_file(fd, text);
	if (!text)
		return (NULL);
	line = get_line(text);
}

//BUT: lire et affciher chaque ligne d'un fichier text
//READ_FILE:
//text = calloc(1,1) initialise l'espace mémoire à 0, donc text pointe alors vers une chaîne vide.
//bytes_read = read(fd, buffer, BUFFER_SIZE)
//buffer stocke le nb de char lu, BS combien d'octet lire
//fd est le fichier a lire