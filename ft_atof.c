/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:48:38 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/28 11:14:22 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	filler_float(double answer, const char *str, int sign)
{
	double	count;
	double	virgule;

	count = 1;
	if (*str == '.')
	{
		str++;
		virgule = 0;
		while ((*str <= '9') && (*str >= '0'))
		{
			virgule = (virgule * 10) + (*str - '0');
			count = count * 10;
			str++;
		}
		answer = answer - (virgule / count);
	}
	if (sign != 1)
		return (answer);
	else
		return (answer * (-1));
}

double	ft_atof(const char *str)
{
	double	answer;
	int		sign;

	answer = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str <= '9') && (*str >= '0'))
	{
		answer = (answer * 10) - (*str - '0');
		str++;
	}
	return (filler_float(answer, str, sign));
}
