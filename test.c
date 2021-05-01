#include "directory.c"

//Functions
void CreateDir(Directory D);

int main()
{
    Directory D = createDirectory();
    CreateDir(D);

    HashTable HT = CreateHT_SC(10);
    Alias(D,HT,"Pizza","root/Pictures/Travel/Italy/");
    Alias(D,HT,"Baguette","root/Pictures/Travel/France/");
    Alias(D,HT,"Java","root/Desktop/Code/");
    Alias(D,HT,"Beer","root/Pictures/Travel/Germany/");
    Alias(D,HT,"SomePDF","root/Documents/");
    Alias(D,HT,"Goa","root/Pictures/Beach/");
    Alias(D,HT,"PicType","root/Pictures/Landscape/");
    Alias(D,HT,"Snow","root/Pictures/Mountains/");
    Alias(D,HT,"Pizza","root/Pictures/Travel/France/");

    PrintTable(HT);

    /*
    int flag = IsCorrectPath(D, "root/Pictures/Travel/Italy");
    
    if( flag )
    {
        printf("correct alias\n");
    }
    else
    {
        printf("wrong alias\n");
    }
    */
}

void CreateDir(Directory D)
{
    Directory A = (Directory)malloc(sizeof(struct DM));
    assert(A != NULL);
    Directory B = (Directory)malloc(sizeof(struct DM));
    assert(B != NULL);
    Directory C = (Directory)malloc(sizeof(struct DM));
    assert(C != NULL);
    Directory Z = (Directory)malloc(sizeof(struct DM));
    assert(Z != NULL);
    Directory E = (Directory)malloc(sizeof(struct DM));
    assert(E != NULL);
    Directory F = (Directory)malloc(sizeof(struct DM));
    assert(F != NULL);
    Directory G = (Directory)malloc(sizeof(struct DM));
    assert(G != NULL);
    Directory H = (Directory)malloc(sizeof(struct DM));
    assert(H != NULL);
    Directory I = (Directory)malloc(sizeof(struct DM));
    assert(I != NULL);

    D->LeftChild = A;

    strcpy(A->Name, "Documents");
    A->Parent = D;
    A->RightSibling = B;
    A->LeftChild = NULL;
    
    strcpy(B->Name, "Pictures");
    B->Parent = D;
    B->RightSibling = C;
    B->LeftChild = Z;
    
    strcpy(C->Name, "Desktop");
    C->Parent = D;
    C->RightSibling = NULL;
    C->LeftChild = G;

    strcpy(Z->Name, "Beach");
    Z->Parent = B;
    Z->RightSibling = E;
    Z->LeftChild = NULL;

    strcpy(E->Name, "Mountains");
    E->Parent = B;
    E->RightSibling = F;
    E->LeftChild = NULL;

    strcpy(F->Name, "Travel");
    F->Parent = B;
    F->RightSibling = NULL;
    F->LeftChild = H;

    strcpy(G->Name, "Code");
    G->Parent = C;
    G->RightSibling = NULL;
    G->LeftChild = NULL;

    strcpy(H->Name, "France");
    H->Parent = F;
    H->RightSibling = I;
    H->LeftChild = NULL;

    strcpy(I->Name, "Italy");
    I->Parent = F;
    I->RightSibling = NULL;
    I->LeftChild = NULL;
}

/*
void Alias(Directory D, HashTable HT, char alias[20], char path[100])
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

int IsCorrectPath(Directory D, char path[100])
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

char* ExtractPath(char path[100], int level)
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

*****************************
#ifndef __DIRECTORY_H
#define __DIRECTORY_H
#define _invalid -555;

//Include
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>

//Typedefs
typedef struct DM * Directory;
typedef struct DM * PtrToDir;

typedef struct Table* HashTable;
typedef struct Node* PtrToNode;

typedef int Key;

//Directory Structure
struct DM
{
    int Type;
    char Name[20];
    PtrToDir Current;
    PtrToDir Parent;
    PtrToDir RightSibling;
    PtrToDir LeftChild;   
};

struct Table
{
    int iTableSize;
    PtrToNode* pStart;
};

struct Node
{
    char Alias[20];
    char Path[100];
    PtrToNode Next;
};

//Functions
Directory createDirectory();
void Add(Directory manger, char type[20], char name[20]);
void Move(Directory manager, char path[20]);
void Alias(Directory D, HashTable HT, char alias[20], char path[100]);
int IsCorrectPath(Directory D, char path[100]);
char* ExtractPath(char path[100], int level);
void Teleport(char alias[20]);
void Find(char prefix[20]);

//Alias table functions
HashTable CreateHT_SC(int iTableSize);
Key HashString(HashTable HT, char alias[]);
int Insert_Alias(HashTable HT, char alias[], char path[]);
char* Search_Alias(HashTable HT, char alias[]);
void PrintTable(HashTable HT);

#endif
*/