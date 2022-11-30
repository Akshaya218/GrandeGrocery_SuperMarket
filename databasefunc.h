#ifndef DATABASEFUNC_H
#define DATABASEFUNC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item
{
    int item_id;
    char item_name[100];
    float item_prz;
};

struct item* additem(int *no_of_items,struct item *arr);
void view_items(struct item pro[],int numberofitems);
struct item* modifyitem(int *no_of_items,struct item *pro);
struct item* deleteitem(int *no_of_items,struct item *pro);
int search(int no_of_items,struct item pro[]);

#endif // DATABASEFUNC
