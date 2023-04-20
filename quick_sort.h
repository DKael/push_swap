/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmkael <hyungdki@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:58:07 by dmkael            #+#    #+#             */
/*   Updated: 2023/04/20 19:58:09 by dmkael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

void	sorting(int *lst, int size);
void	quick_sort(int *part, int left, int right);
int		make_partition(int *part, int start, int end);
void	swap(int *a, int *b);

#endif
