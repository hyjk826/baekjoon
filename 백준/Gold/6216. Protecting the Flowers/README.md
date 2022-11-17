# [Gold II] Protecting the Flowers - 6216 

[문제 링크](https://www.acmicpc.net/problem/6216) 

### 성능 요약

메모리: 2808 KB, 시간: 16 ms

### 분류

그리디 알고리즘(greedy), 수학(math), 정렬(sorting)

### 문제 설명

<p>Farmer John went to cut some wood and left N (2 <= N <= 100,000) cows eating the grass, as usual. When he returned, he found to his horror that the cluster of cows was in his garden eating his beautiful flowers. Wanting to minimize the subsequent damage, FJ decided to take immediate action and transport each cow back to its own barn.</p>

<p>Each cow i is at a location that is Ti minutes (1 <= Ti <= 2,000,000) away from its own barn. Furthermore, while waiting for transport, she destroys Di (1 <= Di <= 100) flowers per minute. No matter how hard he tries, FJ can only transport one cow at a time back to her barn. Moving cow i to its barn requires 2*Ti minutes (Ti to get there and Ti to return). FJ starts at the flower patch, transports the cow to its barn, and then walks back to the flowers, taking no extra time to get to the next cow that needs transport.</p>

<p>Write a program to determine the order in which FJ should pick up the cows so that the total number of flowers destroyed is minimized.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer N</li>
	<li>Lines 2..N+1: Each line contains two space-separated integers, Ti and Di, that describe a single cow's characteristics</li>
</ul>

<p> </p>

### 출력 

 <p>Line 1: A single integer that is the minimum number of destroyed flowers</p>

