const int STARTING_CAPACITY = 10;
struct ArrayList {
  int current_capacity;
  int current_size;
  int *data;

  void add(ArrayList *list, int value);
  int get(ArrayList *list, int index);
  void remove(ArrayList *list, int index);
  void clear(ArrayList *list);
  int size(ArrayList *list);
};
