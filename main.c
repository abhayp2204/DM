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
    char alias_te[20];
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
                printf("Please include a slash at last\n\n");
                goto L1;
            }

            int index = 0, result;
            
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

                result = Move(manager, path[j]);
              
                if(result == 0)
                    goto L1;

                j++;
                index = 0;
            }
            printf("\nSuccessfully moved to the '%s' file/directory\n\n", path[j-1]);
        }

        //ALIAS
        else if (strcmp(action, "ALIAS") == 0)
        {
            //Input alias and path
            printf("Enter the alias and the path of the directory\n");
            scanf("%s %s", iAlias, iPath);

            Alias(manager, HT, iAlias, iPath);
        }

        //TELEPORT
        else if (strcmp(action, "TELEPORT")==0)
        {
            //INPUT ALIAS
            printf("Enter the alias to which you want to teleport\n");
            scanf("%s",alias_te);

            int tele=Teleport(manager,HT,alias_te);
            
            if(tele==1){
                printf("\nTeleport successfully\n\n");
            }
            if(tele==0){
                printf("\nAlias Not Found (Invalid Input)\n\n");
            }
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
            printf("\nThe program terminates....\n\n");
                
            return 0;
        }

        else
        {
            printf("\nInvalid action, please check\n\n");
        }
    }
}
