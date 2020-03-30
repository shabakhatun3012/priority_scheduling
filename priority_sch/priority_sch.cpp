#include<stdio.h>
int n;
struct process
{
    int process_no;
    int arrival_t,burst_t,completion_time,waiting_t,taround_time,p;
    int flag;

}process_list[100];

void Sorting()
{
   struct process p;
   int i, j;
   for(i=0;i<n-1;i++)
   {
       for(j=i+1;j<n;j++)
       {
           if(process_list[i].arrival_t > process_list[j].arrival_t)//swap the process
           {
                p = process_list[i];
                process_list[i] = process_list[j];
                process_list[j] = p;
           }
       }
   }
}
void end_display()
{
	 int i,t=0,b_t=0,peak;
    int a[10];
    float waiting_time = 0, taround_time = 0, avg_w_t=0, avg_taround_time=0;
 for( i=0;i<n;i++)
    {
        process_list[i].taround_time=(process_list[i].completion_time)-(process_list[i].arrival_t);
        avg_taround_time=avg_taround_time+process_list[i].taround_time;
        process_list[i].waiting_t=((process_list[i].taround_time)-a[i]);
        avg_w_t=avg_w_t+process_list[i].waiting_t;
    }
    printf("PNO\tAT\tCT\tTA\tWTt\n");
    
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",process_list[i].process_no,process_list[i].arrival_t,process_list[i].completion_time,process_list[i].taround_time,process_list[i].waiting_t);
    }
    
    printf("Average Turn around Time: %f\t\n\n",avg_taround_time);
    printf("Average Waiting Time :\t %f\t\n",avg_w_t);	
	
}

int main()
{
    int i,t=0,b_t=0,peak;
    int a[10];
    float waiting_time = 0, taround_time = 0, avg_w_t=0, avg_taround_time=0;
    printf("enter the no. of processes: ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        process_list[i].process_no = i+1;
        printf("\nEnter Details For P%d process:-\n", process_list[i].process_no);
        printf("Enter Arrival Time: ");
        scanf("%d", &process_list[i].arrival_t );
        printf("Enter Burst Time: ");
        scanf("%d", &process_list[i].burst_t);
        process_list[i].flag = 0;
        b_t = b_t + process_list[i].burst_t;//totaling of burst time
    }
    
    Sorting();

    for(int i=0;i<n;i++)
    {
        a[i]=process_list[i].burst_t;
    }
    process_list[9].burst_t = 9999;
    
    for(t = process_list[0].arrival_t; t <= b_t+1;)
    {
        peak = 9;
        for(i=0;i<n;i++)
        {
            if(process_list[i].arrival_t <= t && process_list[i].burst_t < process_list[peak].burst_t && process_list[i].flag != 1)
            {
                peak = i;
            }
            if(process_list[peak].burst_t==0 && process_list[i].flag != 1)
            {
                process_list[i].flag = 1;
                process_list[peak].completion_time=t;process_list[peak].burst_t=9999;
                printf("P%d completes in %d\n",process_list[i].process_no,process_list[peak].completion_time);
            }
        }
        t++; 
        (process_list[peak].burst_t)--;
        
    }
    end_display();
    /*\t%d\t%d\t%d\n",process_list[i].process_no,process_list[i].arrival_t,process_list[i].ct,process_list[i].taround_time,process_list[i].waiting_t);
    }
    
    printf("Average Turn around Time: %f\t\n\n",avg_taround_time);
    printf("Average Waiting Time :\t %f\t\n",avg_w_t);*/
}
