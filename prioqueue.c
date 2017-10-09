#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

PRIO_q_p prio_q_new(void) {
	PRIO_q_p this = (PRIO_q_p) calloc(1, sizeof(PRIO_q_s));
	// construct each fifo queue
	for (int i = 0; i < NUM_PRIORITY_LEVEL; i++) {
		this->queues[i] = fifo_q_new();
	}
	return this;
}

void prio_q_destroy(PRIO_q_p this) {
	// destroy each fifo queue
	for (int i = 0; i < NUM_PRIORITY_LEVEL; i++) {
		fifo_q_destroy(this->queues[i]);
	}
	free(this);
}

void prio_q_enqueue(PRIO_q_p this, PCB_p proc) {
	fifo_q_enqueue(this->queues[proc->priority], proc);
}

PCB_p prio_q_dequeue(PRIO_q_p this) {
	// check each fifo queue's head
	for (int i = 0; i < NUM_PRIORITY_LEVEL; i++) {
		void * head = fifo_q_dequeue(this->queues[i]);

		// if null, this queue is empty
		// else, the returned dequeued pcb gets to run now
		if (head) {
			return (PCB_p) head;
		}
	}
	return NULL;
}

char * prio_q_to_string(PRIO_q_p this, char * s) {
	if (!this || !s) {
		return NULL;
	}
	char tempstring[256];
	char buffer[256];
	for (int i = 0; i < NUM_PRIORITY_LEVEL; i++) {
		sprintf(buffer, "\n  Q%u: %s", i, fifo_q_to_string(this->queues[i], buffer));
		strcat(tempstring, buffer);
	}
	strcpy(s, tempstring);
	return s;
}
