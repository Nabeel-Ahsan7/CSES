# Bottom-Up Approach: A Comprehensive Guide

## What is Bottom-Up Approach?

### Definition
Bottom-up approach is a problem-solving technique in dynamic programming where:
- You solve the smallest subproblems first
- Gradually build up to solve more complex problems
- Solutions are computed iteratively, starting from the simplest cases
- Typically implemented using iteration (loops) instead of recursion

### Key Characteristics
1. **Builds Solution Incrementally**
   - Starts with the smallest, most basic subproblems
   - Solves progressively larger subproblems
   - Uses previously computed results to solve more complex problems

2. **Tabulation Method**
   - Uses a table (usually an array or matrix) to store intermediate results
   - Fills the table in a systematic, bottom-up manner
   - Eliminates recursive function call overhead

## Comparison with Top-Down (Recursive) Approach

### Top-Down (Memoization)
```cpp
// Recursive with Memoization
int fibonacci(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo);
    return memo[n];
}
```

### Bottom-Up (Iterative)
```cpp
// Bottom-Up Approach
int fibonacci(int n) {
    if (n <= 1) return n;
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
```

## Step-by-Step Bottom-Up Approach

### 1. Identify Subproblems
- Break down the problem into smallest possible subproblems
- Determine how smaller solutions contribute to larger solutions

### 2. Create State Representation
- Choose appropriate data structure (array, matrix)
- Decide how to represent problem states

### 3. Define Base Cases
- Initialize the simplest, known solutions
- These are the starting points for building complex solutions

### 4. Build Solution Iteratively
- Use loops to compute solutions for increasingly complex subproblems
- Utilize previously computed results

## Practical Example: Climbing Stairs Problem

**Problem**: How many distinct ways to climb n stairs if you can climb 1 or 2 stairs at a time?

```cpp
int climbStairs(int n) {
    // Base case handling
    if (n <= 2) return n;
    
    // Create DP table
    vector<int> dp(n + 1);
    
    // Initialize base cases
    dp[1] = 1;  // One way to climb 1 stair
    dp[2] = 2;  // Two ways to climb 2 stairs
    
    // Build solution bottom-up
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
```

## Advantages of Bottom-Up Approach
1. **Efficient Memory Usage**
   - Avoids recursive call stack overhead
   - Predictable memory consumption
   - Often more space-efficient

2. **Faster Execution**
   - No function call overhead
   - Direct computation
   - Compiler can optimize better

3. **Prevents Stack Overflow**
   - Works well for large input sizes
   - No recursion depth limitations

## Common Problem Types Suited for Bottom-Up
- Fibonacci-like sequences
- Optimization problems
- Counting problems
- Path finding
- Sequence alignment
- Longest common subsequence

## When to Use Bottom-Up
- Problem has overlapping subproblems
- Can be solved by building from smallest to largest
- Recursive solution would be inefficient
- Memory is a constraint
- Need predictable performance

## When to Avoid
- Extremely complex state transitions
- Problems with many conditional branches
- When recursive approach is more intuitive
