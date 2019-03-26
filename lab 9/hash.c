#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int hash(char* input, int baseNumber, int tableSize)
{
	int len = strlen(input);
	int hash = 0;
	for ( int i=0; i<len; i++)
	{
		hash += (int)input[i];
	}
	hash = ((hash % baseNumber) % tableSize);
	//printf("The hash for \"%s\" is :%d\n", input, hash);
	return hash;
}

int collisionCount(char** string, int n, int baseNumber, int tableSize)
{
	int collisions[tableSize], total =0;
	for(int i=0; i< tableSize; i++)
	{
		collisions[i] = -1;
	}
	for( int i=0; i<n; i++)
	{
		collisions[hash(string[i], baseNumber, tableSize)]++;
	}
	for(int i=0; i< tableSize; i++)
	{
		if(collisions[i] != -1)
		{
		total += collisions[i];
		}
	} 
	return total;
}

char** parse(char* input, int* bookSize)
{
	FILE* infile = fopen(input, "r");
	char** book;
	book = (char**)malloc(sizeof(char*) * 100);
	int size =100;
	int i=0, f=0;
	//book[i] = (char*)malloc(sizeof(char)*50);
	while(!feof(infile))
	{
		book[i] = (char*)malloc(sizeof(char)*50);
		fscanf(infile, "%s", book[i]);
		//printf("%s %d.\n", book[i], i);
		f=0;
		for(int j=0; j< strlen(book[i]); j++)
		{
			if (!((book[i][j]>='a' && book[i][j]<='z') ||(book[i][j]>='A' && book[i][j] <= 'Z')))
			{
				f=1;
				//printf("f=1 at %d %d %c %s\n", i, j, book[i][0], book[i]);
				break;
			}
			
		}
		if (f==0)
		{
			i++;
		}
		if ( i== size-1){
			size *= 2;
			book = (char**)realloc(book, sizeof(char*) * size);
		}
	}
	*bookSize = i;
	printf("bookSIze is: %d\n", *bookSize);
	return book;
}

int main(int argc, char* argv[])
{
	//hash(argv[1], (int)argv[2][0] - (int)'0', (int)argv[3][0]- (int)'0');
	int* bookSize = (int*)malloc(sizeof(int));
	char** book = parse("aliceinwonderland.txt", bookSize);
	FILE* outFile = fopen("parsed.txt", "w");
	/*for(int i=0; i<*bookSize; i++){
		fprintf(outFile, "%s ", book[i]);
	}*/
	int collisions = collisionCount(book, *bookSize, 9661, 5000);
	printf("collisions with 9661 5000: %d\n", collisions);
}
