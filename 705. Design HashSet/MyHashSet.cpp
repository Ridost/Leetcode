#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
class MyHashSet{
    public:
    MyHashSet(){
        headnode = nullptr;
    }
    void add(int key){
        if(headnode==nullptr){
            headnode = new node;
            headnode->data = key;
            headnode->left = nullptr;
            headnode->right = nullptr;
            return;
        }
        node* currentNode = headnode;
        while(true){
            if(key>currentNode->data){
                if(currentNode->right==nullptr){
                    currentNode->right = new node;
                    currentNode->right->data = key;
                    currentNode->right->left = nullptr;
                    currentNode->right->right = nullptr;
                    return;
                }
                currentNode = currentNode->right;
            }
            else if(key<currentNode->data){
                if(currentNode->left==nullptr){
                    currentNode->left = new node;
                    currentNode->left->data = key;
                    currentNode->left->left = nullptr;
                    currentNode->left->right = nullptr;
                    return;
                }
                currentNode = currentNode->left;
            }
            else{return;}
        }
    }
    void remove(int key){   //移除後要取右邊最小或是左邊最大的node進行補位 
        if(headnode==nullptr){return;}
        node* currentNode = headnode;
        while(currentNode->left!=nullptr || currentNode->right!=nullptr){
            if(key>currentNode->data){
                if(currentNode->right==nullptr){return;}
                else if(currentNode->right->data==key){
                    node* minNode = currentNode->right;
                    if (minNode->left==nullptr){
                        currentNode->right = currentNode->right->right;
                        delete minNode;
                        return;
                    }
                    while(minNode->left!=nullptr){
                        if(minNode->left->left==nullptr) {
                            currentNode->right = minNode->left;
                            minNode->left = nullptr;
                        }
                        else minNode = minNode->left;
                    }

                    return;
                }
                currentNode = currentNode->right;
            }
            else if(key<currentNode->data){
                if(currentNode->left==nullptr){return;}
                else if(currentNode->left->data==key){
                    node* maxNode = currentNode->left;
                    if(maxNode->right==nullptr){
                        currentNode->left = currentNode->left->left;
                        delete maxNode;
                        return;
                    }
                    while(maxNode->right!=nullptr){
                        if(maxNode->right->right==nullptr){
                            currentNode->left = maxNode->right;
                            maxNode->right = nullptr;
                        }
                        else maxNode = maxNode->right;
                    }
                    return;
                }
                currentNode = currentNode->left;
            }
            else{
                if (currentNode->left!=nullptr) {
                    node* maxNode = currentNode->left;
                    if(maxNode->right==nullptr){
                        currentNode->left = currentNode->left->left;
                        delete maxNode;
                        return;
                    }
                    while(maxNode->right!=nullptr){
                        if(maxNode->right->right==nullptr){
                            currentNode->left = maxNode->right;
                            maxNode->right = nullptr;
                        }
                        else maxNode = maxNode->right;
                    }
                }
                else if (currentNode->right!=nullptr) {
                    node* minNode = currentNode->right;
                    if (minNode->left==nullptr){
                        currentNode->right = currentNode->right->right;
                        delete minNode;
                        return;
                    }
                    while(minNode->left!=nullptr){
                        if(minNode->left->left==nullptr) {
                            currentNode->right = minNode->left;
                            minNode->left = nullptr;
                        }
                        else minNode = minNode->left;
                    }
                }
                return;
            }
        }
        if (currentNode->data==key) currentNode = nullptr;
    }
    bool contains(int key){
        if(headnode==nullptr){return false;}
        node *currentNode = headnode;
        while(currentNode->left!=nullptr || currentNode->right!=nullptr){
            if(currentNode->data==key){
                return true;
            }
            else if(key>currentNode->data){
                if(currentNode->right==nullptr){return false;}
                currentNode = currentNode->right;
            }
            else{
                if(currentNode->left==nullptr){return false;}
                currentNode = currentNode->left;
            }
        }
        if(currentNode->data==key) return true;
        else return false;
    }

    private:
    node* headnode;
};

int main(){
    MyHashSet * obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    cout<<"test "<<obj->contains(1);
    cout<<"test "<<obj->contains(3);
    obj->add(2);
    cout<<"test "<<obj->contains(2);
    obj->remove(2);
    cout<<"test "<<obj->contains(2);
    
    return 0;
}