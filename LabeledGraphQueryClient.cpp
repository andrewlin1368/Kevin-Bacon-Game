#include "LabeledGraph.h"
#include <iostream>
using namespace std;

int main()
{
    LabeledGraph g("movies_short.txt");
    string source;
    string destination;
    cout << "Enter source vector: ";
    getline(cin, source);
    cout << "All (shortest) paths from " << source << " to other vertices have been created.\n";
    int src, dest;
    for (int i = 0; i < g.getlabels().size(); i++)
    {
        if (g.getlabels().at(i) == source)
        {
            src = i;
            break;
        }
    }
    while (true)
    {
        cout << "\nEnter a target vertex and I will display the shortest path from " << source << " to that vertex (-1 to exit):  ";
        getline(cin, destination);
        if (destination == "-1")
            break;
        for (int i = 0; i < g.getlabels().size(); i++)
        {
            if (g.getlabels().at(i) == destination)
            {
                dest = i;
                break;
            }
        }
        vector<string> solution;
        map<int, int> movies = g.breath_first_search(src);
        vector<int> pathoutput = g.pathTo(movies, dest);
        for (auto x : pathoutput)
        {
            solution.push_back(g.getlabels().at(x));
            solution.push_back(" ---> ");
        }
        solution.pop_back();
        cout << "Shortest Path from " << source << " to " << destination << ": \n";
        for (auto x : solution)
            cout << x;
    }
    return 0;
}