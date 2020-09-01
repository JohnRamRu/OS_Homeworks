#include <stdlib.h>
#include <stdio.h>

//Sturcts
struct node
{
    struct node* next;
    int value;
};

struct linkedList
{
    struct node* next;
};

//Fucts
struct node* node(int value)//init node
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;

    return node;
}

void nodeDestructor(struct node *node)//destructor of node
{
    free(node);
}

struct linkedList* linkedList()//init LL
{
    struct linkedList* list = (struct linkedList*)malloc(sizeof(struct linkedList));
    list->next = NULL;
}

void linkedListDestructor(struct linkedList* head)//destructor of LL (from start(head))
{
    if(head->next == NULL)
    {
        free(head);
        return;
    }

    struct node *current = head->next;
    struct node *next = current->next;

    while(current != NULL)
    {
        nodeDestructor(current);
        current = next;

        if(current != NULL)
        {
            next = current->next;
        }
    }
}

void insert_node(int value, int position, struct linkedList *head)
{
    if(position == 0)//if pasting in a head
    {
        struct node *newNode = node(value);
        newNode->next = head->next;
        head->next = newNode;
        return;
    }

    struct node* currentNode = head->next;

    for (int i = 1; i <= position; ++i) 
    {
        if(currentNode != NULL)
        {
            if(i == position)
            {
                struct node *newNode = node(value); //accocate new node
                newNode->next = currentNode->next; //change tail
                currentNode->next = newNode; //put new node in LL
                return;
            } 
            else 
            {
                currentNode = currentNode->next;
            }
        } 
    }
    return;
}

void delete_node(int position, struct linkedList *head)
{
    if(position == 0)//if delete the head
    {
        if(head->next != NULL) 
        {
            struct node *toDelete = head->next;
            head->next = head->next->next;
            nodeDestructor(toDelete);
            return;
        }
        return;
    }

    struct node* currentNode = head->next;

    for (int i = 1; i <= position; ++i) 
    {
        if (currentNode != NULL) 
        {
            if(i == position)
            {
                struct node *toDelete = currentNode->next; //taking node to delete
                currentNode->next = currentNode->next->next; //chain the "next"
                nodeDestructor(toDelete);

                return;
            } 
            else
            {
                currentNode = currentNode->next;//goto next
            }
        } 
    }
    return;
}

void print_list(struct linkedList *head)
{
    if(head->next == NULL)//if list is empty
    {
        printf("Empty list\n");
        return;
    }

    struct node *currentNode = head->next;

    printf("Head");
    while(currentNode != NULL)
    {
        printf(" -> %d", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main()
{
    struct linkedList *head = linkedList();

    print_list(head);

    insert_node(6, 0, head);
    print_list(head);

    delete_node(0, head);
    print_list(head);

    insert_node(2, 0, head);
    print_list(head);

    insert_node(-158, 1, head);
    print_list(head);

    insert_node(35, 1, head);
    print_list(head);

    insert_node(0, 2, head);
    print_list(head);

    delete_node(0, head);
    print_list(head);
    
    delete_node(1, head);
    print_list(head);

    linkedListDestructor(head);

    return 0;
}

