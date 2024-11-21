<!-- day07.md -->
<!-- Licensed under the MIT license. -->

# Day 7: No Space Left on Device

Let $T=(V,E)$ be a tree. Let $L\subseteq V$ denote the set of leaves in $T$.
Let $w^\ast:L\to\mathbb{Z}$.

**Algorithm I.**

If $V=\emptyset$, return nothing.

Define $w_v$ for $v\in V$.

Initialize a stack $S$.

Let $D\leftarrow\emptyset$.

Let $v\leftarrow v\in V$, arbitrarily.

Push $v$ onto $S$.

While $S$ is not empty, do:

* $v\leftarrow$ top of $S$;
* if $v\in D$, then:
  * if $v\in L$, then assign $w_v\leftarrow w^\ast(v)$;
  * otherwise, assign $w_v\leftarrow\underset{\lbrace u,v\rbrace\in E}{\sum}w_u$;
  * pop $S$;
* otherwise:
  * for $\lbrace u,v\rbrace\in E$, push $u$ onto $S$;
  * assign $D\leftarrow D\cup\lbrace v\rbrace$.

Return $w_v$ for $v\in V$.

## Part A

Let $w_v$ for $v\in V$ be given by Algorithm I.

Let $V'=\lbrace v\,:\, v\in V,v\notin L, w_v\leq 100000\rbrace$.

Return $\underset{v\in V'}{\sum}{v}$.