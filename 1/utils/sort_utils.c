#include "../push_swap.h"

//Checks if the stack is sorted in ascending order
int is_stack_sorted(t_lst *stack)
{
    while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//Find the index of the biggest value inside the stack
int	get_max_value_index(t_lst *lst)
{
	int	max_value;
	int	max_ind;
	int	i;

	max_ind = 0;
	max_value = lst->value;
	lst = lst->next;
	i = 1;
	while (lst)
	{
		if (lst->value > max_value)
		{
			max_ind = i;
			max_value = lst->value;
		}
		lst = lst->next;
		i++;
	}
	return (max_ind);
}

//Just Bubble sort.
static void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Create an array, copy the values from stack_a to the array then sort the array and find median value.
int	get_median_value(t_lst *stack_a, int len)
{
	int i;
	int median;
	int *arr = (int *)malloc(sizeof(int) * len);
    t_lst *current = stack_a;

	i = 0;
	while (i < len)
	{
		arr[i] = current->value;
        current = current->next;
		i++;
	}
    bubble_sort(arr, len);
    if (len % 2 == 0) {
        median = arr[len / 2 - 1];
    } else {
        median = arr[len / 2];
    }
    free(arr);
    return median;
}