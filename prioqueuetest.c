#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

	char buffer[4096];
	char buffer2[256];
	srand(time(0));

	PRIO_q_p pq = prio_q_new();

	int processes = (rand() % 40) + 60;

	for (int i = 0; i < processes; i++) {
		PCB_p pcb = pcb_new();
		pcb->priority = (unsigned char) (rand() % 16);
		prio_q_enqueue(pq, pcb);
		if (i % 10 == 9) {
			printf("enqueued %d PCBs,\n", (i % 10) + 1);
			int todequeue = (rand() % 3) + 4;
			printf("dequeued %d PCBS:\n", todequeue);
			for (int j = 0; j < todequeue; j++) {
				PCB_p dequeued = prio_q_dequeue(pq);
				printf("  %s\n", pcb_to_string(dequeued, buffer2));
				pcb_destroy(dequeued);
			}
			printf("%s\n", prio_q_to_string(pq, buffer));
		}
	}

	prio_q_destroy(pq);
}
