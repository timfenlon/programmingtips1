/**
 * @file linkedlist.h
 * @author Copyright (C) 2016 by Tim Fenlon
 * @date 8 November 2016
 * @brief Header for linked list node, singly linked list
 */
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
} Node_List;

