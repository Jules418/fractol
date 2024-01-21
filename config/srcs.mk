SRCS= 			main.c \
				$(COMPLEX_SRCS) \
				$(FRACTAL_SRCS) \
				$(INITIALIZER_SRCS) \
				$(HOOKS_SRCS)

COMPLEX_SRCS = complex/complex_operators.c

FRACTAL_SRCS = fractal_management/draw_fractals.c \
				fractal_management/colors.c \
				fractal_management/mandelbrot_explorer.c

INITIALIZER_SRCS = inits/initializer.c

HOOKS_SRCS = hooks/hooks.c \
				hooks/keyboard_hooks.c