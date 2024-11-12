#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// A Huffman Tree node
struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char character, int frequency) {
        this->character = character;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap based on frequency)
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Traverse the Huffman Tree and store the Huffman Codes in a map
void encode(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->character] = code;
    }

    encode(root->left, code + "0", huffmanCode);
    encode(root->right, code + "1", huffmanCode);
}

// Build Huffman Tree and generate codes
void buildHuffmanTree(const string& text) {
    // Count frequency of each character
    unordered_map<char, int> frequency;
    for (char ch : text) {
        frequency[ch]++;
    }

    // Create a priority queue to store nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate until there is more than one node in the queue
    while (pq.size() != 1) {
        // Remove the two nodes with the highest priority (lowest frequency)
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with the combined frequency
        int sum = left->frequency + right->frequency;
        Node* node = new Node('\0', sum);
        node->left = left;
        node->right = right;

        // Add the new node to the priority queue
        pq.push(node);
    }

    // Root node stores pointer to the Huffman Tree
    Node* root = pq.top();

    // Traverse the Huffman Tree and store the codes in a map
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    // Display the Huffman codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    // Display encoded string
    cout << "\nEncoded message:\n";
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }
    cout << encodedString << "\n";
}

// Main function
int main() {
    string text = "mississippi";
    buildHuffmanTree(text);
    return 0;
}
