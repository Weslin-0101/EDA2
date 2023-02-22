#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node
{
    char *content;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} List;

void init(List *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void destroy(List *list)
{
    Node *curr = list->head;
    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp->content);
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
}

Node *create_node(char *content)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->content = (char *)malloc(strlen(content) + 1);
    strcpy(node->content, content);
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insert(List *list, char *content)
{
    Node *node = create_node(content);
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}

char *undo(List *list)
{
    if (list->tail == NULL)
    {
        return "NULL";
    }
    Node *node = list->tail;
    list->tail = node->prev;
    if (list->tail != NULL)
    {
        list->tail->next = NULL;
    }
    else
    {
        list->head = NULL;
    }
    char *content = node->content;
    free(node);
    return content;
}

int main()
{
    List list;
    init(&list);
    char buffer[MAX_SIZE + 8]; // +8 para considerar "inserir " ou "desfazer"
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (strncmp(buffer, "inserir ", 8) == 0)
        {
            char *content = buffer + 8;
            content[strcspn(content, "\n")] = '\0'; // remove o caractere de nova linha
            insert(&list, content);
        }
        else if (strcmp(buffer, "desfazer\n") == 0)
        {
            char *content = undo(&list);
            printf("%s\n", content);
        }
    }
    destroy(&list);
    return 0;
}
