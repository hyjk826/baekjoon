# [Gold II] Marked Ancestor - 22629 

[문제 링크](https://www.acmicpc.net/problem/22629) 

### 성능 요약

메모리: 8320 KB, 시간: 1668 ms

### 분류

자료 구조(data_structures), 분리 집합(disjoint_set), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 오프라인 쿼리(offline_queries)

### 문제 설명

<p>You are given a tree <i>T</i> that consists of <i>N</i> nodes. Each node is numbered from 1 to <i>N</i>, and node 1 is always the root node of <i>T</i>. Consider the following two operations on <i>T</i>:</p>

<ul>
	<li>M v: (Mark) Mark node v.</li>
	<li>Q v: (Query) Print the index of the nearest marked ancestor of node v which is nearest to it. Initially, only the root node is marked. Note that a node is an ancestor of itself.</li>
</ul>

<p>Your job is to write a program that performs a sequence of these operations on a given tree and calculates the value that each Q operation will print. To avoid too large output file, your program is requested to print the sum of the outputs of all query operations. Note that the judges confirmed that it is possible to calculate every output of query operations in a given sequence.</p>

### 입력 

 <p>The first line of the input contains two integers <i>N</i> and <i>Q</i>, which denotes the number of nodes in the tree <i>T</i> and the number of operations, respectively. These numbers meet the following conditions: 1 ≤ <i>N</i> ≤ 100000 and 1 ≤ <i>Q</i> ≤ 100000.</p>

<p>The following <i>N</i> - 1 lines describe the configuration of the tree <i>T</i>. Each line contains a single integer <i>p<sub>i</sub></i> (<i>i</i> = 2, ... , <i>N</i>), which represents the index of the parent of <i>i</i>-th node.</p>

<p>The next <i>Q</i> lines contain operations in order. Each operation is formatted as "M v" or "Q v", where <i>v</i> is the index of a node.</p>

### 출력 

 <p>Print the sum of the outputs of all query operations in one line.</p>

