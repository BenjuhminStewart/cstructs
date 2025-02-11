static const int STARTING_CAPACITY_MAX_HEAP = 8;


typedef struct MaxHeap{
    int *values;
    int capacity;
    int length;
} MaxHeap;

struct MaxHeap *NewMaxHeap();
void bubble_up_max_heap(struct MaxHeap *pq);
int get_biggest_child(struct MaxHeap *pq, int left, int right);
int get_left_max_heap(struct MaxHeap *pq, int index);
int get_max(struct MaxHeap *pq);
int get_parent_max_heap(struct MaxHeap *pq, int index);
int get_right_max_heap(struct MaxHeap *pq, int index);
void offer_max_heap(struct MaxHeap *pq, int val);
int poll_max_heap(struct MaxHeap *pq);
void print_max_heap(struct MaxHeap *pq);
void sink_down_max_heap(struct MaxHeap *pq);

