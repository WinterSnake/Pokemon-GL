# -Project
project('pokemon', 'cpp', version: '1.0.0', default_options: {'warning_level': '2'})

# -Dependencies
depgl = dependency('opengl')
depglfw = dependency('glfw3')

# -Output
executable('pokemon', sources: ['./src/main.cpp', './src/pokemon.cpp', './src/battle.cpp'], include_directories: './include', dependencies: [depgl, depglfw])
