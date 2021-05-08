#include "directory.c"
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
    char prefix[20];

    while (1)
    {
L1:     //Input the action
        printf("State the action you want to perform\n");
        scanf("%s", action);

        //ADD
        if (strcmp(action, "ADD") == 0)
        {
            printf("Enter the type and name of a file/directory\n");
            scanf("%s %s", type, name);

            Add(manager, type, name);
        }

        //MOVE
        else if (strcmp(action, "MOVE") == 0)
        {
            printf("Enter the path for the desired file/directory\n");
            scanf("%s", whole_path);

            if(whole_path[strlen(whole_path)-1] != '/')
            {
                printf("Please enter the path with proper slashes\n\n");
                goto L1;
            }

            int index = 0;
            
            //breaking the whole path into subpaths directory by directory
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
            printf("Enter the alias and the path of the file/directory\n");
            scanf("%s %s", iAlias, iPath);

            Alias(manager, HT, iAlias, iPath);
        }
        
        //FIND 
        else if(strcmp(action, "FIND")==0)
        {
            printf("Enter the prefix you want to find\n");
            scanf("%s",prefix);

            Find(manager, prefix);
        }

        //QUIT
        else if(strcmp(action, "QUIT")==0)
        {
            char ans;
            printf("This will terminate the program, are you sure you want to quit(y/n)\n");
            scanf("%c",ans);

            if(ans == 'y')
                return 0;
            else
                goto L1;
        }

    }
}
