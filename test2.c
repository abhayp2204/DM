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
    Alias(D,HT,"Parix","root/Pictures/Travel/France/");

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
    DirDirPectory Z = (Directory)malloc(sizeof(struct DM));
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