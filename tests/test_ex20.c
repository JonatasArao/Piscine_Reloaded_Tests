/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex20.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:40:07 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/07 10:40:08 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minunit.h"

char	*ft_strdup(char *src);

MU_TEST(test_ft_strdup_forty_two)
{
	// ARRANGE
	char	expected_result[3];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "42");
	actual_result = ft_strdup(expected_result);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST(test_ft_strdup_empty_string)
{
	// ARRANGE
	char	expected_result[1];
	char	*actual_result;

	// ACT
	strcpy(expected_result, "");
	actual_result = ft_strdup(expected_result);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);

	// CLEANUP
	free(actual_result);
}

MU_TEST_SUITE(ft_strdup_test_suite)
{
	MU_RUN_TEST(test_ft_strdup_forty_two);
	MU_RUN_TEST(test_ft_strdup_empty_string);
}

int	main(void) {
	MU_RUN_SUITE(ft_strdup_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
