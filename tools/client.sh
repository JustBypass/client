g++ -std=c++17  ../src/main.cpp ../src/shell/*.cpp ../src/client/*.cpp   ../src/shell/user_cli/*.cpp  -lboost_thread -lboost_timer -lboost_chrono -lrt

status=$?