    #include <stdio.h>
    #include <stdlib.h>
    #define size 3

    int mutex = 1, full = 0, empty = 3, x = 0, buffer[size];

    void producer();
    void consumer();
    int wait(int);
    int signal(int);

    int main() {
        int n;
        printf("\n1.Producer\n2.Consumer\n3.Exit\n");
        while(1){
            printf("Enter your choice: ");
            scanf("%d", &n);
            switch(n){
                case 1:
                    if(mutex == 1 && empty != 0){
                        producer();
                    } else {
                        printf("Buffer is full!\n");
                    }
                    break;

                case 2:
                    if(mutex == 1 && full != 0){
                        consumer();
                    } else {
                        printf("Buffer is empty!\n");
                    }
                    break;

                case 3:
                    exit(0);

                default:
                    printf("Invalid choice. Try again.\n");
            }
        }
        return 0;
    }

    int wait(int s) {
        return (--s);
    }

    int signal(int s) {
        return (++s);
    }

    void producer() {
        mutex = wait(mutex);
        empty = wait(empty);

        buffer[x % size] = x;
        printf("Produced item %d at buffer[%d]\n", x, x % size);
        x++;

        full = signal(full);
        mutex = signal(mutex);
    }

    void consumer() {
        mutex = wait(mutex);
        full = wait(full);

        x--;
        printf("Consumed item %d from buffer[%d]\n", buffer[x % size], x % size);
        buffer[x % size] = -1;

        empty = signal(empty);
        mutex = signal(mutex);
    }
