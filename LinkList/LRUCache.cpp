#include <unordered_map>
#include <iostream>
using namespace std;

struct LinkNode
{
    int key;
    int value;
    LinkNode *prev;
    LinkNode *next;
};

void insertNode(LinkNode *&tail,LinkNode *node){
    tail->next = node;
    node->prev = tail;
    node->next = nullptr;
    tail = tail->next;
}

LinkNode* getNode(LinkNode *head, int key,unordered_map<int, LinkNode*> &cacheMap){
    auto it = cacheMap.find(key);
    if (it != cacheMap.end()) {
        return it->second;
    }
    return nullptr;
}
void updateNode(LinkNode *&tail,LinkNode *node){
    if(node == tail) return;
    node->prev->next = node->next;
    if(node->next){
        node->next->prev = node->prev;
    }
    insertNode(tail, node);
}
void removeNode(LinkNode *head,LinkNode *&tail,unordered_map<int, LinkNode*> &cacheMap){
    LinkNode *node = head->next;
    if(node == nullptr) return;
    cacheMap.erase(node->key);
    head->next = node->next;
    if(head->next){
        head->next->prev = head;
    }else{
        tail = head;
    }
    delete node;
}
class LRUCache{
private:
    int size=0;
    int capacity;
    LinkNode *head;
    LinkNode *tail;
    unordered_map<int, LinkNode*> cacheMap; // key to node mapping for O(1) access
public:
    LRUCache(int capacity){
        this->capacity = capacity;
        head = new LinkNode();
        head->prev = nullptr;
        head->next = nullptr;
        tail = head;

    }

    int get(int key){
        LinkNode *node = getNode(head, key, cacheMap);
        if(node){
            updateNode(tail, node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value){
        LinkNode *node = getNode(head, key, cacheMap);
        //如果Node存在，更新Node的值，并将Node移动到链表尾部
        if(node){
            node->value = value;
            updateNode(tail, node);
            return;
        }
        //如果Node不存在
        //如果缓存已满，删除链表头部的Node
        else if(size == capacity){
            removeNode(head, tail, cacheMap);
            size--;
        }
        //创建新的Node，并将其插入到链表尾部
        LinkNode *newNode = new LinkNode();
        newNode->key = key;
        newNode->value = value;
        insertNode(tail, newNode);
        cacheMap[key] = newNode;
        size++;
    }

};

int main(){
    LRUCache cache(2); // Cache capacity of 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // Returns 1
    cache.put(3, 3); // Evicts key 2
    cout << cache.get(2) << endl; // Returns -1 (not found)
    cache.put(4, 4); // Evicts key 3
    cout << cache.get(3) << endl; // Returns -1 (not found)
    cout << cache.get(4) << endl; // Returns 4

    return 0;
}