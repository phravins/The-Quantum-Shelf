# The Quantum Shelf
Div1/Div2 Competitive Programming Problem.
## Content
- `problem.md`: Statement.
- `solution.cpp`: Reference Solution ($O(N \cdot \text{Bell}(K))$).
- `generator.cpp`: Test case generator.
- `qwen/`: Proof of difficulty (failed AI attempts).
- `test_cases/`: 5+ cases covering edge scenarios.
## To Run
```bash
g++ -O3 solution.cpp -o solution
./solution < test_cases/1.in
```
## Constraints
$N \le 60, K \le 8$.
Time Limit: 2.0s.
