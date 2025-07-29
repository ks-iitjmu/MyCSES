# MyCSES - CSES Problem Set Solutions

This repository contains my solutions to problems from the [CSES Problem Set](https://cses.fi/problemset/), implemented in C++. The CSES Problem Set is a collection of competitive programming practice problems that cover various algorithmic topics.

## 👨‍💻 Author
**Kunal Sharma**  
IIT Jammu

## 📁 Repository Structure

The solutions are organized by problem categories:

```
├── 1_introductory_problems/    # Basic algorithmic problems
├── 2_sorting_searching/        # Sorting and searching algorithms
├── 3_dp/                      # Dynamic programming problems
├── 7_mathematics/             # Mathematical problems
├── .builds/                   # Build configurations
└── .vscode/                   # VS Code settings
```

## 🧩 Problem Categories

### 1. Introductory Problems
- **Two Sets** - Partitioning numbers into two equal sum sets
- **Gray Code** - Generating Gray code sequences
- **Apple Division** - Minimizing difference in apple weight distribution
- **Chessboard and Queens** - N-Queens problem variant
- **Coin Piles** - Mathematical puzzle with coin removal rules
- **Bit Strings** - Counting binary strings

### 2. Sorting and Searching
- **Apartments** - Matching applicants to apartments
- **Movie Festival** - Activity selection problem
- **Collecting Numbers** - Array manipulation problems
- **Minimum Coin Sum** - Finding smallest unrepresentable sum

### 3. Dynamic Programming
- **Minimizing Coins** - Classic coin change problem

### 7. Mathematics
- **Exponentiation 2** - Fast exponentiation with modular arithmetic
- **Sum of Divisors** - Mathematical series calculation
- **Creating Strings** - Combinatorics with factorial calculations

## 🔧 Implementation Details

### Language & Standards
- **Language**: C++
- **Compiler**: Standard C++ compiler
- **Libraries**: STL (Standard Template Library)

### Common Patterns Used
```cpp
// Standard template used across solutions
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

// Fast I/O optimization
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
```

### Key Algorithmic Techniques
- **Fast Exponentiation**: Binary exponentiation for efficient power calculation
- **Modular Arithmetic**: Using MOD = 1000000007 for large number calculations
- **Dynamic Programming**: Bottom-up and memoization approaches
- **Greedy Algorithms**: Activity selection and optimization problems
- **Bit Manipulation**: Efficient subset generation and Gray codes
- **Mathematical Formulas**: Combinatorics and number theory

## 🚀 How to Use

1. **Clone the repository**:
   ```bash
   git clone https://github.com/ks-iitjmu/MyCSES.git
   cd MyCSES
   ```

2. **Compile a solution**:
   ```bash
   g++ -o solution category/problem_name.cpp
   ```

3. **Run the solution**:
   ```bash
   ./solution < input.txt
   ```

## 📊 Problem Solving Approach

Each solution follows a structured approach:
1. **Problem Analysis**: Understanding constraints and edge cases
2. **Algorithm Selection**: Choosing optimal time/space complexity approach
3. **Implementation**: Clean, readable C++ code
4. **Optimization**: Fast I/O and efficient algorithms for competitive programming

## 🏆 Competitive Programming Features

- **Fast I/O**: All solutions use optimized input/output
- **Type Definitions**: Consistent use of `typedef long long ll`
- **Modular Arithmetic**: Proper handling of large numbers
- **Edge Case Handling**: Robust solutions for boundary conditions
- **Clean Code**: Readable and well-structured implementations

## 📈 Progress Tracking

- ✅ Introductory Problems: Multiple problems solved
- ✅ Sorting and Searching: Core algorithms implemented
- ✅ Dynamic Programming: Foundation problems completed
- ✅ Mathematics: Advanced mathematical concepts covered

## 🔗 Useful Links

- [CSES Problem Set](https://cses.fi/problemset/)
- [CSES Book](https://cses.fi/book/book.pdf) - Competitive Programming Handbook

## 📝 Notes

- Solutions are optimized for competitive programming contests
- Time complexity is prioritized for large input constraints
- Code follows standard competitive programming conventions
- All solutions have been tested against CSES judge system

---

*Feel free to explore the solutions and use them for learning purposes. Happy coding! 🚀*
