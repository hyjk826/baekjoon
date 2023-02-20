# [Diamond V] How Many to Be Happy? - 14955 

[문제 링크](https://www.acmicpc.net/problem/14955) 

### 성능 요약

메모리: 2252 KB, 시간: 8 ms

### 분류

최대 유량(flow), 그래프 이론(graphs), 최대 유량 최소 컷 정리(mfmc), 최소 스패닝 트리(mst)

### 문제 설명

<p>Let <em>G</em> be a connected simple undirected graph where each edge has an associated weight. Let’s consider the popular MST (Minimum Spanning Tree) problem. Today, we will see, for each edge <em>e</em>, how much modification on <em>G</em> is needed to make <em>e</em> part of an MST for <em>G</em>. For an edge <em>e</em> in <em>G</em>, there may already exist an MST for <em>G</em> that includes <em>e</em>. In that case, we say that <em>e</em> is <em>happy</em> in <em>G</em> and we define <em>H</em>(<em>e</em>) to be 0. However, it may happen that there is no MST for <em><u>G</u></em> that includes <em>e</em>. In such a case, we say that <em><u>e</u></em> is <em>unhappy</em> in <em>G</em>. We may remove a few of the edges in <em>G</em> to make a <em>connected</em> graph <em>G</em>′ in which <em>e</em> is happy. We define <em>H</em>(<em>e</em>) to be the minimum number of edges to remove from <em>G</em> such that <em>e</em> is happy in the resulting graph <em>G</em>′.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14955/1.png" style="height:238px; width:269px"></p>

<p style="text-align:center">Figure E.1. A complete graph with 3 nodes.</p>

<p>Consider the graph in Figure E.1. There are 3 nodes and 3 edges connecting the nodes. One can easily see that the MST for this graph includes the 2 edges with weights 1 and 2, so the 2 edges are happy in the graph. How to make the edge with weight 3 happy? It is obvious that one can remove any one of the two happy edges to achieve that.</p>

<p>Given a connected simple undirected graph <em>G</em>, your task is to compute <em>H</em>(<em>e</em>) for each edge <em>e</em> in <em>G</em> and print the total sum.</p>

### 입력 

 <p>Your program is to read from standard input. The first line contains two positive integers <em>n</em> and <em>m</em>, respectively, representing the numbers of vertices and edges of the input graph, where <em>n</em> ≤ 100 and <em>m</em> ≤ 500. It is assumed that the graph <em>G</em> has <em>n</em> vertices that are indexed from 1 to <em>n</em>. It is followed by <em>m</em> lines, each contains 3 positive integers <em>u</em>, <em>v</em>, and <em>w</em> that represent an edge of the input graph between vertex <em>u</em> and vertex <em>v</em> with weight <em>w</em>. The weights are given as integers between 1 and 500, inclusive.</p>

### 출력 

 <p>Your program is to write to standard output. The only line should contain an integer <em>S</em>, which is the sum of <em>H</em>(<em>e</em>) where <em>e</em> ranges over all edges in <em>G</em>.</p>

