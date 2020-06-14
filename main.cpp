#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int element;
    List *next;
} List;

List make_list(List &l, int element)
{
    l.next = NULL;
    l.element = element;
    return l;
}

int is_empty_list(List &l)
{
    if (l.next == NULL)
    {
        return 1;
    }
    return 0;
}

// 它是委托的，也就是假的，不会产生什么...
void append_element(List *l, int element)
{
    List *initList = (List *)malloc(sizeof(List));
    initList->element = element;
    initList->next = NULL;

    if (is_empty_list(*l))
    {
        l->next = initList;
    }
    else
    {
        List *head = l;
        while (head->next)
        {
            head = head->next;
        }
        head->next = initList;
    }
}

// 链表长度
int list_len(List &l)
{
    List *head = l.next;
    int len = 0;
    while (head)
    {
        ++len;
        head = head->next;
    }
    return len;
}

void print_list(List &l)
{
    List *head = l.next;
    int i = 0;
    while (head)
    {
        printf("%d\n", head->element);
        head = head->next;
    }
}

void insert_head(List &l, List &pl)
{
    pl.next = &l;
}

void insert_element(List &l, int element)
{
    List *temp_list = (List *)malloc(sizeof(List));
    temp_list->next = NULL;
    temp_list->element = element;
    List *pre;

    List *head = l.next;

    while (head)
    {
        if (head->element < element)
        {
            pre = head->next;
            head->next = temp_list;
            temp_list->next = pre;
            return;
        }
        head = head->next;
    }
}

void delete_element(List &l, int element)
{
    List *pre;
    List *head = l.next;

    while (head)
    {
        if (head->element == element)
        {
            if (head->next->next)
            {
                head = head->next;
            }
            else
            {
                head->next = NULL;
            }
        }
    }
}

List *find_element(List &l, int element)
{
    if (l.element == element)
    {
        return &l;
    }
    List *head = l.next;
    while (head)
    {
        if (head->element == element)
        {
            return head;
        }
        head = head->next;
    }
}

int main()
{
    List *l = (List *)malloc(sizeof(List));
    List *fn = (List *)malloc(sizeof(List));
    make_list(*fn, 1234);
    make_list(*l, 1);
    append_element(l, 12);
    append_element(l, 123);
    insert_element(*l, 13);
    delete_element(*l, 123);
    print_list(*l);
}