#include <stdio.h>

#define LINKED_LIST_IMPLEMENTATION
#include "linked_list.h"

#define STACK_IMPLEMENTATION
#include "stack.h"

#define QUEUE_IMPLEMENTATION
#include "queue.h"

#define DEQUE_IMPLEMENTATION
#include "deque.h"

int main(int argc, char ** argv)
{
	// List example
	list_t list = create_list();
	list_add(&list, 10);
	list_add(&list, 90);
	list_add(&list, 150);
	list_add(&list, 175);
	list_add(&list, 60);
	list_add(&list, 95);
	print_list(list);

	list_remove(&list, 3);
	print_list(list);

	list_remove_value(&list, 150);
	print_list(list);

	printf("\n");

	// Stack example
	stack_t stack = create_stack();
	stack_push(&stack, 100);
	stack_push(&stack, 90);
	stack_push(&stack, 99);
	stack_push(&stack, 50);
	print_stack(stack);

	stack_pop(&stack);
	print_stack(stack);

	stack_pop(&stack);
	print_stack(stack);

	printf("\n");

	// Queue example
	queue_t queue = create_queue();
	queue_enqueue(&queue, 10);
	queue_enqueue(&queue, 90);
	queue_enqueue(&queue, 150);
	print_queue(queue);

	queue_dequeue(&queue);
	print_queue(queue);

	printf("\n");

	// Deque example
	deque_t deque = create_deque();
	deque_push_front(&deque, 10);
	deque_push_front(&deque, 20);
	deque_push_front(&deque, 30);
	print_deque(deque);

	deque_push_back(&deque, 90);
	deque_push_back(&deque, 15);
	print_deque(deque);

	deque_pop_front(&deque);
	print_deque(deque);

	printf("\n");

	return 0;
}