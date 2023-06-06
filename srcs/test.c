#include "lib.h"
#include "pipex.h"

int	main(void)
{
	char	buf[3];
	int		res;

	write(0, "12345", 5);
	res = read(0, buf, 5);
	printf("%s\n", buf);
	return (0);
}
