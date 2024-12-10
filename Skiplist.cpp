#include "SkipList.h"

// Constructor for SkipListNode
SkipListNode::SkipListNode(const std::string& song, int level)
    : song(song), forward(level, nullptr) {}

// Constructor for SkipList
SkipList::SkipList(int maxLevel, float probability)
    : maxLevel(maxLevel), probability(probability), currentLevel(0) {
    header = std::make_shared<SkipListNode>("", maxLevel);
}

// Generate random level 
int SkipList::randomLevel() {
    static std::default_random_engine generator;
    static std::uniform_real_distribution<float> distribution(0.0, 1.0);

    int level = 1;
    while (distribution(generator) < probability && level < maxLevel) {
        level++;
    }
    return level;
}

// Insert a song into Skip List
void SkipList::insert(const std::string& song) {
    std::vector<std::shared_ptr<SkipListNode>> update(maxLevel, nullptr);
    auto current = header;

    for (int i = currentLevel; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->song < song) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (!current || current->song != song) {
        int newLevel = randomLevel();
        if (newLevel > currentLevel) {
            for (int i = currentLevel + 1; i < newLevel; ++i) {
                update[i] = header;
            }
            currentLevel = newLevel;
        }

        auto newNode = std::make_shared<SkipListNode>(song, newLevel);
        for (int i = 0; i < newLevel; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

// Search for a song in Skip List
bool SkipList::search(const std::string& song) const {
    auto current = header;
    for (int i = currentLevel; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->song < song) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    return current && current->song == song;
}

// Delete a song from Skip List
void SkipList::remove(const std::string& song) {
    std::vector<std::shared_ptr<SkipListNode>> update(maxLevel, nullptr);
    auto current = header;

    for (int i = currentLevel; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->song < song) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current && current->song == song) {
        for (int i = 0; i <= currentLevel; ++i) {
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }

        while (currentLevel > 0 && !header->forward[currentLevel]) {
            currentLevel--;
        }
    }
}

// Display the Skip List
void SkipList::display() const {
    for (int i = currentLevel; i >= 0; --i) {
        auto current = header->forward[i];
        std::cout << "Level " << i << ": ";
        while (current) {
            std::cout << current->song << " ";
            current = current->forward[i];
        }
        std::cout << "\n";
    }
}