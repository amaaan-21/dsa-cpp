#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Each node stores one key-value pair.
// Multiple nodes can share a bucket and form a linked list.
class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
    }

    ~Node() {
        // Deleting a node also deletes the chain following it.
        // delete nullptr is safe and does nothing.
        //
        // When removing just ONE node, disconnect its next pointer
        // before deleting it, or the remaining chain will also be deleted.
        delete next;
    }
};

class HashTable {
    int totSize;   // Number of buckets.
    int currSize;  // Number of key-value pairs currently stored.

    // Pointer to an array of Node pointers.
    // Each array entry points to the first node in its bucket.
    Node** table;

    int HashFunction(const string& key) const {
        // const string& avoids copying the string.
        // The final const means this function does not modify the table.
        int idx = 0;

        // unsigned char gives each character a nonnegative numeric value.
        for (unsigned char ch : key) {
            // Accumulate character contributions.
            // Modulo keeps idx between 0 and totSize - 1.
            idx = (idx + ch * ch) % totSize;
        }

        // Different keys can produce the same index.
        // These collisions are handled using linked lists.
        return idx;
    }

    void rehash() {
        // Keep access to the old bucket array.
        Node** oldTable = table;
        int oldSize = totSize;

        // Double the number of buckets.
        totSize *= 2;

        // () initializes every bucket pointer to nullptr.
        table = new Node*[totSize]();

        // Visit each linked list in the old array.
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];

            while (temp != nullptr) {
                // Save the old next pointer BEFORE changing it.
                // Otherwise, we would lose access to the rest of the list.
                Node* next = temp->next;

                // The bucket count changed, so calculate a new index.
                int idx = HashFunction(temp->key);

                // Move this existing node to the front of its new bucket.
                temp->next = table[idx];
                table[idx] = temp;

                // Continue through the OLD chain using the saved pointer.
                temp = next;
            }
        }

        // No entries were added or removed, so currSize stays unchanged.
        //
        // Delete only the old pointer array.
        // Do NOT delete its nodes: they now belong to the new table.
        delete[] oldTable;
    }

public:
    HashTable(int size) {
        // A zero size would cause division by zero in the hash function.
        // Negative sizes are also invalid.
        if (size <= 0) {
            throw invalid_argument("Table size must be positive.");
        }

        totSize = size;
        currSize = 0;

        // Allocate the bucket array and initialize pointers to nullptr.
        table = new Node*[totSize]();
    }

    ~HashTable() {
        // Delete each bucket's entire linked list.
        // Node's destructor recursively deletes the remaining nodes.
        for (int i = 0; i < totSize; i++) {
            delete table[i];
        }

        // Free the bucket array after freeing its nodes.
        delete[] table;
    }

    // Default copying would copy the pointer addresses rather than nodes.
    // Two tables would then own the same memory and delete it twice.
    // Disable copying until a proper deep-copy operation is implemented.
    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;

    void insert(const string& key, int val) {
        int idx = HashFunction(key);

        // Check whether this key already exists in its bucket.
        Node* temp = table[idx];

        while (temp != nullptr) {
            if (temp->key == key) {
                // Update the existing value instead of inserting a duplicate.
                // The number of stored entries does not change.
                temp->val = val;
                return;
            }

            temp = temp->next;
        }

        // The key is new, so allocate a node.
        Node* newNode = new Node(key, val);

        // Connect the new node to the current bucket head.
        newNode->next = table[idx];

        // Update the actual bucket to point to the new head.
        table[idx] = newNode;

        currSize++;

        // Load factor = number of entries / number of buckets.
        // Converting to double prevents integer division.
        double lambda = currSize / static_cast<double>(totSize);

        // When entries outnumber buckets, expand the table.
        // Rehashing can reduce average chain lengths.
        if (lambda > 1.0) {
            rehash();
        }
    }

    bool exists(const string& key) const {
        // Search only the bucket where this key would be stored.
        int idx = HashFunction(key);
        Node* temp = table[idx];

        while (temp != nullptr) {
            if (temp->key == key) {
                return true;
            }

            temp = temp->next;
        }

        // Reached the end of the chain without finding the key.
        return false;
    }

    int search(const string& key) const {
        int idx = HashFunction(key);
        Node* temp = table[idx];

        while (temp != nullptr) {
            if (temp->key == key) {
                return temp->val;
            }

            temp = temp->next;
        }

        // Missing-key marker.
        // If -1 is a stored value, call exists() to distinguish the cases.
        return -1;
    }

    void remove(const string& key) {
        int idx = HashFunction(key);

        Node* temp = table[idx]; // Node currently being examined.
        Node* prev = nullptr;   // Node immediately before temp.

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    // Removing the first node:
                    // make the bucket point to the second node.
                    table[idx] = temp->next;
                } else {
                    // Removing a middle or last node:
                    // make the previous node skip over temp.
                    prev->next = temp->next;
                }

                // Disconnect temp from the remaining chain.
                // This prevents its destructor from deleting other entries.
                temp->next = nullptr;

                delete temp;
                currSize--;

                // The key has been removed; stop searching.
                return;
            }

            // Advance both pointers while preserving their relationship.
            prev = temp;
            temp = temp->next;
        }

        // If the key does not exist, leave the table unchanged.
    }

    void print() const {
        // Display each bucket and all entries in its chain.
        for (int i = 0; i < totSize; i++) {
            cout << "idx " << i << " -> ";

            Node* temp = table[i];

            while (temp != nullptr) {
                cout << "(" << temp->key << ", "
                     << temp->val << ") -> ";

                temp = temp->next;
            }

            cout << "NULL\n";
        }
    }
};

int main() {
    // Start with five empty buckets.
    HashTable ht(5);

    // Insert four key-value pairs.
    ht.insert("India", 150);
    ht.insert("China", 80);
    ht.insert("US", 130);
    ht.insert("Kalu", 400);

    // Check that the key exists before retrieving its value.
    if (ht.exists("India")) {
        cout << "India population: " << ht.search("India") << '\n';
    }

    // Display the buckets and any collision chains.
    ht.print();

    // ht goes out of scope when main ends.
    // Its destructor automatically frees the allocated memory.
    return 0;
}
