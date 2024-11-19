<!-- day04.md -->

# Day 4: Camp Cleanup

Let $\ell$ be a list where for all $((a_0,a_1),(b_0,b_1))\in\ell$, we have
$a_0,a_1,b_0,b_1\in\mathbb{N}$.

## Part A

Let $n\leftarrow 0$.

For $((a_0,a_1),(b_0,b_1))\in\ell$:

* if ($a_0\leq b_0$ and $b_1\leq a_1$) or ($b_0\leq a_0$ and $a_1\leq b_1$), then $n\leftarrow n+1$.

Return $n$.

## Part B

Let $n\leftarrow 0$.

For $((a_0,a_1),(b_0,b_1))\in\ell$:

* if ($b_0\leq a_0\leq b_1$) or ($b_0\leq a_1\leq b_1$) or ($a_0\leq b_0\leq a_1$) or ($a_0\leq b_1\leq a_1$), then $n\leftarrow n+1$.

Return $n$.
