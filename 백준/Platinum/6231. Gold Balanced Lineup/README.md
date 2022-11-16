# [Platinum V] Gold Balanced Lineup - 6231 

[문제 링크](https://www.acmicpc.net/problem/6231) 

### 성능 요약

메모리: 26808 KB, 시간: 116 ms

### 분류

자료 구조(data_structures), 해싱(hashing), 해시를 사용한 집합과 맵(hash_set), 누적 합(prefix_sum), 트리를 사용한 집합과 맵(tree_set)

### 문제 설명

<p>Farmer John's N cows (1 <= N <= 100,000) share many similarities. In fact, FJ has been able to narrow down the list of features shared by his cows to a list of only K different features (1 <= K <= 30). For example, cows exhibiting feature #1 might have spots, cows exhibiting feature #2 might prefer C to Pascal, and so on.</p>

<p>FJ has even devised a concise way to describe each cow in terms of its "feature ID", a single K-bit integer whose binary representation tells us the set of features exhibited by the cow. As an example, suppose a cow has feature ID = 13. Since 13 written in binary is 1101, this means our cow exhibits features 1, 3, and 4 (reading right to left), but not feature 2. More generally, we find a 1 in the 2^(i-1) place if a cow exhibits feature i.</p>

<p>Always the sensitive fellow, FJ lined up cows 1..N in a long row and noticed that certain ranges of cows are somewhat "balanced" in terms of the features the exhibit. A contiguous range of cows i..j is balanced if each of the K possible features is exhibited by the same number of cows in the range. FJ is curious as to the size of the largest balanced range of cows. See if you can determine it.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers, N and K.</li>
	<li>Lines 2..N+1: Line i+1 contains a single K-bit integer specifying the features present in cow i.  The least-significant bit of this integer is 1 if the cow exhibits feature #1, and the most-significant bit is 1 if the cow exhibits feature #K.</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer giving the size of the largest contiguous balanced group of cows.</li>
</ul>

