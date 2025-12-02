/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivila <vivila@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:55:35 by vivila            #+#    #+#             */
/*   Updated: 2025/11/30 23:49:33 by vivila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
int	ft_printf(const char *, ...);

int main()
{
/* 	char a = 'A';
 	char *str = "ceci est une chaine.";
	void *vo;
	int b = 90;
	unsigned int c = 450; 

	vo = &a;
 */
	int i = 0;
	char a = 'A';
	i = printf("test %x !", 156);
	printf("--- longueur : %d\n", i);
	i = ft_printf("test %x !", 156);
	printf("--- longueur : %d\n", i);
	i = printf("test %p !", &a);
	printf("--- longueur : %d\n", i);
	i = ft_printf("test %p !", &a);
	printf("--- longueur : %d\n", i);
}
/* 
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign. */