    // PUSH FIRST IN STACK_A TO FIRST IN STACK_B
void    pa(t_list *stack_a, t_list *stack_b)
{
    int i;

    i = 0;
    stack_a.next->preview = stack_a.preview;
    stack_a.preview->next = stack_a.next;
    stack_a->preview = stack_b->preview;
    stack_a->next = stack_b;
    stack_b.prev->next = stack_a;
    stack_b->prev = stack_a;
    while(i <= stack_a->total)
    {
        stack_a->total -= 1;
        stack_a->pos -= 1;
        stack_a = stack_a.next;
        i++;
    }
    i = 0;
    while(i <= stack_b->total)
    {
        stack_b->total += 1;
        stack_b->pos += 1;
        stack_b = stack_b.next;
        i++;
    }
}

    // LAST ELEMENT BECOMES THE FIRST ONE
void    rra(t_list *list)
{
    int i;

    i = 0;
    list.preview->pos = 0;
    while (i <= list->total -1)
    {
        list->pos += 1;
        i++;
        list = list.next;
    }
}

    // FIRST ELEMENT BECOMES THE LAST ONE
void    ra(t_list *list)
{
    int i;

    i = 1;
    list->pos = list->total;
    while(i <= list->total)
    {
        list.next->pos -= 1;
        list = list.next;
        i++;
    }
}

    // SWAP FIRST TWO ELEMENTS IN STACK
void    sa(t_list *list)
{
    list->pos = 1;
    list.next->pos = 0;
    list->next = list.next->next;
    list.new->prev = list.prev;
    list->prev = list.new;
    list.new->next = list;

}

    // RANK STRUCT FROM SMALLEST TO BIGGEST
void    ranking(t_list *list)
{
    t_list *temp;
    t_list  *buffer;
    int ranking;

    ranking = 0;
    buffer = list;
    temp = buffer;
    while(ranking <= list->total)
    {
        while(buffer.next != list)
        {
            if (temp->num > buffer.next->num && buffer.next->rank == -3)
                temp = buffer.next;
            buffer = buffer.next;
        }
        temp->rank = ranking;
        ranking++;
        buffer = list;
    }
}

    // CREATE STACK_A CIRCULAR LIST
t_list  *create_list(char **v)
{
    t_list  *stlist;
    t_list  *prev;
    t_list  *new;
    int     i;

    i = 1;
    stlist = malloc(sizeof(t_list));
    while(v[i])
    {
        if (i == 1)
        {
            stlist->pos = i - 1;
            stlist->num = ft_atoi(v[i]);
            stlist->next = NULL;
            stlist->rank = -3;
            stlist->preview = NULL;
            prev = stlist;
            i++;
        }
        new = malloc(sizeof(t_list));
        new->pos = i - 1;
        new->num = ft_atoi(v[i]);
        new->next = NULL;
        new->rank = -3;
        prev->next = new;
        new->preview = prev;
        prev = new;
        i++;
    }
    list->total = i - 1;
    prev->next = stlist;
    stlist->preview = prev;
    return(stlist);
}

    // CHECK INPUT ONLY CONTAINS NUMBERS
void    num_check(char *pot_num)
{
    int i;

    i = 0;
    while (pot_num[i])
    {
        if (pot_num[i] >= '0' && pot_num[i] <= '9')
            i++;
        else
            exit(0);
    }
}

    // CHECK VALID INPUT
void    input_handler(int c, char **v)
{
    int     i;

    i = 1;
    if (c < 2)
        exit(0);
    if (c > 2)
    {
        while(v[i])
            num_check(v[i++]);
    }
    i = 0;
    if (c == 2)
    {
        v = ft_split(v[1], " ");
        while(v[i])
            num_check(v[i++]);
    }
}

int main(int argc,char **argv)
{
    t_list  *stack_a;

    input_handler(argc, argv);
    stack_a = create_list(argv);
    ranking(stack_a);
    chunkz_sort(stack_a);
}

// void    chunkz_sort(t_list *list)
// {

// }