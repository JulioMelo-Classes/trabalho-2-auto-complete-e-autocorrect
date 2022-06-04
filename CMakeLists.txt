## linux ou windows + wsl ubuntu apenas
## usuarios do replit a primeira compilação da versão extra pode demorar *um pouco*
## por favor não tentem com mingw ou msvc (compiladores do windows)

cmake_minimum_required(VERSION 3.2)
project(Autocomplete)

include(./ncurses.cmake)

#com ncurses
add_executable(words_complete_correct_extra
               src/main_ncurses.cpp)
target_include_directories(words_complete_correct_extra PUBLIC
                           ./include
                           ${NCURSES_INCLUDES}/ncurses)
target_link_libraries(words_complete_correct_extra ncurses)


#sem ncurses
add_executable(words_complete_correct
               src/main.cpp
               src/Processamento.cpp
               src/Autocomplete.cpp
               src/Ordenacao.cpp 
               src/Interface.cpp
               src/Autocorrect.cpp
              )
              
target_include_directories(words_complete_correct PUBLIC
                           include
                           )

