#include "pcb.h"
#include "fifoqueue.h" 

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    FIFO_queue_p queue = FIFO_queue_new(sizeof(PCB_p));
	int i;
	int j = (int)((double)rand() / ((double)RAND_MAX + 1) * 30);
	for (i = 0; i < j; i++) {
		int priority (int)((double)rand() / ((double)RAND_MAX + 1) * 15);
		PCB_p process = pcb_new();
		process->priority = priority;
	}
    PCB_p process = pcb_new();
    
    if (fifo_q_is_empty(queue)) 
        printf("The queue is empty.\n");
    
    printf("%s", fifo_q_to_string(queue));
    
    fifo_q_enqueue(queue, process);
    
    if (!fifo_q_is_empty(queue)) 
        printf("\nThe queue is not empty.\n");
    
    printf("%s", fifo_q_to_string(queue));
    
    fifo_q_dequeue(queue, process);
    
    printf("%s", fifo_q_to_string(queue));
    
    fifo_q_destroy(queue);
    
}
