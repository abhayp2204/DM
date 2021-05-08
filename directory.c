#include"directory.h"
#include"hash.c"

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
    //Check if the path is correct
    int correctPath = IsCorrectPath(D,path);

    if( correctPath )
    {
        //If path is correct, insert alias to hash table
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
    int found;                                          //found indicates whether the directory is present at a particular level

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


void Find(Directory manager, char prefix[20]){

    
    Directory Curr;

    Curr = (Directory) malloc(sizeof(struct DM));

    assert(Curr != NULL);

    Curr = manager->Current;
    //printf("dee\n");

    Inorder(Curr,prefix);


}

void Inorder(Directory Curr,char prefix[20]){


    if(Curr == NULL){

        return;
    }

    char str[20];
    char str1[strlen(prefix)];

    int len = strlen(prefix);


    Inorder(Curr->LeftChild,prefix);

    strcpy(str,Curr->Name);
    strncpy(str1,str,len);


    if(strcmp(str1,prefix) == 0){

        printf("%s\n",str);
    }

    Inorder(Curr->RightSibling, prefix);

}