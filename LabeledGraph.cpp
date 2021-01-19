#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "LabeledGraph.h"
#include <fstream>
#include <queue>

using namespace std;

LabeledGraph::LabeledGraph(string filename)
{
    ifstream myfile(filename);
    string temp;
    while (getline(myfile, temp))
    {
        string temp2 = temp.substr(0, temp.find(')') + 1);
        string temp3 = temp.substr(temp.find(')') + 2, temp.length() + 1);
        vector<string> container;
        string temp4;
        for (int i = 0; i < temp3.length(); i++)
        {
            if (temp3[i] != '/')
                temp4 += temp3[i];
            else
            {
                container.push_back(temp4);
                temp4.clear();
            }
        }
        container.push_back(temp4);
        add_vertex(temp2);
        for (auto x : container)
        {
            add_vertex(x);
            add_edge(temp2, x);
        }
    }
    myfile.close();
}

void LabeledGraph::add_vertex(string vlabel)
{
    auto itr = indexedLabels.find(vlabel);
    if (itr != indexedLabels.end())
        return;
    labels.push_back(vlabel);
    indexedLabels.insert(pair<string, int>(vlabel, V()));
    set<int> s;
    vertices.push_back(s);
}

void LabeledGraph::add_edge(string source, string target)
{
    if (!contains(source))
        add_vertex(source);
    if (!contains(target))
        add_vertex(target);
    vertices[indexedLabels[source]].insert(indexedLabels[target]);
    vertices[indexedLabels[target]].insert(indexedLabels[source]);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const
{
    return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const
{
    return vertices[v];
}

string LabeledGraph::label(int v) const
{
    return labels[v];
}

int LabeledGraph::index(string vlabel)
{
    return indexedLabels[vlabel];
}

ostream &operator<<(ostream &out, const LabeledGraph &g)
{
    for (int i = 0; i < g.vertices.size(); i++)
    {
        auto itr = g.indexedLabels.find(g.labels.at(i));
        cout << itr->first << "--> " << itr->second << "--> ";
        for (auto itr = g.vertices.at(i).begin(); itr != g.vertices.at(i).end(); itr++)
        {
            cout << g.labels.at(*itr) << " ";
        }
        cout << "\n";
    }
    return out;
}

void LabeledGraph::display(std::string name)
{
    auto itr = indexedLabels.find(name);
    if (itr == indexedLabels.end())
    {
        cout << "Does not exist\n";
        return;
    }
    for (auto it = vertices.at(itr->second).begin(); it != vertices.at(itr->second).end(); it++)
    {
        cout << labels.at(*it) << "    ";
    }
}

std::map<int, int> LabeledGraph::breath_first_search(int v)
{
    vector<int> temp;
    vector<bool> visited;
    temp.resize(labels.size());
    visited.resize(labels.size());
    for (int i = 0; i < labels.size(); i++)
    {
        visited.at(i) = false;
        temp.at(i) = -1;
    }
    queue<int> check;
    check.push(v);
    visited[v] = true;
    temp.at(v) = -1;
    while (!check.empty())
    {
        int counter = check.front();
        for (auto itr = vertices.at(counter).begin(); itr != vertices.at(counter).end(); itr++)
        {
            if (visited.at(*itr) == false)
            {
                visited.at(*itr) = true;
                check.push(*itr);
                temp.at(*itr) = counter;
            }
        }
        check.pop();
    }
    map<int, int> graph;
    for (int i = 0; i < temp.size(); i++)
    {
        graph.insert(make_pair(i, temp.at(i)));
    }
    graph.insert(make_pair(-1, v));
    return graph;
}

vector<int> LabeledGraph::pathTo(map<int, int> &parent_map, int target)
{
    auto itr = parent_map.begin();
    int v = itr->second;
    vector<int> temp;
    vector<bool> visited;
    vector<int> path;
    for (int i = 0; i < labels.size(); i++)
    {
        visited.push_back(false);
        temp.push_back(-1);
    }
    queue<int> check;
    check.push(v);
    visited[v] = true;
    while (!check.empty())
    {
        int counter = check.front();
        check.pop();
        for (auto itr = vertices.at(counter).begin(); itr != vertices.at(counter).end(); itr++)
        {
            if (visited.at(*itr) == false)
            {
                visited.at(*itr) = true;
                check.push(*itr);
                temp.at(*itr) = counter;
            }
            if (*itr == target)
            {
                path.push_back(*itr);
                int x = *itr;
                while (x != -1)
                {
                    if (temp.at(x) == -1)
                        break;
                    path.push_back(temp.at(x));
                    x = temp.at(x);
                }
                vector<int> pathto;
                for (int i = path.size() - 1; i >= 0; i--)
                    pathto.push_back(path.at(i));
                return pathto;
            }
        }
    }
    return vector<int>();
}

std::vector<std::string> LabeledGraph::getlabels()
{
    return labels;
}