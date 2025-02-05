typedef struct ListNode {
        int value;
        struct ListNode *next;
    } ListNode;


struct ListNode *NewListNode(int val);
void append(struct ListNode **head, int val);
void behead(struct ListNode **head);
void insert(struct ListNode **head, int val, int index);
void pop(struct ListNode **head);
void prepend(struct ListNode **head, int val);
void print(struct ListNode **head);
void removeNode(struct ListNode **head, int index);
