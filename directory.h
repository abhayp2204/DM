#ifndef __DIRECTORY_H
#define __DIRECTORY_H

// //Type
// #define FILE 0;
// #define DIR 1;

//Typedefs
typedef struct DM * Directory;
typedef struct DM * PtrToDir;

//Structure
struct DM
{
    int Type;
    char Name[20];
    PtrToDir current;
    PtrToDir RightSibling;
    PtrToDir LeftChild;   
};

//Functions
void createDirectory(Directory manager);
void Add(Directory manger, char type[20], char name[20]);
void Move(char path[20]);
void Alias(char alias[20], char path[20]);
void Teleport(char alias[20]);
void Find(char prefix[20]);

#endif