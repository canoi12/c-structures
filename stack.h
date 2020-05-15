#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack_node_s stack_node_t;

struct stack_node_s {
	int value;
	stack_node_t *next;
};

typedef struct stack_s {
	int count;
	stack_node_t *root;
	stack_node_t *top;
} stack_t;

/**
* create a new stack
**/
stack_t create_stack();

/**
* push a value to the stack
**/
void stack_push(stack_t *stack, int value);
/**
* pop the last value from the stack
**/
int stack_pop(stack_t *stack);

int stack_top(stack_t stack);
int stack_count(stack_t stack);

void print_stack(stack_t stack);

#endif // STACK_H

#if defined(STACK_IMPLEMENTATION)

static stack_node_t * new_stack_node(int value)
{
	stack_node_t *node = malloc(sizeof(stack_node_t));
	node->value = value;
	node->next = NULL;

	return node;
}

stack_t create_stack()
{
	stack_t stack = {0};
	stack.count = 0;
	stack.root = NULL;
	stack.top = NULL;

	return stack;
}

void stack_push(stack_t *stack, int value)
{
	stack_node_t *node = stack->top;
	// if top node is empty, create a new node
	if (!node) {
		stack->top = new_stack_node(value);
		stack->count++;
		stack->root = stack->top;
		return;
	}

	// while (node->next != NULL) node = node->next;

	// create a new node and point the stack top next node the it
	node->next = new_stack_node(value);

	// point stack top to the new created node
	stack->top = node->next;
	stack->count++;
}

int stack_pop(stack_t *stack)
{
	stack_node_t *node = stack->root;
	// if stack is empty return -1
	if (!node) {
		printf("Empty stack\n");
		return -1;
	} else if (!node->next) { // if there's only 1 node in the stack, remove it
		int value = stack->top->value;
		stack->top = NULL;
		stack->root = NULL;
		free(node);
		stack->count--;
		return value;
	}

	// search for the penultimate node
	while(node->next->next != NULL) node = node->next;

	int value = stack->top->value;

	// remove the top from the stack
	free(stack->top);
	node->next = NULL;

	// point stack top to the penultimate node
	stack->top = node;
	stack->count--;

	return value;
}

int stack_top(stack_t stack)
{
	if (!stack.top) {
		printf("Empty stack\n");
		return -1;
	}

	return stack.top->value;
}

int stack_count(stack_t stack)
{
	return stack.count;
}

void print_stack(stack_t stack) {
	stack_node_t *node = stack.root;
	printf("stack(%d): ", stack.count);
	while(node) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

#endif // STACK_IMPLEMENTATION