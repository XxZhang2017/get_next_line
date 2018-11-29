#include "includes/libft.h"

char	*ft_strrenew(char *a, char *b)
{
	char	*tmp;

	if(a)
	{
		tmp = a;
		a = ft_strjoin(a, b);
		free(tmp);
	}
	return (a);
}