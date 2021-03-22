#include "get_next_line.h"

int get_next_line(char **line)
{
	int ret;
	int i;
	char buf;
	if (!line)
		return -1;
	*line = malloc(1234567);
	**line = 0;
	i = 0;
	buf = 0;
	while ((ret = read(0, &buf, 1)) > 0)
	{
		if (buf == '\n')
			break ; 
		(*line)[i] = buf;
		buf = 0;
		i++;
	}
	(*line)[i] = 0;
	if (ret == -1)
		**line = 0;
	return ret;
}
