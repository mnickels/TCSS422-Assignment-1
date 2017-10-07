#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	PRIO_q_p pq = prio_q_new();
	print_queues(pq);
	prio_q_destroy(pq);
}

void print_queues(PRIO_q_p this) {
	for (int i = 0; i < NUM_PRIORITY_LEVEL; i++) {
		printf("Q%d:Count=%d: ", i, this->queues[i]->length);
		Node_p node = this->queues[i]->front;
		while (node) {
			if (node) {
				printf("P%d->", node->process->pid);
				node = node->next;
			}
		}
		printf("*");
	}
}