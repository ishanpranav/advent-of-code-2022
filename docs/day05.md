<!-- day05.md -->
<!-- Licensed under the MIT license. -->

# Day 5: Supply Stacks

Let $(S_0,\dots,S_n)$ be a list of $n$ stacks and $\ell$ be a list of tuples
where for all $e\in\ell$, we have $e=(a,b,c)$ for
$a,b\in\lbrace 0,\dots,n\rbrace$ and $c\in\mathbb{N}$.

## Part A

For $(a,b,c)\in\ell$:

* for $c$ iterations:
  * let $s\leftarrow$ pop $S_a$;
  * push $s$ onto $S_b$.

Let $m=()$.

For $S\in(S_0,\dots,S_n)$:

* let $s\leftarrow$ top of $S$;
* append $s$ to $m$.

Return $m$.

## Part B

For $(a,b,c)\in\ell$:

* let $S$ be an empty stack;
* for $c$ iterations:
  * let $s\leftarrow$ pop $S_a$;
  * push $s$ onto $S$;
* for $c$ iterations:
  * let $s\leftarrow$ pop $S$;
  * push $s$ onto $S_b$.

Let $m=()$.

For $S\in(S_0,\dots,S_n)$:

* let $s\leftarrow$ top of $S$;
* append $s$ to $m$.

Return $m$.
