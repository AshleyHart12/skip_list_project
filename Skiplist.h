#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <memory>

class SkipListNode {
public:
    std::string song;
    std::vector<std::shared_ptr<SkipListNode>> forward;

    SkipListNode(const std::string& song, int level);
};

class SkipList {
private:
    int maxLevel;
    float probability;
    int currentLevel;
    std::shared_ptr<SkipListNode> header;

    int randomLevel();

public:
    SkipList(int maxLevel = 16, float probability = 0.5);
    void insert(const std::string& song);
    bool search(const std::string& song) const;
    void display() const;
};

#endif 