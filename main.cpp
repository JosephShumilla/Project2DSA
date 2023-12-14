#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
class AdjacencyList{
    //Adjacency list class
private:
    std::map<std::string, std::vector<std::pair<std::string, int>>> graph; //A map used to take in all nodes that are input
    int pages = 0;
    std::map<std::string, int> outDegreeMap;
    std::map<std::string, int> inDegreeMap;
    std::map<std::string, double> pageRanks;// Map that stores the PageRank of each node
    std::set <std::string> totalPages;

public:
    void addEdge(const std::string& from, const std::string& to, int weight = 1){  //Function used to add edges to the graph map
        graph[from].push_back(std::make_pair(to, weight));
        if(graph.find(to) == graph.end()){
            graph[to];
        }
        totalPages.insert(from);
        totalPages.insert(to);
        outDegreeMap[from]++;// Increment the out-degree of 'from' node
        inDegreeMap[to]++;

    }

    void pageRank(int p);
};

void AdjacencyList::pageRank(int power_iterations){  //Function that ranks the pages
    // Step 1: Initialize PageRank values
    double initRank = 1.0 / totalPages.size();
    for(auto& iter : graph){
        pageRanks[iter.first] = initRank;
    }

    // Temporary map to store updated values
    std::map<std::string, double> tempRanks;

    // Step 2: Iterate to update PageRank
    for(int i = 0; i < power_iterations-1; i++){
        for(auto& iter : graph){
            tempRanks[iter.first] = 0;
        }

        for(auto& iter : graph){
            auto& from = iter.first;
            auto& edges = iter.second;
            for(auto& edge : edges){
                auto& to = edge.first;
                tempRanks[to] += pageRanks[from] / outDegreeMap[from];
            }
        }
        // Update the PageRanks with new values
        pageRanks = tempRanks;
    }
    // Step 3: Prints the PageRanks in alphabetical order
    std::vector<std::pair<std::string, double>> sortedRanks(pageRanks.begin(), pageRanks.end());
    std::sort(sortedRanks.begin(), sortedRanks.end());

    for(auto& pair : sortedRanks){
        std::cout << pair.first << " " << std::fixed << std::setprecision(2) << pair.second << std::endl;
    }
}

int main() {
    int no_of_lines, power_iterations;
    std::string from, to;
    std::cin >> no_of_lines >> power_iterations; //Taking in the input
    AdjacencyList graph;

    for(int i = 0; i < no_of_lines; i++) {
        std::cin >> from >> to;
        graph.addEdge(from, to);
    }
    graph.pageRank(power_iterations);
}
