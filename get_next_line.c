#include "get_next_line.h"

/*
 * 0 = False
 * 1 = True
 */

/*
 * read_line is a recursive function that will (hopefully)
 * read the file until it finds the end of line
 *
 * int num_bytes is a variable that counts number of
 * bytes returned from read
 * if read returns 0, then it is end of file
 * if read returns -1, then there has been an error
 * I may not even use num_bytes but this depends on testers
 *
 * while there isn't a new line character in the line, keep reading
 * always add null to end of string
 */

char	*read_line(int fd, char* line)
{
	char	*buf;
	int 	num_bytes;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while(!ft_strchr(line, '\n') && num_bytes > 0)
	{
		num_bytes = read(fd, buf, BUFFER_SIZE);
		buff[num_bytes] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
}