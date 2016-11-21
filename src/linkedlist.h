/**
 * @file linkedlist.h
 * @author Copyright (C) 2016 by Tim Fenlon
 * @date 16 November 2016
 * @brief Header for linked list node, singly linked list
 */
//Add Macro Guard for 'c' programming
#ifndef MAIN_LINKED_LIST_NODE_H
#define MAIN_LINKED_LIST_NODE_H

#include <stdint.h>

/**
 * @brief Header for linked list nodes
 * @description data and next linked list
 */
typedef struct linked_list
{
    int data;
    struct linked_list *next;
} Node;

/**
 * @brief Header for linked list nodes list
 * @description Holds head and tail of linked list
 */
typedef struct linked_list_nodes
{
    Node *head;
    Node *tail;
    uint64_t numNodes;
} NodeList;

/**
* @brief Creates a specified number of nodes, filled with random values
*
* @param  NodeList* node_list, pointer to valid node list
*
* @return int returns >= 1 if success and <= 0 if a failure occurred
*/
int	createNumRandomNodes(NodeList* node_list);

/**
* @brief prints out all of the linked list nodes using a loop
*
* @param  NodeList* node_list, pointer to valid node list
*
* @return int returns >= 1 if success and <= 0 if a failure occurred
*/
int	printAllLinkedListNodes(NodeList* node_list);

/**
* @brief prints out all of the linked list nodes using a recursive loop
*
* @param  NodeList* node_list, pointer to valid node list
*
* @return int returns >= 1 if success and <= 0 if a failure occurred
*/
int	printAllLinkedListNodesRecursive(NodeList* node_list);

/**
* @brief deletes all of the linked list nodes using a recursive loop and frees allocated memory
*
* @param  NodeList* node_list, pointer to valid node list
*
* @return int returns >= 1 if success and <= 0 if a failure occurred
*/
int	deleteAllLinkedListNodes(NodeList* node_list);

/**
* @brief deletes all of the linked list nodes using a loop and frees allocated memory
*
* @param  NodeList* node_list, pointer to valid node list
*
* @return int returns >= 1 if success and <= 0 if a failure occurred
*/
int	deleteAllLinkedListNodesRecursive(NodeList* node_list);

#endif//MAIN_LINKED_LIST_NODE_H
