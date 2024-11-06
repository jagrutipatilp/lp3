#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int val;
    Node *l;
    Node *r;
    Node(int val,char ch) : val(val),ch(ch), l(nullptr), r(nullptr) {}
};

class MinHeap {
    vector<Node*> heap;

    void heapifyup(int index) {
        while (index > 0) {
            int parentIdx = (index - 1) / 2;
            if (heap[index]->val < heap[parentIdx]->val) {
                swap(heap[index], heap[parentIdx]);
                index = parentIdx;
            } else {
                break;
            }
        }
    }

    void heapifydown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallestIdx = index;

        if (leftChild < heap.size() && heap[leftChild]->val < heap[smallestIdx]->val) {
            smallestIdx = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild]->val < heap[smallestIdx]->val) {
            smallestIdx = rightChild;
        }

        if (smallestIdx != index) {
            swap(heap[index], heap[smallestIdx]);
            heapifydown(smallestIdx);
        }
    }

public:
    MinHeap() {}

    void insert(Node* node) {
        heap.push_back(node);
        heapifyup(heap.size() - 1);
    }

    Node* getMin() {
        if (heap.empty()) {
            cout << "Heap is Empty" << endl;
            return nullptr; 
        }
        return heap[0];
    }

    void removeMin() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return; 
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifydown(0);
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

void printCodes(unordered_map<char,string>&huffmanCodes){
    cout<<"Huffman Codes: "<<endl;
    for(const auto &pair:huffmanCodes){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }
}

void generateCodes(Node* root,string str,unordered_map<char,string>&huffmanCodes){
    if(root==nullptr){
        return;
    }
    if(root->l==NULL && root->r==NULL){
        huffmanCodes[root->ch]=str;
    }
    generateCodes(root->l,str+"0",huffmanCodes);
    generateCodes(root->r,str+"1",huffmanCodes);
}

string encode(string str,unordered_map<char,string> &huffmanCodes){
    string encoded="";
    for(int i=0;i<str.size();i++){
        encoded+=huffmanCodes[str[i]];
    }
    return encoded;
}

void decode(string encoded,Node* root){
    string decoded="";
    Node*temp=root;
    for(int i=0;i<encoded.size();i++){
        
        if(encoded[i]=='0'){
            temp=temp->l;
        }else if(encoded[i]=='1'){
            temp=temp->r;
        }
        if(temp->l==NULL && temp->r==NULL){
            decoded+=temp->ch;
            temp=root;
        }
    }

    cout<<decoded<<endl;
}

Node* huffman(string str,char data[],int val[], int size) {
    MinHeap minHeap;

    // Insert all values as leaf nodes
    for (int i = 0; i < size; i++) {
        minHeap.insert(new Node(val[i],data[i]));
    }

    Node* root = nullptr;  // Track the root of the Huffman tree

    // Build Huffman Tree
    while (minHeap.size() > 1) {
        Node *left = minHeap.getMin();
        minHeap.removeMin();
        
        Node *right = minHeap.getMin();
        minHeap.removeMin();
        
        Node *temp = new Node(left->val + right->val,'\0');
        temp->l = left;
        temp->r = right;

        minHeap.insert(temp);
        
        // Set root to the last combined node
        root = temp;
    }
    return root;
    // unordered_map<char,string> huffmanCodes;
    // generateCodes(root,"",huffmanCodes);
    // printCodes(huffmanCodes);
    // string encoded = encode(str,huffmanCodes);
    // cout<<encoded<<endl;
    // decode(encoded,root);
}

Node* inputFunc(string str){
    unordered_map<char,int> input;
    
    int i=0;
    for(int i=0;i<str.size();i++){
        input[str[i]]+=1;
    }
    int size = input.size();
    char data[size];
    int val[size];
    for(const auto &pair:input){
        val[i] = pair.second;
        data[i] = pair.first;
        i++;
    }

    Node* root = huffman(str,data,val,size);
    return root;
}

int main() {
    string str = "This is huffman coding program";
    Node* root = inputFunc(str);
    // char data[] = {'A','B','C','D','E'};
    // int frequency[] = {5, 3, 8, 1, 6};

    // huffman(data,frequency, 5);
    // cout << endl;

    unordered_map<char,string> huffmanCodes;
    generateCodes(root,"",huffmanCodes);
    printCodes(huffmanCodes);
    string encoded = encode(str,huffmanCodes);
    cout<<encoded<<endl;
    decode(encoded,root);

    return 0;
}
