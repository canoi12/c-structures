#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct queue_node_s queue_node_t;

struct queue_node_s {
	int value;
	queue_node_t *next;
};

typedef struct queue_s {
	int count;
	queue_node_t *front;
} queue_t;

/**
* create a new queue
**/
queue_t create_queue();

/**
* push a value to the back of queue
**/
void queue_enqueue(queue_t *queue, int value);

/**
* dequeue a value from the front of queue
**/
int queue_dequeue(queue_t *queue);

/**
* the value on the front of queue
**/
int queue_front(queue_t queue);
/**
* queue count
**/
int queue_count(queue_t queue);

void print_queue(queue_t queue);

#endif // QUEUE_H

#if defined(QUEUE_IMPLEMENTATION)

/**
* create a new queue node
*/
static queue_node_t* new_queue_node(int value)
{
	queue_node_t *node = malloc(sizeof(queue_node_t));
	node->value = value;
	node->next = NULL;
	return node;
}

queue_t create_queue()
{
	queue_t queue = {0};
	queue.front = NULL;
	queue.count = 0;
	return queue;
}

void queue_enqueue(queue_t *queue, int value)
{
	queue_node_t *node = queue->front;
	// If front is NULL, creates a new node
	if (!node) {
		queue->front = new_queue_node(value);
		queue->count++;
		return;
	}

	// iterate over the queue until find the last node
	while (node->next) node = node->next;

	// create a new node
	queue_node_t *newNode = new_queue_node(value);
	// make last node point to the new node
	node->next = newNode;

	// if (!queue->front) queue->front = newNode;

	queue->count++;
}

int queue_dequeue(queue_t *queue)
{
	queue_node_t *node = queue->front;
	// if queue is empty, return -1
	if (queue->count <= 0) return -1;

	int value = queue->front->value;

	// point queue front to the next node
	queue->front = node->next;
	// remove actual front node
	free(node);

	queue->count--;
	return value;
}

int queue_front(queue_t queue)
{
	if (!queue.front) return -1;

	return queue.front->value;
}

int queue_count(queue_t queue)
{
	return queue.count;
}

void print_queue(queue_t queue) {
	queue_node_t *node = queue.front;
	printf("queue(%d): ", queue.count);
	while(node) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

#endif // QUEUE_IMPLEMENTATION