/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:56 by hyungdki          #+#    #+#             */
/*   Updated: 2023/05/03 20:31:23 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "quick_sort.h"

void	sorting(int *lst, int size)
{
	quick_sort(lst, 0, size - 1);
}

void	quick_sort(int *part, int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = make_partition(part, left, right);
		quick_sort(part, left, pivot - 1);
		quick_sort(part, pivot + 1, right);
	}
}

int	make_partition(int *part, int start, int end)
{
	int	pivot;
	int	head;
	int	tail;

	pivot = start;
	head = start;
	tail = end + 1;
	while (head < tail)
	{
		while (++head < end && part[head] < part[pivot])
			;
		while (--tail > start && part[tail] > part[pivot])
			;
		if (head < tail)
			swap(&part[head], &part[tail]);
	}
	swap(&part[pivot], &part[tail]);
	return (tail);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
