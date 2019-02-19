typedef struct{
	char name[11];
	float cgpa;
}student;

#define Element student
#define key cgpa
void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
void mergeSort(Element input[], int size);
void print(Element a);
