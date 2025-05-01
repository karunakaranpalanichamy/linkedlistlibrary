typedef struct Node
{
    int value;
    struct Node *next;
} Node;

void print_list(Node *head);
Node *insert_at_head(Node *head, int value);
Node *insert_at_tail(Node *head, int value);
Node *delete_the_head_node(Node *head);
Node *delete_the_tail_node(Node *head);
Node *delete_the_matching_records(Node *head, int value);
int count_the_nodes(Node *head);
int search(Node *head, int value);
int count_matches(Node *head, int value);