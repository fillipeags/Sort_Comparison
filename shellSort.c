#include<stdio.h>

#include "staticList.c"
#include "getValues.c"


#include <sys/times.h> 
#include <sys/types.h> 
#include <unistd.h> 

int shellSort(list *ls);

int main(int agrc, char *argv[])
{
    
    clock_t tt;
	struct tms time;
    int tics_per_second; 

    tics_per_second = sysconf(_SC_CLK_TCK);
    
    list ls;
    ls.count = 0;

    ls.size = SIZE;
    runList(&ls);

    const char *fileName = argv[1];
    startList(&ls,fileName); 

    shellSort(&ls);

    printf("Numero de trocas = %d\n",ls.count);
    tt = times(&time);
    printf("\nRUN TIME: %f segundos\n", ( (double)time.tms_utime) / tics_per_second );

    return 0;
}


int shellSort(list *ls)
{
    if(ls->array!=NULL)
    {
        int i, j, k, valueAux, gap;
        
        for (gap = ls->size/2; gap > 0; gap /=2)
        {
            for (i = gap; i < ls->size; i++)
            {   
                int temp = ls->array[i]; 
  
                // shift earlier gap-sorted elements up until the correct  
                // location for a[i] is found 
                int j;             
                for (j = i; j >= gap && ls->array[j - gap] > temp; j -= gap) 
                    ls->array[j] = ls->array[j - gap]; 
                    ls->count++;
                //  put temp (the original a[i]) in its correct location 
                ls->array[j] = temp;
                                
            }
        }
    }
    return 0;
}
