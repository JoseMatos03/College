# Classe grafo para representaçao de grafos,
import math
from queue import Queue

import networkx as nx  # biblioteca de tratamento de grafos necessária para desnhar graficamente o grafo
import matplotlib.pyplot as plt  # idem

from Node import Node


# Constructor
# Methods for adding edges
# Methods for removing edges
# Methods for searching a graph
# BFS, DFS, A*, Greedy





class Graph:
    def __init__(self, directed=False):
        self.m_nodes = []
        self.m_directed = directed
        self.m_graph = {}
        self.m_h = {}

    #############
    #    escrever o grafo como string
    #############
    def __str__(self):
        out = ""
        for key in self.m_graph.keys():
            out = out + "node" + str(key) + ": " + str(self.m_graph[key]) + "\n"
        return out

    ################################
    #   encontrar nodo pelo nome
    ################################

    def get_node_by_name(self, name):
        search_node = Node(name)
        for node in self.m_nodes:
            if node == search_node:
                return node

        return None

    ##############################3
    #   imprimir arestas
    ############################333333

    def imprime_aresta(self):
        listaA = ""
        lista = self.m_graph.keys()
        for nodo in lista:
            for (nodo2, custo) in self.m_graph[nodo]:
                listaA = listaA + nodo + " ->" + nodo2 + " custo:" + str(custo) + "\n"
        return listaA

    ################
    #   adicionar   aresta no grafo
    ######################

    def add_edge(self, node1, node2, weight):
        n1 = Node(node1)
        n2 = Node(node2)
        if (n1 not in self.m_nodes):
            n1_id = len(self.m_nodes)  # numeração sequencial
            n1.setId(n1_id)
            self.m_nodes.append(n1)
            self.m_graph[node1] = []
        else:
            n1 = self.get_node_by_name(node1)

        if (n2 not in self.m_nodes):
            n2_id = len(self.m_nodes)  # numeração sequencial
            n2.setId(n2_id)
            self.m_nodes.append(n2)
            self.m_graph[node2] = []
        else:
            n2 = self.get_node_by_name(node2)

        self.m_graph[node1].append((node2, weight))

        if not self.m_directed:
            self.m_graph[node2].append((node1, weight))

    #############################
    # devolver nodos
    ##########################

    def getNodes(self):
        return self.m_nodes

    #######################
    #    devolver o custo de uma aresta
    ##############3

    def get_arc_cost(self, node1, node2):
        custoT = math.inf
        a = self.m_graph[node1]  # lista de arestas para aquele nodo
        for (nodo, custo) in a:
            if nodo == node2:
                custoT = custo

        return custoT

    ##############################
    #  dado um caminho calcula o seu custo
    ###############################

    def calcula_custo(self, caminho):
        # caminho é uma lista de nodos
        teste = caminho
        custo = 0
        i = 0
        while i + 1 < len(teste):
            custo = custo + self.get_arc_cost(teste[i], teste[i + 1])
            i = i + 1
        return custo

    ################################################################################
    #     procura DFS
    ####################################################################################

    def procura_DFS(self, start: Node, end: Node, path: list, visited: set) -> list:
        if start == end:
            return path + [start]
        if start in visited:
            return None
        visited.add(start)

        for node in self.m_graph[start]:
            if node[0] not in visited:
                new_path = self.procura_DFS(node[0], end, path + [start], visited)
                if new_path:
                    return new_path
        return None

    #####################################################
    # Procura BFS
    ######################################################

    def procura_BFS(self, start: Node, end: Node) -> list:
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

    ####################
    # funçãop  getneighbours, devolve vizinhos de um nó
    ##############################

    def getNeighbours(self, nodo):
        lista = []
        for (adjacente, peso) in self.m_graph[nodo]:
            lista.append((adjacente, peso))
        return lista

    ###########################
    # desenha grafo  modo grafico
    #########################

    def desenha(self):
        ##criar lista de vertices
        lista_v = self.m_nodes
        lista_a = []
        g = nx.Graph()
        for nodo in lista_v:
            n = nodo.getName()
            g.add_node(n)
            for (adjacente, peso) in self.m_graph[n]:
                lista = (n, adjacente)
                # lista_a.append(lista)
                g.add_edge(n, adjacente, weight=peso)

        pos = nx.spring_layout(g)
        nx.draw_networkx(g, pos, with_labels=True, font_weight='bold')
        labels = nx.get_edge_attributes(g, 'weight')
        nx.draw_networkx_edge_labels(g, pos, edge_labels=labels)

        plt.draw()
        plt.show()

    ####################################33
    #    add_heuristica   -> define heuristica para cada nodo 1 por defeito....
    ################################3

    def add_heuristica(self, n, estima):
        n1 = Node(n)
        if n1 in self.m_nodes:
            self.m_h[n] = estima



    ##########################################
    #    A*
    ##########################################

    def procura_aStar(self, start: Node, end: Node) -> list:
        # Fila de prioridade manual (lista de tuplas): (f(n), nó_atual, caminho)
        open_list = [(0, start, [start])]  # Começa com o nó inicial
        g_costs = {start: 0}  # Dicionário para armazenar o custo g de cada nó
        visited = set()

        while open_list:
            # Ordena a lista para garantir que o nó com o menor f(n) seja o primeiro
            open_list.sort(key=lambda x: x[0])

            # Pega o nó com o menor f(n)
            current_f, current_node, path = open_list.pop(0)

            # Se o nó objetivo for alcançado, retorna o caminho
            if current_node == end:
                return path

            if current_node in visited:
                continue

            visited.add(current_node)

            # Para cada vizinho do nó atual
            for neighbor, weight in self.getNeighbours(current_node):
                g_cost = g_costs[current_node] + weight  # Calcula o custo g até o vizinho

                if neighbor not in g_costs or g_cost < g_costs[neighbor]:
                    g_costs[neighbor] = g_cost  # Atualiza o custo g do vizinho
                    f_cost = g_cost + self.getH(neighbor)  # f(n) = g(n) + h(n)
                    open_list.append((f_cost, neighbor, path + [neighbor]))

        # Se nenhum caminho for encontrado, retorna None
        return None

    ###################################3
    # devolve heuristica do nodo
    ####################################

    def getH(self, nodo):
        if nodo not in self.m_h.keys():
            return 1000
        else:
            return (self.m_h[nodo])


    ##########################################
    #   Greedy
    ##########################################

    def procura_greedy(self, start: Node, end: Node) -> list:
        open_list = [(start, [start])]
        visited = set()

        while open_list:
            open_list.sort(key=lambda x: self.getH(x[0]))
            current_node, path = open_list.pop(0)  # pop the node with the lowest heuristic

            # If the goal is reached, return the path
            if current_node == end:
                return path

            visited.add(current_node)

            # Explore neighbors
            for neighbor, weight in self.getNeighbours(current_node):
                if neighbor not in visited:
                    open_list.append((neighbor, path + [neighbor]))
                    cost += weight

        # If no path is found
        return None