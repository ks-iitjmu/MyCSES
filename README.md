# MyCSES - CSES Problem Set Solutions

[![Hacktoberfest](https://img.shields.io/badge/Hacktoberfest-2025-blueviolet.svg)](https://hacktoberfest.digitalocean.com/)
[![Contributions Welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](CONTRIBUTING.md)
[![Code of Conduct](https://img.shields.io/badge/code%20of-conduct-ff69b4.svg?style=flat)](CODE_OF_CONDUCT.md)
[![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://isocpp.org/)

This repository contains solutions to problems from the [CSES Problem Set](https://cses.fi/problemset/), implemented in C++. The CSES Problem Set is a collection of competitive programming practice problems that cover various algorithmic topics.

**🎃 Participating in Hacktoberfest 2025!** We welcome quality contributions from the community. Check out our [Contributing Guidelines](CONTRIBUTING.md) to get started.

## 👨‍💻 Maintainer
**Kunal Sharma**  
IIT Jammu

## 🤝 Contributing

We encourage contributions from the competitive programming community! Whether you're a beginner or an expert, there are many ways to contribute:

- 🐛 **Report bugs** or suggest improvements
- 💡 **Add new problem solutions** 
- 📚 **Improve documentation** 
- 🎯 **Optimize existing solutions**
- ✨ **Add explanatory comments** to complex algorithms

**New to open source?** Look for issues labeled [`good first issue`](../../labels/good%20first%20issue) to get started!

👉 **Read our [Contributing Guide](CONTRIBUTING.md)** for detailed instructions on how to contribute.

## 📋 Code of Conduct

This project follows the [Contributor Covenant Code of Conduct](CODE_OF_CONDUCT.md). By participating, you are expected to uphold this code. Please report unacceptable behavior to the maintainers.

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

### 4. [Graph Algorithms](./4_graph_algorithms/)
- [**Counting Rooms**](./4_graph_algorithms/Counting_Rooms.cpp) 
- [**Labyrinth** ](./4_graph_algorithms/Labyrinth.cpp) - Finding path from A to B

### 7. Mathematics
- **Exponentiation 2** - Fast exponentiation with modular arithmetic
- **Sum of Divisors** - Mathematical series calculation
- **Creating Strings** - Combinatorics with factorial calculations
- **Next Prime** - Finding next prime
- **Christmas Party** - Finding derangement of $n$ elements

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

## 🌟 Contributors

Thanks to all the amazing contributors who have helped improve this repository!

<!-- Contributors will be listed here automatically -->

Want to contribute? Check out our [Contributing Guidelines](CONTRIBUTING.md)!

## 🎃 Hacktoberfest

This repository participates in **Hacktoberfest**! We welcome quality contributions during October and throughout the year.

### How to participate:
1. Look for issues labeled `hacktoberfest`
2. Check out `good first issue` labels for beginner-friendly tasks
3. Read our [Contributing Guidelines](CONTRIBUTING.md)
4. Submit quality pull requests
5. Help review other contributions

### Contribution Ideas:
- Solve new CSES problems
- Optimize existing solutions
- Add detailed comments and explanations
- Improve documentation
- Add test cases
- Create problem difficulty classifications

## 🔗 Useful Links

- [CSES Problem Set](https://cses.fi/problemset/)
- [CSES Book](https://cses.fi/book/book.pdf) - Competitive Programming Handbook

## 📝 Notes

- Solutions are optimized for competitive programming contests
- Time complexity is prioritized for large input constraints
- Code follows standard competitive programming conventions
- All solutions have been tested against CSES judge system

## 🚀 Getting Started for Contributors

1. **Fork this repository**
2. **Clone your fork**: `git clone https://github.com/YOUR_USERNAME/MyCSES.git`
3. **Create a branch**: `git checkout -b feature/problem-name`
4. **Add your solution** following our [guidelines](CONTRIBUTING.md)
5. **Test thoroughly** against CSES judge
6. **Submit a pull request**

## 📞 Support

- 🐛 Found a bug? [Create an issue](../../issues/new)
- 💡 Have a suggestion? [Start a discussion](../../discussions)
- 📧 Need help? Check our [Contributing Guide](CONTRIBUTING.md)

## 📜 License

This project is open source and available under the [MIT License](LICENSE).

---

*Feel free to explore the solutions, contribute, and use them for learning purposes. Happy coding! 🚀*

**⭐ Star this repository if you find it helpful!**
