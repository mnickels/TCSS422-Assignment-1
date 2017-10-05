#ifndef FIFOQUEUE_H_INCLUDED
#define FIFOQUEUE_H_INCLUDED

#include "pcb.h"

typedef struct node {
	PCB_p process;
	struct node * next;
} Node_s;

typedef Node_s * Node_p;

typedef struct fifo_q {
    int length;
    int elementSize;
    Node_p front;
    Node_p back ;
} FIFO_q_s;

typedef FIFO_q_s * FIFO_q_p; 

FIFO_q_p q_new(FIFO_q_p);

void q_destroy(FIFO_q_p);

char * q_to_string(FIFO_q_p);

int q_is_empty(FIFO_q_p);

int q_enqueue(FIFO_q_p, PCB_p);

PCB_p q_dequeue(FIFO_q_p);

#endif
