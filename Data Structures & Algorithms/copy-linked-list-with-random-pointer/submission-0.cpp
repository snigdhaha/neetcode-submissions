/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //create insert newNodes in between
        Node *temp=head;
        while(temp!=NULL){
            Node *copyNode = new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;

            //traversal
            temp=temp->next->next;
        }

        //connect the random ptrs
        temp=head;
        while(temp!=NULL){
            Node *copyNode = temp->next;
            if(temp->random!=NULL){
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random=nullptr;
            }
        

            temp=temp->next->next;
        }

        //connect next ptrs
        Node *dummyNode = new Node(-1);
        Node *res=dummyNode;
        temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }

        return dummyNode->next; //new head
    }
};
