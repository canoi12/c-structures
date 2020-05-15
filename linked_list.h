#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct list_node_s list_node_t;

struct list_node_s {
	int value;
	list_node_t *next;
};

typedef struct list_s {
	int count;
	list_node_t *root;
} list_t;

/** 
*	create a new list 
**/
list_t create_list();

/**
* add a new value to the list
**/
void list_add(list_t *list, int value);
/**
* remove the node of the index from list
**/
void list_remove(list_t *list, int index);
/**
* remove the value from the list
**/
void list_remove_value(list_t *list, int value);

int list_get(list_t list, int index);
int list_count(list_t list);

void print_list(list_t list);


#endif // LINKED_LIST_H

#if defined(LINKED_LIST_IMPLEMENTATION)

static list_node_t* new_list_node(int value)
{
	list_node_t *node = malloc(sizeof(*node));
	node->value = value;
	node->next = NULL;
	return node;
}

list_t create_list()
{
	list_t list = {0};
	list.root = NULL;
	list.count = 0;
	return list;
}

void list_add(list_t *list, int value)
{
	list_node_t *node = list->root;
	if (!node) {
		list->root = new_list_node(value);
		list->count++;
		return;
	}

	while(node->next != NULL) {
		node = node->next;
	}

	list_node_t *newNode = new_list_node(value);
	node->next = newNode;

	list->count++;
}

void list_remove(list_t *list, int index)
{
	list_node_t *node = list->root;

	// if list is empty or index is invalid, return
	if (!node || index < 0 || index > list->count - 1) return;

	// if index is zero remove the first element
	if (index == 0) {
		list->root = node->next;
		free(node);
		list->count--;
		return;
	}

	// iterate over the list
	int i = 0;
	while(node->next != NULL)
	{
		// if the next (i+1) is the element i want to remove
		if ((i+1) == index) {
			list_node_t *next = node->next;
			node->next = next->next;
			free(next);
			list->count--;
			return;
		}
		node = node->next;
		i++;
	}
}

void list_remove_value(list_t *list, int value) {
	list_node_t *node = list->root;

	// if list is empty, return
	if (!node) return;

	// if index is zero remove the first element
	if (node->value == value) {
		list->root = node->next;
		free(node);
		list->count--;
		return;
	}

	// iterate over list elements
	int found = 0;
	while(node->next != NULL)
	{
		// check if next node value is what we want
		if (node->next->value == value) {
			found = 1;
			break;
		}
		node = node->next;
	}

	// if found a node with 'value'
	if (found) {
		list_node_t *next = node->next;
		// point current node next to the next next node
		node->next = next->next;
		free(next);
		list->count--;
	}
}

int list_get(list_t list, int index)
{
	list_node_t *node = list.root;
	int i = 0;
	while(node->next != NULL)
	{
		node = node->next;
		if (i == index) return node->value;
		i++;
	}
}

int list_count(list_t list)
{
	return list.count;
}

void print_list(list_t list)
{
	list_node_t *node = list.root;
	printf("list(%d): ", list.count);
	while(node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

#endif // LINKED_LIST_IMPLEMENTATION