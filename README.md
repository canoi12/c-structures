# C Structure

tiny single header examples of c structures

- linked list (linked_list.h)
- stack (stack.h)
- queue (queue.h)
- deque (deque.h)

TODO:

- binary search tree
- AVL tree
- vector
- map

## examples

you will find some examples in main.c file

put this in a .c file before compile

```c
#define LIB_NAME_IMPLEMENTATION
#include "lib_name.h"

```

example for linked list:

```c
// main.c
#define LINKED_LIST_IMPLEMENTATION
#include "linked_list.h"

int main(int argc, char ** argv) {
	list_t list = create_list();

	list_add(&list, 90);
	list_add(&list, 110);
	list_add(&list, 5);
	list_add(&list, 20);
	print_list(list);

	list_remove(&list, 2);
	print_list(list);

	return 0;
}

```