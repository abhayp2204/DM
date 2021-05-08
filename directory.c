#include"directory.h"
#include"hash.c"

Directory createDirectory()
{
    //creating a directory manager with a root node

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
    //checking if the current directory we are working in is file or not
    if(manager->Current->Type == 0)
    {
        printf("this file/directory can't be added in this file\n");
        return;
    }
    Directory D, T; 

    //checking if the name we are adding already exists or not
    T = manager->Current->LeftChild;
    while(T != NULL)
    {
        if(strcmp(T->Name, name)==0)
        {
            printf("the file/directory with the name '%s' already exists\n", name);
            return;
        }
        T = T->RightSibling;
    }
    
    //assigning all the characteristics of the adding file/directory to the variable directory D
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

    //traversing in the current directory till we find the last file/directory to add the file/direcotry to the right of it
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
    printf("\n'%s' added in the current directory\n\n",name);

    return;
}

void Move(Directory manager, char path[400])
{
    Directory T = manager->Current;
    Directory D;
    int flag = 0;

    //Moving from current directory to the root directory
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

    //Moving from root directory to the desired directory till we traverse to the right most file/directory in the current directory
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

    //if we move to the desired directory then return else if desired directory is not found then incorrect path
    if(flag == 1)
    {
        printf("\nsuccessfully moved to the desired file/directory\n\n");
        return;
    }
    else
    {
        printf("\nerror: incorrect path\n\n");
        manager->Current = T;
        return;
    }
}

void Alias(Directory D, HashTable HT, char alias[20], char path[400])
{
    //Check if the path is correct
    int correctPath = IsCorrectPath(D,path);

    if( correctPath )
    {
        //If path is correct, insert alias to hash table
        if(Insert_Alias(HT,alias,path))
        printf("\n\"%s\" has been added\n\n", alias);
    }
    else
    {
        printf("\n\"%s\" has an invalid path\n\n", alias);
    }
}

int IsCorrectPath(Directory D, char path[400])
{
    Directory P =  D;
    Directory Parent =  P;

    int correctPath = 1;
    int found;              //found indicates whether the directory is present at a particular level

    int level = 0;
    char* word;

    //Check if the path is correct
    do
    {
        /*If path is "root/Desktop/Pictures"

          ExtractPath(path,0) = "root"
          ExtractPath(path,1) = "Desktop"
          ExtractPath(path,2) = "Pictures"

          First we check if root is present at level 0,
          then we check if Desktop is present at level 1
          and so on
        */
        word = ExtractPath(path,level++);

        //If word is empty, we reached the end of the path
        if( strcmp(word, "") == 0 )
        break;

        //If path contains directories that do not exist in the actual directory structure
        if( P == NULL )
        {   
            correctPath = 0;
            break;
        }

        //Reinitialize found to 0 at the start of each level
        found = 0;

        //Traverse right across the level and search
        while(P != NULL)
        {
            if(strcmp(P->Name, word) == 0 && P->Type == _DIR )
            {
                found = 1;
                Parent = P;   //Must save the parent to travese down
                break;
            }
            P = P->RightSibling;
        }

        //If founnd is 0, then directory doesn't exist in the current level
        if( found ==  0 )
        {
            correctPath = 0;
            break;
        }

        //Traverse down
        P = Parent->LeftChild;
        
    }while( strcmp(word, "") != 0 );

    return correctPath;
}

char* ExtractPath(char path[400], int level)
{
    char* word = (char*)malloc(20*sizeof(char));
    char ch;
    int k = 0;

    for( int i = 0 ; i < strlen(path) ; i++ )
    {
        ch = path[i];

        //We skip all characters before level number of '/'
        //If the level is 2, at the end of this loop we will
        //be at the character after the second /
        while( level > 0 )
        {
            if( ch == '/' )
            {
                level--;
            }
            i++;
            ch = path[i];
        }

        //Get the string between nth slash and (n+1)th slash
        if( ch == '/' )
        {
            break;
        }
        
        word[k++] = ch;
    }

    return word;
}

void Find(Directory manager, char prefix[20])
{
    Directory D = manager->Current->LeftChild;
    int flag = 0;

    printf("\n");

    //finding all the files/directories with the given prefix
    while(D != NULL)
    {
        char str[strlen(prefix)+1];

        if(strlen(D->Name) >= strlen(prefix))
        {
            strncpy(str, D->Name, strlen(prefix));

            str[strlen(prefix)] = '\0';

            if(strcmp(prefix, str)==0)
            {
                printf("%s  ", D->Name);
                flag = 1;
            }
        }
        D = D->RightSibling;
    }
    
    //if not found any file/directory with the given prefix then incorrect prefix  
    if(flag == 0)
    {
        printf("Please enter correct prefix");
    }

    printf("\n\n");
    return;
}