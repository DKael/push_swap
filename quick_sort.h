/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:16:20 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/04 22:38:54 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

void	sorting(int *lst, int size);
void	quick_sort(int *part, int left, int right);
int		make_partition(int *part, int start, int end);
void	swap(int *a, int *b);

#endif
