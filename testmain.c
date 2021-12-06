#include "so_long.h"

int	main()
{
	char *map;
	int fd = open("map.ber", O_RDONLY);

	map = get_next_line(fd);
	printf("%s\n", map);
	if (!mapfullmur(map))
		printf("map pas bi1 mure");
	else
		printf("map bi1 mure");
	return (0);
}
