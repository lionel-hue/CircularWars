@echo off

g++ ../src/*/cpp ../src/*.cc -o main -L../raylib -I../header -I../raylib -lraylib -lopengl32 -lwinmm -lgdi32

rename main circular_wars

del ../app/circular_wars

move circular_wars ../app/