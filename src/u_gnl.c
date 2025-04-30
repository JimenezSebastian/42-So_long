#include "../includes/so_long.h"

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
		token = ft_calloc(2);
		if (!token)
			return (NULL);
		token[0] = buf[i];
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