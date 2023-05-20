#===============================================================
# Name        : mandelbrot_set.py
# Description : Mandelbrot set fractal
#     Based on:
#      - https://realpython.com/mandelbrot-set-python/
#      - https://www.codingame.com/playgrounds/2358/how-to-plot-the-mandelbrot-set/mandelbrot-set
#===============================================================

from dataclasses import dataclass
from math import log
from PIL import Image, ImageDraw


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

    def generate_image(self):
        # Image size (pixels)
        height = 4000
        width = int(height * 1.5)

        # Plot window
        re_start = -2.1
        re_end = 1.3
        im_start = -1.2
        im_end = 1.2

        image = Image.new('RGB', (width, height), (0, 0, 0))
        draw = ImageDraw.Draw(image)

        for x in range(width):
            for y in range(height):
                # Convert pixel coordinate to complex number
                c = complex(
                    re_start + (x / width) * (re_end - re_start),
                    im_start + (y / height) * (im_end - im_start)
                )
                # Compute the number of iterations
                instability = 1 - self.stability(c, smooth=True)
                color = int(instability * 255)
                # Plot the point
                draw.point([x, y], (color, color, color))

        image.save(
            f'mandelbrot_set_{self.max_iterations}_{self.escape_radius}_{height}.png',
            'PNG'
        )


if __name__ == '__main__':
    mandelbrot_set = MandelbrotSet(max_iterations=80)
    mandelbrot_set.generate_image()
