#include <stdlib.h>

#include "queue.h"

// a typical queue implementation

void enqueue(queue_t **queueptr, void *data) {
	if (!(*queueptr)) {
		*queueptr = malloc(sizeof(queue_t));
		(*queueptr)->head = malloc(sizeof(qnode_t));
		(*queueptr)->head->data = data;
		(*queueptr)->head->next = 0;
		return;
	}
	queue_t *queue = *queueptr;
	qnode_t *node = queue->head;
	while (node->next) {
		node = node->next;
	}
	node->next = malloc(sizeof(qnode_t));
	node->next->data = data;
	node->next->next = 0;
}

qnode_t *dequeue(queue_t **queueptr) {
	qnode_t *head = (*queueptr)->head;
	(*queueptr)->head = head->next;
	return head;
}
