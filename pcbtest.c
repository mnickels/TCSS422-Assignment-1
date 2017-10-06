#include "pcb.h"

#include <stdlib.h>
#include <stdio.h>

int main(void) {
	PCB_p process = pcb_new();
	
	char * pcbstring;
	
	pcb_to_string(process, pcbstring);
	
	pcb_set_priority(process, (int)((double)rand() / ((double)RAND_MAX + 1) * N));
	/*
	int i;
	for (i = 0; i < 15; i++) {
		int random = (int)((double)rand() / ((double)RAND_MAX + 1) * 15);
		
	}
	*/
	
	pcb_to_string(process, pcbstring);
	
	/*
	pcb_set_pid(process, 1);
	
	pcb_set_state(process, READY);
	
	pcb_set_parent(process, 1);
	
	pcb_set_priority(process, 1);
	
	printf("The pid is: %u", pcb_get_pid(process));
	
	printf("The pid is: %d", pcb_get_state(process));

	printf("The pid is: %u", pcb_get_parent(process));
	
	printf("The pid is: %u", pcb_get_priority(process));
	
	//printf("%s", pcb_to_string(process));
	
	pcb_destroy(process);
	
	*/
}
