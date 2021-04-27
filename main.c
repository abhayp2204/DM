#include "directory.h"
#include<stdio.h>
#include<string.h>

int main()
{
    Directory manager;

    char action[10];
    char type[20];
    char name[20];

    while(1)
    {
        scanf("%s",action);

        if(strcmp(action, "ADD")==0)
        {
            scanf("%s %s",type, name);
            Add(manager, type, name);
        }
    }
}