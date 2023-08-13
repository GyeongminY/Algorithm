#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* next;
	struct node* prev;
}node;

int main() {
	node* head = (node*)malloc(sizeof(node));
	head->data = '!';
	head->prev = head->next = NULL;
	node* cur = head;
	char t;
	while ((t = getchar()) != '\n') {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->data = t;
		newnode->next = NULL;
		newnode->prev = cur;
		cur->next = newnode;
		cur = newnode;
	}
	//printf("head->data: %c head->prev: %p head->next: %p\n", head->data, head->prev, head->next);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char cmd;
		scanf(" %c", &cmd);
		//printf("cmd = %c\n", cmd);
		switch (cmd) {
			case 'L': {
				if (cur->prev) cur = cur->prev; 
				//printf("cur->data = %c\n", cur->data);
				break;
			}
			case 'D': {
				if (cur->next) cur = cur->next;
				break;
			}
			case 'B': { //cur이 가리키는 노드 삭제
				if (cur->prev == NULL) { 
					//printf("cur->prev == NULL\n");
					continue; }
				 //cur->prev가 true라면 head가 아니다.
				//printf("cur->data: %c cur->prev: %p cur->next: %p\n", cur->data, cur->prev, cur->next);
				node* del = cur;
				cur = cur->prev;
				cur->next = del->next;
				if (del->next)
					del->next->prev = cur;
				free(del);
				//printf("cur->data = %c\n", cur->data);
				break;
			}
			case 'P': { //cur 오른쪽에 문자 추가
				char c;
				scanf(" %c", &c);
				//printf("c = %c\n", c);
				node* newnode = (node*)malloc(sizeof(node));
				newnode->data = c;
				//newnode->next = cur->next;
				newnode->prev = cur;
				newnode->next = NULL;
				//printf("cur->data: %c cur->prev: %p cur->next: %p\n", cur->data, cur->prev, cur->next);
				if (cur->next) { //예외  발생
					cur->next->prev = newnode;
					newnode->next = cur->next;
				}
				cur->next = newnode;
				cur = newnode;
			}
		}
	}
	cur = head->next;
	while (cur) {
		printf("%c", cur->data);
		cur = cur->next;
	}
	while (cur) {
		node* temp = cur;
		cur = temp->prev;
		free(temp);
	}
}