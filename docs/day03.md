<!-- day03.md -->
<!-- Licensed under the MIT license. -->

# Day 3: Rucksack Reorganization

## Part A

Let $(a_0,\dots,a_{2n-1})$ be a $2n$-element list. Let
$p:\lbrace a_0,\dots,a_{2n-1}\rbrace\to\mathbb{Z}$.

Let $D\leftarrow\lbrace a_i\,:\,1\leq i\lt n\rbrace$.

For $i\in(n,\dots,2n-1)$:

* if $a_i\in D$, then return $p(a_i)$.

Return $0$.

## Part B

Let $\ell_0,\ell_1,\ell_2$ be lists.

Let $e^\ast\in\ell_0$, $e^\ast\in\ell_1$, and $e^\ast\in\ell_2$.

Let $E\subseteq\mathbb{Z}$. For $0\leq i\leq 2$, for all $e\in\ell_i$, we have
$e\in E$. Let $p:E\to\mathbb{Z}$.

Define $f_e$ for all $e\in E$.

For $e\in\ell_0$: assign $f_e\leftarrow f_e\text{ bitwise OR }01_2$.

For $e\in\ell_1$: assign $f_e\leftarrow f_e\text{ bitwise OR }10_2$.

For $e\in\ell_2$:

* if $f_e=11_2$, then return $p(e)$.
