#include "../includes/so_long.h"

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