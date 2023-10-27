/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btr_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:22:52 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/02 19:22:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	btr_iter(t_btree *tree, t_btr_trvsl traversal, void (*func)(void *))
{
	if (tree == NULL || func == NULL)
		return ;
	if (traversal == preorder)
		func(tree->data);
	btr_iter(tree->left, traversal, func);
	if (traversal == inorder)
		func(tree->data);
	btr_iter(tree->right, traversal, func);
	if (traversal == postorder)
		func(tree->data);
}
