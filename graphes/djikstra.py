#Student: Gustavo Sampaio Lima
#ID: 12623992

from collections import defaultdict
from heapq import *

def dijkstra(edges, f, t):
    g = defaultdict(list)
    for l, r, c in edges:
        g[l].append((c, r))

    q, seen, mins = [(0, f, [])], set(), {f: 0}
    while q:
        (cost, v1, path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = [v1] + path
            if v1 == t:
                return cost

            for c, v2 in g.get(v1, ()):
                if v2 in seen:
                    continue
                prev = mins.get(v2, None)
                next = cost + c
                if prev is None or next < prev:
                    mins[v2] = next
                    heappush(q, (next, v2, path))

    return -1

if __name__ == "__main__":

    cities_amnt, roads, queries = map(int, input().split())

    edges = []
    for i in range(roads):
        new_edge1 = list(map(int, input().split()))
        edges.append(tuple(new_edge1))
        new_edge2 = [new_edge1[1], new_edge1[0], new_edge1[2]] 
        edges.append(tuple(new_edge2))

    for i in range(queries):
        new_querie = list(map(int, input().split()))
        print(dijkstra(edges, new_querie[0], new_querie[1]))