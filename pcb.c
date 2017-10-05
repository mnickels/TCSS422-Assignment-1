#include "pcb.h"
#include <stdlib>

PCB_p pcb_new(void) {
	PCB_p this = (PCB_p) calloc(1, sizeof(PCB_s));
	// initialize new PCB
	pcb_init(this);
	return this;
}

void pcb_init(PCB_p this) {
	// TODO: assign values to properties
}

void pcb_destroy(PCB_p this) {
	context_destroy(this->context);
	free(this);
}

unsigned int pcb_get_pid(PCB_p this) {
	return this->pid;
}

void pcb_set_pid(PCB_p this, unsigned int pid) {
	this->pid = pid;
}

enum state_type pcb_get_state(PCB_p this) {
	return this->state;
}

void pcb_set_state(PCB_p this, enum state_type state) {
	this->state = state;
}

unsigned int pcb_get_parent(PCB_p this) {
	return this->parent;
}

void pcb_set_parent(PCB_p this, unsigned int parent_pid) {
	this->parent = parent_pid;
}

unsigned char pcb_get_priority(PCB_p this) {
	return this->priority;
}

void pcb_set_priority(PCB_p this, unsigned char priority) {
	this->priority = priority % 16;
}
