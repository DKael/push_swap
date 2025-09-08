# push_swap

## 1️⃣ 프로젝트 소개

push_swap은 42서울 커리큘럼의 알고리즘 최적화 과제 중 하나로, 제한된 두 개의 Deque(a, b)과 최소한의 명령어 세트만을 이용해 임의의 수열을 오름차순으로 정렬하는 프로그램입니다.
핵심은 정렬 알고리즘을 구현하는 것뿐 아니라, 주어진 명령어(sa, pb, ra, …)만을 사용하여 연산 횟수를 최소화하는 전략을 세우는 것입니다.

---

## 2️⃣ 과제 목표
	•	단순한 정렬 알고리즘 구현이 아닌, 제한된 환경에서의 최적화 문제 해결.
	•	최대 500개의 임의의 정수에 대해, 가능한 한 적은 연산 횟수로 정렬하는 전략 수립.
	•	자료구조(덱, 연결 리스트) 및 알고리즘(quick sort, greedy, radix sort, etc..) 활용 능력 강화.
	•	Bonus 파트에서는 checker 프로그램을 제작하여, push_swap의 출력 명령어가 실제로 올바른 정렬을 수행하는지 검증.

---

## 3️⃣ 구현 사항
* 덱 자료구조: 배열과 연결 리스트 기반으로 덱을 직접 구현.
* 기본 명령어 구현: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.
* 정렬 전략:
  - Quick Sort 기반 분할: 피벗을 설정해 스택을 재귀적으로 분할. 수 목록을 3중으로 분할(아래 영상에서 색을 보고 3중 분할이 되는 것을 확인 가능). 그 후 Greedy 알고리즘 적용.
  - Greedy 접근: 각 단계에서 가장 적은 이동 횟수로 원하는 위치에 원소를 삽입하도록 최적화.
  - 두 방식을 결합하여, 빠른 분할 + 효율적인 삽입을 동시에 달성.
* 최적화 포인트:
  - 작은 수열(3개 이하)에 대해서는 하드코딩된 최적 전략 사용.
  - 중복 연산 제거 및 불필요한 스왑 최소화.
  - 명령어 합치기(ra + rb → rr) 등 최적화 처리.
* Bonus:
  - checker 프로그램 구현 → push_swap이 출력한 명령어 시퀀스를 입력으로 받아 실제 정렬이 올바른지 확인.
  - 잘못된 명령어 처리, 정렬 실패 여부(OK/KO) 반환.

---

## 4️⃣ 배운 점
	•	단순 구현을 넘어 연산 최적화의 중요성을 이해.
	•	제한된 명령어 세트 내에서 알고리즘 설계와 자료구조 최적화를 동시에 고민.
	•	Quick Sort의 분할정복 전략과, Greedy의 지역 최적 선택을 조합하여 실제 성능 개선 효과 확인.
	•	시간 복잡도와 공간 복잡도를 모두 고려한 설계 습관.
	•	bonus checker 제작을 통해 테스트 자동화의 중요성 경험.

---

## 5️⃣ 정렬 과정 영상
### case 100
https://github.com/user-attachments/assets/6350f373-ef84-4cb3-8dfb-1c8138298b93

### case 500
https://github.com/user-attachments/assets/2f4a643e-0363-4b54-9b6e-2fb46f35cef2

---

## 6️⃣ 사용 방법

### 빌드

bash
```
make        # push_swap 실행 파일 생성
make bonus  # checker 생성
```

### 실행

bash
```
./push_swap 3 2 1
# → 최소한의 명령어 시퀀스를 출력
```

### 검증

bash
```
./push_swap 3 2 1 | ./checker 3 2 1
# → OK / KO 반환
```
---

## 7️⃣ 기술 스택
	•	언어: C
	•	알고리즘: Quick Sort + Greedy Hybrid, Hard-coded small sort
	•	자료구조: Stack (배열/연결 리스트), Doubly Linked List
	•	빌드 도구: Makefile
	•	테스트 도구: 자체 checker 프로그램

 ## 8️⃣ 참고 사항
 push_swap visualizer: https://github.com/Niimphu/push_swap_visualiser
