const int STARTING_CAPACITY_ARRAYLIST = 10;

typedef struct ArrayList {
  int current_capacity;
  int current_size;
  int *data;
} ArrayList;

struct ArrayList *NewArrayList();
int get(struct ArrayList *list, int index);
int pop_val(struct ArrayList *list);
void print(struct ArrayList *list);
int push(struct ArrayList *list, int value);
void updateAt(struct ArrayList *list, int index, int value);
