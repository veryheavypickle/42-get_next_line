#include "get_next_line.h"

/*
 * 0 = False
 * 1 = True
 */

/*
 * read_line is a recursive function that will (hopefully)
 * read the file until it finds the end of line
 *
 * the if (ft_strchr(line, '\n')) moves the pointer to the start of the next line
 *
 * int num_bytes is a variable that counts number of
 * bytes returned from read
 * if read returns 0, then it is end of file
 * if read returns -1, then there has been an error
 * I may not even use num_bytes but this depends on testers
 * num_bytes is set to 1 so it can enter the while loop
 *
 * while there isn't a new line character in the line, keep reading
 * always add null to end of string
 */

char	*read_line(int fd, char* line)
{
	char	*buf;
	int 	num_bytes;

	num_bytes = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (ft_strchr(line, '\n'))
	{
		line = ft_strchr(line, '\n');
		line++;
	}
	while(!ft_strchr(line, '\n') && num_bytes > 0)
	{
		num_bytes = read(fd, buf, BUFFER_SIZE);
		if (num_bytes < 0)
			return (NULL);
		buf[num_bytes] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*clean_line;
	char 		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	clean_line = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
	clean_line = ft_memcpy(clean_line, line, ft_strlen(line));
	clean_line[ft_strlen(clean_line) - 1] = 0;
	str = clean_line;
	free(clean_line);
	return (str);
}