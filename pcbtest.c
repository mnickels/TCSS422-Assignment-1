#include "pcb.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

	// Create a PCB structure on the heap
	PCB_p process = pcb_new();

	char pcbstring[256];

	// Print the initial contents of the structure
	printf("Contents of the PCB: %s\n", pcb_to_string(process, pcbstring));

	// Populate the PCB with appropriate data
	srand(time(0));
	pcb_set_priority(process, (unsigned char)(rand() % 15));
	//TODO: Add more data

	pcb_set_state(process, READY);

	printf("Contents of the PCB: %s\n", pcb_to_string(process, pcbstring));

	pcb_destroy(process);

}
