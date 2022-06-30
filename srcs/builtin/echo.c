/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:19:04 by jim               #+#    #+#             */
/*   Updated: 2022/06/30 17:23:26 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "builtin.h"
#include "utils.h"

/*
 * ", ' 같은 부분은 파싱되었다는 가정하에 해당 명령어에 케이스에 따른 예외처리를 진행한다.
 * if문으로 범벅할지 나눌지는 추후에 고민
 * 파싱에서 넘겨받은 값을 파싱한다.
 * e.g) echo 1152 $PWD abc '\
		1152, $PWD, abc, '\
		해당값을 자료구조에 담는다.
		체크해서 모든 케이스들이 실행가능한지 확인한다.
		모든 케이스가 실행된다면 출력한다.
 * echo함수에 값이 어떻게 넘어오는지에 따라 ft_split이 필요할수도 아닐수도 있다.
 * 넘겨줄때 어떻게 넘겨줄것인가?
 * 우선 2D array로 가정하며 파싱 이후에 알맞게 변경한다.
 * -nnnnnn -n도 처리되게한다면 어떻게 넘겨받고 어디서 처리할것인가?
 * 어떻게 처리하는게 깔끔할것인가?

 */
// option이 있을때에 대한 처리가 필요하다.
// builtin별로 일관된 처리가 어렵다.
// 결국 builtin별로 나눠서 처리할것인가?
/*
	첫번째 argument가 -n으로 시작해서 중간에 다른 문자없이 끝나면 개행제거이다
*/

int	is_n_option(char *argv)
{
	size_t	idx;

	idx = 0;
	if (argv[idx] == '-')
	{
		while (argv[idx] == 'n')
			idx++;
		if (argv[idx] == '\0')
			return (TRUE);
	}
	return (FALSE);
}

int	echo_cmd(const char **arg_list)
{
	int	idx;
	int	newline_flag;

	newline_flag = TRUE;
	if (is_n_option(arg_list[idx]) == TRUE)
		newline_flag = FALSE;
	idx = 0;
	while (arg_list[idx])
	{
		ft_putstr_fd(arg_list[idx], STDOUT_FILENO);
		if (newline_flag == TRUE)
			write(STDOUT_FILENO, &"\n", 1);
		idx++;
		// ft_putstr_fd(STDOUT_FILENO, arg_list[idx], ft_strlen(arg_list[idx]));
		// print_newline_fd(STDOUT_FILENO);
	}
	return (0);
}
