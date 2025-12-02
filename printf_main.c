/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mai.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivila <vivila@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:14:27 by nopons            #+#    #+#             */
/*   Updated: 2025/12/03 00:07:27 by vivila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

# define RESET "\033[0m"
# define CYAN "\033[36m"
# define YELLOW "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void	test_char(char *str, int nb)
{
	int	len1, len2;

	(void)nb;
	printf(CYAN "\n========== TEST %%c (char) ==========" RESET "\n");
	len1 = ft_printf("ft: argv[1][0] = %c\n", str[0]);
	printf(YELLOW);
	len2 = printf("or: argv[1][0] = %c\n", str[0]);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: argv[1][0,1,2] = %c%c%c\n", str[0], str[1], str[2]);
	printf(YELLOW);
	len2 = printf("or: argv[1][0,1,2] = %c%c%c\n", str[0], str[1], str[2]);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: char = %c\n", 0);
	printf(YELLOW);
	len2 = printf("or: char = %c\n", 0);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_string(char *str, int nb)
{
	int		len1, len2;
	char	*null_str;

	(void)nb;
	printf(CYAN "\n========== TEST %%s (string) ==========" RESET "\n");
	len1 = ft_printf("ft: argv[1] = %s\n", str);
	printf(YELLOW);
	len2 = printf("or: argv[1] = %s\n", str);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: argv[1] + string = %s%s\n", str, " World");
	printf(YELLOW);
	len2 = printf("or: argv[1] + string = %s%s\n", str, " World");
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	null_str = NULL;
	len1 = ft_printf("ft: NULL string = %s\n", null_str);
	printf(YELLOW);
	len2 = printf("or: NULL string = %s\n", null_str);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: empty = %s\n", "");
	printf(YELLOW);
	len2 = printf("or: empty = %s\n", "");
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_pointer(char *str, int nb)
{
	int		len1, len2;
	void	*ptr;

	printf(CYAN "\n========== TEST %%p (pointer) ==========" RESET "\n");
	
	len1 = ft_printf("ft: ptr str_argv = %p\n", str);
	printf(YELLOW);
	len2 = printf("or: ptr str_argv = %p\n", str);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: ptr nb_argv = %p\n", &nb);
	printf(YELLOW);
	len2 = printf("or: ptr nb_argv = %p\n", &nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	ptr = NULL;
	len1 = ft_printf("ft: NULL ptr = %p\n", ptr);
	printf(YELLOW);
	len2 = printf("or: NULL ptr = %p\n", ptr);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: multiple = %p %p\n", &len1, &len2);
	printf(YELLOW);
	len2 = printf("or: multiple = %p %p\n", &len1, &len2);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_decimal(char *str, int nb)
{
	int	len1, len2;

	(void)str;
	printf(CYAN "\n========== TEST %%d (decimal) ==========" RESET "\n");
	len1 = ft_printf("ft: decimal argv = %d\n", nb);
	printf(YELLOW);
	len2 = printf("or: decimal argv = %d\n", nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: negative = %d\n", -nb);
	printf(YELLOW);
	len2 = printf("or: negative = %d\n", -nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: 0 = %d\n", 0);
	printf(YELLOW);
	len2 = printf("or: 0 = %d\n", 0);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: INT_MAX = %d\n", INT_MAX);
	printf(YELLOW);
	len2 = printf("or: INT_MAX = %d\n", INT_MAX);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: INT_MIN = %d\n", INT_MIN);
	printf(YELLOW);
	len2 = printf("or: INT_MIN = %d\n", INT_MIN);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_integer(char *str, int nb)
{
	int	len1, len2;

	(void)str;
	printf(CYAN "\n========== TEST %%i (integer) ==========" RESET "\n");
	len1 = ft_printf("ft: integer argv = %i\n", nb);
	printf(YELLOW);
	len2 = printf("or: integer argv = %i\n", nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: negative = %i\n", -nb);
	printf(YELLOW);
	len2 = printf("or: negative = %i\n", -nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: 0 = %i\n", 0);
	printf(YELLOW);
	len2 = printf("or: 0 = %i\n", 0);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_unsigned(char *str, int nb)
{
	int	len1, len2;

	(void)str;
	printf(CYAN "\n========== TEST %%u (unsigned) ==========" RESET "\n");
	len1 = ft_printf("ft: unsigned argv = %u\n", (unsigned int)nb);
	printf(YELLOW);
	len2 = printf("or: unsigned argv = %u\n", (unsigned int)nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: 0 = %u\n", 0);
	printf(YELLOW);
	len2 = printf("or: 0 = %u\n", 0);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: UINT_MAX = %u\n", UINT_MAX);
	printf(YELLOW);
	len2 = printf("or: UINT_MAX = %u\n", UINT_MAX);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: negative as unsigned = %u\n", -1);
	printf(YELLOW);
	len2 = printf("or: negative as unsigned = %u\n", -1);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_hexa_lower(char *str, int nb)
{
	int	len1, len2;

	(void)str;
	printf(CYAN "\n========== TEST %%x (hexa lowercase) ==========" RESET "\n");
	len1 = ft_printf("ft: argv = %x\n", nb);
	printf(YELLOW);
	len2 = printf("or: argv = %x\n", nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: 255 = %x\n", 255);
	printf(YELLOW);
	len2 = printf("or: 255 = %x\n", 255);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: 0 = %x\n", 0);
	printf(YELLOW);
	len2 = printf("or: 0 = %x\n", 0);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: UINT_MAX = %x\n", UINT_MAX);
	printf(YELLOW);
	len2 = printf("or: UINT_MAX = %x\n", UINT_MAX);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_hexa_upper(char *str, int nb)
{
	int	len1, len2;

	(void)str;
	printf(CYAN "\n========== TEST %%X (hexa uppercase) ==========" RESET "\n");
	len1 = ft_printf("ft: ARGV = %X\n", nb);
	printf(YELLOW);
	len2 = printf("or: ARGV = %X\n", nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: 255 = %X\n", 255);
	printf(YELLOW);
	len2 = printf("or: 255 = %X\n", 255);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: 0 = %X\n", 0);
	printf(YELLOW);
	len2 = printf("or: 0 = %X\n", 0);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: argv ARGV = %x %X\n", nb, nb);
	printf(YELLOW);
	len2 = printf("or: argv ARGV = %x %X\n", nb, nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_percent(char *str, int nb)
{
	int	len1, len2;

	(void)str;
	(void)nb;
	printf(CYAN "\n========== TEST %%%% (percent) ==========" RESET "\n");
	len1 = ft_printf("ft: percent = %%\n");
	printf(YELLOW);
	len2 = printf("or: percent = %%\n");
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: multiple = %%%%%%\n");
	printf(YELLOW);
	len2 = printf("or: multiple = %%%%%%\n");
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: 100%% done!\n");
	printf(YELLOW);
	len2 = printf("or: 100%% done!\n");
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

void	test_mixed(char *str, int nb)
{
	int	len1, len2;

	printf(CYAN "\n========== TEST MIXED (combinations) ==========" RESET "\n");
	len1 = ft_printf("ft: %c %s %d %i %u %x %X %%\n", str[0], str, nb, -nb, nb, nb, nb);
	printf(YELLOW);
	len2 = printf("or: %c %s %d %i %u %x %X %%\n", str[0], str, nb, -nb, nb, nb, nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
	
	len1 = ft_printf("ft: %s %p %d\n", str, &len1, nb);
	printf(YELLOW);
	len2 = printf("or: %s %p %d\n", str, &len1, nb);
	printf(RESET);
	printf("Lengths: ft=%d, or=%d [%s]\n", len1, len2, len1 == len2 ? GREEN "OK" RESET : RED "KO" RESET);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		nb;

	if (argc != 3)
	{
		printf("Usage: %s <string> <number>\n", argv[0]);
		return (1);
	}
	str = argv[1];
	nb = ft_atoi(argv[2]);
	
	printf("=========================================\n");
	printf("   FT_PRINTF - TESTS COMPLETS\n");
	printf("   String: %s | Number: %d\n", str, nb);
	printf("=========================================\n");

	test_char(str, nb);
	test_string(str, nb);
	test_pointer(str, nb);
	test_decimal(str, nb);
	test_integer(str, nb);
	test_unsigned(str, nb);
	test_hexa_lower(str, nb);
	test_hexa_upper(str, nb);
	test_percent(str, nb);
	test_mixed(str, nb);

	printf("\n=========================================\n");
	printf("   TESTS TERMINÉS\n");
	printf("=========================================\n");

	return (0);
}