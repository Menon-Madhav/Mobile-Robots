import numpy as np
import matplotlib.pyplot as plt
import scipy.ndimage as sp
import math


class MpaaStar:
    def __init__(self, input_map, start, goal):
        self.s_start = start
        self.s_goal = goal
        self.parent = {}
        self.next = {}
        self.search = {}
        self.maps = input_map
        self.g = np.inf(input_map.shape)

        self.counter = 0
        self.observe(start)
        # for statement
        while self.s_start != self.s_goal:
            self.counter = self.counter + 1
            s = self.a_start(self.s_start)
            if s == math.nan:
                print("goal is unreachable")
            for c in self.closed:
                pass

    def initialize_state(self, s):  # done
        if self.search[s] != self.counter:
            self.g[s[0], s[1]] = math.inf
        self.search[s] = self.counter

    def build_path(self, s):  # done
        while s != self.s_start:
            self.next[self.parent[s]] = s
            s = self.parent[s]

    def observe(self, s):  # incomplete
        pass

    def a_start(self, s_init):  # incomplete
        self.initialize_state(s_init)
        self.parent[s_init] = math.nan
        self.g[s_init[0], s_init[1]] = 0
        opens = [[s_init, ]]
        closed = []
        while opens:
            return 0
            pass

    def cost(self, a, b):
        if self.maps[b[1], b[2]] == 0:
            return math.inf
        else:
            return math.sqrt((a[1] - b[1]) ** 2 + (a[2] - b[2]) ** 2)

    def heuristic(self, a):
        b = self.s_goal
        return math.sqrt((a[1] - b[1]) ** 2 + (a[2] - b[2]) ** 2)

    def get_neighbors(self, s):
        m = np.zeros(self.maps.shape)
        m[s[0], s[1]] = 1
        weights = np.array([[1, 1, 1], [1, 0, 1], [1, 1, 1]])
        n = sp.filters.convolve(m, weights, mode='constant')
        neighbors = np.where(n == 1)
        neighbors = np.dstack((neighbors[0], neighbors[1]))
        return neighbors
