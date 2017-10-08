#include "pcb.h"
#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

PCB_p pcb_new(void) {
	PCB_p this = (PCB_p) calloc(1, sizeof(PCB_s));
	// initialize new PCB
	pcb_init(this);
	return this;
}

void pcb_init(PCB_p this) {
	this->context = (CPU_context_p) calloc(1, sizeof(CPU_context_s));
	this->context->pc = 0;
	this->context->ir = 0;
	this->context->psr = 0;
	this->context->r0 = 0;
	this->context->r1 = 0;
	this->context->r1 = 0;
	this->context->r1 = 0;
	this->context->r1 = 0;
	this->context->r1 = 0;
	this->context->r6 = 0;
	this->context->r7 = 0;
	
	this->pid = 0;
	this->state = NEW;
	this->parent = 0;
	this->priority = 0;
	this->mem = 0;
	this->size = 0;
	this->channel_no = 0;
}

void pcb_destroy(PCB_p this) {
	free(this->context);
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

unsigned int pcb_get_pc(PCB_p this) {
	return this->context->pc;
}

void pcb_set_parent(PCB_p this, unsigned int parent_pid) {
	this->parent = parent_pid;
}

unsigned char pcb_get_priority(PCB_p this) {
	return this->priority;
}

void pcb_set_priority(PCB_p this, unsigned char priority) {
	this->priority = priority % NUM_PRIORITY_LEVEL;
}

char * pcb_to_string(PCB_p this, char * s) {
	char buffer[INT_MAX]  = "";
	//sprintf prints formatted data into a buffer/char array (does not allocate space, can overwrite data)
	sprintf(buffer, "PID: %u, Priority: %u, state: %d, PC: %u, Mem: %u, Size: %u, Channel No.: %u", 
			this->pid, this->priority, this->state, this->context->pc, this->mem, this->size, this->channel_no);
	//TODO: add additional pcb data to to_string
	strcpy(s, buffer);
	return s;
	/*
	s = "PCB[";
	strcat(s, "\n  PID:" + this->pid);
	strcat(s, "\n  state:" + this->state);
	strcat(s, "\n  parentPID:" + this->parent);
	strcat(s, "\n  prio:" + this->priority);
	strcat(s, "\n  mem:" + this->mem);
	strcat(s, "\n  size:" + this->size);
	strcat(s, "\n  cannel_no:" + this->channel_no + '\n]');
	// TODO: strcat(s, "  context:" + this->pid);
	*/
}