/*
 * list.c - implementation of the integer list functions 
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"



list_t* lst_new()
{
   list_t *list;
   list = (list_t*) malloc(sizeof(list_t));
   list->first = NULL;
   return list;
}


void lst_destroy(list_t *list)
{
	struct lst_iitem *item, *nextitem;

	item = list->first;
	while (item != NULL){
		nextitem = item->next;
		free(item);
		item = nextitem;
	}
	free(list);
}


void insert_new_process(list_t *list, int pid, int status, time_t starttime)
{
	lst_iitem_t *item;

	item = (lst_iitem_t *) malloc (sizeof(lst_iitem_t));
	item->pid = pid;
	item->status = status;
	item->starttime = starttime;
	item-> endtime = 0;
	item->next = list->first;
	list->first = item;
}


void update_terminated_process(list_t *list, int pid, int status, time_t endtime)
{
   printf("teminated process with pid and status: %d and %d\n", pid, status);
}


void lst_print(list_t *list)
{
	lst_iitem_t *item;

	printf("Process list:\n");
	item = list->first;
	/*while(1){  */
	while (item != NULL){
		printf("PID:%d STATUS:%d DURATION:%s\n", item->pid, item->status, ctime(&(item->endtime))-ctime(&(item->starttime)));
		item = item->next;
	}
	printf("-- END OF LIST.\n");
}
