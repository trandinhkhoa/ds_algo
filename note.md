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