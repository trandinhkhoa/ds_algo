- C/C++ Intellisense
  - create `.vscode/c_cpp_properties.json` by:
    - open "Command Palette"
    - Choose "C/C++: Edit Configurations"
  - configure **clang** for Mac:
    - https://code.visualstudio.com/docs/cpp/config-clang-mac
    -
      ```
        "compilerPath": "/usr/bin/clang",
        "cStandard": "c11",
        "cppStandard": "c++17",
        "intelliSenseMode": "clang-x64"
      ```
    - there is also `includePath`. Here is just an example in the case where I download the headers of my dependencies into `${workspaceFolder}/build/_deps/**`:
      ```
        "includePath": [
              "${workspaceFolder}/**",
              "${workspaceFolder}/build/_deps/**"
          ],
      ```
- cmake
  - setup
  ```
    cmake -S <source_directory> -B <build_files_directory>
  ```
  - build
  ```
    cmake --build <build_files_directory>
  ```

  - `set`: set variables
  - `target_link_directories`
  ```
  target_link_directories(<target> [BEFORE]
    <INTERFACE|PUBLIC|PRIVATE> [items1...]
    [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
  ```
    - similar to `target_link_libraries`. But not as specific. Tell the linker to find the library in the relative/absolute path.
      - Relative = relative to the current source directory
    - The named <target> must have been created by a command such as add_executable() or add_library()
    - should be avoided where there are other choices.
    - Prefer to pass full absolute paths to libraries where possible. since this ensures the correct library will always be linked.
    - Situations where a library search path may be needed: https://cmake.org/cmake/help/latest/command/target_link_directories.html

  - `target_link_directories`
  ```
  target_link_libraries(<target>
                        <PRIVATE|PUBLIC|INTERFACE> <item>...
                      [<PRIVATE|PUBLIC|INTERFACE> <item>...]...)
  ```
    - <item> can be
      - A library target name
      - A full path to a library file:
      - more: https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries
- Debug CMake project in VSCode:
  - have your `CMakeLists.txt` ready
  - install CMake Tools
  - Open the extension (left side bar)
  - `Configure All Projects`
  - Build
  - Right-click on target and debug
- googleTest
  ```
  ./build/HelloWorld --gtest_filter="BubbleSort*.BubbleSort*"
  ```

- ArrayList
  - be sure to be comfortable with dynamically resizeable array/lists in whatever language you will be working with.

- Amortized Time
  - relevant when you have to perform the same operation(s) repeatedly. This is often the case when dealing with large data structures, and the operation is adding or removing items.
  - it applies when the algorithms are designed to guarantee that the worst case scenario is only encountered once in a while, and not in every run.
  - If you add up the complexities of N repeated operations, and the average complexity (i.e. the sum of the complexities divided by N) is better than the worst case scenario, then you can use amortized analysis.

- **Unicode** vs **ASCII**
  - ASCII defines 128 characters, which maps to 0-127. Unicode defines (les than) 2^21 characters, which maps to numbers 0-2^21.
  - Unicode is a superset of ASCII, and the number 0-127 have the same meaning in ASCII as they have in Unicode. e.g. the number 65 means "Latin capital 'A'"
  - Because Unicode characters are usually larger than one 8-bit byte, there are numerous ways of storing Unicode characters in byte sequences. e.g UTF-32, UTF-8
    - **UTF-8**, **UTF-16**, **UTF-32**:
      - code points are encoded with one to four 8-bits, one to two 16-bits, one 32-bits code units, respectively
      - Why there is no **UTF-24** ?
        - Computers are generally much better at dealing with data on 4 byte boundaries. The benefits in terms of reduced memory consumption are relatively small compared with the pain of working on 3-byte boundaries
      - **Code points** : similar to characters: a numerical values that maps to a specific character
      - Encoding example: wikipedia
        - **Big-endian** stores the most significant byte of **a word** at the smallest memory address
        - **littele-endian** stores the least significant byte at the smallest memory address
- Bitwise **OR** vs **XOR**
  - OR = is there a 1 among the 2 ?
  - XOR = are these 2 bits different from each other?
  - AND = are both 1s ?

- C and C++
  - Classes and Inheritance
  - Constructors and Destructors
    - called upon an object's creation
    - no constructor => use default constructor
    - when the field to be initialized is constant.
    ```
     Person(int a) : id(a) { }
    ```
    Here field `id` is assigned before the object is created and before the constructor code is executed.
    - the destructor is called when the object is destroyed. We dont explicitly call a destructor => cannot take an argument.
  - Virtual Functions
    - member functions whose behaviors can be overridden by the derived class
    - also used when you do not want to implement a member function for the base class
    - without virtual functions
    ```
      Student * p = new Student();
      p->aboutMe();
    ```
    output: "I am a student"
    ```
      Person * p = new Student();
      p->aboutMe();
    ```
    Because of `static binding` => output: "I am a person"
      - `static binding`: determine type at compile time
    ```
    class Person {
      ...
      virtual aboutMe() {};
    }
    class Student {
      ...
      aboutMe() {};
    }
    Person * p = new Student();
    p->aboutMe();
    ```
    output: "I am a student"
    - `pure virtual function` => `abstract class` => cannot be instantiated
    ```
    class Person {
      ...
      virtual aboutMe() = 0;
    }
    ```

  - Virtual Destructors
    - make the destructor of the base class virtual so that the destructor of the derived class can be called
    - different from normal virtual function: the destructors are chained (those of the base classes are so called)
  - Operator overloading
  ```
  Bookshelf BookShelf::operator+(BookShelf &other) { ... }
  ```
  - Pointers and References
    - Pointer
      - a variable that holds an address of a variable
      - the size of a pointer varies depending on the architecture: 32 bits on a 32-bit machine and 64 bits on a 64-bit machine.
    - Reference
      - an alias for a pre-existing object
    - both are useful for pass by reference.
  - Templates
  - `volatile`
  - `lvalue` vs `rvalue`
  - move semantic
