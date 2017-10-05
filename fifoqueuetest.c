#include "pcb.h"
#include "fifoqueue.h" 

#include <stdlib>
#include <stdio.h>

int main(void) {
    FIFO_queue_p queue = FIFO_queue_new(sizeof(PCB_p));
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
