#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line;
	int ret;
	line = NULL;
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%d - Line: [%s]\n", ret, line);
		free(line);
		line = NULL;
	}
	printf("%d - Line: [%s]\n", ret, line);
	free(line);
	line = NULL;
	return 0;
}
