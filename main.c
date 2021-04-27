#include "directory.h"
#include<stdio.h>
#include<string.h>

int main()
{
    Directory manager;

    manager = createDirectory();

    char action[10];
    char type[20];
    char name[20];
    char whole_path[400];
    char path[20][20];

    while(1)
    {
        scanf("%s",action);

        if(strcmp(action, "ADD")==0)
        {
            scanf("%s %s",type, name);
            Add(manager, type, name);
        }
        
        else if(strcmp(action, "MOVE")==0)
        {
            scanf("%s",whole_path);

            int index=0;

            int i=0,j=0;
            while(whole_path[i])
            {
                while(whole_path[i] && whole_path[i] != '/')
                {
                    path[j][index++] = whole_path[i];
                    i++;         
                }
                i++;
                path[j][index] = 0;
                Move(manager, path[j]);
                j++;
                index=0;
            }
        }
    }
}