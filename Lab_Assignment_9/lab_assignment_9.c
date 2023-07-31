#include <stdio.h>
#include <stdlib.h>

struct RecordType
{
    int     id;
    char    name;
    int     order;
};

struct ListNode
{
    struct RecordType record;
    struct ListNode* next;
};

struct HashType
{
    struct ListNode* head;
};

int hash(int x, int size)
{
    return x % size;
}

void displayRecordsInHash(struct HashType* hashTable, int hashSz)
{
    int i;
    printf("\n********************************** Records in the Hash Structure *****************************************\n\n");
    for (i = 0; i < hashSz; ++i)
    {
        if (hashTable[i].head != NULL)
        {
            struct ListNode* curr = hashTable[i].head;
            printf("index: %d -> ", i);
            while (curr != NULL)
            {
                printf("ID: %d, Name: %c, Order: %d   ", curr->record.id, curr->record.name, curr->record.order);
                curr = curr->next;
            }
        }
            printf("\n\n");
    }
}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (struct RecordType*) malloc(sizeof(struct RecordType) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

void createHashTable(struct RecordType* pRecords, int recordSz, struct HashType** ppHashTable, int hashSz)
{
    *ppHashTable = (struct HashType*)calloc(hashSz, sizeof(struct HashType));

    if (*ppHashTable == NULL)
    {
        printf("Cannot allocate memory for the hash table.\n");
        exit(-1);
    }

    for (int i = 0; i < hashSz; ++i)
    {
        (*ppHashTable)[i].head = NULL;
    }

    for (int i = 0; i < recordSz; ++i)
    {
        int index = hash(pRecords[i].order, hashSz);
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (newNode)
        {
            newNode->record = pRecords[i];
            newNode->next = (*ppHashTable)[index].head;
            (*ppHashTable)[index].head = newNode;
        }
    }
}

int main(void)
{
    struct RecordType* pRecords;
    int recordSz = 0;
    struct HashType* hashTable;
    int hashSz = 15;

    recordSz = parseData("input.txt", &pRecords);
    printRecords(pRecords, recordSz);

    createHashTable(pRecords, recordSz, &hashTable, hashSz);

    displayRecordsInHash(hashTable, hashSz);

    for (int i = 0; i < hashSz; ++i)
    {
        struct ListNode* curr = hashTable[i].head;
        while (curr != NULL)
        {
            struct ListNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(pRecords);
    free(hashTable);

    return 0;
}



