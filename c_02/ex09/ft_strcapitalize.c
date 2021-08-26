/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:07:19 by strisha           #+#    #+#             */
/*   Updated: 2021/08/06 20:00:36 by strisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
	{
		if ((c >= '0' && c <= '9'))
			return (1);
		else
			return (0);
	}
}

int	skip_space(char *str, int i)
{
	while (*(str + i) != '\0')
	{
		if (!(is_alphanumeric(*(str + i))))
			i++;
		else
			return (i);
	}
	return (i);
}

int	skip_word(char *str, int i)
{
	while (*(str + i) != '\0')
	{
		if (is_alphanumeric(*(str + i)))
			i++;
		else
			return (i);
	}
	return (i);
}

void	capitalize(char *str, int start, int end)
{
	if (*(str + start) >= 'a' && *(str + start) <= 'z')
	{
		*(str + start) = *(str + start) - 32;
	}
	start++;
	while (start < end)
	{
		if (*(str + start) >= 'A' && *(str + start) <= 'Z')
			*(str + start) = *(str + start) + 32;
		start++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i = skip_space(str, i);
		start = i;
		end = skip_word(str, i);
		capitalize(str, start, end);
		i = end;
	}
	return (str);
}
