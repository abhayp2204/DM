#include "directory.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

Directory createDirectory()
{
    Directory manager;
    manager = (Directory)malloc(sizeof(struct DM));
    assert(manager != NULL);

    manager->Type = 1;
    strcpy(manager->Name, "root");
    manager->Current = manager;
    manager->RightSibling = NULL;
    manager->LeftChild = NULL;

    return manager;
}

void Add(Directory manager, char type[20], char name[20])
{
    Directory D, T; 
    D = (Directory)malloc(sizeof(struct DM));
    assert(D != NULL);

    if(strcmp(type, "file")==0)
    {
        D->Type = 0;
    }

    else if(strcmp(type, "directory")==0)
    {
        D->Type = 1;
    }

    else
    {
        printf("invalid type\n");
        return;
    }

    strcpy(D->Name, name);
    D->Parent = manager->Current;
    D->RightSibling = NULL;
    D->LeftChild = NULL;

    T = manager->Current->LeftChild;
    
    if(manager->Current->LeftChild != NULL)
    {
        while(T->RightSibling != NULL)
        {
            T = T->RightSibling;
        }
        T->RightSibling = D;
    }
    else
    {
        manager->Current->LeftChild = D;
    }

    return;
}

void Move(Directory manager, char path[20])
{
    Directory T = manager->Current;
    Directory D;
    int flag = 0;

    if(strcmp(path, "root")==0)
    {
        while(strcmp(manager->Current->Name, "root") != 0)
        {
            manager->Current = manager->Current->Parent;
        }
        D = manager->Current;
    }
    else
        D = manager->Current->LeftChild;

    while(flag != 1 && D != NULL)
    {
        if(strcmp(D->Name, path)==0)
        {
            manager->Current = D;
            flag = 1;
        }
        else
        {
            D = D->RightSibling;
        }
    }

    if(flag == 1)
        return;
    else
    {
        printf("error: incorrect path\n");
        manager->Current = T;
        return;
    }
}
