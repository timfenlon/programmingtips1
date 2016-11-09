/*
 * @file main.c
 * @author Copyright (C) 2016 by Tim Fenlon
 * @date 8 November 2016
 * @brief Description : LinkedList in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "logging.h"

#include "linkedlist.h"

int main(void)
{
	/* prints Hello Linked Lists */
	print_hello_linked_list();

	/* In (ANSI) C99, you can use a designated initializer to initialize a structure
	 * Initialize linkedlistnodes */
	Node_List aList = { .head = NULL, .tail = NULL, .numNodes=0 };

	return EXIT_SUCCESS;
}
