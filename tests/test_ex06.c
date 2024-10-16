/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex06.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarao-de <jarao-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:41:22 by jarao-de          #+#    #+#             */
/*   Updated: 2024/10/04 11:07:08 by jarao-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_print_alphabet(void);

void ft_putchar(char c) { write(1, &c, 1); }

void capture_ft_print_alphabet_output(void (*func)(void), char *buffer,
                                      size_t size) {
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
  func();

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

MU_TEST(test_print_alphabet_response) {
  // ARRANGE
  char expected_result[27];
  char actual_result[256];

  // ACT
  strcpy(expected_result, "abcdefghijklmnopqrstuvwxyz");
  capture_ft_print_alphabet_output(ft_print_alphabet, actual_result,
                                   sizeof(actual_result));

  // ASSERT
  mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_print_alphabet_test_suite) {
  MU_RUN_TEST(test_print_alphabet_response);
}

int main(void) {
  MU_RUN_SUITE(ft_print_alphabet_test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
