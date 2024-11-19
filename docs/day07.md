<!-- day07.md -->

# Day 7: No Space Left on Device

Let $T=(V,E)$ be a tree. For $v\in V$, if $v$ is a leaf, then let $w(v)$ denote the weight of leaf $v$. Assume, without loss of generality, that $V=\{1,\dots,|V|\}$. 

Let $W[1,\dots,|V|]$ be a $|V|$-element array, where $W[v]=w(v)$ for all leaves $v\in V$.

Let $D[1,\dots|V|]$ be a $|V|$-element array, where $D[v]\in\{\verb|true|,\verb|false|\}$ for all vertices $v\in V$.

Let $S$ be a stack.

For all $v\in V$, let $D[v]\leftarrow\verb|false|.$

Let $v\leftarrow v\in V$, arbitrarily.

Push $v$ onto $S$.

While $S$ is not empty, do:

* $v\leftarrow$ pop $v$ off of $S$;
* if $D[v]$, then continue to next;
* assign $D[v]\leftarrow\verb|true|$;
* for $\{u,v\}\in E$, push $u$ onto $S$.
