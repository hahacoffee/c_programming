#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;
Node *createList(int);
void freeList(Node* head);
int solveJosephus(Node **head, int step);

Node *createList(int n){
    Node* now = NULL;
    for(int i=1;i<=n;i++){
        Node* np = (Node*)malloc(sizeof(Node));
        np->next = np;
        np->number = i;
        if(now != NULL){
            np->next = now->next;
            now->next = np;
        }
        now = np;
    }
    now = now->next;
    return now;
}

int solveJosephus(Node **head, int step){
    int cnt = 0;
    Node *now = *head;
    while(now->next != *head){
        now = now->next;
        cnt++;
    }
    cnt++;
    now = now->next;
    int new_step = 0;
    for(int i=cnt;i>1;i--){
        new_step = (step % i);
        if(new_step == 0)
            new_step += i;
        new_step--;
        while(1){
            if(new_step == 0 && now->number != -1)
                break;
            if(now->number != -1)
                new_step--;
            now = now->next;
        }
        now->number = -1;
    }
    while(1){
        if(now->number != -1)
            return now->number;
        now = now->next;
    }
}
void freeList(Node* head){
    Node* now = head;
    int cnt = 0;
    while(1){
        now = now->next;
        cnt++;
        if(now->next == head)
            break;
    }

    while(cnt--){
        Node* tmp = now->next;
        free(now);
        now = tmp;
    }
}
#endif