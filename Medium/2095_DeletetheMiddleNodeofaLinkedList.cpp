#include <iostream>
#include <vector>
using namespace std;

// LeetCode 內建的 ListNode 定義
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 輔助函式 1：將 vector 轉為 Linked List
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// 輔助函式 2：將 Linked List 印出以便觀察結果
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << (curr->next ? " -> " : "");
        curr = curr->next;
    }
    cout << endl;
}

// 輔助函式 3：釋放記憶體避免 Leak（選用）
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// 假設這是你的解題類別或函式
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // delete middle node
        slow->next = slow->next->next;
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

int main() {
    Solution sol;

    // 定義測試案例
    std::vector<int> input = { 1, 3, 4, 7, 1, 2, 6 };

    // 1. 建立串列
    ListNode* head = createList(input);

    std::cout << "Original: ";
    printList(head);

    // 2. 執行演算法
    head = sol.deleteMiddle(head);

    std::cout << "Result:   ";
    printList(head);

    // 3. 清理記憶體
    freeList(head);

    return 0;
}