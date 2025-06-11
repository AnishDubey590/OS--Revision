#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg[100];
} message;

int main() {
    key_t my_key;
    int msg_id;

    my_key = ftok("programfile", 85);                 // Same key as writer
    msg_id = msgget(my_key, 0666 | IPC_CREAT);        // Access message queue

    // Receive message of type 120
    msgrcv(msg_id, &message, sizeof(message.msg), 120, 0);  

    printf("Received Message is: %s\n", message.msg);

    // Delete the message queue
    msgctl(msg_id, IPC_RMID, NULL);       

    return 0;
}
