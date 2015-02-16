rm -rvf libcrashme.so app
g++ -shared -o libcrashme.so crashme.cpp `llvm-config-3.6 --cxxflags` && \
g++ -rdynamic -o app app.cpp -L. -lcrashme -lGL -lglut `llvm-config-3.6 --ldflags --libs` -lpthread -ldl -lncurses && \
LD_LIBRARY_PATH=. ./app
