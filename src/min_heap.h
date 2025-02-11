static const int STARTING_CAPACITY_MIN_HEAP = 8;


typedef struct MinHeap{
    int *values;
    int capacity;
    int length;
} MinHeap;

struct MinHeap *NewMinHeap();
void bubble_up_min_heap(struct MinHeap *pq);
int get_smallest_child(struct MinHeap *pq, int left, int right);
int get_left_min_heap(struct MinHeap *pq, int index);
int get_min(struct MinHeap *pq);
int get_parent_min_heap(struct MinHeap *pq, int index);
int get_right_min_heap(struct MinHeap *pq, int index);
void offer_min_heap(struct MinHeap *pq, int val);
int poll_min_heap(struct MinHeap *pq);
void print_min_heap(struct MinHeap *pq);
void sink_down_min_heap(struct MinHeap *pq);
