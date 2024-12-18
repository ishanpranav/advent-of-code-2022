<!-- day01.md -->
<!-- Licensed under the MIT license. -->

# Day 1: Calorie Counting

Let $L$ be a set where for all $\ell\in L$, $\ell$ is a list such that for all
$e\in\ell$, we have $e\in\mathbb{N}$.

## Part A

Return
$\underset{\ell\in L}{\max}\left(\sum_{e\in\ell}e\right).$

## Part B

Let $m_0\leftarrow 0$.

Let $m_1\leftarrow 0$.

Let $m_2\leftarrow 0$.

For $\ell\in L$:

* assign $s\leftarrow\sum_{e\in\ell}e$;
* if $s\leq m_2$, then continue to next $\ell$;
* if $s\leq m_1$, then:
  * assign $m_2\leftarrow s$;
  * continue to next $\ell$;
* if $s\leq m_0$, then:
  * assign $m_2\leftarrow m_1$;
  * assign $m_1\leftarrow s$;
  * continue to next $\ell$;
* assign $m_2\leftarrow m_1$;
* assign $m_1\leftarrow m_0$;
* assign $m_0\leftarrow s$.

Return $m_0+m_1+m_2$.
