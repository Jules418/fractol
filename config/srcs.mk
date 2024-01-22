SRCS= 			main.c \
				$(COMPLEX_SRCS) \
				$(FRACTAL_MANAGEMENT_SRCS) \
				$(INITIALIZER_SRCS) \
				$(HOOKS_SRCS) \
				$(ERRORS_SRCS) \
				$(UTILS_SRCS)

COMPLEX_SRCS = complex/complex_operators.c \
				complex/conjugate.c

ERRORS_SRCS = errors/errors.c

FRACTAL_MANAGEMENT_SRCS = fractal_management/draw_fractals.c \
				fractal_management/colors.c \
				fractal_management/mandelbrot_explorer.c

INITIALIZER_SRCS = inits/initializer.c

HOOKS_SRCS = hooks/hook_functions.c \
				hooks/actions1.c \
				hooks/actions2.c

UTILS_SRCS = utils/utils.c