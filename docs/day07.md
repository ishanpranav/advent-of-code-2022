<!-- day07.md -->
<!-- Licensed under the MIT license. -->

# Day 7: No Space Left on Device

Let $T=(V,E)$ be a directed tree.

Let $L\subseteq V$ denote the set of leaves in $T$. Let $w^\ast:L\to\mathbb{N}$.

Let $s\in V$.

**Algorithm I.**

Define $w_v$ for $v\in V$.

Let $S$ be an empty stack.

Let $D\leftarrow\emptyset$.

Push $s$ onto $S$.

While $S$ is not empty:

* let $u\leftarrow$ top of $S$;
* if $u\in D$, then:
  * if $u\in L$, then assign $w_u\leftarrow w^\ast(u)$;
  * otherwise, assign $w_u\leftarrow\sum_{(u,v)\in E}w_v$;
  * pop $S$;
* otherwise:
  * for $(u,v)\in E$, push $v$ onto $S$;
  * assign $D\leftarrow D\cup\lbrace u\rbrace$.

Return $w_v$ for $v\in V$.

## Part A

Let $w_v$ for $v\in V$ be given by Algorithm I.

Let $V'=\lbrace v\,:\, v\in V,v\notin L, w_v\leq 100000\rbrace$.

Return $\sum_{v\in V'}{w_v}$.

## Part B

Let $w_v$ for $v\in V$ be given by Algorithm I.

Let $V'=\lbrace v:v\in V,v\notin L,70000000-(w_s-w_v)\geq 30000000\rbrace$.

Return $\underset{v\in V'}{\min}(w_v)$.
