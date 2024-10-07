/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex26.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:21:00 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/07 19:55:30 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

int	ft_count_if(char **tab, int (*f)(char*));

int	ft_str_is_alpha(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] < 'A' || str[index] > 'Z')
			&& (str[index] < 'a' || str[index] > 'z'))
			return (0);
		index = index + 1;
	}
	return (1);
}

MU_TEST(test_ft_count_if_multiple_elements)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	**word;

	// ACT
	word = (char *[]){"cadete", "Cadete", "c4d3t3", "CADETE", "c@d&t&", NULL};
	expected_result = 3;
	actual_result = ft_count_if(word, ft_str_is_alpha);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_count_if_empty_array)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	**word;

	// ACT
	word = (char *[]){NULL};
	expected_result = 0;
	actual_result = ft_count_if(word, ft_str_is_alpha);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_ft_count_if_single_element)
{
	// ARRANGE
	int		expected_result;
	int		actual_result;
	char	**word;

	// ACT
	word = (char *[]){"cadete", NULL};
	expected_result = 1;
	actual_result = ft_count_if(word, ft_str_is_alpha);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_count_if_test_suite)
{
	MU_RUN_TEST(test_ft_count_if_multiple_elements);
	MU_RUN_TEST(test_ft_count_if_empty_array);
	MU_RUN_TEST(test_ft_count_if_single_element);
}

int	main(void) {
	MU_RUN_SUITE(ft_count_if_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
