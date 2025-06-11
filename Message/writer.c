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

    my_key = ftok("programfile", 85);                 // Generate unique key
    msg_id = msgget(my_key, 0666 | IPC_CREAT);        // Get or create message queue

    message.msg_type = 120;

    printf("Write Message: ");
    fgets(message.msg, sizeof(message.msg), stdin);   // Read input
    message.msg[strcspn(message.msg, "\n")] = '\0';   // Remove newline if any

    // Send message (size = only msg, not msg_type)
    msgsnd(msg_id, &message, sizeof(message.msg), 0); 

    printf("Sent message is: %s\n", message.msg);

    return 0;
}
