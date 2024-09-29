class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        vector<int> v;
        struct Node* curr=head;
        while(curr != NULL) {
            v.push_back(curr->data);
            curr = curr->next;
        }
        int n=v.size();
        for(int i=0;i<n/2;i++) {
            v[n-1-i] = (v[n-1-i]-v[i]);
            swap(v[i],v[n-1-i]);
        }
        curr = head;
        int i=0;
        while(curr != NULL) {
            curr->data = v[i++];
            curr = curr->next;
        }
        return head;
    }
};