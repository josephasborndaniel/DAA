#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;

    // Move  n+1 steps 
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move fast to the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return dummy->next;
}


int main() {
   
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    int n = 2; // Remove the 2nd node from the end

    struct ListNode* result = removeNthFromEnd(head, n);

    // Print 
    struct ListNode* current = result;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
