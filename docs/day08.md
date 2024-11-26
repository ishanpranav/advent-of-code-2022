<!-- day08.md -->
<!-- Licensed under the MIT license. -->

# Day 8: Treetop Tree House

Let $\mathbf{A}=(a_{i,j})$ be a matrix for $0\leq i\lt m$ and $0\leq j\lt n$,
where $a_{i,j}\in\lbrace 0,\dots,9\rbrace$.

## Part 1

If $m=0$ or $n=0$, then return $0$.

If $m=1$, then return $n$.

If $n=1$, then return $m$.

Let $\mathbf{B}=(b_{i,j})$ be a matrix for $0\leq i\lt m$ and $0\leq j\lt n$;
assign $b_{i,j}\leftarrow 0$.

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

Let $\mathbf{B}=(b_{i,j})$ be a matrix for $0\leq i\lt m$ and $0\leq j\lt n$; assign $b_{i,j}\leftarrow 1$.

For $i\in(0,\dots,m-1)$:

* let $k_x\leftarrow 0$ for $x\in\lbrace 0,\dots,9\rbrace$;
* for $j\in(0,\dots,n-1)$:
  * let $j^\ast\leftarrow\underset{x\in\lbrace a_{i,j},\dots,9\rbrace}{\max}(k_x)$;
  * assign $b_{i,j}\leftarrow b_{i,j}\times(j-j^\ast)$;
  * assign $k_{a_{i,j}}\leftarrow j$.

For $i\in(0,\dots,m-1)$:

* let $k_x\leftarrow n-1$ for $x\in\lbrace 0,\dots,9\rbrace$;
* for $j\in(n-1,\dots,0)$:
  * let $j^\ast\leftarrow\underset{x\in\lbrace a_{i,j},\dots,9\rbrace}{\min}(k_x)$;
  * assign $b_{i,j}\leftarrow b_{i,j}\times(j^\ast-j)$;
  * assign $k_{a_{i,j}}\leftarrow j$.

For $j\in(0,\dots,n-1)$:

* let $k_x\leftarrow 0$ for $x\in\lbrace 0,\dots,9\rbrace$;
* for $i\in(0,\dots,m-1)$:
  * let $i^\ast\leftarrow\underset{x\in\lbrace a_{i,j},\dots,9\rbrace}{\max}(k_x)$;
  * assign $b_{i,j}\leftarrow b_{i,j}\times(i-i^\ast)$;
  * assign $k_{a_{i,j}}\leftarrow i$.

For $j\in(0,\dots,n-1)$:

* let $k_x\leftarrow m-1$ for $x\in\lbrace 0,\dots,9\rbrace$;
* for $i\in(m-1,\dots,0)$:
  * let $i^\ast\leftarrow\underset{x\in\lbrace a_{i,j},\dots,9\rbrace}{\min}(k_x)$;
  * assign $b_{i,j}\leftarrow b_{i,j}\times(i-i^\ast)$;
  * assign $k_{a_{i,j}}\leftarrow i$.

Return $\underset{0\leq i\lt m}{\max}\left(\underset{0\leq j\lt n}{\max}\left(b_{i,j}\right)\right)$.
