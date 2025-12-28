class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0, head);
      
        ListNode* prevGroupEnd = dummyHead;

        while (prevGroupEnd != nullptr) {
            ListNode* currentNode = prevGroupEnd;
            for (int i = 0; i < k; i++) {
                currentNode = currentNode->next;
                if (currentNode == nullptr) {
                    return dummyHead->next;
                }
            }

            ListNode* groupStart = prevGroupEnd->next; 
            ListNode* nextGroupStart = currentNode->next;  
          
            currentNode->next = nullptr;
          
            prevGroupEnd->next = reverseList(groupStart);
          
            groupStart->next = nextGroupStart;
          
            prevGroupEnd = groupStart;
        }
      
        return dummyHead->next;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyNode = new ListNode();
        ListNode* current = head;
      
        while (current != nullptr) {
            ListNode* nextNode = current->next; 
            current->next = dummyNode->next;   
            dummyNode->next = current;          
            current = nextNode;                  
        }
      
        return dummyNode->next;
    }
};
