/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- < almejia-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:57:09 by almejia-          #+#    #+#             */
/*   Updated: 2025/05/02 17:31:58 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_temp(char *line, char *token)
{
	char	*new_line;

	new_line = NULL;
	new_line = ft_strjoin(line, token);
	if (!new_line)
		return (NULL);
	free(line);
	free(token);
	return (new_line);
}

char	*ft_token(int fd)
{
	char			*token;
	static char		buf[BUFFER_SIZE];
	static int		i = 0;
	static ssize_t	br = 0;

	token = NULL;
	if (i == br)
	{
		br = read(fd, buf, BUFFER_SIZE);
		i = 0;
		if (br == -1 || br == 0)
			return (NULL);
	}
	if (i < br)
	{
		token = malloc(2);
		if (!token)
			return (NULL);
		token[0] = buf[i];
		token[1] = '\0';
		++i;
	}
	return (token);
}

char	*ft_concate_nation(int fd)
{
	char		*token;
	char		*line;
	static int	i = 0;

	i = 0;
	line = NULL;
	token = NULL;
	while (1)
	{
		token = ft_token(fd);
		if (!token && !line)
			return (NULL);
		if (!token)
			return (line);
		if (!line)
			line = token;
		else
			line = ft_temp(line, token);
		if (line[i] == '\n')
			return (line);
		++i;
	}
}

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_concate_nation(fd);
	if (!line)
		return (NULL);
	return (line);
}

int	ft_is_valid_filename(const char *filename)
{
	int		len;
	char	*name;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	name = ft_strrchr(filename, '/');
	if (name)
		name++;
	else
		name = (char *)filename;
	if (ft_strlen(name) <= 4)
		return (0);
	return (1);
}

