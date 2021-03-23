# Built upon the following repos
[click me](https://github.com/andrewlin1368/bfs-project-part-1)
[click me](https://github.com/andrewlin1368/bfs-project-part-2)
[click me](https://github.com/andrewlin1368/bfs-project-part-3)

# Quick Recap of Concepts (2)
This section is a quick recap of the concepts that you need to know for this project. If you
don’t understand something or can’t answer the questions and exercises, you should
review the textbook/material provided for this topic.

To find the single-source shortest paths in a graph, we use Breadth First Search (BFS).
Given a graph and a source vertex s, BFS builds a table (map) containing a parent-link
representation of a tree rooted at s, which defines the shortest paths from s to every
vertex that is connected to s. From that table, we can obtain the path from s to any vertex
that is connected to it. Example:

![image](https://i.ibb.co/sVjbbCP/Capture.png)

## BFS Algorithm

![image](https://i.ibb.co/RjP1Ydv/Capture.png)

## The Kevin Bacon Game
Querying the actors in a movie is not much more than returning the
corresponding line in the input file. Querying the list of movies in which an
actor has appeared is a bit more complex since it is an inverted index, but it
can be done without a graph. The graph model not only serves as an
inverted index, it also provides the basis for more sophisticated processing,
as we will see next.

At this point, we can get to work on the Kevin Bacon Game explained in the introduction of
this project. To implement the game, what we need to do is use the graph to query paths
between pairs of actors or between pairs of movies. In fact, we want to find the shortest
path (one with a minimal number of edges) between any pair of vertices.

###
Add a member function that will perform breadth-firstsearch on the graph to find shortest paths from a source vertex. The function should
receive the source vertex, v, as argument and return a map containing a parent-link
representation of a tree rooted at v, which defines the shortest paths from v to every
vertex that is connected to it.

###  
Write a client program that will build the graph from the input file provided in Part
3 of this project (movies.txt or movies_short.txt) and then, it will allow querying paths from
a source vertex (e.g. “Kevin Bacon”) to any other vertex (actor or movie).

The program should ask for the source vertex only once (at the beginning) and then it
should repeatedly ask for a target vertex until the user decides to exit the program.
A sample session is shown below. Notice that the input files provided have the names in a
different format, so you have to either enter the names as formatted on the file or convert
the user input to that format:

![image](https://i.ibb.co/ccV4vjq/Capture.png)

