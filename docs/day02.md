<!-- day01.md -->

# Day 2: Rock, Paper, Scissors

## Part A

Let $S=\{1,2,3\}$. Let $\ell$ be a list where for all $(s_0,s_1)\in\ell$ we
have $(s_0,s_1)\in S\times S$.

Let $a\leftarrow 0$.

For $(s_0,s_1)\in\ell$:

* assign $a\leftarrow a+s_1$;
* if $s_0=s_1$, then:
  * assign $a\leftarrow a+3$;
  * continue to next $(s_0,s_1)$;
* if ($s_0=1$ and $s_1=2$) or ($s_0=2$ and $s_1=3$) or ($s_0=3$ and $s_1=1$), then $a\leftarrow a+6$.

Return $a$.

## Part B

Let $S=\{1,2,3\}$. Let $T=\{0,3,6\}$. Let $\ell$ be a list where for all
$(s,t)\in\ell$ we have $(s,t)\in S\times T$.

Let $a\leftarrow 0$.

For $(s,t)\in\ell$:

* assign $a\leftarrow a+t$;
* consider $t=0$, then:
  * assign $a\leftarrow a+(\text{ if }s=1\text{ then }3\text{; otherwise }s-1)$;
* consider, $t=3$, then:
  * assign $a\leftarrow a+s$;
* consider $t=6$, then:
  * assign $a\leftarrow a+(\text{ if }s=3\text{ then }1\text{; otherwise }s+1)$;
  
Return $a$.
