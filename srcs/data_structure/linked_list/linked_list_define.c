/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_define.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:23:01 by jim               #+#    #+#             */
/*   Updated: 2022/07/13 15:52:23 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // debug
#include <stdlib.h>
#include "linked_list.h"
#include "utils.h"
#include "token.h"

t_LinkedList	*create_linked_list(void)
{
	t_LinkedList	*plinked_list;

	plinked_list = (t_LinkedList *)malloc(sizeof(t_LinkedList));
	if (plinked_list == NULL)
		return (NULL);
	plinked_list->list_length = 0;
	plinked_list->header_node = NULL;
	return (plinked_list);
}

t_LinkedListNode	*create_linked_node(char *str, t_token_type type)
{
	t_LinkedListNode	*plinked_node;

	plinked_node = (t_LinkedListNode *)malloc(sizeof(t_LinkedListNode));
	if (plinked_node == NULL)
		return (NULL);
	plinked_node->node_str = str;
	plinked_node->next_node = NULL;
	plinked_node->type = type;
	return (plinked_node);
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

/*
int	main(int argc, char **argv)
{
	t_LinkedList		*pLinkedList;
	t_LinkedListNode	*plinked_node;
	size_t				idx;

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
*/
