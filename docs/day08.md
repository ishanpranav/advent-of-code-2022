<!-- day08.md -->
<!-- Licensed under the MIT license. -->

# Day 8: Treetop Tree House

Let matrix $\mathbf{A}=(a_{i,j})$ for $0\leq i\lt m$ and $0\leq j\lt n$.

## Part 1

If $m=0$ or $n=0$, then return $0$.

If $m=1$, then return $n$.

If $n=1$, then return $m$.

Let matrix $\mathbf{B}=(b_{i,j})$ for $0\leq i\lt n$ and $0\leq j\lt m$; assign
$b_{i,j}\leftarrow 0$.

For $i\in(1,\dots,m-2)$:

* let $a^\ast\leftarrow a_{i,0}$;
* for $j\in(1,\dots,n-2)$:
  * if $a_{i,j}\gt a^\ast$, then:
    * assign $a^\ast\leftarrow a_{i,j}$;
    * assign $b_{i,j}\leftarrow 1$.

For $i\in(1,\dots,m-2)$:

* let $a^\ast\leftarrow a_{i,n-1}$;
* for $j\in(n-2,\dots,1)$:
  * if $a_{i,j}\gt a^\ast$, then:
    * assign $a^\ast\leftarrow a_{i,j}$;
    * assign $b_{i,j}\leftarrow 1$.

For $j\in(1,\dots,n-2)$:

* let $a^\ast\leftarrow a_{0,j}$;
* for $i\in(1,\dots,m-2)$:
  * if $a_{i,j}\gt a^\ast$, then:
    * assign $a^\ast\leftarrow a_{i,j}$;
    * assign $b_{i,j}\leftarrow 1$.

For $j\in(1,\dots,n-2)$:

* let $a^\ast\leftarrow a_{m-1,j}$;
* for $i\in(m-2,\dots,1)$:
  * if $a_{i,j}\gt a^\ast$, then:
    * assign $a^\ast\leftarrow a_{i,j}$;
    * assign $b_{i,j}\leftarrow 1$.

Return $\sum_{i=0}^{m-1}\sum_{j=0}^{n-1}b_{i,j}+2m+2n-4$.

## Part 2
