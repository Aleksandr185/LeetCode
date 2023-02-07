
#include <stdint.h>
#include <cassert>
#include <memory>

/*

  2. Add Two Numbers
    You are given two non-empty linked lists representing two non-negative integers. The digits are
    stored in reverse order, and each of their nodes contains a single digit. Add the two numbers
    and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.


  Example 1:
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
                  2 -> 4 -> 3 = 342
                  5 -> 6 -> 4 = 465
                  7 -> 0 -> 8 = 807

  Example 2:
    Input: l1 = [0], l2 = [0]
    Output: [0]

  Example 3:
    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]


  Constraints:
    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
*/


// * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() { delete next; }

  ListNode* addNext(int x)
  {
    next = new ListNode(x);
    return next;
  }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

      bool overflow_flag = false;
      ListNode* result = nullptr;

      ListNode* current_node = nullptr;
      while (l1 || l2 || overflow_flag) {
        const int value_l1 = l1 ? l1->val : 0;
        const int value_l2 = l2 ? l2->val : 0;
        int sum = overflow_flag ? 1 : 0;
        sum += value_l1 + value_l2;
        overflow_flag = sum >= 10;

        if (overflow_flag) {
          sum -= 10;
        }

        if ( result )  {
          current_node->next = new ListNode(sum);
          current_node = current_node->next;
        }
        else {
          result = new ListNode(sum);
          current_node = result;
        }


        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
      }

      return result;
    }
};

int main(/*int argc, char** argv*/)
{
  Solution s;
  {
     std::unique_ptr<ListNode> l1 = std::make_unique<ListNode>(2);
     l1->addNext(4)->addNext(3);
     std::unique_ptr<ListNode> l2 = std::make_unique<ListNode>(5);
     l2->addNext(6)->addNext(4);

     std::unique_ptr<ListNode> l3( s.addTwoNumbers(l1.get(), l2.get()) );
     assert( l3->val == 7 );
     assert( l3->next->val == 0 );
     assert( l3->next->next->val == 8 );
  }

  {
     std::unique_ptr<ListNode> l1 = std::make_unique<ListNode>(0);
     std::unique_ptr<ListNode> l2 = std::make_unique<ListNode>(0);

     std::unique_ptr<ListNode> l3( s.addTwoNumbers(l1.get(), l2.get()) );
     assert( l3->val == 0 );
  }

  {
     std::unique_ptr<ListNode> l1 = std::make_unique<ListNode>(9);
     l1->addNext(9)->addNext(9)->addNext(9)->addNext(9)->addNext(9)->addNext(9);
     std::unique_ptr<ListNode> l2 = std::make_unique<ListNode>(9);
     l2->addNext(9)->addNext(9)->addNext(9);

     std::unique_ptr<ListNode> l3( s.addTwoNumbers(l1.get(), l2.get()) );
     assert( l3->val == 8 );
     assert( l3->next->val == 9 );
     assert( l3->next->next->val == 9 );
     assert( l3->next->next->next->val == 9 );
     assert( l3->next->next->next->next->val == 0 );
     assert( l3->next->next->next->next->next->val == 0 );
     assert( l3->next->next->next->next->next->next->val == 0 );
     assert( l3->next->next->next->next->next->next->next->val == 1 );
  }

  return 0;
}

