#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

	char buffer[256];
	srand(time(0));

	PRIO_q_p pq = prio_q_new();

	int processes = (rand() % 60) + 40;

	for (int i = 0; i < processes; i++) {
		prio_q_enqueue(pq, pcb_new());
		if (i % 10 == 9) {
			prio_q_to_string(pq, buffer);
		}
	}

	printf("%s\n", prio_q_to_string(pq, buffer));

	prio_q_destroy(pq);
}
