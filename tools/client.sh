g++ -std=c++17   ../src/main.cpp ../src/shell/*.cpp ../src/client/*.cpp   ../src/shell/user_cli/*.cpp  ../src/shell/server_cli/*.cpp  ../src/builders/*.cpp   ../src/parser/*.cpp -lstdc++fs  -lboost_thread -lboost_timer -lboost_chrono -lrt

status=$?