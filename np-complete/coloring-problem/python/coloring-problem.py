class Algorithm:
    def __init__(self, adjacency_matrix, num_of_colors):
        self._adjacency_matrix = adjacency_matrix
        self._num_of_colors = num_of_colors
        self._num_of_vertexes = len(adjacency_matrix)
        self._colors = list(range(self._num_of_vertexes))

    def solve(self):
        if self._solve_problem(0):
            self._show_results()
        else:
            print('No solution')

    def _solve_problem(self, node_index):
        if node_index == self._num_of_vertexes:
            return True

        for color_index in range(self._num_of_colors):
            if self._is_color_valid(node_index, color_index):
                self._colors[node_index] = color_index

                if self._solve_problem(node_index + 1):
                    return True

                # BACKTRACKING

        return False

    def _is_color_valid(self, node_index, color_index):
        for i in range(self._num_of_vertexes):
            if self._adjacency_matrix[node_index][i] == 1 and color_index == self._colors[i]:
                return False
        return True

    def _show_results(self):
        for i in range(self._num_of_vertexes):
            print(f'Node {i + 1} has color index: {self._colors[i] + 1}')


if __name__ == '__main__':
    graph_matrix = [
        [0, 1, 0, 1, 0],
        [1, 0, 1, 1, 0],
        [0, 1, 0, 1, 0],
        [1, 1, 1, 0, 1],
        [0, 0, 0, 1, 0]
    ]

    num_colors = 3

    algorithm = Algorithm(graph_matrix, num_colors)
    algorithm.solve()
