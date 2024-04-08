/*
 * @Author: bzdhxs bzdhxsnt01@gmail.com
 * @Date: 2024-04-08 16:23:23
 * @LastEditors: bzdhxs bzdhxsnt01@gmail.com
 * @LastEditTime: 2024-04-08 18:29:22
 * @FilePath: \start\source\kernel\tools\list.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "tools/list.h"
#include "comm/types.h"


void list_init (list_t * list) {
    list->first = list->last = (list_node_t *)0;
    list->count = 0;
}

void list_insert_first(list_t *list, list_node_t *node){

    node->next = list->first;
    node->pre = (list_node_t *)0;

    if (list_is_empty(list)) {
        list->first = list->last = node;
    } else {
        list->first->pre = node;
        list->first = node;
    }

    list->count++;
}

void list_insert_last(list_t *list, list_node_t *node) {
    node->pre = list->last;
    node->next = (list_node_t *)0;

    if(list_is_empty(list)) {
        list->first = list->last = node;
    } else {
        list->last->next = node;
        list->last = node;
    }

    list->count++;
}


list_node_t * list_remove_first(list_t *list) {
    if (list_is_empty(list)) {
        return (list_node_t *)0;
    }

    list_node_t * remove_node = list->first;
    list->first = remove_node->next;

    if (list->first ==  (list_node_t *)0) {
        list->last = (list_node_t *)0;
    } else {
        remove_node->next->pre = (list_node_t *)0;
    }

    remove_node->pre = remove_node->next = (list_node_t *)0;
    list->count--;
    return remove_node;
}


list_node_t* list_remove(list_t *list, list_node_t *node) {
    if (node == list->first) {
        list->first = node->next;
    }

    if (node == list->last) {
        list->last = node->pre;
    }

    if (node->pre) {
        node->pre->next = node->next;
    }

    if (node->next) {
        node->next->pre = node->pre;
    }

    node->pre = node->next = (list_node_t *)0;

    list->count--;
    return node;
}








