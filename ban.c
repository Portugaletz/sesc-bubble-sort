#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node * next;
};


void pushb(struct Node ** head, int val){
  struct Node * tempnode;
  tempnode = *head;
  while (tempnode->next!=NULL){
    tempnode = tempnode->next; 
  }
  tempnode->next =(struct Node*)malloc(sizeof(struct Node));
  tempnode->next->value = val;
  tempnode->next->next = NULL;
}


int main(void) {
  struct Node * head = (struct Node*)malloc(sizeof(struct Node));
  int n, k;
  struct Node * temp;
  scanf("%d", &n);
  for (int i=0;i<n;i++){
    scanf("%d", &k);
    pushb(&head, k);
  }
  int sorted=0; 
  while (sorted == 0){
    sorted = 1;
    temp = head;
    //printf("%d\n", temp->next->next->value);
    while (temp->next->next!=NULL){
      if (temp->next->value < temp->next->next->value){
        k = temp->next->value;
        //printf("%d\n", k);
        temp->next->value = temp->next->next->value;
        temp->next->next->value = k;
        sorted = 0;
      } 
      temp=temp->next;
    }
  }
  temp = head;
  while (temp->next!=NULL){
    printf("%d ",temp->next->value);
    temp = temp->next;
  }
  return 0;
}
