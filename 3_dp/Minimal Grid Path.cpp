#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <ranges>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> grid(n);
    for (auto& row : grid) std::cin >> row;
    std::vector<std::pair<int, int>> positions{{0, 0}};
    while (!positions.empty()) {
        positions.erase(std::ranges::unique(positions).begin(), positions.end());
        char minc = std::ranges::min(positions | std::views::transform([&](auto& p) { 
            return grid[p.first][p.second];
        }));
        std::cout << minc;
        decltype(positions) nextPositions;
        for (auto [r, c] : positions)
            if (grid[r][c] == minc) {
                if (r + 1 < n) nextPositions.emplace_back(r + 1, c);
                if (c + 1 < n) nextPositions.emplace_back(r, c + 1);
            }
        positions = std::move(nextPositions);
    }
}