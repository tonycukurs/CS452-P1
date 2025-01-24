/**Update this file with the starter code**/
#include "lab.h" 
 
list_t *list_add(list_t *list, void *data) {
    if (!list || !data) {
        return NULL;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = list->head->next;
    new_node->prev = list->head;

    if (list->head->next) {
        list->head->next->prev = new_node;
    }

    list->head->next = new_node;
    list->size++;

    return list;
}