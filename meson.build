# -Project
project('pokemon', 'c', 'cpp', version: '1.0.0', default_options: {'warning_level': '2'})

# -Dependencies
depgl = dependency('opengl')
depglfw = dependency('glfw3')

# -Output
executable('pokemon', sources: ['./src/main.cpp', './src/glad.c'], include_directories: './include', dependencies: [depgl, depglfw])
