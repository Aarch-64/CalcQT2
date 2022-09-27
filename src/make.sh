rm build
mkdir build
cmake . -B build/
cd build/ && make
rm *.txt && rm -r Cal2QT_autogen
rm *.cmake && rm -r CMakeFiles && rm Makefile
./Cal2QT &
