#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Graph
{
public:
    int vertex_num;
    int edges_num;
    int** adj_matrix;
    Graph(string filePath)
    {
        readGraph(filePath);
        printGraph();
    }
    void readGraph(string filePath) {
        ifstream inFile(filePath);
        int v1, v2, edge;

        inFile >> vertex_num >> edges_num;

        adj_matrix = new int* [vertex_num];
        for (int i = 0; i < vertex_num; i++) {
            adj_matrix[i] = new int[vertex_num];
            for (int j = 0; j < vertex_num; j++) adj_matrix[i][j] = 0;
        }

        for(int e = 0; e < edges_num; e++)
        {
            inFile >> v1 >> v2 >> edge;
            adj_matrix[v1][v2] = adj_matrix[v2][v1] = edge;
        }
        inFile.close();
    }
    void printGraph() {
        cout << " ¦ ";
        for (int i = 0; i < vertex_num; i++) cout << i << "\t ";
        cout << endl;
        for (int i = 0; i < 8 * vertex_num + 2; i++) cout << "-";
        cout << endl;
        for (int i = 0; i < vertex_num; i++) {
            cout << i << "¦ ";
            for (int j = 0; j < vertex_num; j++) cout << adj_matrix[i][j] << "\t ";
            cout << endl;
        }
        cout << endl;
    }
};

void DFS(Graph graph, int Node) 
{
    bool* Visited = new bool[graph.vertex_num];
    for (int i = 0; i < graph.vertex_num; i++) Visited[i] = false;
    int* List = new int[graph.vertex_num];
    int Head;
    for (int i = 0; i < graph.vertex_num; i++) List[i] = 0;
    Head = 0;
    List[Head] = Node;
    Visited[Node] = true;
    while (Head >= 0) {
        Node = List[Head]; 
        Head--;
        cout << Node << endl;
        for (int i = 0; i < graph.vertex_num; i++) {
            if (graph.adj_matrix[Node][i] && !Visited[i]) {
                Head++; 
                List[Head] = i;
                Visited[i] = true;
            }
        }
    }
}

int DFS_faraway(Graph graph, int Node) 
{
    bool* Visited = new bool[graph.vertex_num];
    for (int i = 0; i < graph.vertex_num; i++) Visited[i] = false;
    int* List = new int[graph.vertex_num];
    int Head;
    for (int i = 0; i < graph.vertex_num; i++) List[i] = 0;
    Head = 0;
    List[Head] = Node;
    Visited[Node] = true;
    while (Head >= 0) {
        Node = List[Head];
        Head--;
        cout << Node << endl;
        for (int i = 0; i < graph.vertex_num; i++) {
            if (graph.adj_matrix[Node][i] && !Visited[i]) {
                Head++;
                List[Head] = i;
                Visited[i] = true;
            }
        }
    }
    return Head;
}

void BFS(Graph graph, int Node) 
{
    bool* Visited = new bool[graph.vertex_num];
    for (int i = 0; i < graph.vertex_num; i++) Visited[i] = false;
    int* List = new int[graph.vertex_num];
    int Count, Head;
    for (int i = 0; i < graph.vertex_num; i++) List[i] = 0;
    Count = Head = 0;
    List[Count++] = Node;
    Visited[Node] = true;
    while (Head < Count) {
        Node = List[Head++];
        cout << Node << endl;
        for (int i = 0; i < graph.vertex_num; i++) {
            if (graph.adj_matrix[Node][i] && !Visited[i]) {
                List[Count++] = i;
                Visited[i] = true;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string path;
    cout << "Введите путь к файлу с графом: ";
    cin >> path;
    Graph graph = Graph(path);

    cout << "Обход графа в глубину" << endl;
    DFS(graph, 0);

    cout << endl << "Обход графа в глубину" << endl;
    BFS(graph, 0);
}