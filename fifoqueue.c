#include "fifoqueue.h"
#include "pcb.h"

#include <stdlib>
#include <stdio.h>


FIFO_q_p q_new(FIFO_q_p queue, int element_size) {
    FIFO_q_p this = (FIFO_q_p) malloc(sizeof(FIFO_q_p));
    if (!this)
        return NULL;
    this->length = 0;
    this->elementSize = element_size;
    this->front = NULL;
    this->back = NULL;
    return this;
}

int q_destroy(FIFO_q_p queue) {
    if (!queue)
        return 0;
    while (!q_is_empty(queue))
        q_dequeue(queue);
    free(queue);
    return 1;
}

char * q_to_string(FIFO_q_p) {
   
}

int q_is_empty(FIFO_q_p queue) {
    if (!queue)
        return 1;
    if (!queue->front)
        return 1;
    return 0;
}

int q_enqueue(FIFO_q_p queue, PCB_p process) {
    if (!queue || !process) 
        return 0;   
    Node_p node = malloc(sizeof(Node_p));
    if (!node)
        return 0;
    node->process = process;
    node->next = NULL;
    if (queue->back)
        queue->back->next = node;
    queue->back = node;
    if (!queue->front)
        queue->front = node;
    queue->length++;
}

PCB_p q_dequeue(FIFO_q_p queue) {
    if (q_is_empty(queue))
        return NULL;
    Node_p front = queue->front;
    Node_p next = front->next;
    free(queue->front);
    queue->front = next;
    queue->length--;
    return next->process;
}
