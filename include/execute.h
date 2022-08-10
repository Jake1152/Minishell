/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:33:03 by jim               #+#    #+#             */
/*   Updated: 2022/08/10 18:04:32 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "env_list.h"
# include "lexer.h"

int		execute_processing(t_env_list *env_list, t_list *parse_list, \
							int is_child, t_list *org_list);
int		pipeline_processing(t_env_list *env_list, t_list *pipeline_list, \
							t_list *org_list);
int		execute_cmd(char **envp, char **cmd);
int		simple_cmd(t_env_list *env_list, t_simple *scmd_list, int is_child);

char	**list_to_array(t_list *env_list);
char	**env_list_to_array(t_env_list *env_list);

int		check_builtin(t_list *cmd_list);
int		builtin_process(t_env_list *env_list, char **cmd, int is_child);

#endif