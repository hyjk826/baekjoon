# [Platinum IV] 폰의 각성 - 25960 

[문제 링크](https://www.acmicpc.net/problem/25960) 

### 성능 요약

메모리: 7196 KB, 시간: 140 ms

### 분류

다익스트라(dijkstra), 그래프 이론(graphs), 구현(implementation)

### 문제 설명

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times N$</span></mjx-container> 체스판에서의 전쟁 중 상대 나라의 압도적인 병력탓에 준웅나라에는 폰 병사인 선우 혼자만 남게 되었다. 홀로 남게 된 준웅나라의 폰선우는 이러한 절체절명의 위기 속에서 각성하였다! 각성한 폰선우는 한 턴에 다음과 같은 과정을 수행한다.</p>

<ol>
	<li>초기에 폰선우는 가로, 세로, 대각선 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c38"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>8</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$8$</span></mjx-container>방향으로 한 칸 움직일 수 있다. 한 칸 움직여 킹의 위치로 이동했다면, 턴을 종료한다.</li>
	<li>폰선우가 도달할 수 있는 칸 중 상대 말이 있는 곳을 하나 선택한다. 상대 말이 있는 칸이 하나도 없다면, 선택이 불가능하고 폰선우의 턴은 종료된다.</li>
	<li>폰선우는 선택한 칸으로 이동한다. 선택한 칸에 있던 말은 폰선우에게 능력을 빼앗겨 더 이상 이동할 수 없는 돌이 되고, 폰선우는 빼앗은 이동 방법으로 현재 자신의 이동 방법을 대체한다. 만약, 이동한 위치가 킹의 위치라면 턴을 종료한다. 그렇지 않다면 현 위치에서 2번 과정을 반복한다.</li>
</ol>

<p>폰선우는 이러한 각성 능력을 이용하여 상대 킹을 잡으러 가야 한다. 상대의 말에는 다음과 같은 종류가 있다.</p>

<ul>
	<li>퀸: 가로, 세로, 대각선 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c38"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>8</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$8$</span></mjx-container>방향으로 거리 제한 없이 움직일 수 있다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b8ba226c-7975-48dd-9b6d-440c6c5f0ecf/-/preview/" style="width: 200px; height: 200px;"></p>

<ul>
	<li>룩: 가로, 세로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4$</span></mjx-container>방향으로 거리 제한 없이 움직일 수 있다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/68cd8c2f-3a4b-46b0-8c67-97a28bd73b72/-/preview/" style="height: 201px; width: 200px;"></p>

<ul>
	<li>비숍: 대각선 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4$</span></mjx-container>방향으로 거리 제한 없이 움직일 수 있다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/61ef49d9-7dd2-480c-ae2a-2a91ae1ef5f7/-/preview/" style="height: 201px; width: 200px;"></p>

<ul>
	<li>나이트: 가로, 세로 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c34"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>4</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$4$</span></mjx-container>방향 중 한 방향으로 한 칸, 그리고 그 방향의 양 대각선 방향 중 한 방향으로 한 칸 움직인다. 또한 다른 말을 뛰어넘을 수 있다. 즉, 진행 경로 중간에 장애물이 있어도 체스판을 벗어나지 않는 한 무조건 초록색 칸으로 이동할 수 있다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/760c0550-a5ab-4b01-b0e0-39043feb9719/-/preview/" style="height: 200px; width: 200px;"></p>

<p>대각 이동도 한 칸이라고 친다. 예를 들어 나이트는 상하좌우 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>칸, 대각 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>칸을 이동하기 때문에 무조건 한 번에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2$</span></mjx-container>칸씩 이동한다.</p>

<p>폰선우는 한 번 능력을 빼앗아 돌이 된 말에게서 다시 능력을 빼앗을 수 없다. 폰선우는 현재 능력이 나이트인 경우를 제외하면 다른 말들 및 돌이 된 말을 뛰어넘을 수 없다.</p>

<p>폰선우가 한 턴만에 상대 킹을 잡을 수 있다면, <strong>최소 칸 수</strong>를 이동하여 상대 킹을 잡을 수 있도록 도와주자. 킹을 잡을 수만 있다면, 체스판에 다른 말들이 남아있어도 상관이 없다.</p>

### 입력 

 <p>첫째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>(<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>1</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \le N \le 1\,000$</span></mjx-container>)이 주어진다.</p>

<p>둘째 줄부터는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>줄에 걸쳐 줄마다 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 문자가 공백으로 구분되어 주어진다. 이때 <code>0</code>은 빈칸, <code>Q</code>는 퀸, <code>R</code>는 룩, <code>B</code>는 비숍, <code>N</code>은 나이트, <code>K</code>는 킹, <code>P</code>는 폰선우를 의미한다.</p>

<p>킹과 폰선우는 무조건 한 개 존재하고, 퀸은 왕비로서 최대 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>개만 존재한다.</p>

### 출력 

 <p>첫째 줄에 폰선우가 상대 킹을 한 턴 만에 잡을 수 있다면, 최소 몇 칸을 이동하여 잡을 수 있는지를 출력하고, 한 턴 만에 잡을 수 없다면, <code>-1</code>을 출력한다.</p>

