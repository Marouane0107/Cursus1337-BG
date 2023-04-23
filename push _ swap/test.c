#include "push_swap.h"

void    check_arg(int argc, char *argv[], t_vr *p)
{
    if (argc < 2)
        exit(0);
    check_numbers(argv, p);
    is_daplicate(p);
    is_sorted(p);
    //max_min(p);
}

int main(int ac, char* av[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_vr    *p;

    stack_b = NULL;
    stack_a = NULL;
    p = (t_vr *)malloc(sizeof(t_vr));
    if (!p)
        return(0);
    check_arg(ac, av, p);
    push_to_stack_a(&stack_a, p);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    // while(stack_b != NULL)
    // {
    //     printf("---%d\n",stack_b->data);
    //     stack_b = stack_b->next;
    // }
    push_a(&stack_a, &stack_b);
    push_a(&stack_a, &stack_b);
    push_a(&stack_a, &stack_b);
    while(stack_a != NULL)
    {
        printf("---%d\n",stack_a->data);
        stack_a = stack_a->next;
    }
    return(0);
}