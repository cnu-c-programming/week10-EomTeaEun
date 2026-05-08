#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char name[50];
    int score;
    struct Node* next;
};

struct Node* create_node(const char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

int main(){
    struct Node* head = NULL;
    char command[20];

    while(1){ //quit 할 때 까지
        if (scanf("%s", command) == EOF) break;

        // add
        if (strcmp(command, "add") == 0) {
            char name[50];
            int score;
            scanf("%s %d", name, &score);
            struct Node* newNode = create_node(name, score);

            if (head == NULL){
                head = newNode; // 첫 노드
            } else {
                // 끝까지 감
                struct Node* curr = head;
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
            
        }

        //delete
        else if (strcmp(command, "delete") == 0) {
            char name[50];
            scanf("%s", name);

            struct Node* curr = head;
            struct Node* prev = NULL;

            while (curr != NULL) {
                if (strcmp(curr->name, name) == 0) {
                    if (prev == NULL) {
                        head = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    free(curr);
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        }

        //print
        else if (strcmp(command, "print") == 0) {
            struct Node* curr = head;
            while (curr != NULL) {
                printf("%s %d\n", curr->name, curr->score);
                curr = curr->next;
            }
        }

        //quit
        else if (strcmp(command, "quit") == 0) {
            struct Node* curr = head;
            
            while (curr != NULL) {
                struct Node* next = curr->next;
                free(curr);
                curr = next;
            }
            break;
        }
    }

    return 0;

}