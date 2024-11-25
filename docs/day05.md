<!-- day05.md -->
<!-- Licensed under the MIT license. -->

# Day 5: Supply Stacks

Let $\ell$ be a list of tuples where for all $e\in\ell$, we have $e=(a,b,c)$ for
$a,b\in\lbrace 0,\dots,n\rbrace$ and $c\in\mathbb{N}$.

## Part A

Let $(S_0,\dots,S_n)$ be a list of $n$ stacks.

For $(a,b,c)\in\ell$:

* for $c$ iterations:
  * let $s\leftarrow$ pop $S_a$;
  * push $s$ onto $S_b$.

Let $m=()$.

For $S\in(S_0,\dots,S_n)$, append top of $S$ to $m$.

Return $m$.

## Part B

Let $(k_0,\dots,k_n)$ be a list of $n$ lists.

For $(a,b,c)\in\ell$:

* let $s\leftarrow$ remove last $c$ elements of $k_a$;
* reverse $s$;
* assign $k_b\leftarrow$ concatenate $k_b,s$.

Let $m=()$.

For $k\in(k_0,\dots,k_n)$, append last element of $k$ to $m$.

Return $m$.
