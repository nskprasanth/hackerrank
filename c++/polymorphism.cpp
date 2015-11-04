/**
  * https://www.hackerrank.com/challenges/abstract-classes-polymorphism
  * Author: Prasanth Kalapatapu
  * Oct 14, 2015
  */
class LRUCache: public Cache {

public:
    LRUCache (int cap) {
        cp = cap;
        tail = head = NULL;
    }
    
    // 5 3 2 1 4 
    // set 1 -> 1 5 3 2 4
    // set 6 -> 6 1 5 3 2
    virtual void set(int k, int v) {
        if (mp.find(k) == mp.end()) { // cache miss
            Node* node = new Node(k, v);
            mp[k] = node;
            
            if (mp.size() > 1) {
                insert_head(node);
            } else {
                head = tail = node;
            }
            
            if(mp.size()>cp) {
                remove_tail();
            }
        } else { // cache hit
            Node* node = mp[k];
            node->value = v;
            cache_hit(node);
        }
        //print();
    }
    
    virtual int get (int k) {
        if (mp.find(k) == mp.end()) {
            return -1;
        }
        Node* node = mp[k];
        cache_hit(node);
        //print();
        return node->value;
    }
    
private:
    void print() {
        Node* t = head;
        while (t) {
            cout << t->key << " " << t->value << endl;
            t=t->next;
        }
        cout << "reverse order:" << endl;
        t = tail;
        while(t) {
            cout << t->key << " " << t->value << endl;
            t=t->prev;
        }
        cout << endl;
    }
    void insert_head(Node* node) {
        if(mp.size() == 1) {
            return;
        }
        //cout << "insert head: begin" << endl;
        Node* old_head = head;
        head = node;
        old_head->prev = head;
        head->next = old_head;
        head->prev = NULL;
        //cout << "insert head: end" << endl;
    }
    
    void remove_tail() {
        if (mp.size() == 1) {
            return;
        }
        //cout << "remove tail: begin" << endl;
        mp.erase(mp.find(tail->key));
        
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
        
        //cout << "remove tail: end" << endl;
    }
    
    void cache_hit(Node* node) {
        //cout << "cache hit: begin" << endl;
        if (head==node) {
            return;
        }
        Node* p = node->prev;
        Node* n = node->next;
        if (p) { p->next = n; }
        if (n) { n->prev = p; }
        insert_head(node);
        //cout << "cache hit: end" << endl;
    }
    
};
