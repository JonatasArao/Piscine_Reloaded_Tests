/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex15.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:22:24 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/05 15:14:53 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

void	ft_putstr(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void capture_ft_putstr_output(void (*func)(char *), char *str, char* buffer, size_t size) {
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
	func(str);

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

MU_TEST(test_ft_putstr_undercase_alphabet)
{
	// ARRANGE
	char	expected_result[26];
	char	actual_result[256];

	// ACT
	strcpy(expected_result, "abcdefghijklmnopqrstuvwxyz");
	capture_ft_putstr_output(ft_putstr, expected_result, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_putstr_uppercase_alphabet)
{
	// ARRANGE
	char	expected_result[26];
	char	actual_result[256];

	// ACT
	strcpy(expected_result, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	capture_ft_putstr_output(ft_putstr, expected_result, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_putstr_numbers)
{
	// ARRANGE
	char	expected_result[10];
	char	actual_result[256];

	// ACT
	strcpy(expected_result, "0123456789");
	capture_ft_putstr_output(ft_putstr, expected_result, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_putstr_special)
{
	// ARRANGE
	char	expected_result[34];
	char	actual_result[256];

	// ACT
	strcpy(expected_result, " !@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~");
	capture_ft_putstr_output(ft_putstr, expected_result, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_putstr_unprintable)
{
	// ARRANGE
	char	expected_result[8];
	char	actual_result[256];

	// ACT
	strcpy(expected_result, "\a\b\f\n\r\t\v");
	capture_ft_putstr_output(ft_putstr, expected_result, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_putstr_test_suite)
{
	MU_RUN_TEST(test_ft_putstr_undercase_alphabet);
	MU_RUN_TEST(test_ft_putstr_uppercase_alphabet);
	MU_RUN_TEST(test_ft_putstr_numbers);
	MU_RUN_TEST(test_ft_putstr_special);
	MU_RUN_TEST(test_ft_putstr_unprintable);
}

int	main(void) {
	MU_RUN_SUITE(ft_putstr_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
