#include<stdio.h>
void main(){
    int n;
    float Average_turn_around_time,Average_waiting_time;
    
    printf("Enter the nummber of processes");
    scanf("%d",&n);
    
    int burst_time[n],waiting_time[n],Turn_around_time[n];
    
    printf("Enter burst time of each processes");
    for(int i=0;i<n;i++){
        scanf("%d",&burst_time[i]);
    }

    waiting_time[0]=0;
    Turn_around_time[0]=burst_time[0];
    Average_turn_around_time+=Turn_around_time[0];
    for(int i=1;i<n;i++){
        waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
        Turn_around_time[i]=waiting_time[i]+burst_time[i];
        Average_turn_around_time+=Turn_around_time[i];
        Average_waiting_time+=waiting_time[i];
    }
    Average_turn_around_time/=n;
    Average_waiting_time/=n;
    
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n"); 
    
    for(int i=0;i<n;i++){
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, burst_time[i], waiting_time[i], Turn_around_time[i]);
    }
    
    printf("\nAverage Waiting Time -- %f", Average_waiting_time); 
    printf("\nAverage Turnaround Time -- %f", Average_turn_around_time);

}



