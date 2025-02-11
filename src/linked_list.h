typedef struct ListNode {
        int value;
        struct ListNode *next;
    } ListNode;


struct ListNode *NewListNode(int val);
void append_node(struct ListNode **head, int val);
void behead_node(struct ListNode **head);
void insert_node(struct ListNode **head, int val, int index);
int length_node(struct ListNode **head);
void pop_node(struct ListNode **head);
void prepend_node(struct ListNode **head, int val);
void print_node(struct ListNode **head);
void remove_node(struct ListNode **head, int index);
void reverse_node(struct ListNode **head);
