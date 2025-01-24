/**Update this file with the starter code**/
#include "lab.h" 
 
 //Creates a list and initilizes the node.
list_t *list_init(void (*destroy_data)(void *), int (*compare_to)(const void *, const void *))
{
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list->destroy_data = destroy_data;
    list->compare_to = compare_to;
    list->size = 0;
    list->head = (node_t *)malloc(sizeof(node_t));
    list->head->next = list->head;
    list->head->prev = list->head;
    list->head->data = NULL;
    return list;

}

void list_destroy(list_t **list)
{
    node_t *curr = (*list)->head->next;
    while (curr != (*list)->head)
    {
        node_t *temp = curr;
        curr = curr->next;
        (*list)->destroy_data(temp->data);
        free(temp);
    }
    free((*list)->head);
    free(*list);
    *list = NULL;
}

list_t *list_add(list_t *list, void *data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = list->head->next;
    new_node->prev = list->head;
    list->head->next->prev = new_node;
    list->head->next = new_node;
    list->size++;
}   

void *list_remove_index(list_t *list, size_t index)
{
    if (index >= list->size)
    {
        return NULL;
    }
    node_t *curr = list->head->next;
    for (size_t i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    void *data = curr->data;
    free(curr);
    list->size--;
    return data;
}   

int list_indexof(list_t *list, void *data){
    node_t *curr = list->head->next;
    for (size_t i = 0; i < list->size; i++)
    {
        if (list->compare_to(curr->data, data) == 0)
        {
            return i;
        }
        curr = curr->next;
    }
    return -1;
}

