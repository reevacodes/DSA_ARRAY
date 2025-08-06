// REVERSE GROUP WITH K NODES

#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *findKThNode(ListNode *head, int k)
{
  ListNode *temp = head;
  k -= 1;
  while (temp && k > 0)
  {
    k--;
    temp = temp->next;
  }
  return temp;
}

ListNode *reverse(ListNode *head)
{
  ListNode *prev = nullptr;
  ListNode *curr = head;
  while (curr)
  {
    ListNode *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }
  return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
  ListNode *temp = head;
  ListNode *prevLast = nullptr;

  while (temp)
  {
    ListNode *kThNode = findKThNode(temp, k);
    if (kThNode == nullptr)
    {
      if (prevLast)
        prevLast->next = temp;
      break;
    }

    ListNode *nextNode = kThNode->next;
    kThNode->next = nullptr;

    ListNode *newHead = reverse(temp);

    if (temp == head)
      head = newHead;
    else
      prevLast->next = newHead;

    prevLast = temp;
    temp = nextNode;
  }
  return head;
}

// Utility function to print the linked list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

// Utility function to create a linked list from an array
ListNode *createList(vector<int> vals)
{
  if (vals.empty())
    return nullptr;
  ListNode *head = new ListNode(vals[0]);
  ListNode *current = head;
  for (int i = 1; i < vals.size(); i++)
  {
    current->next = new ListNode(vals[i]);
    current = current->next;
  }
  return head;
}

// Example usage
int main()
{
  vector<int> vals = {1, 2, 3, 4, 5};
  int k = 3;
  ListNode *head = createList(vals);

  cout << "Original List: ";
  printList(head);

  head = reverseKGroup(head, k);

  cout << "After reversing in groups of " << k << ": ";
  printList(head);

  return 0;
}
