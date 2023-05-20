#===============================================================
# Name        : mandelbrot_set_pil.py
# Description : Mandelbrot set fractal with PIL lib
#===============================================================

from dataclasses import dataclass
from PIL import Image, ImageEnhance


@dataclass
class MandelbrotSet:
    max_iterations: int = 100

    def generate_image(self, height=1000, width=None, brightness=True):
        if width is None:
            width = int(height * 1.5)

        limits = (-2.1, -1.2, 1.3, 1.2)  # default
        limits = (-1.805, -0.03, -1.725, 0.03)  # tail
        limits = (-0.7445, 0.1304, -0.7425, 0.1324)  # seahorse valley - spiral
        # limits = (
        #    -0.744539761 - 0.5*6.25e-6, 0.121724001 - 0.5*6.25e-6,
        #    -0.744539761 + 0.5*6.25e-6, 0.121724001 + 0.5*6.25e-6
        # )  # island
        # limits = (
        #    -0.745067 - 0.5*7e-4, 0.118346 - 0.5*7e-4,
        #    -0.745067 + 0.5*7e-4, 0.118346 + 0.5*7e-4
        # )  # island_2

        image = Image.effect_mandelbrot((width, height), limits, self.max_iterations)
        if brightness:
            image = ImageEnhance.Brightness(image).enhance(1.25)

        image.save(f'mandelbrot_set_{self.max_iterations}_{height}_pil.png', 'PNG')


if __name__ == '__main__':
    #MandelbrotSet(max_iterations=150).generate_image(height=4000)
    MandelbrotSet(max_iterations=1000).generate_image(height=8000, width=8000)  # seahorse valley
