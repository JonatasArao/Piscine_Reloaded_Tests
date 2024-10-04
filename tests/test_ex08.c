/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex08.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:41:22 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/04 10:33:00 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

void	ft_is_negative(int n);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void capture_ft_is_negative_output(void (*func)(int), int n, char* buffer, size_t size) {
	int pipefd[2];
	ssize_t count;

	// Cria um pipe
	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	// Salva o descritor de arquivo original da saída padrão
	int stdout_backup = dup(STDOUT_FILENO);

	// Redireciona a saída padrão para o pipe
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);

	// Chama a função cuja saída queremos capturar
	func(n);

	// Restaura a saída padrão
	fflush(stdout);
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdout_backup);

	// Lê o conteúdo do pipe
	count = read(pipefd[0], buffer, size - 1);
	if (count == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	buffer[count] = '\0';
}

MU_TEST(test_is_ten_negative)
{
	// ARRANGE
	char	expected_result[1];
	char	actual_result[256];

	// ACT
	strcpy(expected_result, "P");
	capture_ft_is_negative_output(ft_is_negative, 10, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_is_zero_negative)
{
	// ARRANGE
	char	expected_result[1];
	char	actual_result[256];

	// ACT
	strcpy(expected_result, "P");
	capture_ft_is_negative_output(ft_is_negative, 0, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_is_minus_ten_negative)
{
	// ARRANGE
	char	expected_result[1];
	char	actual_result[256];

	// ACT
	strcpy(expected_result, "N");
	capture_ft_is_negative_output(ft_is_negative, -10, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_is_negative_test_suite)
{
	MU_RUN_TEST(test_is_ten_negative);
	MU_RUN_TEST(test_is_zero_negative);
	MU_RUN_TEST(test_is_minus_ten_negative);
}

int	main(void) {
	MU_RUN_SUITE(ft_is_negative_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
