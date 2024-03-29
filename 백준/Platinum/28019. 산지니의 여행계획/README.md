# [Platinum V] 산지니의 여행계획 - 28019 

[문제 링크](https://www.acmicpc.net/problem/28019) 

### 성능 요약

메모리: 17356 KB, 시간: 372 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 그리디 알고리즘, 최소 스패닝 트리

### 문제 설명

<p>산지니가 여행 계획을 짜려고 한다.</p>

<p>렌터카 서비스를 이용하여 $N$개의 도시를 모두 방문할 계획인 산지니는 지도에서 가려고 하는 도시 간의 직통 도로들을 살펴본다.</p>

<p>운전대를 잡아야 하는 산지니는 기억력이 좋지 않아 최대한 직통 도로를 적게 선택하면서도, 여러 풍경을 차 안에서 느긋이 즐기고 싶기에 선택한 도로 길이의 합이 최대가 되기를 원한다.</p>

<p>산지니와 같이 여행하게 된 당신은 산지니의 의견을 반영하여 이용할 도로를 선택하고, 그 도로를 토대로 이동 경로를 대신 짜주려 한다.</p>

<p>모든 도시에는 이용하고자 하는 렌터카 서비스가 있어, 마지막 도시를 방문하면 시작 도시로 돌아가지 않고 그 도시에서 차량을 반납하기로 하였다.</p>

<p>여행을 시작할 도시는 산지니가 정해두었다. 최적의 경로를 구하여 운전 거리를 최대한 줄여보자.</p>

### 입력 

 <p>첫 줄에는 방문할 도시의 수 $N$과 이 도시들 사이를 연결하는 직통 도로의 수 $M$이 주어진다. $(2\leq N\leq 50\,000,N-1\leq M\leq 1\,000\,000)$</p>

<p>각 도시는 1부터 $N$사이의 서로 다른 번호로 구분된다. 모든 도시는 연결되어 있다.</p>

<p>다음 $M$개의 줄에는 길에 대한 정보를 의미하는 세 정수 $a, b, c$가 입력되는데 이는 $a$번 도시와 $b$번 도시 사이를 연결 짓는 직통 도로의 길이가 $c$ 임을 의미한다. $a$와 $b$는 서로 다른 수이다. 모든 직통 도로의 길이는 서로 다르며, 양방향 도로이다. 방문할 도시 간의 직통 도로가 아닌 도로는 주어지지 않는다. $(1\leq a,b\leq N,1\leq c\leq 1\,000\,000)$</p>

<p>다음 줄에는 산지니가 선택한 시작 도시의 번호가 주어진다. 입력으로 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>첫 줄에 여행을 완료하기 위한 최소 운전 거리를 출력한다.</p>

