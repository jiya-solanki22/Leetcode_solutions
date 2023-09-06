/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* current = head;
        while (current) 
        {
            length++;
            current = current->next;
        }
        int partSize = length / k;
        int remaining = length % k;
        current = head;
        vector<ListNode*> parts;
        for (int i = 0; i < k; i++) {
            ListNode* partHead = current;
            int partLength = partSize + (i < remaining ? 1 : 0);
            for (int j = 0; j < partLength - 1; j++) 
            {
                if (current) 
                {
                    current = current->next;
                }
            }
            if (current) 
            {
                ListNode* nextNode = current->next;
                current->next = nullptr;
                current = nextNode;
            }
            parts.push_back(partHead);
        }
        return parts;
    }
};