#include"util.h"

Element* quickSortIterative(Element* ls, int lo, int hi, int min);
Index pivot(Element* array, Index lo, Index high);
Index partition(Element* array, Index lo, Index hi, Index pivot);
Element* mixSort(Element* ls, int lo, int hi, int min);