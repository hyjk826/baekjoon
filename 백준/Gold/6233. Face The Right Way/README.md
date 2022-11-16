# [Gold II] Face The Right Way - 6233 

[문제 링크](https://www.acmicpc.net/problem/6233) 

### 성능 요약

메모리: 2160 KB, 시간: 84 ms

### 분류

누적 합(prefix_sum), 슬라이딩 윈도우(sliding_window)

### 문제 설명

<p>Farmer John has arranged his N (1 <= N <= 5,000) cows in a row and many of them are facing forward, like good cows, Some of them are facing backward, though, and he needs them all to face forward to make his life perfect.</p>

<p>Fortunately, FJ recently bought an automatic cow turning machine. Since he purchased the discount model, it must be irrevocably preset to turn K (1 <= K <= N) cows at once, and it can only turn cows that are all standing next to each other in line. Each time the machine is used, it reverses the facing direction of a contiguous group of K cows in the line (one cannot use it on fewer than K cows, e.g., at the either end of the line of cows). Each cow remains in the same *location* as before, but ends up facing the *opposite direction*.  A cow that starts out facing forward will be turned backward by the machine and vice-versa.</p>

<p>Because FJ must pick a single, never-changing value of K, please help him determine the minimum value of K that minimizes the number of operations required by the machine to make all the cows face forward. Also determine M, the minimum number of machine operations required to get all the cows facing forward using that value of K.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains a single character, F or B, indicating whether cow i is facing forward or backward.</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: Two space-separated integers: K and M</li>
</ul>

