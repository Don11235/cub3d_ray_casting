#include "../include/cub.h"

bool	ft_is_color_line(char *line)
{
	char	*new_line;

	if (!line)
		return (false);
	new_line = ft_skip_space(line);
	if (!new_line)
		return (false);
	if (ft_strncmp(new_line, "F ", 2) == 0)
		return (true);
	if (ft_strncmp(new_line, "C ", 2) == 0)
		return (true);
	return (false);
}

bool	ft_valid_rgb_splited(char **split_rgb)
{
	if (!split_rgb || !split_rgb[0] || !split_rgb[1] || !split_rgb[2])
		return (false);
	if (split_rgb[3] != NULL)
		return (false);
	if (!ft_is_numeric(split_rgb))
		return (false);
	return (true);
}

static bool	ft_is_valid_rgb_string(char *s)
{
	int	i;

	if (!s || !s[0])
		return (false);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',')
			return (false);
		i++;
	}
	if (s[0] == ',' || s[ft_strlen(s) - 1] == ',')
		return (false);
	i = 0;
	while (s[i])
	{
		if (s[i] == ',' && s[i + 1] == ',')
			return (false);
		i++;
	}
	return (true);
}

int	*ft_handel_rgb(char *s)
{
	char	**split_rgb;
	int		*rgb;

	if (!s || !ft_is_valid_rgb_string(s))
		return (NULL);
	split_rgb = ft_split(s, ',');
	if (!ft_valid_rgb_splited(split_rgb))
	{
		ft_free_split(split_rgb);
		return (NULL);
	}
	rgb = (int *)malloc(sizeof(int) * 3);
	if (!rgb)
		return (ft_free_split(split_rgb), NULL);
	rgb[0] = ft_atoi(split_rgb[0]);
	rgb[1] = ft_atoi(split_rgb[1]);
	rgb[2] = ft_atoi(split_rgb[2]);
	ft_free_split(split_rgb);
	return (rgb);
}

bool	ft_is_valid_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (false);
	if (g < 0 || g > 255)
		return (false);
	if (b < 0 || b > 255)
		return (false);
	return (true);
}
