#ifndef QUEUE_H
#define QUEUE_H

// a typical queue implementation

typedef struct _qnode {
	void *data;
	struct _qnode *next;
} qnode_t;

typedef struct _queue {
	qnode_t *head;
} queue_t;

queue_t *array_queue;

void enqueue(queue_t **queueptr, void *data);

qnode_t *dequeue(queue_t **queueptr);

#endif /* QUEUE_H */
