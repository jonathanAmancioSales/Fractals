#===============================================================
# Name        : samambaia_fractal.py
# Author      : Jonathan Amancio
# Description : Samambaia Fractal (Barnsley fern e variações)
#               [para testar diferentes parâmetros:
#                https://www.chradams.co.uk/fern/maker.html]
#===============================================================

import sys
from random import seed, uniform
from time import time
from typing import Tuple


class SamambaiaFractal():

    def __init__(self, number_of_points: int, type: str = 'barnsley') -> None:
        self.number_of_points = number_of_points
        self.xnew = 0
        self.ynew = 0
        self.list_coordinates = [(self.xnew, self.ynew)]
        seed(time())
        self.type = type
        self.matrix, self.probability = self._get_matrix()

    def _get_matrix(self) -> Tuple[dict]:
        matrix_ = {
            'barnsley': {
                1: (0, 0, 0, 0.16, 0, 0),
                2: (0.85, 0.04, -0.04, 0.85, 0, 1.6),
                3: (0.2, -0.26, 0.23, 0.22, 0, 1.6),
                4: (-0.15, 0.28, 0.26, 0.24, 0, 0.44),
            },
            'modified_barnsley_JS_1': {
                1: (0, 0, 0, 0.16, 0, 0),
                2: (0.85, 0.04, -0.001, 0.85, 0, 1.6),
                4: (0.2, -0.26, 0.23, 0.22, 0, 1.6),
                3: (-0.15, 0.28, 0.26, 0.24, 0, 0.44),
            },
            'modified_barnsley_JS_2': {
                1: (0, 0, 0, 0.16, 0, 0),
                2: (0.85, 0.004, -0.001, 0.85, 0, 1.6),
                4: (0.2, -0.26, 0.23, 0.22, 0, 1.6),
                3: (-0.15, 0.28, 0.26, 0.24, 0, 0.44),
            },
            'modified_barnsley': {
                1: (0, 0, 0, 0.2, 0, -0.12),
                2: (0.845, 0.035, -0.03, 0.82, 0, 1.6),
                3: (0.2, -0.31, 0.255, 0.245, 0, 0.29),
                4: (-0.15, 0.24, 0.25, 0.2, 0, 0.68),
            },
            'culcita': {
                1: (0, 0, 0, 0.25, 0, -0.14),
                2: (0.85, 0.02, -0.02, 0.83, 0, 1),
                3: (0.09, -0.28, 0.3, 0.11, 0, 0.6),
                4: (-0.09, 0.28, 0.3, 0.09, 0, 0.7),
            },
            'cyclosorus': {
                1: (0, 0, 0, 0.25, 0, -0.4),
                2: (0.93, 0.0035, -0.005, 0.93, -0.002, 0.5),
                3: (0.035, -0.2, 0.16, 0.04, -0.09, 0.02),
                4: (-0.04, 0.2, 0.16, 0.04, 0.083, 0.12),
            },
            'fractal_tree': {
                1: (0, 0, 0, 0.5, 0, 0),
                2: (0.42, -0.42, 0.42, 0.42, 0, 0.2),
                3: (0.42, 0.42, -0.42, 0.42, 0, 0.2),
                4: (0.1, 0, 0, 0.1, 0, 0.2),
            },
        }
        probability_ = {
            'barnsley': {
                1: 0.01,
                2: 0.85,
                3: 0.07,
                4: 0.07,
            },
            'culcita': {
                1: 0.02,
                2: 0.84,
                3: 0.07,
                4: 0.07,
            },
            'fractal_tree': {
                1: 0.005,
                2: 0.4,
                3: 0.4,
                4: 0.15,
            },
        }
        probability_['cyclosorus'] = probability_['culcita']
        probability_['modified_barnsley'] = probability_['barnsley']
        probability_['modified_barnsley_JS_1'] = probability_['barnsley']
        probability_['modified_barnsley_JS_2'] = probability_['barnsley']

        return matrix_[self.type], probability_[self.type]
    
    def generate_fractal(self) -> None:
        p1, p2, p3, p4 = self.probability.values()
        for _ in range(self.number_of_points + 1):
            r = uniform(0, 1)
            if r < p1:
                self._calculate_value(parameters=self.matrix[1])
            elif r < p1 + p2:
                self._calculate_value(parameters=self.matrix[2])
            elif r < p1 + p2 + p3:
                self._calculate_value(parameters=self.matrix[3])
            else:
                self._calculate_value(parameters=self.matrix[4])
            self.list_coordinates.append((self.xnew, self.ynew))
        self._write_values()

    def _calculate_value(self, parameters: tuple) -> None:
        """The matrix contains the parameters of the following equation:
        f(x, y) = | a b |*|x| +|e |
                  | c d | |y|  |f |

        => x_new = a*x + b*y + e
           y_new = c*x + d*y + f
        """
        a, b, c, d, e, f = parameters
        x = self.xnew
        y = self.ynew
        self.xnew = a*x + b*y + e
        self.ynew = c*x + d*y + f
        # self.ynew = c*self.xnew + d*y + f  # modified_barnsley_JS_0: Tornar as folhas finas.

    def _write_values(self, mode='w') -> None:
        with open(f'fern_data_{self.type}_{self.number_of_points}.txt', mode) as f:
            for x, y in self.list_coordinates:
                f.write(f'{x}\t{y}\n')


if __name__ == '__main__':
    number_of_points = int(sys.argv[1])
    type = sys.argv[2]
    SamambaiaFractal(number_of_points, type).generate_fractal()
