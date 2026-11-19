struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        // count n
        int n = 1;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            n++;
            cur = cur->next;
        }
        // case n = 2
        if (n == 2) {
            int ans = head->val;
            ans += head->next->val;
            return ans;
        }
        // reverse first half
        ListNode* pre = head;
        cur = head->next;
        ListNode* next = cur;
        for (int i = 1; i < n / 2; i++) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = nullptr;
        // add two List
        ListNode* first_head = pre;
        ListNode* second_head = cur;
        int ans = 0;
        while (pre != nullptr && cur != nullptr) {
            ans = max(ans, pre->val + cur->val);
            pre = pre->next;
            cur = cur->next;
        }
        return ans;
    }
};