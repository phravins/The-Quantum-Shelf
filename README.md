# The Quantum Shelf

**Div1 / Div2 Competitive Programming Problem**
---

## 🧠 Problemsetter Assessment

Design a **new, original competitive programming problem** suitable for **Codeforces Div1/Div2**.

Your submission must follow the structure below and include a **working optimal solution implemented in C++**.
---

## 📁 Folder Structure
```
.
├── qwen/
│   ├── conversations.md          # Links to Qwen model runs
│   ├── solution_01.cpp           # Qwen attempt 1 (should fail)
│   ├── solution_02.cpp           # Qwen attempt 2 (should fail)
│   └── solution_03.cpp           # Qwen attempt 3 (should fail)
│
├── test_cases/
│   ├── 1.in                      # Input test case
│   ├── 1.out                     # Expected output
│   └── ...                       # At least 5 cases
│
├── idea.md                       # Describe how the problem idea was developed
├── problem.md                    # Full problem statement with input/output specs
├── solution.md                   # Explanation of efficient solution
├── solution.cpp                  # Optimal accepted solution
├── solution_bf.cpp               # (Optional) Brute-force solution
├── generator.cpp                 # (Optional) Test case generator
├── requirements.json             # Time / memory limits
└── README.md                     # This file
```
---

## 📌 Requirements

- The problem must be **original**
- Difficulty level: **Div1 / Div2**
- Must **not** be a known variation
- Model **Qwen3-235B-A22B-2507** (thinking disabled) must fail on **three plausible attempts**
- None of the failed attempts should pass **even a single test**
- Shared conversation links and failed code must be stored under `qwen/`
- The problem must be **search-proof**
- Avoid rephrasing existing problems

### Documentation Rules

- `idea.md` must include:
  - Initial concept
  - Rejected variants
  - Final formulation rationale
- `requirements.json` must specify limits:

```json
{ "time": 2, "space": 256 }
```

- Include **at least 5 strong test cases**
- `solution.md` must clearly explain:
  - Algorithm
  - Data structures
  - Complexity
- Folder structure **must exactly match** the specification

---

## 📄 Repository Content

- **problem.md** — Full problem statement  
- **solution.cpp** — Reference solution (`O(N · Bell(K))`)  
- **generator.cpp** — Test case generator  
- **qwen/** — Proof of difficulty (failed AI attempts)  
- **test_cases/** — Edge and stress test cases  
---

## ▶️ How to Run

```bash
g++ -O3 solution.cpp -o solution
./solution < test_cases/1.in
```
---

## 📊 Constraints

- `N ≤ 60`
- `K ≤ 8`
- **Time Limit:** 2.0 seconds
- **Memory Limit:** 256 MB
