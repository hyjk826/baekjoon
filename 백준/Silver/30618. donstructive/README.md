# [Silver IV] donstructive - 30618 

[문제 링크](https://www.acmicpc.net/problem/30618) 

### 성능 요약

메모리: 2944 KB, 시간: 20 ms

### 분류

해 구성하기

### 제출 일자

2023년 11월 17일 16:41:27

### 문제 설명

<p><strong>순열</strong>은 $1$부터 $N$까지 $N$개의 정수가 각각 한 번씩 나오는 수열이다. 예를 들어, $[1]$, $[3, 5, 2, 1, 4]$, $[1, 3, 2]$는 순열이지만, $[2, 3, 2]$, $[4, 3, 1]$, $[0]$은 순열이 아니다.</p>

<p>순열의 점수는 다음과 같은 방법으로 구한다.</p>

<ol>
	<li>순열의 모든 연속 부분 수열 각각에 대해 원소의 합을 구한다.</li>
	<li>순열의 점수는 (1)에서 구한 모든 값의 합이다.</li>
</ol>

<p>길이가 $N$인 모든 순열 중에서 점수가 가장 높은 순열을 구해보자. 점수가 가장 높은 순열이 여러 가지라면 그 중 아무거나 하나를 출력한다.</p>

### 입력 

 <p>첫째 줄에 구하고자 하는 순열의 길이 $N$이 주어진다. $(1 \le N \le 200\,000)$</p>

### 출력 

 <p>첫째 줄에 점수가 가장 높은 순열에 해당하는 $N$개의 정수를 공백으로 구분해서 출력한다.</p>

