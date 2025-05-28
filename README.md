# C Learning Project

A comprehensive C programming learning project that covers fundamental to advanced concepts in the C programming language. This repository contains practical examples and exercises organized in a progressive learning structure.

## 📚 Learning Topics Covered

### Basic Concepts (1-6)
- **Hello World** - Basic program structure and compilation
- **Printf** - Output formatting and format specifiers
- **Data Types** - Understanding different data types and their sizes
- **Constants** - Working with constant values
- **Operations** - Arithmetic and logical operations
- **User Input** - Reading input from users

### Control Structures (7-9)
- **Math Operations** - Mathematical functions and calculations
- **Conditionals & Switch** - Decision making with if-else and switch statements
- **Loops** - Iteration with for, while, and do-while loops

### Functions (10)
- **Function Basics** - Function declaration, definition, and calling
- **Random Numbers** - Working with random number generation
- **Time Functions** - Time-related operations

### Data Structures (11-16)
- **Arrays** - Array declaration, memory management, operations, and algorithms
- **Pointers** - Pointer syntax, operations, types, 2D arrays, and function pointers
- **Strings** - String operations and exercises
- **Structures** - Struct declaration, typedef, nested structures, and memory alignment
- **Unions** - Union basics and combination with structures

### Advanced Topics (17-18)
- **Dynamic Memory Allocation** - malloc, calloc, realloc, and free
- **File Handling** - File I/O operations including reading and writing

## 🛠️ Project Structure

```
C-Learning/
├── src/                    # Source code files
│   ├── 1_hellow_world.c   # Basic hello world program
│   ├── 2_printf.c         # Printf examples
│   ├── 3_data_types.c     # Data type demonstrations
│   ├── ...                # Progressive learning files
│   └── 18_file_handling_*.c # Advanced file operations
├── resources/             # Resource files for file handling exercises
│   ├── example.txt        # Sample text files
│   ├── students.txt       # Student data files
│   └── *.bin             # Binary files for advanced exercises
├── include/              # Header files (if any)
├── cmake-build-debug/    # CMake build directory
├── CMakeLists.txt        # CMake configuration
└── README.md            # This file
```

## 🚀 Getting Started

### Prerequisites
- GCC compiler or any C compiler
- CMake (version 3.30 or higher)
- Make (optional, for manual compilation)

### Building the Project

#### Using CMake (Recommended)
```bash
# Create build directory
mkdir build && cd build

# Generate build files
cmake ..

# Build all executables
make
```

This will create individual executable files for each source file in the `src/` directory.

#### Manual Compilation
You can also compile individual files manually:
```bash
# Compile a specific file
gcc src/1_hellow_world.c -o hello_world

# Run the executable
./hello_world
```

### Running Examples

After building, you can run any of the generated executables:
```bash
# Run hello world example
./1_hellow_world

# Run data types example
./3_data_types

# Run file handling example
./18_file_handling_1_input
```

## 📖 Learning Path

It's recommended to follow the numerical order of the files as they build upon each other:

1. **Start with basics** (1-6): Understand fundamental concepts
2. **Control flow** (7-9): Learn decision making and loops
3. **Functions** (10): Understand modular programming
4. **Data structures** (11-16): Master arrays, pointers, and structures
5. **Advanced topics** (17-18): Explore memory management and file I/O

## 🎯 Key Learning Objectives

- **Syntax Mastery**: Understanding C syntax and language features
- **Memory Management**: Learning stack vs heap, pointers, and dynamic allocation
- **Data Structures**: Working with arrays, structures, and unions
- **File Operations**: Reading from and writing to files
- **Problem Solving**: Implementing algorithms and solving programming challenges

## 📝 Code Style

The project follows consistent C coding practices:
- Clear variable naming
- Comprehensive comments (including Chinese explanations)
- Proper memory management
- Error handling for file operations

## 🔧 Development Environment

- **Language**: C99 standard
- **Build System**: CMake
- **IDE Support**: Compatible with CLion, VS Code, and other C IDEs

## 📚 Additional Resources

For further learning, consider exploring:
- C programming textbooks
- Online C tutorials
- Advanced topics like data structures and algorithms
- System programming concepts

## 🤝 Contributing

This is a personal learning project, but suggestions for improvements or additional examples are welcome!

## 📄 License

This project is for educational purposes. Feel free to use and modify for your own learning journey.

---

**Happy Learning! 🎉**

*This project demonstrates a progressive approach to learning C programming, from basic syntax to advanced concepts like dynamic memory allocation and file handling.* 