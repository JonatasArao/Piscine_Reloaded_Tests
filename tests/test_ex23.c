/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex23.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:21:21 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/07 15:27:22 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "ft_point.h"

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

MU_TEST(test_ft_point_values)
{
	// ARRANGE
	t_point point;

	// ACT
	set_point(&point);

	// ASSERT
	mu_assert_int_eq(42, point.x);
	mu_assert_int_eq(21, point.y);
}

MU_TEST_SUITE(ft_point_test_suite)
{
	MU_RUN_TEST(test_ft_point_values);
}

int	main(void) {
	MU_RUN_SUITE(ft_point_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
