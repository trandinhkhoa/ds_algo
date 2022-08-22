# Compile and run
- From root folder (containing `CMakeLists.txt`)
```
mkdir build
cmake -S . -B build
```
- compile
```
cmake --build build
```
- run
```
./build/HelloWorld"
```
- run selected tests
```
./build/HelloWorld --gtest_filter="BubbleSort*.BubbleSort*"
```