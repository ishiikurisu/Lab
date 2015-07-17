#ifndef LIST_H
#define LIST_H

#define inc(A) ((A) = (A)->next)

typedef struct NODE
{
    struct NODE* next;
    char* info;
} NODE;

typedef NODE LIST;

LIST* new_list()
{
    LIST* list = (LIST*) malloc(sizeof(LIST));

    list->next = NULL;
    list->info = NULL;

    return list;
}

LIST* tail(LIST* head)
{
    LIST* list = head;

    while (list->next != NULL)
        list = list->next;

    return list;
}

int list_length(LIST* head)
{
    LIST* list   = head->next;
    int   result = 0;

    while (list != NULL)
    {
        inc(list);
        result++;
    }

    return result;
}

char* get_from_list(LIST* head, int index)
{
    LIST* list = head->next;
    char* outlet = NULL;
    int i = 0;

    while ((i != index) && (list != NULL))
    {
        inc(list);
        ++i;
    }

    if (list != NULL)
        outlet = list->info;

    return outlet;
}

LIST* add_to_list(LIST* head, char* data)
{
    LIST* new_node = new_list();
    LIST* list = tail(head);

    new_node->info = data;
    list->next = new_node;

    return head;
}

LIST* add_to_list_at_index(LIST* head, char* data, int index)
{
    LIST* new_node = new_list();
    LIST* list = head;
    int i = 0;

    new_node->info = data;
    while (list != NULL)
    {
        if (i == index) {
            new_node->next = list->next;
            list->next = new_node->next;
            break;
        }

        inc(list);
        i++;
    }

    if (list == NULL) {
        list = tail(head);
        list->next = new_node;
        new_node->next = NULL;
    }

    return head;
}

int find_in_list(LIST* head, char* to_find)
{
    LIST* list = head->next;
    int outlet = -1;
    int index = 0;

    while ((list != NULL) && (outlet < 0))
    {
        if (equals(to_find, list->info))
            outlet = index;

        ++index;
        inc(list);
    }

    return outlet;
}

/*
char* to_string(LIST* head)
{
    LIST* list = head->next;
    char* outlet = "";

    outlet = concat(outlet, "---\n- list:\n");
    while (list != NULL)
    {
        outlet = concat(outlet, "  - ");
        outlet = concat(outlet, list->info);
        outlet = concat(outlet, "\n");
        inc(list);
    }

    outlet = concat(outlet, "...\n");
    return outlet;
}
*/
char* to_string(LIST* head)
{
    LIST* list = head->next;
    char* outlet = "";

    while (list != NULL)
    {
        outlet = concat(outlet, list->info);
        outlet = concat(outlet, "\n");
        inc(list);
    }

    return outlet;
}

char* to_string_with_title(LIST* head, char* title)
{
    LIST* list = head->next;
    char* outlet = "";

    outlet = concat(outlet, "---\n- ");
    outlet = concat(outlet, title);
    outlet = concat(outlet, ":\n");

    while (list != NULL)
    {
        outlet = concat(outlet, "  - ");
        outlet = concat(outlet, list->info);
        outlet = concat(outlet, "\n");
        inc(list);
    }

    outlet = concat(outlet, "...\n");
    return outlet;
}

void print_list(LIST* head)
{
    LIST* list = head->next;

    printf("---\n");
    printf("- list:\n");
    while (list != NULL)
    {
        if (list->info != NULL)
            printf("  - %s\n", list->info);
        else
            printf("  - NULL\n");
        inc(list);
    }
    printf("...\n");
}

void write_list_to_file(LIST* head, char* output)
{
    FILE* outlet = fopen(output, "w");
    LIST* list   = head->next;

    for (list = head->next; list != NULL; inc(list))
        fprintf(outlet, "%s\n", list->info);

    fclose(outlet);
}

int contains(LIST* head, char* to_find)
{
    LIST* list = head->next;
    int result = 0;

    while ((list != NULL) && (result == 0))
    {
        result = equals(to_find, list->info);
        inc(list);
    }

    return result;
}

LIST* using_bubblesort(LIST* head, int(*function)(int))
{
    LIST* list = head->next;
    char* temp = NULL;
    char* stri = NULL;
    char* strj = NULL;
    int   len  = list_length(head);
    int   i    = 0;
    int   flag = 1;

    while (flag)
    {
        flag = 0;

        for (i = 0, list = head->next; i < len - 1; ++i, inc(list))
        {
            stri = list->info;
            strj = (list->next)->info;

            if (function(compare(stri, strj)))
            {
                temp = (list->next)->info;
                (list->next)->info = list->info;
                list->info = temp;
                flag = 1;
            }
        }
    }

    /* MEOW */
    if ((head->next)->info == NULL)
        head->next = (head->next)->next;

    return head;
}

int is_bigger(int result)
{
    if (result == BIGGER)
        return 1;
    else
        return 0;
}

LIST* sort_list(LIST* head)
{
    return using_bubblesort(head, &is_bigger);
}

char* pop_from_list(LIST* head)
{
    LIST* list   = head->next;
    char* result = NULL;

    if (list != NULL)
    {
        head->next = list->next;
        result = list->info;
    }

    return result;
}

LIST* push_to_list(LIST* head, char* item)
{
    LIST* list = tail(head);
    list->next = (LIST*) malloc(sizeof(LIST));
    inc(list);
    list->info = item;
    list->next = NULL;
    return head;
}

LIST* remove_from_list(LIST* head, int index)
{
    LIST* list   = head->next;
    LIST* to_del = NULL;
    char* outlet = NULL;
    int i = 0;

    while ((i + 1 != index) && (list != NULL))
    {
        inc(list);
        ++i;
    }

    if (list->next != NULL)
    {
        to_del = list->next;
        list->next = to_del->next;
        free(to_del);
    }

    return head;
}

void free_list(LIST* head)
{
    LIST* list = head;
    LIST* memo;

    while (list->next != NULL)
    {
        memo = list->next;
        free(list);
        list = memo;
    }

    free(list);
}

LIST* split(char* string, char to_divide)
{
    LIST* result  = new_list();
    char* section = "";
    char  to_add  = '\n';
    int   length  = strlen(string);
    int   i       = 0;

    for (i = 0; i < length; ++i)
    {
        section = "";

        while (string[i] != to_divide && i < length)
        {
            section = concat(section, to_array(string[i]));
            i++;
        }

        result = add_to_list(result, section);
    }

    return result;
}

#endif
