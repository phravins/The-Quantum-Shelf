# Idea: The Quantum Shelf

## Development Log

I was looking for a problem about restricted permutations. Initially, I thought about standard Hamiltonian paths or GCD constraints, but GCD relies too much on number theory (primes) which feels a bit overused.

Then I wondered: "What if the restrictions effectively form a really simple graph?"
If we forbid neighbors that are "too close" ($|u-v| \le K$), the forbidden graph structure is very regular.

- $K=0$: No restrictions. Answer is $N!$.
- $K=1$: Neighbors can't diff by 1. $1-2, 2-3 \dots$ are forbidden.
- Small $K$: The forbidden edges are only "local".

This local property implies we can use Dynamic Programming. Since we only scan $1 \dots N$, the "active" nodes that matter are the ones in the window of size $K$. 

### The DP Approach
We can use inclusion-exclusion. We want to avoid *all* forbidden edges.
Formula: $\sum (-1)^{|S|} \times (\text{permutations containing edges } S)$.
Inside the sum, if we pick a set of edges $S$, they must form paths (since a node can have at most 2 neighbors in a permutation).
If they form paths with $k$ edges total, we have $N-k$ components.
The count is $(N-k)!$.

So the problem reduces to: **Count ways to select $k$ disjoint paths in the graph where edges connect $u,v$ if $|u-v| \le K$.**

State needs to track:
1. Degrees of nodes in the current window (0, 1, or 2).
2. Connectivity (which nodes in the window belong to the same component).

With $N=60, K=8$, a profile DP with state compression (tracking partition of $K$ elements) is feasible.

### Rejected Ideas
- **Grid Layout**: Too complicated, hard to create good test cases without easy heuristics.
- **Tree Constraints**: "Tree DP" is often tedious to implement.
- **Cycle arrangement**: Doesn't add much difficulty over linear arrangement, just one extra constraint.

### Final Decision
I went with the linear version because it's clean, the statement is easy to understand, and the constraint $N \le 60$ clearly hints at something exponential in $K$ or polynomial $N^3/N^4$, ruling out simple backtracking but allowing smart DP.
