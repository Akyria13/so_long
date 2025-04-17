/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:29:31 by jowagner          #+#    #+#             */
/*   Updated: 2025/04/17 20:26:18 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Create a new string containing the remaining characters in the stack
 * after the first line.
 *
 * @param stack The string to create the new line from.
 * @return A pointer to the new string, or NULL if an error occurred.
 */
static char	*new_line(char *stack)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	new_line = malloc(ft_strlen(stack) - i + 1);
	if (!new_line)
		return (NULL);
	if (stack[i] == '\n')
		i++;
	j = 0;
	while (stack[i])
	{
		new_line[j] = stack[i];
		i++;
		j++;
	}
	new_line[j] = '\0';
	free(stack);
	return (new_line);
}

/**
 * @brief Extract the first line from the stack.
 *
 * @param stack The string to extract the line from.
 * @return A pointer to the extracted line, or NULL if an error occurred.
 */
static char	*extract_line(char *stack)
{
	char	*line;
	size_t	i;

	line = NULL;
	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	line = malloc(i + 1 + (stack[i] == '\n'));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/**
 * @brief Read data from the file descriptor and appends it to the stack.
 *
 * @param fd The file descriptor to read from.
 * @param stack The current stack of characters read so far.
 * @return A pointer to the updated stack, or NULL if an error occurred.
 */
static char	*read_files(int fd, char *stack)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(stack, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_strs(buffer, stack), NULL);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		stack = ft_strnjoin(stack, buffer);
		if (NULL == stack)
		{
			free(buffer);
			free(stack);
			stack = NULL;
			return (NULL);
		}
	}
	free(buffer);
	return (stack);
}

/**
 * @brief Read a line from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @return The read line, including the newline character if present,
 * or NULL if there is nothing more to read or an error occurred.
 */
char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = read_files(fd, stack);
	if (!stack || *stack == '\0')
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	line = extract_line(stack);
	stack = new_line(stack);
	return (line);
}
