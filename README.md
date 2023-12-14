# algorithm-basic

<details>
<summary> 기초 코드 작성요령 </summary>

* O(1) < O(logN) < O(N) < O(NlogN) < O(N^2) < O(2^n) < O(N!)

* 항상 타입 범위에 맞게 사용 (Integer Overflow)

* 실수는 저장/연산 과정에서 반드시 오차가 발생

* 실수를 비교할 때는 등호를 사용하면 안됨

* 배열은 주소값을 넘겨 원본에 영향을 줄 수 있지만 , 구조체와 STL(vector 등) 또한 함수 인자로 사용 시 값 복사가 일어나 원본에 영향 없음

* 공백이 포함된 문자열을 받으려면 scanf, cin을 사용하지 말 것. 아래 구문 사용
```bash
string s;
getline(cin, s);
cout << s;
```

* cout/cin 사용 시 아래 세 줄 작성할 것
```bash
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

* 줄 바꿈 시 endl 사용하지 말 것. 차라리 개행 문자를 사용

* 출력 맨 마지막에 공백 혹은 줄바꿈이 추가로 있어도 정답 처리
  
</details>

<details>
<summary> 목차 </summary>

``` bash
0x00강 - 오리엔테이션
0x01강 - 기초 코드 작성 요령 I
0x02강 - 기초 코드 작성 요령 II
0x03강 - 배열
0x04강 - 연결 리스트
0x05강 - 스택
0x06강 - 큐
0x07강 - 덱
0x08강 - 스택의 활용(수식의 괄호 쌍)
0x09강 - BFS
0x0A강 - DFS
0x0B강 - 재귀
0x0C강 - 백트래킹
0x0D강 - 시뮬레이션
0x0E강 - 정렬 I
0x0F강 - 정렬 II
0x10강 - 다이나믹 프로그래밍
0x11강 - 그리디
0x12강 - 수학
0x13강 - 이분탐색
0x14강 - 투 포인터
0x15강 - 해시
0x16강 - 이진 검색 트리
0x17강 - 우선순위 큐
0x18강 - 그래프
0x19강 - 트리
0x1A강 - 위상정렬
0x1B강 - 최소 신장 트리
0x1C강 - 플로이드 알고리즘
0x1D강 - 다익스트라 알고리즘
0x1E강 - KMP 알고리즘 
0x1F강 - 트라이
부록 A - 문자열 기초
부록 B - 동적 배열
부록 C - 비트마스킹
부록 D - Union Find
부록 E - 다이나믹 프로그래밍 심화
```

</details>

</details>

<details>
<summary> 출처 </summary>

blog: https://blog.encrypted.gg/

github: https://github.com/encrypted-def

youtube: https://www.youtube.com/@BaaaaaaaaaaaaaaaaaaaaarkingDog

</details>



