SRCS= 			main.c \
				$(COMPLEX_SRCS) \
				$(FRACTAL_SRCS)

COMPLEX_SRCS = complex/complex_operators.c

FRACTAL_SRCS = fractal_management/mandelbrot.c \
				fractal_management/colors.c