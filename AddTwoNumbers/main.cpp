#include <iostream>
#include <new>
#include <initializer_list>

using namespace std;

struct ListNode;
void display(ListNode* node);
void append(ListNode** head_ref, int new_data);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct LinkedList
{
    ListNode *next;
    LinkedList() = default;
    LinkedList(const std::initializer_list<int> &list)
    {
        next = nullptr;
        for(auto& element: list)
        {
            append(&next, element);
        }
    }

    ~LinkedList()
    {
        ListNode* current = next;
        while(current != nullptr)
        {
            ListNode* nextNode = current->next;
            if(current != nullptr)
            {
                delete current;
            }
            current = nextNode;
        }

        next = nullptr;
    }
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result = nullptr;
        int carry = 0;
        while(l1 && l2)
        {
            int addition = l1->val + l2->val + carry;
            carry = addition / 10;
            addition %= 10;
            
            append(&result, addition);
            l1 = l1->next;
            l2 = l2->next;
        }
        
        
        addRest(&result, l1, carry);
        addRest(&result, l2, carry);
        
        if(carry != 0)
            append(&result, carry);


        return result;
    }
    
    void addRest(ListNode** result, const ListNode* list, int& carry)
    {
        while(list)
        {
            int newData = (list->val + carry);
            carry = newData / 10;
            newData %= 10;
            append(result, newData);
            list = list->next;
        }
    }
    
   
};

 void display(ListNode* node)
{
    while (node != NULL)  
    {  
        cout<<node->val;  
        node = node->next;
        
        if(node)
            cout << " -> ";
    } 
    
    cout << "\n";
}


void append(ListNode** head_ref, int new_data)
    {
        ListNode* newNode = new ListNode(new_data);
        ListNode* last = *head_ref;
        
        if (*head_ref == NULL) 
        { 
            *head_ref = newNode; 
            return; 
        }
        
        while (last->next != NULL) 
            last = last->next;
            
        last->next = newNode; 
        return;     
    }


int main()
{

    {
        cout << "======= TEST 1 =======\n";
        LinkedList l1{1};
        LinkedList l2{9};

        display(l1.next);
        display(l2.next);

        LinkedList res;
        Solution s;
        res.next = s.addTwoNumbers(l1.next, l2.next);
        display(res.next);
        cout << "======= END =========\n";
    }



    {
        cout << "======= TEST 2 =======\n";
        LinkedList l1{9,7,3};
        LinkedList l2{1,2,3};

        display(l1.next);
        display(l2.next);

        LinkedList res;
        Solution s;
        res.next = s.addTwoNumbers(l1.next, l2.next);
        display(res.next);
        cout << "======= END =========\n";
    }


    {
        cout << "======= TEST 3 =======\n";
        LinkedList l1{1,2,3, 6};
        LinkedList l2{1,2,3, 4};

        display(l1.next);
        display(l2.next);

        LinkedList res;
        Solution s;
        res.next = s.addTwoNumbers(l1.next, l2.next);
        display(res.next);
        cout << "======= END =========\n";
    }

    {
        cout << "\n======= TEST 4 =======\n";
        LinkedList l1{1};
        LinkedList l2{1,2,3, 4};

        display(l1.next);
        display(l2.next);

        LinkedList res;
        Solution s;
        res.next = s.addTwoNumbers(l1.next, l2.next);
        display(res.next);
        cout << "======= END =========\n";
    }

{
        cout << "\n======= TEST 5 =======\n";
        LinkedList l1{1};
        LinkedList l2{9,9};

        display(l1.next);
        display(l2.next);

        LinkedList res;
        Solution s;
        res.next = s.addTwoNumbers(l1.next, l2.next);
        display(res.next);
        cout << "======= END =========\n";
    }


    return 0;
}
