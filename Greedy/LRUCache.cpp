#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class LRUCache {
  public:
        class Node{
          public:
          int key,val;
          Node* next;
          Node* prev;

          Node(int _key,int _val){
            key=_key;
            val=_val;
            next = nullptr;
            prev = nullptr;
          }
        };

        int cap;
        unordered_map<int,Node*> mp;

        Node* head=new Node(-1,-1);
        Node* tail=new Node(-1,-1);

  LRUCache(int capacity) {
    cap=capacity;
    head->next=tail;
    tail->prev=head;
  }
  void insertAfterHead(Node* node){
    Node* currentHeadNext=head->next;
    head->next=node;
    node->prev=head;
    node->next=currentHeadNext;
    currentHeadNext->prev=node;
  }
  void deleteNode(Node* node){
    Node* nodePrev=node->prev;
    Node* nodeNext=node->next;
    nodePrev->next=nodeNext;
    nodeNext->prev=nodePrev;
  }

  int get(int key_) {
    if(mp.find(key_)!=mp.end()){
      Node* node=mp[key_];
      int res=node->val;
      mp.erase(key_);
      deleteNode(node);
      insertAfterHead(node);
      mp[key_]=head->next;
      return res;
    }
    return -1;
  }

  void put(int key_, int value) {
    if(mp.find(key_)!=mp.end()){
      Node* node=mp[key_];
      mp.erase(key_);
      deleteNode(node);
      delete node;
    }
    if(mp.size()==cap){
      mp.erase(tail->prev->key);
      deleteNode(tail->prev);
    }
    insertAfterHead(new Node(key_,value));
    mp[key_]=head->next;
  }
};
int main() {
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;    // returns 1
    cache.put(3, 3);                 // evicts key 2
    cout << cache.get(2) << endl;    // returns -1 (not found)
    cache.put(4, 4);                 // evicts key 1
    cout << cache.get(1) << endl;    // returns -1 (not found)
    cout << cache.get(3) << endl;    // returns 3
    cout << cache.get(4) << endl;    // returns 4
    
    return 0;
}