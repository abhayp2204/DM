HashTable CreateHT_SC(int iTableSize)
{
    HashTable HT;

    //Allocate memory for the hashtable
    HT = (HashTable)malloc(sizeof(struct Table));
    assert(HT != NULL);

    //Allocate memory for buckets
    HT->iTableSize = iTableSize;
    HT->pStart = (PtrToNode*)malloc(sizeof(PtrToNode)*iTableSize);

    //Allocate memory for each linked list in a bucket
    for( int i = 0 ; i < iTableSize ; i++ )
    {
        HT->pStart[i] = malloc(sizeof(struct Node));
        assert(HT->pStart[i] != NULL);

        HT->pStart[i]->Next = NULL;
    }

    return HT;
}

Key HashString(HashTable HT, char S[])
{
    int P = 31;
    int term;
    int key = (int)tolower(S[0])-'a';

    for( int i = 1 ; i < strlen(S)-1 ; i++ )
    {  
        if( tolower(S[i]) - 'a' < 0 )
        {
            return -1;
        }

        term = (int)tolower(S[i]) - 'a';
        key = (key*P + term)%(HT->iTableSize);
    }

    return key;
}

int Insert_Alias(HashTable HT, char alias[], char path[])
{
    //Create the node
    PtrToNode Q = malloc(sizeof(struct Node));
    assert(Q != NULL);

    strcpy(Q->Alias, alias);
    strcpy(Q->Path, path);
    Q->Next = NULL;

    Key k = HashString(HT, alias);
    int exists = 0;

    if( k >= 0 )
    {
        PtrToNode P = HT->pStart[k]->Next;

        //If bucket is empty
        if( P == NULL )
        {
            HT->pStart[k]->Next = Q;
        }
        else
        {
            //Insert at end                                       
            while(P->Next != NULL)
            {
                //Check if the alias already exists
                if( strcmp(Q->Alias, P->Alias) == 0 )
                {
                    exists = 1;
                    break;
                }
                P = P->Next;
            }
            //Check if the alias already exists
            if( strcmp(Q->Alias, P->Alias) == 0 )
            {
                exists = 1;
            }

            //Insert Alias
            if(!exists)
            {
                P->Next = Q;
                return 1;
            }
            else
            {
                printf("\"%s\" already exists\n", Q->Alias);
                return 0;
            }
        }
    }
}

char* Search_Alias(HashTable HT, char alias[])
{
    PtrToNode P = NULL;
    Key k = HashString(HT, alias);
    int i = 0;

    //Find the bucket
    P = HT->pStart[k]->Next;

    //Bucket is empty
    if( P == NULL )
    return "";

    //Element located at the start
    if(strcmp(P->Alias, alias) == 0)
    return P->Path;

    //Search the linked list
    while((P != NULL) && (strcmp(P->Alias,alias) != 0))
    {
        P = P->Next;
    }

    //E not found
    if( P == NULL )
    return "";

    return P->Path;
}

void PrintTable(HashTable HT)
{
    printf("\n*** Table ***\n");
    for( Key k = 0 ; k < HT->iTableSize ; k++ )
    {
        printf("Bucket%d: ", k);
        
        PtrToNode P = HT->pStart[k]->Next;

        if( P == NULL )
        {
            printf("\n");
            continue;
        }
        else
        {
            while( P != NULL )
            {
                printf("%s -> ", P->Alias);
                P = P->Next;
            }
        }
        printf("\n");
    }
}