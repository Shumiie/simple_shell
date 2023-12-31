#include "shell.h"

/**
 * _realloc - reallocates a memory block
 * and free
 * @ptr: The pointer
 * @old_size: The old size
 * @new_size: The new size
 *
 * Return: void pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;

	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL && new_size != 0)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	if (ptr != NULL && (new_size > old_size))
	{
		new_ptr = malloc(new_size);
		_strcpy(new_ptr, ptr);
		free(ptr);
		return (new_ptr);
	}

	if (new_size == old_size)
		return (ptr);

	free(ptr);
	new_ptr = malloc(new_size);
	return (new_ptr);
}
