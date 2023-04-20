#ifndef QUICK_SORT_H
#define QUICK_SORT_H

void sorting(int *lst, int size);
void quick_sort(int *part, int left, int right);
int make_partition(int *part, int start, int end);
void swap(int *a, int *b);

#endif