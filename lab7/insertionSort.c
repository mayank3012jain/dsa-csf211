#include"util.h"
#include"insertionSort.h"

Element* insertionSort(Element* array, Index low,Index high){
    for( int i = low + 1; i <= high; i++)
    {
        Element temp = array[i];
        int f =0,j;
        for(j = i-1; j >= low; j--)
        {
            if(compEmp(array[j],temp) == 1){
                array[j+1] = array[j];
            }else{
                array[j+1] = temp;
                f=1;
                break;
            }
        }
        if (f==0){
            array[j+1]= temp;
        }
        
    }
    return array;
    
}
