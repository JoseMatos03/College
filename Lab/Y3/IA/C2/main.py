from Graph import Graph
from Node import Node


def main():
    g = Graph()

    #add nodes and connections
    g.add_edge(Node("A"), Node("B"), 1)
    g.add_edge(Node("A"), Node("C"), 2)
    g.add_edge(Node("A"), Node("D"), 3)
    g.add_edge(Node("B"), Node("D"), 1)
    g.add_edge(Node("B"), Node("E"), 2)
    g.add_edge(Node("C"), Node("F"), 1)
    g.add_edge(Node("C"), Node("G"), 2)
    g.add_edge(Node("D"), Node("H"), 2)
    g.add_edge(Node("D"), Node("I"), 1)
    g.add_edge(Node("E"), Node("J"), 1)

    saida = -1
    while saida != 0:
        print("1-Print graph on console")
        print("2-Draw graph")
        print("3-Print graph nodes")
        print("4-Print graph edges")
        print("5-DFS search")
        print("6-BFS search")
        print("0-Exit")

        saida = int(input("Choose an option --> "))
        if saida == 0:
            print("Exiting...")
        elif saida == 1:
            print(g.m_graph)
            input("--- Press Enter to continue ---")
        elif saida == 2:
            g.draw()
        elif saida == 3:
            print(g.m_graph.keys())
            input("--- Press Enter to continue ---")
        elif saida == 4:
            print(g.print_edge())
            input("--- Press Enter to continue ---")
        elif saida == 5:
            inicio = input("Nodo inicial->")
            fim = input("Nodo final->")
            print(g.dfs_search(Node(inicio), Node(fim), path=[], visited=set()))
            input("--- Press Enter to continue ---")
        elif saida == 6:
            inicio = input("Nodo inicial->")
            fim = input("Nodo final->")
            print(g.bfs_search(Node(inicio), Node(fim)))
            input("--- Press Enter to continue ---")
        else:
            print("ERR: No input")
            input("--- Press Enter to continue ---")


if __name__ == "__main__":
    main()
