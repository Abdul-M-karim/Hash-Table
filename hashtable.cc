
#include <iostream>
#include <string>
using namespace std;

const int HASHTABLESIZE = 100;

struct node {
    string key;
    node* next;


};

int hashCode(string str) {
    int value = 0;
    for ( int i = 0; i < str.length(); i++)
    {
        value += str[i];
    }
    return value;
}

class LinkedList {
private:
    node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(string key) {
        if (head == NULL) {
            head = new node();
            head->key = key;
            head->next = NULL;
        } else {
            node* temp = new node();
            temp->key = key;
            temp->next = head;
            head = temp;
        }
    }

    void print() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    bool find(string str) {
        node* temp = head;
        while(head != NULL) {
            if (temp->key == str) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

class HashTable {
public:
    
    void insert (string str ){
        int index = hashCode(str) % HASHTABLESIZE;
        list[index].insert(str);
    }
    bool get (string str){
         int index = hashCode(str) % HASHTABLESIZE;
         return list[index].find(str);
    }

    void print() {
        for (int i=0; i<HASHTABLESIZE; i++) {
            list[i].print();
        }
    }
private:
    LinkedList list[HASHTABLESIZE];
};

int main() {

    HashTable Hash;

    Hash.insert("Coders");
    Hash.insert("Rule");
    Hash.insert("the");
    Hash.insert("world");
    Hash.insert("and");
    Hash.insert("the");
    Hash.insert("Web");
    Hash.insert("Abdul");
    Hash.insert("Nick");
    Hash.insert("Faz");
   

    cout << Hash.get("Faz");
    cout << Hash.get("Abdul");
    cout << Hash.get("Coders");
    cout << Hash.get("Nick");

    Hash.print();
}