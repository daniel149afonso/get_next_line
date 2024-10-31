/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:52:23 by daafonso          #+#    #+#             */
/*   Updated: 2024/10/31 19:12:59 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

// char	*ft_line(char *text)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	if (!text[0])
// 		return (NULL);
// 	while(text[i] && text[i] != '\n')
// 	{
// 		i++;
// 	}
// 	line 
// 	return (text);
// }

char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (text);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		text = ft_join_and_free(text, buffer);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	//char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (text)
		{
			free(text);
			text = NULL;
		}
		return (NULL);
	}
	text = read_first_line(fd, text);
	if (!text)
		return (NULL);
	// line = ft_line(text);
	// text = ft_next(text);
	return (text);
}


int	main(void)
{
	int		fd;
	char	*a;

	fd = open("a.txt", O_RDONLY);
	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}

	// printf("%s", get_next_line(fd));
	return (0);
}

//BUT: lire et affciher chaque ligne d'un fichier text
//------------------------------------------------------
//READ_FILE: trouve la premiere ligne et s'arrette au \n
//2 Conditions de sorties: fin du texte ou \n trouvé
//text = calloc(1,1) initialise l'espace mémoire à 0, 
//donc text pointe alors vers une chaîne vide.
//bytes_read = read(fd, buffer, BUFFER_SIZE)
//si bytes_read = 0, on atteint la fin du texte
//buffer stocke le nb de char lu, BS combien d'octet lire
//fd est le fichier source a lire
//------------------------------------------------------
//FT_LINE: