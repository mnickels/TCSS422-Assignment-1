#include "pcb.h"
#include "fifoqueue.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
	// Create a queue on the heap
    FIFO_q_p queue = fifo_q_new();

	//buffers for tostring functions
	char fifostring[256];
	char pcbstring[256];

	srand(time(0));

	// Populate the queue with a random number of PCBs (between 10 and 30
	int j = (rand() % 20) + 10;
	for (int i = 0; i < j; i++) {
		int priority = (unsigned char) (rand() % 16);
		PCB_p process = pcb_new();
		pcb_set_priority(process, priority);
		fifo_q_enqueue(queue, process);
		printf("%s", fifo_q_to_string(queue, fifostring));
		printf(" : contents: %s\n", pcb_to_string(process, pcbstring));
	}

	// testing dequeue
	PCB_p proc = fifo_q_dequeue(queue);
	printf("%s", fifo_q_to_string(queue, fifostring));
	printf(" : contents: %s\n", pcb_to_string(proc, pcbstring));

    fifo_q_destroy(queue);
}
