<!-- day07.md -->

# Day 7: No Space Left on Device

Let $T=(V,E)$ be a tree. Let $L\subseteq V$ denote the set of leaves in $T$. Let $w(v)$ denote
the weight of $v\in L$. Assume, without loss of generality, that
$V=\{1,\dots,|V|\}$.

**Algorithm I.**

Initialize a $|V|$-element array $W[1,\dots,|V|]$.

Initialize a stack $S$.

Let $D\leftarrow\emptyset$.

Let $v\leftarrow v\in V$, arbitrarily.

Push $v$ onto $S$.

While $S$ is not empty, do:

* $v\leftarrow$ pop $v$ off of $S$;
* if $v\in D$, then:
  * if $v\in L$, then assign $W[v]\leftarrow w(v)$;
  * otherwise, assign $W[v]\leftarrow\sum_{\{u,v\}\in E}W[u]$;
* otherwise:
  * for $\{u,v\}\in E$, push $u$ onto $S$;
  * assign $D\leftarrow D\cup\{v\}$.

Return $W$.

## Part A

Let $W$ be the result of Algorithm I.

Let $a\leftarrow 0$.

For $v\in V\setminus L$:

* if $W[v]\geq 10000$, then assign $a\leftarrow a+1$.

Return $a$.
