<!-- day06.md -->

# Day 6: Tuning Trouble

Let $\ell$ be a list where for all $e\in\ell$, we have $e\in\mathbb{Z}$.

**Algorithm I with argument $k\in\mathbb{N}$.**

Let $n\leftarrow 0$.

Let $i\leftarrow 0$.

Let $D\leftarrow\emptyset$.

For $e\in\ell$:

* if $e\in D$, then:
  * assign $i\leftarrow i-(n-1)$;
  * assign $n\leftarrow 0$;
  * assign $D\leftarrow\emptyset$;
* assign $D\leftarrow D\cup\{e\}$;
* assign $n\leftarrow n+1$;
* assign $i\leftarrow i+1$;
* if $n=4$, then return $i$.

Return $+\infty$.

## Part A

Perform Algorithm I with argument $k=4$.

## Part B

Perform Algorithm I with argument $k=14$.
