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
    //Move(D, "root");
    Add(D, "directory", "Documents");
    Add(D, "directory", "Pictures");
    Add(D, "directory", "Desktop");
    
    Move(D, "Desktop");
    Add(D, "directory", "Code");

    Move(D, "root");
    Move(D, "Pictures");
    Add(D, "directory", "Beach");
    Add(D, "directory", "Mountains");
    Add(D, "directory", "Travel");

    Move(D, "Travel");
    Add(D, "directory", "France");
    Add(D, "directory", "Italy");
}