#include<stdio.h>
void main(){
    int n;
    float Average_turn_around_time = 0, Average_waiting_time = 0;
    
    printf("Enter the nummber of processes");
    scanf("%d",&n);
    
    int burst_time[n],waiting_time[n],Turn_around_time[n],arrival_time[n],process_ID[n];
    
    printf("Enter burst time and Arrival Time of each processes");
    for(int i=0;i<n;i++){
        process_ID[i]=i;
        printf("\nEnter The Burst Time of process id %d :",i);
        scanf("%d",&burst_time[i]);
        printf("\nEnter The arrival Time of process id %d :",i);
        scanf("%d",&arrival_time[i]);
    }

   for(int i=0;i<n-1;i++){
    int temp=i;
    for (int j=i+1;j<n;j++){
        if(arrival_time[temp]>arrival_time[j]){
            temp=j;
        }
    }
    if(temp!=i){
        int tempo;
        tempo=process_ID[i];
        process_ID[i]=process_ID[temp];
        process_ID[temp]=tempo;

        tempo=burst_time[i];
        burst_time[i]=burst_time[temp];
        burst_time[temp]=tempo;

        tempo=arrival_time[i];
        arrival_time[i]=arrival_time[temp];
        arrival_time[temp]=tempo;
    }
   }

    waiting_time[0] = 0;
    Turn_around_time[0] = burst_time[0];
    Average_turn_around_time += Turn_around_time[0];
    Average_waiting_time += waiting_time[0];

    int current_time = arrival_time[0] + burst_time[0];

    for (int i = 1; i < n; i++) {
        if (arrival_time[i] > current_time) {
            current_time = arrival_time[i]; // CPU was idle
        }
        waiting_time[i] = current_time - arrival_time[i];
        Turn_around_time[i] = waiting_time[i] + burst_time[i];

        current_time += burst_time[i];

        Average_turn_around_time += Turn_around_time[i];
        Average_waiting_time += waiting_time[i];
    }
    Average_turn_around_time /= n;
    Average_waiting_time /= n;

    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n"); 
    
    for(int i=0;i<n;i++){
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", process_ID[i], burst_time[i], waiting_time[i], Turn_around_time[i]);
    }
    
    printf("\nAverage Waiting Time -- %f", Average_waiting_time); 
    printf("\nAverage Turnaround Time -- %f", Average_turn_around_time);

}



