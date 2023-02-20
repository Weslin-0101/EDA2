#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 100

typedef struct Node
{
    char str[MAX_STR_SIZE + 1];
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void push_back(char *str)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strncpy(node->str, str, MAX_STR_SIZE);
    node->prev = tail;
    node->next = NULL;

    if (tail == NULL)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

char *pop_back()
{
    if (tail == NULL)
    {
        return "NULL";
    }

    Node *node = tail;
    tail = tail->prev;

    if (tail == NULL)
    {
        head = NULL;
    }
    else
    {
        tail->next = NULL;
    }

    char *str = node->str;
    free(node);
    return str;
}

int main()
{
    char str[MAX_STR_SIZE + 1];
    char command[MAX_STR_SIZE + 1];

    while (scanf("%s", command) != EOF)
    {
        if (strcmp(command, "inserir") == 0)
        {
            scanf("%s", str);
            push_back(str);
        }
        else if (strcmp(command, "desfazer") == 0)
        {
            printf("%s\n", pop_back());
        }
    }

    return 0;
}
