<!-- day08.md -->
<!-- Licensed under the MIT license. -->

# Day 8: Treetop Tree House

Let
$\mathbf{A} = \begin{bmatrix}a_{0,0} & a_{0,1} & \dots & a_{0,n-1} \\
a_{1,0} & a_{1,1} & \dots & a_{1,n-1} \\
\vdots & \vdots & \ddots & \vdots \\
a_{m-1,0} & a_{m-1,1} & \dots & a_{m-1,n-1}\end{bmatrix}$
where $a_{i,j} \in\lbrace 0,\dots,9\rbrace$.

## Part 1

If $m=0$ or $n=0$, then return $0$.

If $m=1$, then return $n$.

If $n=1$, then return $m$.

Let
$\mathbf{B} = \begin{bmatrix}b_{0,0} & b_{0,1} & \dots & b_{0,n-1} \\
b_{1,0} & b_{1,1} & \dots & b_{1,n-1} \\
\vdots & \vdots & \ddots & \vdots \\
b_{m-1,0} & b_{m-1,1} & \dots & b_{m-1,n-1}\end{bmatrix}$
where $b_{i,j} \in\lbrace 0,1\rbrace$; assign $b_{i,j}\leftarrow 0$.

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

