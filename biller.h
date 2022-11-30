#ifndef BILLER_H
#define BILLER_H

#include "databasefunc.h"
#include "ui.h"
#include<stdlib.h>
#include<time.h>

typedef struct cart
{
    struct item product;
    int quantity;
    float prz;
} scart;

void biller();
void additemcart( scart *c,int n,struct item pro[],int *num);
void displaycart(scart p[],int size);
float total(int size,scart pro[]);
void printbill(scart p[],int size);

#endif
