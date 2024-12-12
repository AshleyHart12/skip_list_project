#ifndef Skiplist_H 
#define Skiplist_H

#include <iostream>  
#include <string>    
#include <vector>    
#include <random>    
#include <memory>    

// Class representing a node in the skip list
class SkiplistNode {
public:
    std::string song;  // The value stored in the node 
    std::vector<std::shared_ptr<SkiplistNode>> forward; // Pointers to nodes at various levels

    // Constructor to initialize a node with a song and a given level
    SkiplistNode(const std::string& song, int level);
};

// Class representing the skip list data structure
class Skiplist {
private:
    int maxLevel;             // Maximum levels the skip list can have
    float probability;        // Factor for determining node levels
    int currentLevel;         // Current highest level in the skip list
    std::shared_ptr<SkiplistNode> header; // Header node of the skip list

    // Function to generate a random level for a new node
    int randomLevel();

public:
    // Constructor to initialize a skip list with given max level and probability
    Skiplist(int maxLevel = 16, float probability = 0.5);

    // Function to insert a song into the skip list
    void insert(const std::string& song);

    // Function to search for a song in the skip list
    bool search(const std::string& song) const;

    // Function to remove a song in the skip list
    bool remove(const std::string& song);

    // Function to display the skip list contents 
    void display() const;
};

#endif 