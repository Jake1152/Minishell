/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:22:26 by jim               #+#    #+#             */
/*   Updated: 2022/07/23 13:15:16 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- envp등의 값을 초기화하는 함수
	- 전역변수를 쓸지
	- 어떻게 구성할지에 따라 달라진다.
	- 환경변수 등 초기에 세팅이 필요한 값들을 가지고 있는 구조체에 대한 논의 필요
	- 함수별로 어떻게 가지고 다닐 것인가?
	- 전역변수를 쓰지 않는다고해도 계속 가지고 다니면 전역변수와의 차이점은 무엇인가?
	- 전역변수를 씀으로써 생길수 있는 문제와 어디서는 가지고 다니는 변수를 씀으로써
	  발생할 수 있는 문제의 차이점은 무엇인가?
	- 결과를 자료구조에 담아야한다.
*/

#include <unistd.h>
#include "env_list.h"
#include "utils.h"
#include "ft_error.h"
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

/*
	linked로 하면 몇개가 들어올지 신경안써도 되지만
	찾을때 key, value list를 똑같은 횟수만큼 이동해줘야한다.
	그 부분에서 둘다 이동해야하므로 지장이 있을수 있다.
	우선은 linked를 활용해본다.
	불편하면 array list로 변경가능.
*/
#include <stdio.h>
//debug

/*
	init할때 할당에서 실패한다면 어떻게 종료시킬것인가?
	error 문구는 어떻게 표현할것인가?
	표현이 필요한가?
	이전에 할당된 부분만
*/

static int	add_env(t_env_list *env_list, char *key, char *value)
{
	t_env_node	*cur_node;

	cur_node = create_env_node(key, value);
	if (cur_node == NULL)
	{
		free_key_value(&key, &value);
		delete_env_list(&env_list);
		return (-1);
	}
	add_back_env_node(env_list, cur_node);
	return (0);
}

int	init_value(t_env_list	**env_list, char **envp, int io_backup[2])
{
	size_t		idx;
	t_env_node	*cur_node;
	char		*key;
	char		*value;

	*env_list = create_env_list();
	if (env_list == NULL)
		return (-1);
	idx = 0;
	cur_node = (*env_list)->header_node;
	while (envp[idx])
	{
		if (split_key_value(envp[idx], &key, &value) < 0)
			error_handler(NULL, NULL, strerror(errno), 1);
		add_env((*env_list), key, value);
		idx++;
	}
	if (get_env_node((*env_list), "OLDPWD") == NULL)
		add_env((*env_list), "OLDPWD", NULL);
	io_backup[0] = dup(0);
	io_backup[1] = dup(1);
	return (0);
}

/*
	singleton 예정
	getter, setter
*/
