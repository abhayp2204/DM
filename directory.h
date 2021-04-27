#ifndef __DIRECTORY_H
#define __DIRECTORY_H

//Type
#define FILE 0;
#define DIR 1;

//Typedefs
typedef struct Directory* Directory;
typedef struct Directory* Ptr;

//Structure
struct Directory
{
    char Name[20];
    int Type;

    Ptr Parent;
    Ptr LeftChild;
    Ptr RightSibling;
};

//Functions
void Add(char type[20], char name[20]);
void Move(char path[20]);
void Alias(char alias[20], char path[20]);
void Teleport(char alias[20]);
void Find(char prefix[20]);

#endif