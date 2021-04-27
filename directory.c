#include "directory.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void createDirectory(Directory manager)
{
    manager = (Directory)malloc(sizeof(struct DM));
    assert(manager != NULL);

    manager->Type = 1;
    strcpy(manager->Name, "root");
    manager->current = manager;
    manager->RightSibling = NULL;
    manager->LeftChild = NULL;
}

void Add(Directory manager, char type[20], char name[20])
{
    Directory D; 
    D = (Directory)malloc(sizeof(struct DM));
    assert(D != NULL);
    
    D = manager->current->LeftChild;
    
    while(D->RightSibling != NULL)
    {
        D = D->RightSibling;
    }
    D = D->RightSibling;

    if(strcmp(type, "file")==0)
        D->Type = 0;

    else if(strcmp(type, "directory")==0)
        D->Type = 1;
    
    else
    {
        printf("invalid type\n");
        return;
    }

    strcpy(D->Name, name);
    D->RightSibling = NULL;
    D->LeftChild = NULL;

    return;
}
