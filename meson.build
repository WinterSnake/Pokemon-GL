# -Project
project('pokemon', 'c', 'cpp', version: '1.0.0', default_options: {'warning_level': '2'})

# -Dependencies
depgl = dependency('opengl')
depglfw = dependency('glfw3')

# -Sources
opengl_sources = [
  './src/opengl/glad.c',
  './src/opengl/color.cpp',
  './src/opengl/shader.cpp',
]

# -Output
executable('pokemon', sources: ['./src/main.cpp', opengl_sources], include_directories: './include', dependencies: [depgl, depglfw])
