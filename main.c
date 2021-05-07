#include "directory.c"
#include "hash.c"
#include <stdio.h>
#include <string.h>

int main()
{
    Directory manager;
    manager = createDirectory();

    HashTable HT = CreateHT_SC(101);

    char action[10];
    char type[20];
    char name[20];
    char iAlias[20];
    char iPath[400];
    char whole_path[400];
    char path[20][20];

    while (1)
    {
        scanf("%s", action);

        //ADD
        if (strcmp(action, "ADD") == 0)
        {
            scanf("%s %s", type, name);
            Add(manager, type, name);
        }

        //MOVE
        else if (strcmp(action, "MOVE") == 0)
        {
            scanf("%s", whole_path);

            int index = 0;

            int i = 0, j = 0;
            while (whole_path[i])
            {
                while (whole_path[i] && whole_path[i] != '/')
                {
                    path[j][index++] = whole_path[i];
                    i++;
                }
                i++;
                path[j][index] = 0;
                Move(manager, path[j]);
                j++;
                index = 0;
            }
        }

        //ALIAS
        else if (strcmp(action, "ALIAS") == 0)
        {
            //Input alias and path
            scanf("%s %s", iAlias, iPath);

            Alias(manager, HT, iAlias, iPath);
        }
        
        else if (strcmp(action, "FIND") == 0)
        {

            //Input Name to search

            scanf("%s", name);
            Find(manager, name);
        }

        printf("\n");
    }
}
