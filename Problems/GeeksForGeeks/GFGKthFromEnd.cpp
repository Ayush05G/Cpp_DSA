class Solution{  
public:
  int getKthFromLast(struct Node* head, int k)
  {
      // Your code here
      if (head == NULL)
          return -1;
      int count = 0;
      Node* temp = head;
      while (temp != NULL) {
          count++;
          temp = temp->next;
      }
      if (k > count)
          return -1;
      temp = head;
      while (temp != NULL && count != k) {
          temp = temp->next;
          count--;
      }
      return (temp->data);
  }
};