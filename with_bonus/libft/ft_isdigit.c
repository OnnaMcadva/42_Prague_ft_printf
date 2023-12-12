#include "libft.h"

int	ft_isdigit(int symba)
{
	if ('0' <= symba && symba <= '9')
		return (1);
	return (0);
}