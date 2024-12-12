#include "Skiplist.h"
#include <iostream>
#include <vector>

int main() {
    Skiplist Skiplist;

    // Insert "Songs I Hate"
    Skiplist.insert("Song A");
    Skiplist.insert("Song C");
    Skiplist.insert("Song E");

    std::cout << "Skip List (Songs I Hate):\n";
    Skiplist.display();

    std::cout << "-----------------------\n";
    
    Skiplist.remove("Song C");
    std::cout << "After removing Song C:\n"; 
    Skiplist.display();

    // "Top Hits" playlist
    std::vector<std::string> topHits = {"Song A", "Song B", "Song C", "Song D", "Song E"};
    std::cout << "\nPlaying Top Hits:\n";
    for (const auto& song : topHits) {
        if (Skiplist.search(song)) {
            std::cout << "Skipping " << song << "\n";
        } else {
            std::cout << "Playing " << song << "\n";
        }
    }

    return 0;
}