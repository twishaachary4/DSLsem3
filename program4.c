
//4.	Develop a program in C for simulating a Printer Queue using Queue data structure with the following operations:
//a.	Add a print job to the Printer Queue.
//b.	Process a print job from the Printer Queue (delete).
//c.	Display the number of print jobs currently waiting in the Queue.
//d.	Demonstrate Queue overflow and underflow conditions.
//e.	Exit.

#include <stdio.h>
#define MAX 5

typedef struct {
    int jobId;
    char fileName[50];
} PrintJob;

PrintJob q[MAX];
int front = -1, rear = -1;

// a. Add a print job
void insert() {
    PrintJob item;

    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Printer queue is full.\n");
        return;
    }

    printf("\nEnter Job ID   : ");
    scanf("%d", &item.jobId);
    printf("Enter File Name: ");
    scanf("%s", item.fileName);

    if (front == -1)
        front = 0;

    rear = rear + 1;
    q[rear] = item;

    printf("Print job '%s' (ID: %d) added to queue.\n", item.fileName, item.jobId);
}

// b. Process a print job (delete)
void delete() {
    PrintJob item;

    if (front > rear) {
        printf("\nQueue Underflow! No print jobs to process.\n");
        return;
    }

    item = q[front];
    printf("\nProcessing print job -> ID: %d, File: %s\n", item.jobId, item.fileName);
    front++;

    if (front > rear) {
        front = 0;
        rear = -1;
    }
}

// c. Display waiting jobs
void display() {
    int i;

    if (front > rear) {
        printf("\nQueue is empty. No print jobs waiting.\n");
        return;
    }

    printf("\nThe elements of queue are:\n");
    for (i = front; i <= rear; i++)
        printf("Job ID: %d\tFile: %s\n", q[i].jobId, q[i].fileName);

    printf("Number of print jobs waiting: %d\n", rear - front + 1);
}

void main() {
    int choice;

    while (1) {
        printf("\n===== PRINTER QUEUE MENU =====\n");
        printf("1. Add a print job\n");
        printf("2. Process a print job\n");
        printf("3. Display waiting jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); 
                    break;
            case 2: delete();  
                    break;
            case 3: display(); 
                    break;
            case 4: return;
            default: printf("\nInvalid choice! Try again.\n");
        }
    }
}
