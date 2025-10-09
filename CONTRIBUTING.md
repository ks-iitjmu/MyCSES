# Contributing to MyCSES

First off, thank you for considering contributing to MyCSES! 🎉

The following is a set of guidelines for contributing to this CSES Problem Set solutions repository. These are mostly guidelines, not rules. Use your best judgment, and feel free to propose changes to this document in a pull request.

## 🎯 How Can I Contribute?

### Reporting Bugs
- Ensure the bug was not already reported by searching existing Issues
- If you can't find an open issue addressing the problem, open a new one
- Include a clear title and description with as much relevant information as possible

### Suggesting Enhancements
- Open an issue with a clear title and detailed description
- Explain why this enhancement would be useful
- Provide examples or mockups if applicable

### Adding New Solutions
We welcome new CSES problem solutions! Here's how you can contribute:

#### 1. Problem Categories
Solutions should be organized in the appropriate category folders:
- `1_introductory_problems/` - Basic algorithmic problems
- `2_sorting_searching/` - Sorting and searching algorithms  
- `3_dp/` - Dynamic programming problems
- `4_graph/` - Graph algorithms
- `5_range_queries/` - Range query data structures
- `6_tree/` - Tree algorithms
- `7_mathematics/` - Mathematical problems
- `8_string/` - String algorithms
- `9_geometry/` - Computational geometry
- `10_advanced/` - Advanced techniques

#### 2. Code Standards
All C++ solutions must follow these guidelines:

**Required Template:**
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Your solution here
    
    return 0;
}
```

**Naming Convention:**
- Use snake_case for file names
- File name should match the problem name from CSES
- Example: `weird_algorithm.cpp`, `missing_number.cpp`

**Code Quality:**
- Write clean, readable code
- Add comments for complex algorithms
- Ensure optimal time/space complexity
- Test thoroughly before submitting

#### 3. Solution Requirements
- ✅ Must pass all CSES test cases
- ✅ Should handle edge cases properly
- ✅ Use appropriate data types (long long for large numbers)
- ✅ Include proper modular arithmetic where needed
- ✅ Follow competitive programming best practices

### Pull Request Process

1. **Fork** the repository
2. **Create** a new branch for your feature (`git checkout -b feature/problem-name`)
3. **Add** your solution in the appropriate category folder
4. **Test** your solution thoroughly
5. **Commit** your changes (`git commit -m 'Add solution for Problem Name'`)
6. **Push** to your branch (`git push origin feature/problem-name`)
7. **Create** a Pull Request with a clear title and description

#### Pull Request Guidelines
- Include the problem name and category in the PR title
- Describe what problem you solved and your approach
- Mention time/space complexity in the description
- Link to the original CSES problem if possible
- Ensure your code follows the style guidelines

## 🏷️ Labels for Issues/PRs

We use these labels to categorize contributions:

- `hacktoberfest` - Issues/PRs for Hacktoberfest participation
- `good first issue` - Good for newcomers
- `help wanted` - Extra attention needed
- `bug` - Something isn't working
- `enhancement` - New feature or request
- `documentation` - Improvements to documentation
- `easy` - Beginner-friendly problems
- `medium` - Intermediate problems  
- `hard` - Advanced problems

## 🎃 Hacktoberfest Participation

This repository participates in Hacktoberfest! Here's what you need to know:

- Look for issues labeled `hacktoberfest`
- Quality over quantity - we value meaningful contributions
- Spam PRs will be labeled as `invalid` or `spam`
- Focus on solving new problems or improving existing solutions

## 📝 Solution Documentation

When adding a new solution, consider including:

```cpp
/*
Problem: Problem Name
Category: Category Name
Difficulty: Easy/Medium/Hard
Time Complexity: O(...)
Space Complexity: O(...)

Approach:
Brief description of your algorithm/approach

Key Insights:
- Important observations
- Edge cases to consider
- Optimization tricks used
*/
```

## ❓ Questions?

Feel free to open an issue if you have questions about:
- Problem-solving approaches
- Code optimization techniques
- Competitive programming strategies
- Repository organization

## 🙏 Recognition

Contributors will be acknowledged in our README.md file. Thank you for helping make this resource better for the competitive programming community!

---

Happy coding and contributing! 🚀