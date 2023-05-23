#===============================================================
# Name        : mandelbrot_set.py
# Author      : Jonathan Amancio
# Description : Mandelbrot set fractal
#     Based on:
#      - https://realpython.com/mandelbrot-set-python/
#      - https://www.codingame.com/playgrounds/2358/how-to-plot-the-mandelbrot-set/mandelbrot-set
#===============================================================

from dataclasses import dataclass
from math import log
from PIL import Image

import numpy as np
from matplotlib import cm

@dataclass
class MandelbrotSet:
    max_iterations: int = 100
    escape_radius: float = 2.0

    def __contains__(self, c: complex) -> bool:
        return self.stability(c) == 1

    def stability(self, c: complex, smooth=False, clamp=True) -> float:
        value = self.escape_count(c, smooth) / self.max_iterations
        return max(0.0, min(value, 1.0)) if clamp else value

    def escape_count(self, c: complex, smooth=False) -> int or float:
        z = 0
        for iteration in range(self.max_iterations):
            z = z ** 2 + c
            if abs(z) > self.escape_radius:
                if smooth:
                    return iteration + 1 - log(log(abs(z))) / log(2)
                return iteration
        return self.max_iterations

    def generate_image(self, height=1000, width=None, colorful=False):
        if width is None:
            width = int(height * 1.5)

        self.width = width
        self.height = height

        self._generate_image(colorful)
        self._save_image()

    def _generate_image(self, colorful=False):
        matrix = np.array(list(self._generate_data())).reshape(self.width, self.height)
        matrix = np.rot90(matrix, 1)

        self.image = Image.new('RGB', (self.width, self.height), (0, 0, 0))
        if colorful:
            palette = cm.BrBG
            # palette = cm.jet
            # palette = cm.twilight_shifted
            self.image = Image.fromarray(np.uint8(palette(matrix)*255))
        else:
            self.image = Image.fromarray(np.uint8(matrix*255))

    def _generate_data(self):
        limits = {'re_start': -2.1, 're_end': 1.3, 'im_start': -1.2, 'im_end': 1.2}  # default
        limits = {'re_start': -1.805, 're_end': -1.725, 'im_start': -0.03, 'im_end': 0.03}  # tail
        self.limits = limits

        for x in range(self.width):
            for y in range(self.height):
                # Convert pixel coordinate to complex number:
                c = self._get_complex_number(x, y)
                instability = 1 - self.stability(c, smooth=True)
                yield instability

    def _save_image(self):
        self.image.save(
            f'mandelbrot_set_{self.max_iterations}_{self.escape_radius}_{self.height}.png',
            'PNG'
        )

    def _get_complex_number(self, x: float, y: float) -> complex:
        re_start = self.limits['re_start']
        re_end = self.limits['re_end']
        im_start = self.limits['im_start']
        im_end = self.limits['im_end']

        # Convert coordinate to complex number:
        return complex(
            re_start + (x / self.width) * (re_end - re_start),
            im_start + (y / self.height) * (im_end - im_start)
        )


if __name__ == '__main__':
    mandelbrot_set = MandelbrotSet(max_iterations=200)
    mandelbrot_set.generate_image(height=4000, colorful=True)
