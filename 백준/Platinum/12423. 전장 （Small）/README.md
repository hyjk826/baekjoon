# [Platinum III] 전장 (Small) - 12423 

[문제 링크](https://www.acmicpc.net/problem/12423) 

### 성능 요약

메모리: 2032 KB, 시간: 4 ms

### 분류

최대 유량, 최소 비용 최대 유량

### 제출 일자

2024년 1월 11일 05:13:36

### 문제 설명

<p>제 3차 세계대전 이후 대부분의 현대 기술은 사라졌으며 적은 수의 사람들만이 살아남았다. 인류는 서서히 복구를 해 나갔으며 새 역사를 만들어 나가기 시작하였다. 수천 년이 지난 새로운 중세 시대에, 김유신 장군은 전장에서 적 장군과 대치하고 있었다.</p>

<p>김유신 장군 휘하에는 <strong>N</strong> 명의 장수들이 있었다. 이 장수 중 <strong>A</strong> 명은 1번 종류의 무장을, <strong>B</strong> 명은 2번 종류의 무장을, <strong>C</strong> 명은 3번 종류의 무장을 하고 있었다. 장수들은 언덕 위에 올라 옆으로 길게 한 줄로 서서 상대의 진지를 바라보고 있었다. 김유신 장군은 막 공격 명령을 내리려던 참이었다.</p>

<p>적 장군에게도 <strong>N</strong> 명의 장수들이 있었다. 이 장수 중 <strong>D</strong> 명은 4번 종류의 무장을, <strong>E</strong> 명은 5번 종류의 무장을, <strong>F</strong> 명은 6번 종류의 무장을 하고 있었다. 이 장수들도 반대편 언덕에 올라 옆으로 길게 한 줄로 섰다. 이들은 김유신 장군의 공격을 막아낼 준비를 하고 있었다.</p>

<p>김유신 장군이 공격 명령을 내리려던 그때, 그는 무언가를 깨달았다. 만약 지금 전투를 한다면, 그의 장수들은 줄을 선 대형대로 상대방 장수들과 만나서 각각 1:1로 싸우게 될 것이었다. 만약 줄을 선 순서를 바꾸어서 상대방 장수의 무장 형태에 맞는 무장 형태를 갖춘 장수들을 배치한다면, 더 좋은 전투 결과를 얻을 수 있게 될거라 생각했다.</p>

<p>당신은 정수 <strong>P<sub>14</sub></strong>, <strong>P<sub>15</sub></strong>, <strong>P<sub>16</sub></strong>, <strong>P<sub>24</sub></strong>, <strong>P<sub>25</sub></strong>, <strong>P<sub>26</sub></strong>, <strong>P<sub>34</sub></strong>, <strong>P<sub>35</sub></strong>, <strong>P<sub>36</sub></strong>을 입력으로 받게 된다. 이 수들은 각 무장 형태의 장수들이 전장에서 만났을 때 전투 결과가 어떻게 되는지를 나타낸다. 예를 들어, <strong>P<sub>14</sub></strong>는 김유신 장군의 종류 1 무장을 갖춘 장수가 적 장군의 종류 4 무장을 갖춘 장수를 만났을 때의 전투 결과를 나타낸다. 양의 정수는 김유신 장군에게 유리한 전투 결과를 나타낸다.</p>

<p>전체 전투 결과는 각각의 전투 결과의 합으로 나타내어진다. 김유신 장군의 보조역을 하는 당신은 김유신 장군의 장수들을 재배열함으로써 이 전투 결과를 최대화하려고 한다. 이 최대 수치를 계산하시오.</p>

### 입력 

 <p>입력의 첫 줄에는 테스트 케이스의 숫자 <strong>T</strong>가 주어진다.<br>
각 테스트 케이스는 다음과 같이 네 줄로 주어진다.</p>

<pre>N A B C D E F
P<sub>14</sub> P<sub>15</sub> P<sub>16</sub>
P<sub>24</sub> P<sub>25</sub> P<sub>26</sub>
P<sub>34</sub> P<sub>35</sub> P<sub>36</sub></pre>

<h3>제한</h3>

<ul>
	<li>모든 수들은 정수이다.</li>
	<li><strong>T</strong> ≤ 1000.</li>
	<li>0 ≤ <strong>A</strong>, <strong>B</strong>, <strong>C</strong>, <strong>D</strong>, <strong>E</strong>, <strong>F</strong> ≤ <strong>N</strong>.</li>
	<li><strong>A</strong> + <strong>B</strong> + <strong>C</strong> = <strong>N</strong>.</li>
	<li><strong>D</strong> + <strong>E</strong> + <strong>F</strong> = <strong>N</strong>.</li>
	<li>-100000 ≤ <strong>P<sub>14</sub></strong>, <strong>P<sub>15</sub></strong>, <strong>P<sub>16</sub></strong>, <strong>P<sub>24</sub></strong>, <strong>P<sub>25</sub></strong>, <strong>P<sub>26</sub></strong>, <strong>P<sub>34</sub></strong>, <strong>P<sub>35</sub></strong>, <strong>P<sub>36</sub></strong> ≤ 100000.</li>
	<li>1 ≤ <strong>N</strong> ≤ 100.</li>
</ul>

### 출력 

 <p>각 테스트 케이스에 대한 출력은 "Case #x: y" 형태로 이루어져야 한다. x는 1부터 시작되는 케이스 번호이고, y는 김유신 장군의 최대의 전투 결과를 점수로 나타낸 것이다.</p>

