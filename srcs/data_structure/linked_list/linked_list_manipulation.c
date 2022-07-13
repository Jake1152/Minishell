/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_manipulation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:23:01 by jim               #+#    #+#             */
/*   Updated: 2022/07/13 15:51:29 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "linked_list.h"
#include "utils.h"
#include "token.h"

int	add_back_linked_node(t_LinkedList *pLinkedList, \
						t_LinkedListNode *newLinkedListNode)
{
	t_LinkedListNode	*cur_linked_node;

	if (pLinkedList == NULL)
		return (-1);
	if (pLinkedList->list_length == 0)
		pLinkedList->header_node = newLinkedListNode;
	else
	{
		cur_linked_node = pLinkedList->header_node;
		while (cur_linked_node->next_node)
			cur_linked_node = cur_linked_node->next_node;
		cur_linked_node->next_node = newLinkedListNode;
	}
	pLinkedList->list_length++;
	return (pLinkedList->list_length);
}

int	remove_linked_node(t_LinkedList *pLinkedList, \
							char *data_str)
{
	t_LinkedListNode	*cur_linked_node;
	t_LinkedListNode	*prev_linked_node;

	if (pLinkedList == NULL)
		return (-1);
	cur_linked_node = pLinkedList->header_node;
	prev_linked_node = pLinkedList->header_node;
	while (cur_linked_node)
	{
		if (ft_strncmp(cur_linked_node->node_str, data_str, \
						max_nonnegative(cur_linked_node->node_str, \
										data_str)) == 0)
			break ;
		prev_linked_node = cur_linked_node;
		cur_linked_node = cur_linked_node->next_node;
	}
	if (cur_linked_node == NULL)
		return (-1);
	else
	{
		free(prev_linked_node);
		prev_linked_node = NULL;
		//prev_linked_node->next_node = NULL과 같을 것이다. 확인 필요
	}
	pLinkedList->list_length--;
	return (pLinkedList->list_length);
}

int	clear_linked_list(t_LinkedList *pLinkedList)
{
	/*
		pLinkedList 모든 node를 삭제하고 remove함수 활용
		header_node만 NULL가리키게한다.
	*/
	t_LinkedListNode	*cur_linked_node;
	t_LinkedListNode	*prev_linked_node;

	if (pLinkedList == NULL)
		return (-1);
	cur_linked_node = pLinkedList->header_node;
	prev_linked_node = pLinkedList->header_node;
	while (pLinkedList->list_length)
	{
		prev_linked_node = cur_linked_node;
		cur_linked_node = cur_linked_node->next_node;
		free(prev_linked_node);
		prev_linked_node = NULL;
		pLinkedList->list_length--;
	}
	if (pLinkedList->header_node == NULL)
		printf("pLinkedList->header_node is NULL\n");
	// header node가 NULL되었는지 확인할 것
	return (0);
}

int	delete_linked_list(t_LinkedList **pLinkedList)
{
	/*
		cleare한 뒤에 PLinkedList자체도 삭제한다.
		PLinkedList = NULL을 할당하여 dangling도 방지한다.
	*/
	// pLinkedList 작 동작하는지 확인 필요
	if (pLinkedList == NULL || *pLinkedList == NULL)
		return (-1);
	clear_linked_list(*pLinkedList);
	free(*pLinkedList);
	*pLinkedList = NULL;
	return (0);
}

int	display_linked_list(t_LinkedList *pLinkedList)
{
	/*
		값이 잘 있는지 출력한다.
	*/
	t_LinkedListNode	*curNode;

	if (pLinkedList == NULL)
	{
		printf("pLinkedList is NULL.\n");
		return (-1);
	}
	curNode = pLinkedList->header_node;
	printf("======== in display function() ========\n");
	while (curNode)
	{
		printf("%s", curNode->node_str);
		if (curNode->next_node)
			printf("->");
		curNode = curNode->next_node;
	}
	printf("\n");
	return (0);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_LinkedList		*pLinkedList;
	t_LinkedListNode	*plinked_node;
	size_t				idx;
	/*
		test
		sentence
		4242
	*/
	if (argc < 2)
		return (1);
	pLinkedList = create_linked_list();
	if (pLinkedList == NULL)
		return (1);
	// printf("pLinkedList->list_length in main() : %zu\n", pLinkedList->list_length);
	idx = 1;
	while (argc > idx)
	{
		// printf("argv[idx] : %s\n", argv[idx]);
		plinked_node = create_linked_node(argv[idx]);
		// printf("plinked_node->data_str : %s\n", plinked_node->node_str);
		if (plinked_node == NULL)
		{
			// delete처리
			return (1);
		}
		add_back_linked_node(pLinkedList, plinked_node);
		// free(plinked_node);
		// plinked_node = NULL;
		idx++;
	}
	display_linked_list(pLinkedList);
	delete_linked_list(&pLinkedList);
	display_linked_list(pLinkedList);
	clear_linked_list(pLinkedList);
	display_linked_list(pLinkedList);
	//delete pLinkedList
	return (0);
}

