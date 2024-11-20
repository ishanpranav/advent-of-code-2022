<!-- day03.md -->

# Day 3: Rucksack Reorganization

## Part A

Let $(a_1,\dots,a_{2n})$ be a $2n$-element list. Let $p(a_i)$ denote the
priority of element $1\leq i\leq 2n$.

Let $D\leftarrow\{a_i\,|\,1\leq i\leq n\}$.

For $i\in(n,\dots,2n)$:

* if $a_i\in D$, then return $p(a_i)$.
  
## Part B

Let $\ell_0,\ell_1,\ell_2$ be lists. Let $e^*\in \ell_0$, $e^*\in\ell_1$, and
$e^*\in\ell_2$. For $1\leq i\leq 2$, for all $e\in\ell_i$, we have
$e\in\{0,\dots,255\}$. Let $p(e)$ denote the priority of $e\in\{0,\dots,255\}$.

Define $f_e$ for all $e\in\{0,\dots,255\}$.

For $e\in\ell_0$: assign $f_e\leftarrow f_e\text{ bitwise OR }01_2$.

For $e\in\ell_1$: assign $f_e\leftarrow f_e\text{ bitwise OR }10_2$.

For $e\in\ell_2$:

* if $f_e=11_2$, then return $p(e)$.
