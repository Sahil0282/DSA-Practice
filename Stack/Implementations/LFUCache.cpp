#include<iostream>
#include<map>
#include<list>
using namespace std;

struct Node{
    int key,val,cnt;
    Node* next;
    Node* prev;
    Node(int _key,int _val){
        key=_key;
        val=_val;
        cnt=1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addNode(Node* node){
        Node* temp=head->next;
        head->next=node;
        node->next=temp;
        temp->prev=node;
        node->prev=head;
        size++;
    }
    void removeNode(Node* node){
        Node* nextNode=node->next;
        Node* prevNode=node->prev;
        nextNode->prev=prevNode;
        prevNode->next=nextNode;
        size--;
    }
};
class LFUCache {
public:
    map<int,Node*> keyNode;
    map<int,List*> freqListMap;
    int maxSizeCache;
    int currSize;
    int minFreq;
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        currSize=0;
        minFreq=0;
    }
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }

        List* nextHigherList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherList=freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherList->addNode(node);

        freqListMap[node->cnt]=nextHigherList;
        keyNode[node->key]=node;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            int retVal=node->val;
            updateFreqListMap(node);
            return retVal;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0) return ;

        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->val=value;
            updateFreqListMap(node);
        }else {
            if(currSize==maxSizeCache){
                List* list=freqListMap[minFreq];
                Node* toDelete = list->tail->prev;
                keyNode.erase(toDelete->key);
                freqListMap[minFreq]->removeNode(toDelete);
                delete toDelete;
                currSize--;
            }
            currSize++;
            minFreq=1;

            List* listFreq=new List();

            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq=freqListMap[minFreq];
            }

            Node* node=new Node(key,value);
            listFreq->addNode(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
};
int main(){
    LFUCache* cache = new LFUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl; // returns 1
    cache->put(3, 3); // evicts key 2
    cout << cache->get(2) << endl; // returns -1 (not found)
    cache->put(4, 4); // evicts key 3
    cout << cache->get(3) << endl; // returns -1 (not found)
    cout << cache->get(4) << endl; // returns 4
    return 0;
}
