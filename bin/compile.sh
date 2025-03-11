g++ ../src/*.cpp ../src/*.cc  -o ../main -L./../raylib -I./../raylib -I../header -lraylib -lm -ldl -lpthread -lX11

mv ../main ../app
mv ../app/main ../app/circular_wars