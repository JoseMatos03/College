import math
from queue import Queue

import networkx as nx
import matplotlib.pyplot as plt

from Node import Node


class Graph:
    def __init__(self, directed: bool = False) -> None:
        self.m_nodes = []
        self.m_directed = directed
        self.m_graph = {}

    def __str__(self) -> str:
        out = ""
        for key in self.m_graph.keys():
            out += str(key) + " -> " + str(self.m_graph[key]) + "\n"
        return out

    def get_node_by_name(self, name: str) -> Node:
        for node in self.m_nodes:
            if node.getName() == name:
                return node
        return None

    def print_edge(self) -> None:
        for key in self.m_graph.keys():
            for edge in self.m_graph[key]:
                print(key, " -> ", edge)

    def add_edge(self, node1: Node, node2: Node, weight: int = 1) -> None:
        if node1 not in self.m_graph:
            self.m_graph[node1] = []
        self.m_graph[node1].append((node2, weight))
        if not self.m_directed:
            if node2 not in self.m_graph:
                self.m_graph[node2] = []
            self.m_graph[node2].append((node1, weight)) # undirected graph

    def getNodes(self) -> list:
        return self.m_nodes

    def get_edge_cost(self, node1: Node, node2: Node) -> int:
        for edge in self.m_graph[node1]:
            if edge[0] == node2:
                return edge[1]
        return math.inf

    def calculate_cost(self, path: list) -> int:
        cost = 0
        for i in range(len(path) - 1):
            cost += self.get_edge_cost(path[i], path[i + 1])
        return cost

    def dfs_search(self, start: Node, end: Node, path: list, visited: set) -> list:
        if start == end:
            return path + [start]
        if start in visited:
            return None
        visited.add(start)
        
        for node in self.m_graph[start]:
            if node[0] not in visited:
                new_path = self.dfs_search(node[0], end, path + [start], visited)
                if new_path:
                    return new_path
        return None

    def bfs_search(self, start: Node, end: Node) -> list:
        q = Queue()
        q.put([start])
        while not q.empty():
            path = q.get()
            node = path[-1]
            if node == end:
                return path
            for neighbor in self.m_graph[node]:
                new_path = list(path)
                new_path.append(neighbor[0])
                q.put(new_path)
        return None

    def get_neighbors(self, node: Node) -> list:
        return self.m_graph[node]

    def draw(self) -> None:
        G = nx.Graph()
        for node in self.m_nodes:
            G.add_node(node.getName())
        for key in self.m_graph.keys():
            for edge in self.m_graph[key]:
                G.add_edge(key.getName(), edge[0].getName(), weight=edge[1])

        pos = nx.spring_layout(G)
        labels = nx.get_edge_attributes(G, 'weight')
        nx.draw(G, pos, with_labels=True)
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
        plt.show()