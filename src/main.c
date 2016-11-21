/*! \file */ 
/*
 * @file main.c
 * @author Copyright (C) 2016 by Tim Fenlon
 * @date 8 November 2016
 * @brief Description : LinkedList in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <errno.h>

#include "logging.h"

#include "linkedlist.h"

 //Define some constants for char sizes
extern const int MAX_TITLE_LENGTH = 256;
extern const int MAX_INPUT_LENGTH = 256;

 /**
 * @brief prints out a menu for our program
 *
 * @param  const char* title, must be null terminated at end of char array
 * @param  uint32_t menuVersion, number of version for linked list program
 *
 * @return void no return value
 */
void printMenu(const char* title, uint32_t menuVersion, NodeList* theList)
{
	printf("\nMenu Title %s version %d\n", title, menuVersion);
	printf("We have created %llu nodes\n", theList->numNodes);
	printf("Which operation do you want to perform?\n");
	printf("1. Insert a certain number of randomly generated List Nodes\n");
	printf("2. Print LinkedList Nodes\n");
	printf("3. Recursive Print LinkedList Nodes\n");
	printf("4. Delete All Linked List Nodes\n");
	printf("5. Recursive Delete All Linked List Nodes\n");
	printf("6. or q or Q will Quit Program\n>");
}

/**
* @brief prints out a help menu for our program menu
*
* @return void no return value
*/
void printMenuHelp()
{
	printf("Invalid Selection\n");
	printf("1. Insert Bunch of Random Linked List Nodes\n");
	printf("2. Print LinkedList Nodes\n");
	printf("3. Recursive Print LinkedList Nodes\n");
	printf("4. Delete All Linked List Nodes\n");
	printf("5. Recursive Delete All Linked List Nodes\n");
	printf("6. or q or Q will Quit Program\n");
}

/**
* @brief prints out a help menu for our program
*
* @return void no return value
*/
void printHelp()
{
	printf("Invalid Parameter Values! optional[-v number] [-m \"Menu Title\"]\n");
	printf("You can include -v for version number and -menu for menu title\n");
	printf("Version number is '-v' followed by integer number of version ex, -v 1\n");
	printf("Menu Title is '-menu' followed by character array of Title ex, -menu \"Linked List\"\n");
}

/**
 * @brief main() entry point into console program
 *
 * @param  int argc  number of arguments sent to the progam
 * @param  char *argv[] a array cooresponding to arc each array is a parameter
 * @param  argv[0] number of elements
 * @param  argv[1] '-v', argv[2] is integer value of version number for menu
 * @param  argv[3] '-menu', argv[4] is char array indicating name of menu must be less than 256 chars
 *
 * @return int if success return value is 0
 */
int main(int argc, char *argv[]) 
{
	char menuTitle[256];
	memset(menuTitle, '\0', MAX_TITLE_LENGTH);

	char menuInput[256];
	memset(menuInput, '\0', MAX_INPUT_LENGTH);

	/*Loop counter*/
	size_t i = 0;
	uint32_t menuVersion = 0;

	/* prints Hello Linked Lists */
	print_hello_linked_list();

	printf("There are %d arguments\n\n", argc);
	/*
	* Parse Command Line
	*/
	for (i = 1; i < argc; i++) {
		printf("argv[%zu] = %s\n", i, argv[i]);
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'v')
			{
				if (argc > i) {
  					menuVersion = atoi(argv[++i]);
					continue;
				}
				else {
					printHelp();
					return -1;
				}
			}
			if (argv[i][1] == 'm')
				//NOTE: -m or -menu are okay values
				if (argc > i) {
					i++;
					memcpy(menuTitle, argv[i],( (strlen(argv[i]) < MAX_TITLE_LENGTH) ? strlen(argv[i]): MAX_TITLE_LENGTH));
					continue;
				}
				else {
					printHelp();
					return -1;
				}
			else
			{
				printHelp();
				return -1;
			}
		}
	}

	/* In (ANSI) C99, you can use a designated initializer to initialize a structure
	* Initialize linkedlistnodes */
	NodeList aList = { .head = NULL,.tail = NULL,.numNodes = 0 };
	int retVal = 0;/**< evaluates function return values >= 1 success or <= 0 failed*/
	int menuIntInput = 0;/**< evaluates scanf_s for integer*/

	uint32_t exitProgram = 0;
	do
	{
		printMenu(menuTitle, menuVersion, &aList);
		retVal = scanf_s("%s", menuInput, (unsigned)_countof(menuInput));
		if (retVal <= 0)
		{
			printMenuHelp();
			continue;
		}

		//In C++ we can use regex to extract proper output,
		//In c case we need to parse the input to get the value we are interested in
		if ((menuInput[0] == '\n') || (menuInput[0] == '\r'))
		{
			printMenuHelp();
			continue;
		}
		else if ((menuInput[0] == 'q') || (menuInput[0] == 'Q'))
		{
			menuIntInput = 6;
		}
		else {
			menuIntInput = atoi(menuInput);
		}
		switch (menuIntInput)
		{
			case 1:
			{
				retVal = createNumRandomNodes(&aList);
				if (retVal <= 0)
				{
					printf("An error occurred calling createNumRandomNodes()\n");
				}
				break;
			}
			case 2:
			{
				retVal = printAllLinkedListNodes(&aList);
				if (retVal <= 0)
				{
					printf("An error occurred calling printAllLinkedListNodes()\n");
				}
				break;
			}
			case 3:
			{
				retVal = printAllLinkedListNodesRecursive(&aList);
				if (retVal <= 0)
				{
					printf("An error occurred calling printAllLinkedListNodesRecursive()\n");
				}
				break;
			}
			case 4:
			{
				retVal = deleteAllLinkedListNodes(&aList);
				if (retVal <= 0)
				{
					printf("An error occurred calling deleteAllLinkedListNodes()\n");
				}
				break;
			}
			case 5:
			{
				retVal = deleteAllLinkedListNodesRecursive(&aList);
				if (retVal <= 0)
				{
					printf("An error occurred calling deleteAllLinkedListNodesRecursive()\n");
				}
				break;
			}
			case 6:
			{
				exitProgram = 1;
				break;
			}
			default:
			{
				printMenuHelp();
				break;
			}
		}//endswitch (menuIntInput)
		menuIntInput = 0;
		memset(menuInput, '\0', MAX_INPUT_LENGTH);
	} while (!exitProgram);

	return EXIT_SUCCESS;
}
