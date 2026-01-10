# The Quantum Shelf

**Time Limit**: 2.0 seconds
**Memory Limit**: 256 MB

## Statement

You are the curator of a museum with a collection of $N$ artifacts, each having a distinct energy level from $1$ to $N$.

You want to arrange these artifacts in a row. However, they are unstable: if two adjacent artifacts have energy levels that are **too close**, they will react dangerously.
Specifically, for any two adjacent artifacts with levels $u$ and $v$, they are safe only if:
$$|u - v| > K$$

Your task is to find the number of stable permutations of the $N$ artifacts.
Since the answer can be large, print it modulo $10^9 + 7$.

## Input
A single line containing two integers $N$ and $K$.

## Output
A single integer — the number of valid permutations modulo $10^9 + 7$.

## Constraints
- $2 \le N \le 60$
- $0 \le K \le 8$

## Examples
**Input**
4 1
**Output**
2
**Note**
The valid permutations are $[2, 4, 1, 3]$ and $[3, 1, 4, 2]$. In both cases, adjacent elements differ by at least 2.
**Input**
5 2
**Output**
0
**Note**
It is impossible to satisfy the condition (difference $\ge 3$) for 5 elements.
