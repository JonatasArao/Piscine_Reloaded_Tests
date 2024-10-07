/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex25.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:59:35 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/07 18:46:57 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_putnbr(int nb)
{
	char	nb_char;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb == -2147483648)
	{
		ft_putnbr((nb - 8) / 10);
		nb = 8;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		nb_char = '0' + nb;
		write(1, &nb_char, 1);
	}
}

void capture_ft_foreach_output(int *tab, int length, void (*f)(int), char* buffer, size_t size) {
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
	ft_foreach(tab, length, f);

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

MU_TEST(test_ft_foreach_multiple_elements)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[256];
	int		tab[5];
	int		i;

	// ACT
	i = 0;
	while (i < 5)
	{
		tab[i] = i;
		i++;
	}
	strcpy(expected_result, "01234");
	capture_ft_foreach_output(tab, 5, ft_putnbr, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_foreach_empty_array)
{
	// ARRANGE
	char	expected_result[2];
	char	actual_result[256];
	int		*tab = NULL;

	// ACT
	strcpy(expected_result, "");
	capture_ft_foreach_output(tab, 0, ft_putnbr, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST(test_ft_foreach_single_element)
{
	// ARRANGE
	char	expected_result[6];
	char	actual_result[256];
	int		tab[1];

	// ACT
	tab[0] = 42;
	strcpy(expected_result, "42");
	capture_ft_foreach_output(tab, 1, ft_putnbr, actual_result, sizeof(actual_result));

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_foreach_test_suite)
{
	MU_RUN_TEST(test_ft_foreach_multiple_elements);
	MU_RUN_TEST(test_ft_foreach_empty_array);
	MU_RUN_TEST(test_ft_foreach_single_element);
}

int	main(void) {
	MU_RUN_SUITE(ft_foreach_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
