#include "pcb.h"

#include <stdlib>
#include <stdio.h>

int main(void) {
	PCB_p process = pcb_new();
	
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
	
}
