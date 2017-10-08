#include "pcb.h"

#include <stdlib.h>
#include <stdio.h>

int main(void) {
	
	// Create a PCB structure on the heap
	PCB_p process = pcb_new();
	
	char pcbstring[] = "";
	
	pcb_to_string(process, pcbstring);
	// Print the initial contents of the structure
	printf("Contents of the PCB: %s", pcbstring);
	// Populate the PCB with appropriate data 
	pcb_set_priority(process, (int)((double)rand() / ((double)RAND_MAX + 1) * 15));
	
	pcb_set_state(process, READY);
	
	pcb_to_string(process, pcbstring);
	
	printf("Contents of the PCB: %s", pcbstring);
	
}
