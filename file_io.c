#include <stdio.h>
#include "file_io.h"

int read_processes(const char * filename, Process processes[],int max_processes)
{
    FILE*file=fopen(filename,"r");
    if (!file) 
    {
        printf("Error:could not open file %s\n", filename );
        return 0;
    }

    int count =0 ;
    while (count< max_processes &&
      fscanf(file,"%d %d %d %d",
        &processes[count].pid,
        &processes[count].arrival_time,
        &processes[count].burst_time,
        &processes[count].burst_time,
        &processes[count].priority) ==4)
        {

     if(processes[count].burst_time==0)
     continue;

     processes[count].remaining_time=processes[count].burst_time;
     count++;
        }
       fclose(file);
       return count;
    }

