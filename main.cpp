#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <list.h>

void print_list(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("the value of the node is:  %d \n", current->value);
        current = current->next;
    }
}

int count_the_nodes(Node *head) {
    if(head == NULL) {
        return 0;
    } else{
        return 1 + count_the_nodes(head->next);
    }
}

int count_matches(Node *head, int value) {
    if(head == NULL) {
        return 0;
    } else if(head->value == value)  {
        return 1 + count_matches(head->next,value);
    }  else{
        return 0  + count_matches(head->next,value);
    }
}

Node *delete_the_matching_records(Node *head, int value)
{
    if (head == NULL)
    {
        printf("The head node is empty..\n");
        return NULL;
    }
    else
    {
        Node *current_node = head;
        Node *previous_node;

        while (current_node->next != NULL)
        {
            if (current_node->value == value)
            {
                previous_node->next = current_node->next;
            }
            else
            {
                previous_node = current_node;
            }
            current_node = current_node->next;
        }
        return head;
    }
}

Node *delete_the_head_node(Node *head)
{
    if (head == NULL)
    {
        printf("The head node is empty..\n");
        return NULL;
    }
    else
    {
        Node *newHead = head->next;
        free(head);
        return newHead;
    }
}

Node *delete_the_tail_node(Node *head)
{
    if (head == NULL)
    {
        printf("The head node is empty..\n");
        return NULL;
    }
    else
    {
        Node *current_node = head;
        Node *previous_node;
        while (current_node->next != NULL)
        {
            previous_node = current_node;
            current_node = current_node->next;
        }
        printf("the tail node that contains %d is deleted \n", previous_node->next->value);
      //  free(previous_node->next);
        return head;
    }
}


int search(Node *head, int value) {
    if (head == NULL)
    {
        printf("The linked list is empty..");
        return -1;
    }
    else {
        int position = 0;
        if(head->value == value) {
            return position;
        } else{
            Node *current_node = head;
            while (current_node->next !=  NULL)
            {
                if(current_node->value == value) {
                    return position;
                }
                current_node = current_node->next;
                position ++;
            }
        }
        return position;
    }
}

bool replace(Node  *head, int index, int value) {
    if (head == NULL)
    {
        printf("The linked list is empty..");
        return 0;
    }
    else {
        int position = 0;
        Node *current_node = head;
        while(current_node->next != NULL) {
            if(position == index) {
                current_node->value = value;
                return 1;
            } 
            current_node = current_node->next;
            position ++;
        }
    }
    return 0;
}

Node *insert_at_head(Node *head, int value)
{
    Node *new_node = (Node *)calloc(1, sizeof(Node));
    new_node->value = value;
    if (head == NULL)
    {
        return new_node;
    }
    else
    {
        new_node->next = head;
        return new_node;
    }
}

Node *insert_at_tail(Node *head, int value)
{
    Node *new_node = (Node *)calloc(1, sizeof(Node));
    new_node->value = value;
    if (head == NULL)
    {
        printf("Linkedlist is empty.. so newnode is the head node..\n");
        return new_node;
    }
    else
    {
        Node *current_node = head;
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        return head;
    }
}

int main(int argc, char **argv)
{
 Node a;
    a.value = 5;
    Node b;
    b.value = 10;
    Node c;
    c.value = 15;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    print_list(&a);

    printf("Inserting the new node 11 at the head..\n");
    Node *newHead = insert_at_head(&a, 11);

    printf("Inserting the new node 8 at the head..\n");
    newHead = insert_at_head(newHead, 22);

    printf("Inserting the new node 22 at the head..\n");
    newHead = insert_at_head(newHead, 22);

    printf("Executing the printlines after inserting bunch of elements..\n");
    print_list(newHead);

    printf("Inserting the new node 111 at the end..\n");
    newHead = insert_at_tail(newHead, 111);

    printf("Inserting the new node 222 at the end..\n");
    newHead = insert_at_tail(newHead, 222);

    print_list(newHead);

    printf("Deleting the head node\n");
    newHead = delete_the_head_node(newHead);

    printf("Printing the elements after deleting the head node..\n");
    print_list(newHead);

     printf("Deleting the head node\n");
    newHead = delete_the_head_node(newHead);
     printf("Printing the elements after deleting the head node..\n");
    print_list(newHead);

     printf("Deleting the head node\n");
    newHead = delete_the_head_node(newHead);

     printf("Printing the elements after deleting the head node..\n");
    print_list(newHead);

    printf("Deleting the tail node\n");
    newHead = delete_the_tail_node(newHead);

      printf("Inserting the new node 222 at the end..\n");
    newHead = insert_at_tail(newHead, 222);

    int count = count_the_nodes(newHead);
    printf("The number of nodes in the linked list is: %d  \n",count);

    bool replace_flag = replace(newHead, 3,1000);
    if(replace_flag == 1) {
        printf("the value 111 has been replaced with 1000 \n");
    } else{
        printf("the value 111 has not been replaced with 1000 \n");
    }

    print_list(newHead);

    int match_count = count_matches(newHead, 222);
    printf("The number of nodes that match the value 222 is: %d",match_count);
 
    return 0;
}
