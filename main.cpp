#include "SkipList.h"
#include <iostream>
#include <vector>

int main() {
    SkipList skipList;

    // Insert "Songs I Hate"
    skipList.insert("Song A");
    skipList.insert("Song C");
    skipList.insert("Song E");

    std::cout << "Skip List (Songs I Hate):\n";
    skipList.display();

    // "Top Hits" playlist
    std::vector<std::string> topHits = {"Song A", "Song B", "Song C", "Song D", "Song E"};
    std::cout << "\nPlaying Top Hits:\n";
    for (const auto& song : topHits) {
        if (skipList.search(song)) {
            std::cout << "Skipping " << song << "\n";
        } else {
            std::cout << "Playing " << song << "\n";
        }
    }

    return 0;
}