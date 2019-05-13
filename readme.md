# 0/1 Knapsack Problem

An dynamic-programming approach.

## Description

A thief robbing a store finds _n_ items.
The _i_ th item is worth _v<sub>i</sub>_ dollars and weights _w<sub>i</sub>_ pounds, where _v<sub>i</sub>_ and _w<sub>i</sub>_ are integers.
The thief wants to take as valuable a load as possible, but he can carry at most _W_ pounds in his knapsack, for some integer W. Which items should he take?

We call this the 0-1 knapsack problem because for each item, the thief must either take it or leave it behind; he cannot take a fractional amount of an item or take an item more than once.

Reference: Chapter 16 Greedy Algorithm, page 425, _Introduction to Algorithms_, Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein 3/e

## Solution

### Recurence Relation

```python
# w[i] = the weight of each item
# v[i] = the value of each item
# c[i][w] = the max value of taking among 0...i item with weight constrain w

# Boundary Conditions
if i = 0 or w = 0
    c[i][w] = 0

if w[i] > w
    c[i][w] = c[i - 1][w]

# Choose to take item i or not
if i > 0 and w[i] < w
    c[i][w] = max(c[i - 1][w], c[i - 1][w - w[i]] + v[i])
```