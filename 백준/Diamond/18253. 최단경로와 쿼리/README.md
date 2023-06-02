# [Diamond III] 최단경로와 쿼리 - 18253 

[문제 링크](https://www.acmicpc.net/problem/18253) 

### 성능 요약

메모리: 20884 KB, 시간: 2824 ms

### 분류

데이크스트라, 분할 정복, 그래프 이론

### 문제 설명

<p>N개의 행과 M개의 열로 이루어진 격자가 있다.</p>

<p>격자의 각 셀에는 가중치가 있다. <em>i</em>행 <em>j</em>열의 가중치를 <em>V<sub>i,j</sub></em>로 표기하자.</p>

<p>다음과 같은 쿼리가 <em>Q</em>개 주어진다:</p>

<ul>
	<li><em>r<sub>1</sub> c<sub>1</sub> r<sub>2</sub> c</em><sub><em>2</em> </sub>: <em>r<sub>1</sub></em>행 <em>c<sub>1</sub></em>열에서 <em>r<sub>2</sub></em>행 <em>c<sub>2</sub></em>열로 가는 경로 중 지나는 셀의 가중치 합의 최솟값을 출력하여라.</li>
</ul>

<p>쿼리에 대한 답을 구해보자.</p>

<p>단, 어떤 셀에서 한 번에 이동할 수 있는 셀은 상하좌우로 인접한 셀이다.</p>

### 입력 

 <p>첫 줄에 두 정수 <em>N</em>(1 ≤ <em>N</em> ≤ 5)과 <em>M</em>(1 ≤ <em>M</em> ≤ 100,000)이 주어진다.</p>

<p><em>i</em>+1(1 ≤ <em>i</em> ≤ <em>N</em>)번째 줄에는 <em>M</em>개의 정수 <em>V<sub>i,1</sub></em>, <em>V<sub>i,2</sub></em>, ..., <em>V<sub>i,M</sub></em> 이 주어진다. (0 ≤ <em>V</em><sub><em>i,j</em> </sub>≤ 1,000,000,000)</p>

<p><em>N</em>+2번째 줄에 쿼리의 수를 나타내는 정수 <em>Q</em>(1 ≤ <em>Q</em> ≤ 100,000)가 주어진다.</p>

<p>이후 <em>Q</em>개의 줄에 걸쳐 쿼리를 나타내는 4개의 정수 <em>r<sub>1</sub></em>, <em>c<sub>1</sub></em>, <em>r<sub>2</sub></em>, <em>c</em><sub><em>2</em> </sub>(1 ≤ <em>r<sub>1</sub></em>, <em>r<sub>2</sub></em><sub> </sub>≤ <em>N</em>, 1 ≤ <em>c<sub>1</sub></em>, <em>c<sub>2</sub></em> ≤ <em>M</em>)가 주어진다.</p>

### 출력 

 <p>쿼리에 대한 답을 한 줄에 하나씩 차례로 출력하여라.</p>

