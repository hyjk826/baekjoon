# [Gold I] Cheapest Palindrome - 6240 

[문제 링크](https://www.acmicpc.net/problem/6240) 

### 성능 요약

메모리: 17860 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>Keeping track of all the cows can be a tricky task so Farmer John has installed a system to automate it. He has installed on each cow an electronic ID tag that the system will read as the cows pass by a scanner. Each ID tag's contents are currently a single string with length M (1 <= M <= 2,000) characters drawn from an alphabet of N (1 <= N <= 26) different symbols (namely, the lower-case roman alphabet).</p>

<p>Cows, being the mischievous creatures they are, sometimes try to spoof the system by walking backwards. While a cow whose ID is "abcba" would read the same no matter which direction the she walks, a cow with the ID "abcb" can potentially register as two different IDs ("abcb" and "bcba").</p>

<p>FJ would like to change the cows's ID tags so they read the same no matter which direction the cow walks by. For example, "abcb" can be changed by adding "a" at the end to form "abcba" so that the ID is palindromic (reads the same forwards and backwards). Some other ways to change the ID to be palindromic are include adding the three letters "bcb" to the begining to yield the ID "bcbabcb" or removing the letter "a" to yield the ID "bcb". One can add or remove characters at any location in the string yielding a string longer or shorter than the original string.</p>

<p>Unfortunately as the ID tags are electronic, each character insertion or deletion has a cost (0 <= cost <= 10,000) which varies depending on exactly which character value to be added or deleted. Given the content of a cow's ID tag and the cost of inserting or deleting each of the alphabet's characters, find the minimum cost to change the ID tag so it satisfies FJ's requirements. An empty ID tag is considered to satisfy the requirements of reading the same forward and backward. Only letters with associated costs can be added to a string.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Line 2: This line contains exactly M characters which constitute the initial ID string</li>
	<li>Lines 3..N+2: Each line contains three space-separated entities: a character of the input alphabet and two integers which are respectively the cost of adding and deleting that character.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single line with a single integer that is the minimum cost to change the given name tag.</li>
</ul>

