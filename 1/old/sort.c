#include "push_swap.h"

int is_stack_sorted(a_list *stack)
{
    while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Stack operations implementations
void sa(a_list **a) {
    if (*a && (*a)->next) {
        a_list *first = *a;
        a_list *second = first->next;
        first->next = second->next;
        second->next = first;
        *a = second;
    }
}

void sb(a_list **b) {
    if (*b && (*b)->next) {
        a_list *first = *b;
        a_list *second = first->next;
        first->next = second->next;
        second->next = first;
        *b = second;
    }
}

void ss(a_list **a, a_list **b) {
    sa(a);
    sb(b);
}

void pa(a_list **a, a_list **b) {
    if (*b) {
        a_list *first = *b;
        *b = (*b)->next;
        first->next = *a;
        *a = first;
    }
}

void pb(a_list **a, a_list **b) {
    if (*a) {
        a_list *first = *a;
        *a = (*a)->next;
        first->next = *b;
        *b = first;
    }
}

void ra(a_list **a) {
    if (*a && (*a)->next) {
        a_list *first = *a;
        *a = first->next;

        a_list *last = *a;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = first;
        first->next = NULL;
    }
}

void rb(a_list **b) {
    if (*b && (*b)->next) {
        a_list *first = *b;
        *b = first->next;

        a_list *last = *b;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = first;
        first->next = NULL;
    }
}

void rr(a_list **a, a_list **b) {
    ra(a);
    rb(b);
}

void rra(a_list **a) {
    if (*a && (*a)->next) {
        a_list *second_last = NULL;
        a_list *last = *a;

        while (last->next) {
            second_last = last;
            last = last->next;
        }

        second_last->next = NULL;
        last->next = *a;
        *a = last;
    }
}

void rrb(a_list **b) {
    if (*b && (*b)->next) {
        a_list *second_last = NULL;
        a_list *last = *b;

        while (last->next) {
            second_last = last;
            last = last->next;
        }

        second_last->next = NULL;
        last->next = *b;
        *b = last;
    }
}

void rrr(a_list **a, a_list **b) {
    rra(a);
    rrb(b);
}

// Helper function to find the index of the minimum element
int find_min_index(a_list *a) {
    a_list *current = a;
    int min_value = current->content;
    int min_index = 0;
    int index = 0;

    while (current != NULL) {
        if (current->content < min_value) {
            min_value = current->content;
            min_index = index;
        }
        current = current->next;
        index++;
    }

    return min_index;
}

// Helper function to find the index of the maximum element
int find_max_index(a_list *b) {
    a_list *current = b;
    int max_value = current->content;
    int max_index = 0;
    int index = 0;

    while (current != NULL) {
        if (current->content > max_value) {
            max_value = current->content;
            max_index = index;
        }
        current = current->next;
        index++;
    }

    return max_index;
}

// Helper function to get the size of the stack
int stack_size(a_list *a) {
    int size = 0;
    while (a != NULL) {
        size++;
        a = a->next;
    }
    return size;
}

// Function to print the stack
void print_stack(a_list *stack, char stack_name) {
    printf("Stack %c: ", stack_name);
    while (stack != NULL) {
        printf("%d ", stack->content);
        stack = stack->next;
    }
    printf("\n");
}

void sort_stack(a_list **a, a_list **b) {
    int size = stack_size(*a);

    // Phase 1: Partitioning and Initial Sorting
    while (size > 0) {
        int min_index = find_min_index(*a);

        // Bring the minimum element to the top of stack `a`
        if (min_index == 1) {
            sa(a);
            printf("sa\n");
        } else if (min_index <= size / 2) {
            for (int i = 0; i < min_index; i++) {
                ra(a);
                printf("ra\n");
            }
        } else {
            for (int i = 0; i < size - min_index; i++) {
                rra(a);
                printf("rra\n");
            }
        }

        // Push the smallest element to `b`
        pb(a, b);
        printf("pb\n");
        size--;

        // Use `sb` to sort the top elements of `b` if necessary
        if (stack_size(*b) > 1 && (*b)->content < (*b)->next->content) {
            sb(b);
            printf("sb\n");
        }
    }

    // Phase 2: Further Sorting Stack `b` if needed using `ss`
    if (stack_size(*b) > 1) {
        if ((*a)->content > (*a)->next->content && (*b)->content < (*b)->next->content) {
            ss(a, b);
            printf("ss\n");
        }
    }

    // Phase 3: Merging Sorted Elements Back to `a`
    size = stack_size(*b);
    while (size > 0) {
        int max_index = find_max_index(*b);

        // Bring the maximum element to the top of stack `b`
        if (max_index == 1) {
            sb(b);
            printf("sb\n");
        } else if (max_index <= size / 2) {
            for (int i = 0; i < max_index; i++) {
                rb(b);
                printf("rb\n");
            }
        } else {
            for (int i = 0; i < size - max_index; i++) {
                rrb(b);
                printf("rrb\n");
            }
        }

        // Push the largest element to `a`
        pa(a, b);
        printf("pa\n");
        size--;

        // Use `sa` to sort the top elements of `a` if necessary
        if (stack_size(*a) > 1 && (*a)->content > (*a)->next->content) {
            sa(a);
            printf("sa\n");
        }
    }

    // Final Phase: Ensure Full Stack `a` is in Order using `ra`, `rra`, and `rr`
    size = stack_size(*a);
    for (int i = 0; i < size; i++) {
        if ((*a)->content > (*a)->next->content) {
            sa(a);
            printf("sa\n");
        }
        ra(a);
        printf("ra\n");
    }
}