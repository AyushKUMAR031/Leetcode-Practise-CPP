class LRUCache {
public:

    class Node { //basically creating DLL where we store key and value, and 
    // try to push LRU (least recently used ) key and value to the tail of dll.
        public:
            int key, val;
            Node* next;
            Node* prev;

            Node(int k, int v){
                key = k;
                val = v;
                next = prev = NULL;
            }
    };

    //add these end points so that any NULL error doesn't occur.
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1, -1);

    int limit;

    unordered_map<int,Node*> mp; //using map for tracking mru and lru and limit.
    //since we are storing the node directly in map, we don't have to traverse to go to the node
    //as we have the pointer of that node.

    void addNode(Node* tempNode){ // O(1)
        Node* oldNext = head->next;
        head->next = tempNode;
        tempNode->prev = head;
        tempNode->next = oldNext;
        oldNext->prev = tempNode;
    }

    void deleteNode(Node* oldNode){ // O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity; // A/Q initializing the limit.

        head->next = tail; 
        tail->prev = head;
        //connecting the head and tail, and will insert the nodes as per the
        //limit in b/w these end point nodes.
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        
        Node* useNode = mp[key];

        mp.erase(key);
        deleteNode(useNode);

        addNode(useNode);
        mp[key] = useNode;

        return useNode->val;
    }
    
    void put(int key, int value) {  // O(1)
        if(mp.find(key) != mp.end()){ //check for older value of key if exist
            Node* oldNode = mp[key];
            deleteNode(oldNode);
            mp.erase(key);
        }
        //checking the limit
        if(mp.size() == limit){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev); //here we are deleting the lru data
        }

        Node *tempNode = new Node(key,value);
        addNode(tempNode);
        mp[key] = tempNode; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
