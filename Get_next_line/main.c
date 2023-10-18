#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	
	i = 0;
	fd = open("texto.txt", O_RDONLY);
	while (i++ < 5)
	printf("%s", get_next_line(fd));
	return (0);
}
