#include "pcb.h"
#include "fifoqueue.h" 

#include <stdlib.h>
#include <stdio.h>

int main(void) {
	// Create a queue on the heap
    FIFO_q_p queue = fifo_q_new();
	
	//buffers for tostring functions
	char fifostring[] = "";
	char pcbstring = "";
	
	// Populate the queue with a random number of PCBs (between 10 and 30
	int i;
	int j = (int)((double)rand() / ((double)RAND_MAX + 1 - 10) * 30);
	for (i = 0; i < j; i++) {
		int priority = (int)((double)rand() / ((double)RAND_MAX + 1) * 15);
		PCB_p process = pcb_new();
		pcb_set_priority(process, priority);
		//pcb_to_string(process, pcbstring);
		fifo_q_to_string(queue, fifostring);
		printf("%s", fifostring);
		//printf(" : contents: %s", pcbstring);
		
	}
	
    fifo_q_destroy(queue);
}
