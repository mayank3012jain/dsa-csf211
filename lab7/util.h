#ifndef _UTIL
    #define _UTIL
    typedef struct{
    	char name[10];
    	int empID;
    }employee;

    #define Index int
    //typedef int Index;
    #define Element employee

    int compEmp(Element a, Element b);
    void print(Element a);
#endif