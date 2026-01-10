# The Quantum Shelf
Div1/Div2 Competitive Programming Problem.

Problemsetter Assessment: Div1/Div2-Level CP Task Design a new, original competitive programming problem suitable for Codeforces Div1/Div2. Your submission must follow the structure below and include a working optimal solution implemented in C++ .

📁 Folder Structure
├── qwen/ 
├── conversations.md # Links to Qwen model runs 
├── solution_01.cpp # Qwen attempt 1 (should fail) 
├── solution_02.cpp # Qwen attempt 2 (should fail) 
└── solution_03.cpp # Qwen attempt 3 (should fail) 
├── test_cases/ │ ├── 1.in # Input test case 
├── 1.out # Expected output │ 
└── ... # At least 5 cases
├── idea.md # Describe how the problem idea was developed
├── problem.md # Full problem statement with input/output specs 
├── solution.md # Explanation of efficient solution 
├── solution.cpp # Optimal accepted solution 
├── requirements.json # Time/memory limits, e.g.: 
│ # { "time": 2, "space": 256 } 
├── README.md # (Optional) Any additional notes
├── solution_bf.cpp # (Optional) Brute-force solution for testing 
└── generator.cpp # (Optional) Test case generator

📌 Requirements The problem must be original, of Div1/Div2 difficulty, and not a known variation. Qwen3-235B-A22B-2507 (https://chat.qwen.ai/c/d3998b36-2aa1-4fff-986d-ecaa787d8324) with thinking disabled should fail on three plausible attempts (should not pass at least a single test). Save the shared conversation links and code under qwen/. Search-proof: Search engine checks must not reveal identical or closely similar problems. Avoid merely rephrasing existing problems (e.g., changing story, symbols, or format). idea.md should explain how the core idea was conceived and refined into the final version. Include initial concept, rejected variants, and final formulation rationale. requirements.json must specify time and space limits (in seconds and MB). Include at least 5 strong test cases covering normal and edge conditions. solution.md should clearly explain the efficient algorithm and data structures. Folder structure should be exactly the same as described.

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
