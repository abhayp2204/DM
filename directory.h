#ifndef __DIRECTORY_H
#define __DIRECTORY_H
#define _invalid -555
#define _FILE 0
#define _DIR 1

//Include
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//Typedefs
typedef struct DM *Directory;
typedef struct DM *PtrToDir;

typedef struct Table *HashTable;
typedef struct Node *PtrToNode;

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
    PtrToNode *pStart;
};

struct Node
{
    char Alias[20];
    char Path[400];
    PtrToNode Next;
};

//Functions
Directory createDirectory();
void Add(Directory manger, char type[20], char name[20]);
int Move(Directory manager, char path[20]);
void Alias(Directory D, HashTable HT, char alias[20], char path[400]);
int IsCorrectPath(Directory D, char path[100]);
char *ExtractPath(char path[100]);
void Find(Directory manager, char prefix[20]);
int Teleport(Directory manager,HashTable HT,char alias_te[20]);

//Alias table functions
HashTable CreateHT_SC(int iTableSize);
Key HashString(HashTable HT, char alias[]);
int Insert_Alias(HashTable HT, char alias[], char path[]);
char *Search_Alias(HashTable HT, char alias[]);
void PrintTable(HashTable HT);

#endif