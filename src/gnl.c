#include "../includes/so_long.h"

char	*ft_calloc(int size)
{
	int		i;
	char	*str;

	str = malloc(size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		++i;
	}
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*n_s;

	n_s = NULL;
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	n_s = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!n_s)
		return (NULL);
	while (s1[i])
	{
		n_s[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		n_s[i + j] = s2[j];
		j++;
	}
	return (n_s);
}

char	*ft_temp(char *line, char *token)
{
	char	*new_line;

	new_line = NULL;
	new_line = ft_strjoin(line, token);
	if (!new_line)
		return (NULL);
	free (line);
	free (token);
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