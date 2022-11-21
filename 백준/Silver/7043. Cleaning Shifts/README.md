# [Silver I] Cleaning Shifts - 7043 

[문제 링크](https://www.acmicpc.net/problem/7043) 

### 성능 요약

메모리: 2488 KB, 시간: 8 ms

### 분류

그리디 알고리즘(greedy), 정렬(sorting)

### 문제 설명

<p>Farmer John is assigning some of his N (1 <= N <= 25,000) cows to do some cleaning chores around the barn. He always wants to have one cow working on cleaning things up and has divided the day into T shifts (1 <= T <= 1,000,000), the first being shift 1 and the last being shift T. </p>

<p>Each cow is only available at some interval of times during the day for work on cleaning. Any cow that is selected for cleaning duty will work for the entirety of her interval. </p>

<p>Your job is to help Farmer John assign some cows to shifts so that (i) every shift has at least one cow assigned to it, and (ii) as few cows as possible are involved in cleaning. If it is not possible to assign a cow to each shift, print -1.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and T </li>
	<li>Lines 2..N+1: Each line contains the start and end times of the interval during which a cow can work. A cow starts work at the start time and finishes after the end time.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The minimum number of cows Farmer John needs to hire or -1 if it is not possible to assign a cow to each shift.</li>
</ul>

