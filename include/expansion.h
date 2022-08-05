/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:46:10 by jim               #+#    #+#             */
/*   Updated: 2022/08/05 13:27:53 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

#include "linked_list.h"
#include "env_list.h"
#include "lexer.h"

typedef enum e_dollar_expansion_flag
{
	VARIABLE,
	NORMAL,
}			t_dollar_expansion_flag;

typedef enum e_check_dollar_expansion_flag
{
	NOT_CHANGED,
	CHANGED,
}			t_check_dollar_expansion_flag;

typedef struct s_sub_str_info
{
	size_t	len;
	size_t	start_idx;
}				t_sub_str_info;

int	expansion(t_env_list *env_list, t_simple *scmd_list);
int	concat_list(t_simple *scmd_list);
int	concat_list_in_condition(t_list *list);
int	dollar_sign_conversion(t_env_list *env_list, t_token *token);
int	wildcard_for_curdir(t_simple *scmd_list);

#endif
