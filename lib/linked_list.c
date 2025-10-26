/**
 * Singly linked list implementation.
 *
 * @author: Zhanyi Chen
 * @class: CS 5008
 * @term: 25Fall
 */

#include <stdlib.h>
#include <stdbool.h>


#include "movie.h"
#include "linked_list.h"


/** 
 * Creates a new linked list node.
*/
node * __ll__new_node(Movie *movie) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->movie = movie;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

/**
 * Creates a new linked list.
 * 
 * @return a pointer to the new linked list
 */
LinkedList *new_linked_list() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/**
 * Frees the memory associated with a linked list.
 * 
 * Frees just the linked list and nodes, the movies
 * stored are not freed. 
 * @param list the linked list to free
 */
void free_linked_list(LinkedList *list) {
    node *curr = list->head;
    node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}

/**
 * Frees the memory, including memory allocated
 * to movies stored in the link list. 
 * 
 * @param list the linked list to free
*/
void clear_and_free_linked_list(LinkedList *list) {
    node *curr = list->head;
    node *next;
    while (curr != NULL) {
        next = curr->next;
        free_movie(curr->movie);
        free(curr);
        curr = next;
    }
    free(list);
}

/**
 * Adds a movie to the front of a linked list.
 * 
 * Don't forget to update the tail pointer if the list is empty,
 * as when there is a single node, head and tail should both point
 * towards it.
 * 
 * @param list the linked list to add to
 * @param movie the movie to add
 */
void ll_add_front(LinkedList *list, Movie *movie) {
    list->size++;
    node* new_node = __ll__new_node(movie);
    if(list->head){
        node* temp = list->head;

        new_node->next = temp;
        temp->prev = new_node;
        list->head = new_node;
        }
        else{
            list->head = new_node;
            list->tail = new_node;  
        }
}

/**
 * Adds a movie to the back of a linked list.
 *
 * Don't forget to update the head pointer if the list is empty,
 * as when there is a single node, head and tail should both point
 * towards it.
 *
 * @param list the linked list to add to
 * @param movie the movie to add
 */
void ll_add_back(LinkedList *list, Movie *movie) {
    list->size++;
    node* new_node = __ll__new_node(movie);
    node* temp = list->tail;
    if(temp){
        temp->next = new_node;
        new_node->prev = temp;
        list->tail = new_node;
        return;
        }
    list->head = new_node;
    list->tail = new_node;
    
}


/**
 * Inserts a movie into a linked list at a given index.
 * 
 * if n == 0, safe to call ll_add_front, if n == list->size, safe to call ll_add_back
 * 
 * if n is out of bounds, do nothing (return early)
 * 
 * @param list the linked list to insert into
 * @param movie the movie to insert
 * @param n the index to insert at
 */
void ll_insert(LinkedList *list, Movie *movie, int n) {
    if(n>list->size || n<0){
        return;
    }
   if(n==0){
    ll_add_front(list, movie);
   }
   else if (n==list->size)
   {
    ll_add_back(list,movie);
   }
   else{
    list->size ++;
    node* new = __ll__new_node(movie);

    node* cur = list->head;
    for(int i= 0; i<=n-1; i++){
        cur = cur->next;
    }
    node* prev = cur->prev;

    prev->next = new;

    new->prev = prev;
    new->next = cur;

    cur->prev = new;
   }
   
}


/**
 * Removes the first movie from a linked list.
 * 
 * Don't forget if there is only one item in the list, and it is removed,
 * to update the tail pointer.
 * 
 * @param list the linked list to remove from
 * @return the movie that was removed
 */
Movie * ll_remove_front(LinkedList *list) {
    Movie *movie = NULL;
    
    if(list->size == 1){
        list->head->prev=NULL;
        list->head->next=NULL;
        movie = list->head->movie;

        list->head = NULL;
        list->tail = NULL;
        list->size--;
    }
    else if (list->size !=0)
    {
        node* prehead = list->head;
        node* next = prehead->next;

        movie = list->head->movie;


        list->head = next;
        next->prev= NULL;

        prehead->next= NULL;
        list->size--;

    }
    return movie;
}

/**
 * Removes the last movie from a linked list.
 * 
 * Don't forget if there is only one item in the list, and it is removed,
 * to update the head pointer.
 * 
 * @param list the linked list to remove from
 * @return the movie that was removed
 */
Movie * ll_remove_back(LinkedList *list) {
    Movie *movie = NULL;
    
    if(list->size == 1){
        list->tail->prev=NULL;
        list->tail->next=NULL;
        movie = list->tail->movie;

        list->tail = NULL;
        list->head = NULL;
        list->size--;
    }
    else if (list->size !=0)
    {
        node* pretail = list->tail;
        node* prev = pretail->prev;

        movie = list->tail->movie;


        list->tail = prev;
        prev->next= NULL;

        pretail->prev= NULL;
        list->size--;

    }
    return movie;
}

/**
 * Removes a movie from a linked list at a given index.
 * 
 * if n == 0, safe to call ll_remove_front, if n == list->size - 1, safe to call ll_remove_back
 * 
 * if n is out of bounds, return NULL
 * 
 * @param list the linked list to remove from
 * @param n the index to remove at
 * @return the movie that was removed
 */
Movie * ll_remove(LinkedList *list, int n) {
    Movie * movie = NULL;
    if(n==0){
        movie= ll_remove_front(list);
    }
    else if (n== list->size -1)
    {
        movie = ll_remove_back(list);
    }
    else if (n >= list->size || n<0)
    {
        return movie;
    }
    
    else{
        list->size --;
    
        node* cur = list->head;
        for(int i= 0; i<=n-1; i++){
            cur = cur->next;
        }
        node* prev = cur->prev;
        node* next = cur->next;
        movie = cur->movie;

        prev->next = next;
        next->prev = prev;
    }
    
    return movie;
}

/**
 * Gets a movie from a linked list at a given index.
 * 
 * if n is out of bounds, return NULL
 * 
 * @param list the linked list to get from
 * @param n the index to get at
 * @return the movie at the given index
 */
Movie* ll_get(LinkedList *list, int n) {
    node *curr = list->head;
    if (n < 0 || n >= list->size) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        curr = curr->next;
    }
    return curr->movie;
}

/**
 * Checks if a linked list contains a given movie.
 * 
 * Rare if a linked list contains a movie more than once, but
 * if so, just immediately return true.
 * 
 * @param list the linked list to check
 * @param movie the movie to check for
 * @return true if the linked list contains the movie, false otherwise
 */
bool ll_contains(LinkedList *list, Movie *movie) {
    node *curr = list->head;
    while (curr != NULL) {
        if (curr->movie == movie) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

/**
 * Checks if a linked list is empty.
 * 
 * @param list the linked list to check
 * @return true if the linked list is empty, false otherwise
 */
bool ll_is_empty(LinkedList *list) {
    return list->size == 0;
}

/**
 * Converts a linked list to a string representation.
 * 
 * @param list the linked list to convert
 * @return a string representation of the linked list
 */
char* ll_to_str(LinkedList *list) {
    
    char *str = (char *)malloc(sizeof(char) * (MAX_MOVIE_STR_LEN + 3) * list->size);
    if (list->size == 0) {
        strcpy(str, "[]");
        return str; // early exit
    }
    // implied else
    strcpy(str, "[");
    node *curr = list->head;
    while (curr != list->tail) {
        char *movie_str = movie_to_str(curr->movie);
        strcat(str, movie_str);
        strcat(str, ", ");
        free(movie_str);
        curr = curr->next;
    }
    // now add the tail
    char *movie_str = movie_to_str(curr->movie);
    strcat(str, movie_str);
    free(movie_str);
    strcat(str, "]");

    return str;
}

