#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>

typedef struct deque_node_s deque_node_t;

struct deque_node_s {
	int value;
	deque_node_t *next;
	deque_node_t *prev;
};

typedef struct deque_s {
	int count;
	deque_node_t *front;
	deque_node_t *back;
} deque_t;


/**
*	create a deque
**/
deque_t create_deque();

/**
* push a new value to the deque front
**/
void deque_push_front(deque_t *deque, int value);
/**
*	push a new value to the deque back
**/
void deque_push_back(deque_t *deque, int value);

/**
* pop the front value of deque
**/
int deque_pop_front(deque_t *deque);
/**
* pop the back value of deque
**/
int deque_pop_back(deque_t *deque);

int deque_front(deque_t deque);
int deque_back(deque_t deque);

void print_deque(deque_t deque);
void print_reverse_deque(deque_t deque);

#endif // DEQUE_H

#if defined(DEQUE_IMPLEMENTATION)

static deque_node_t * new_deque_node(int value)
{
	deque_node_t *node = malloc(sizeof(deque_node_t));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

deque_t create_deque()
{
	deque_t deque = {0};
	deque.front = NULL;
	deque.back = NULL;
	deque.count = 0;

	return deque;
}

void deque_push_front(deque_t *deque, int value)
{
	deque_node_t *node = deque->front;

	// create a new node
	deque_node_t *newNode = new_deque_node(value);

	// point new node next to the deque front node
	newNode->next = deque->front;

	// point deque front prev node to the new node
	if (deque->front) deque->front->prev = newNode;

	// point deque front to the new node
	deque->front = newNode;

	// if deque back is empty, point it to the new node
	if (!deque->back) deque->back = newNode;

	deque->count++;
}

void deque_push_back(deque_t *deque, int value)
{
	// create a new node
	deque_node_t *newNode = new_deque_node(value); 

	// point new node prev node to the deque back
	newNode->prev = deque->back;

	// point deque back next node to the new node
	if (deque->back) deque->back->next = newNode;

	// point deque back to the new node
	deque->back = newNode;

	// if deque front is empty, point it to the new node
	if (!deque->front) deque->front = newNode;

	deque->count++;
}

int deque_pop_front(deque_t *deque)
{
	deque_node_t *front = deque->front;
	// if deque is empty, return -1
	if (!front) return -1;

	int value = front->value;

	// point deque front to the second value
	deque->front = front->next;
	// if there is a second value, point his prev node to null
	if (deque->front) deque->front->prev = NULL;
	// if deque back == old front, point it to the new front (probably NULL)
	if (deque->back == front) deque->back = deque->front;
	free(front);

	deque->count--;
	return value;
}

int deque_pop_back(deque_t *deque)
{
	deque_node_t *back = deque->back;
	// if deque is empty return null
	if (!back) return -1;

	int value = back->value;

	// point deque back to the penultimate node
	deque->back = back->prev;

	// if deque back is not null, point next to null
	if (deque->back) deque->back->next = NULL;
	// if deque front is equal to old back, point it to the new back (probably NULL)
	if (deque->front == back) deque->front = deque->back;
	free(back);

	deque->count--;
	return value;
}

int deque_front(deque_t deque)
{
	if (!deque.front) return -1;
	return deque.front->value;
}

int deque_back(deque_t deque)
{
	if (!deque.back) return -1;
	return deque.back->value;
}

void print_deque(deque_t deque)
{
	deque_node_t *node = deque.front;
	printf("deque(%d): ", deque.count);
	while(node != NULL) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

int deque_count(deque_t deque)
{
	return deque.count;
}

void print_reverse_deque(deque_t deque)
{
	deque_node_t *node = deque.back;
	printf("deque inv: ");
	while(node != NULL) {
		printf("%d ", node->value);
		node = node->prev;
	}
	printf("\n");
}

#endif // DEQUE_IMPLEMENTATION