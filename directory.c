#include"directory.h"

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

void Move(Directory manager, char path[400])
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

void Alias(Directory D, HashTable HT, char alias[20], char path[400])
{
    int correctPath = IsCorrectPath(D,path);

    if( correctPath )
    {
        if(Insert_Alias(HT,alias,path))
        printf("\"%s\" has been added\n", alias);
    }
    else
    {
        printf("\"%s\" has an invalid path\n", alias);
    }
}

int IsCorrectPath(Directory D, char path[400])
{
    Directory P =  D;
    Directory Parent =  P;

    int correctPath = 1;
    int found;

    int level = 0;
    char* word;

    //Check if the path is correct
    do
    {
        word = ExtractPath(path,level++);

        //Reached the end of the path
        if( strcmp(word, "") == 0 )
        break;

        //Path contains extra dir/files
        if( P == NULL )
        {   
            correctPath = 0;
            break;
        }

        //Reinitialize found to 0 at the start of each level
        found = 0;

        //Traverse right
        while(P != NULL)
        {
            if(strcmp(P->Name, word) == 0 )
            {
                found = 1;
                Parent = P;
                break;
            }
            P = P->RightSibling;
        }

        //Directory doesn't exist in the current level
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

        while( level > 0 )
        {
            if( ch == '/' )
            {
                level--;
            }
            i++;
            ch = path[i];
        }

        if( ch == '/' )
        {
            break;
        }
        
        word[k++] = ch;
    }

    return word;
}