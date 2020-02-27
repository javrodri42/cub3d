#include "cub3d.h"

size_t ft_strlen(const char *s);

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}


char	*ft_skipspace_beg(char *s)
{
	unsigned int	len;

	if (s)
	{
		len = ft_strlen(s);
		if (len == 0)
			return (s);
		while (*s != '\0' && (*s == ' ' || *s == '\n' || *s == '\t'))
			s++;
		return (s);
	}
	else
		return (NULL);
}

int main(void)
{
    printf("%s\n", ft_skipspace_beg("123 456     789"));
}