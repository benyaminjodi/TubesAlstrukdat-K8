#ifndef _chooseyouradv_h_
#define _chooseyouradv_h_

#include "boolean.h"
#include <stdio.h>

#define Nil NULL

#include<stdio.h>
 
typedef struct node {
    char* data;
    struct node* left;
    struct node* right;
} node;

int recursive(node* base);

void playchooseyouradv();

#endif