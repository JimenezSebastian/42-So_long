/*

char	*ft_join(char *original, char *new)
{
	char	*new_line;

	new_line = ft_strjoin(original, new);
	free (original);
	free (new);
    if (!new_line)
        return (NULL);
    else
	    return (new_line);
}


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
*/