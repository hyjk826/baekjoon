# [Gold V] 양과 늑대 - 25907 

[문제 링크](https://www.acmicpc.net/problem/25907) 

### 성능 요약

메모리: 14984 KB, 시간: 12 ms

### 분류

이분 탐색(binary_search), 매개 변수 탐색(parametric_search)

### 문제 설명

<p>총 $N$일 동안 빈 회의장에 늑대와 양이 모이기로 했다. 첫 번째 날부터 $N$ 번째 날까지 매일 양 또는 늑대 한 마리가 회의장에 도착한다.</p>

<p><strong>첫 번째 날에는 항상 양이 도착하고 마지막 날에는 항상 늑대의 수가 양의 수보다 많다.</strong></p>

<p>늑대와 양의 수가 같아지면 늑대가 양을 잡아먹을 수도 있어 늑대와 양의 수가 같아지는 모든 날에 회의장에 무지가 출근하게 된다. 무지의 친구인 당신은 무지가 출근하는 날을 알고 싶다. 무지가 언제 출근하는 지 알기 위해 시스템에 특정한 날에 회의장에 있는 양의 수를 물어보고자 한다. 최대 $20$번의 질의를 통해 무지가 출근하는 날을 아무 날이나 하나 출력한다. 만약 그러한 날이 없는 경우 <code>! 0</code>을 출력한다.</p>

<p><strong>시스템은 여러분의 질문에 따라 특정 날에 도착한 동물의 정보를 바꾸지 않는다. 즉, 이전까지의 답변들과 모순되는 답변은 하지 않는다.</strong></p>

### 입력 

 <p>입력의 첫 줄에 정수 $N$이 주어진다. $\left( 3 \le N \le 100\,000\right)$</p>

### 출력 

 <p>다음을 표준 출력 스트림(stdout)으로 한 줄에 출력하여,$i$번째 날에 회의장에 있는 양의 수를 질의할 수 있다. 질의에 대한 답변은 정수로 주어진다.</p>

<ul>
	<li> <code><span style="color:#e74c3c;">?</span> i</code> : $i$번째 날 회의장에 있는 양의 수$\left(1 \le i \le N\right)$</li>
</ul>

<p>각 질문을 출력한 후에는 반드시 표준 출력 버퍼를 flush 해야 하고, 표준 입력 스트림(stdin)을 통해 질문에 대한 답을 입력받아야 한다. 그렇지 않으면, <span style="color:#e74c3c;">시간 초과 </span>또는 <u>런타임에러</u>를 받는다.</p>

<p>질문하는 $i$의 범위가 날짜 구간을 벗어나는 경우, <span style="color:#e74c3c;">틀렸습니다</span>를 받는다.</p>

<p>질문은 최대 $20$번만 할 수 있고, 이보다 더 많이 질문을 하면 <span style="color:#e74c3c;">틀렸습니다</span>를 받는다.</p>

<p>최대 $20$번의 질문을 이용해, 정답을 아래의 표준 출력 스트림(stdout)을 이용해 한 번만 출력한다.</p>

<ul>
	<li><span style="color:#e74c3c;"> </span><code><span style="color:#e74c3c;">!</span> T</code> $\left( 0 \le T \le N\right)$</li>
</ul>

<p>그 후 반드시 표준 출력 버퍼를 flush해야 하고, 프로그램을 종료한다. 이것은 질문 횟수에 포함되지 않는다.</p>

<p>언어 별로 표준 출력 버퍼를 flush하는 방법은 다음과 같다.</p>

<ul>
	<li> C: <code>fflush(stdout)</code></li>
	<li> C++: <code>std::cout << std::flush</code></li>
	<li> Java: <code>System.out.flush()</code></li>
	<li> Python: <code>sys.stdout.flush()</code></li>
</ul>

