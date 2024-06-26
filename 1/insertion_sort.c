#include "push_swap.h"

void push(a_list **stack, int value) {
    a_list *new_node = (a_list *)malloc(sizeof(a_list));
    new_node->content = value;
    new_node->next = *stack;
    *stack = new_node;
}

int pop(a_list **stack) {
    if (*stack == NULL) return 0;
    int value = (*stack)->content;
    a_list *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

void print_stack(a_list *stack) {
    while (stack) {
        printf("%d\n", stack->content);
        stack = stack->next;
    }
}

int stack_size(a_list *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

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

void sa(a_list **a) {
    if (*a && (*a)->next) {
        a_list *first = *a;
        a_list *second = (*a)->next;
        first->next = second->next;
        second->next = first;
        *a = second;
        printf("sa\n");
    }
}

void sb(a_list **b) {
    if (*b && (*b)->next) {
        a_list *first = *b;
        a_list *second = (*b)->next;
        first->next = second->next;
        second->next = first;
        *b = second;
        printf("sb\n");
    }
}

void ss(a_list **a, a_list **b) {
    sa(a);
    sb(b);
    printf("ss\n");
}

void pa(a_list **a, a_list **b) {
    if (*b) {
        int value = pop(b);
        push(a, value);
        printf("pa\n");
    }
}

void pb(a_list **a, a_list **b) {
    if (*a) {
        int value = pop(a);
        push(b, value);
        printf("pb\n");
    }
}

void ra(a_list **a) {
    if (*a && (*a)->next) {
        a_list *first = *a;
        a_list *last = *a;
        while (last->next)
            last = last->next;
        *a = first->next;
        first->next = NULL;
        last->next = first;
        printf("ra\n");
    }
}

void rb(a_list **b) {
    if (*b && (*b)->next) {
        a_list *first = *b;
        a_list *last = *b;
        while (last->next)
            last = last->next;
        *b = first->next;
        first->next = NULL;
        last->next = first;
        printf("rb\n");
    }
}

void rr(a_list **a, a_list **b) {
    ra(a);
    rb(b);
    printf("rr\n");
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
        printf("rra\n");
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
        printf("rrb\n");
    }
}

void rrr(a_list **a, a_list **b) {
    rra(a);
    rrb(b);
    printf("rrr\n");
}

void insertion_sort(a_list **a, a_list **b) {
    int size = stack_size(*a);
    for (int i = 0; i < size; i++) {
        int current = pop(a);
        int b_size = stack_size(*b);
        int j;
        for (j = 0; j < b_size && (*b)->content < current; j++) {
            pa(a, b);
        }
        push(b, current);
        printf("pb\n");
        while (j-- > 0) {
            pb(a, b);
        }
    }
    while (*b) {
        pa(a, b);
    }
}

