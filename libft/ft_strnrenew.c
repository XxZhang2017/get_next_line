#include "includes/libft.h"

char	*ft_strnrenew(char *a, char *b, int len)
{
	char	*tmp;

	if(a)
	{
		tmp = a;
		a = ft_strnjoin(a, b, len);
		free(tmp);
	}
	return (a);
}