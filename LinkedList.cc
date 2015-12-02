#include <iostream>

using namespace std;

struct node{
	struct node* next;
	int data;
};

class LinkedList{
	public:
		int length = 0;
		struct node* headH;

		int setLength(struct node* head){
			struct node *temp = head;
			int l = 0;
			while(temp != NULL){
				temp = temp->next;
				l++;
			}
			this->length = l;
			return l;
		}

		void reverseList(struct node** head){
			//Send head one step down each time
			struct node* t1, t2, t3;
			t1 = NULL;
			t2 = *head;
			while(t2 != NULL){
				t3 = t2->next;
				t2->next = t1;
				t1 = t2;
				t2 = t3;
			}
			head = t1;
		}

		void reverseList2(struct node** head){
			if(head == NULL || head->next == NULL){return;}
			struct node* t1, t2;
			t1 = *head;
			t2 = head->next;
			reverseList2(t2);
			t1->next->next = t1;
			t1->next = NULL;
			head = t2;
		}

		void push(struct node** head, int data){
			struct node* h = *head, tmp;
			while(h->next != NULL){
				h = h->next;
			}
			tmp = tmp->data;
			tmp->next = h->next->next;
			h->next = tmp;
			this->length++;
		}

		void pushAt(struct node** head, int data, int pos){
			struct node* h = *head, tmp;
			while(h->next != NULL && pos > 0){
				h = h->next;
				pos--;
			}
			tmp = tmp->data;
			tmp->next = h->next->next;
			h->next = tmp;
			this->length++;
		}

		int deleteAt(struct node** head, int pos){
			struct node* h = *head;
			while(h->next != NULL && pos > 0){
				h = h->next;
				pos--;
			}
			if(h->next == NULL){return -1;}
			int data = h->next->data;
			h->next = h->next->next;
			this->length--;
			return data;
		}

		int delete(struct node** head, int data){
			struct node* h = *head;
			while(h->next != NULL && h->next->data != data){
				h = h->next;
			}
			if(h->next == NULL){return -1;}
			//delete h->next;
			h->next = h->next->next;
			this->length--;
			return 1;
		}

		struct node* operator[](int n){
			struct node* temp = this->headH;
			while(temp != NULL){n--;}
			if(n < 0){return NULL;}
			return temp;
		}
}
