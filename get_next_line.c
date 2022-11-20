#include "get_next_line.h"

char	*read_line(int fd, char* line)
{
	char	*buf;
	int 	num_bytes;

	num_bytes = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while(!ft_strchr(line, '\n') && num_bytes > 0)
	{
		num_bytes = read(fd, buf, BUFFER_SIZE);
		if (num_bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[num_bytes] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_line = read_line(fd, static_line);
	if (!static_line)
		return (NULL);
	line = ft_clean_line(static_line);
	static_line = ft_clean_static_line(static_line);
	return (line);
}