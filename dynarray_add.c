#include "dynarray.h"

static void		dynset(t_dynarray *this, size_t i, const void *value)
{
	const char	*src;
	char		*dst;

	src = (const char*)value;
	dst = ((char*)this->content) + (i * this->type);
	i = 0;
	while (i < this->type)
	{
		dst[i] = src[i];
		i++;
	}
}

extern short	dyninsert(t_dynarray *this, size_t index, const void *value)
{
}
