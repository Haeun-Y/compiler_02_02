## functions
```
void ComputeHS(int nid, int nfree)
```
* ST[nid]부터 ST[nfree-1]까지의 문자들이 이루는 문자열의 hashcode 값을 계산하는 함수
* [ ] hashcode를 반환할지 결정해야함
* [ ] hashcode 계산 방법 : sum%HTsize vs (sum%HTsize)+1 질문하기
</br>

```
void LookupHS(int nid, int hscode)
```
* ST[nid]부터 시작되는 문자열, 즉 현재 해시테이블에 넣고자하는 문자열과 동일한 문자열이 이미 해시테이블에 존재하는지 확인하는 함수
* [ ] 동일한 문자열이 존재하는지 여부를 담는 변수 found를 전역변수로 처리할지, 반환값으로 처리할지 결정해야함
* [ ] 동일한 문자열이 존재한다면, 해당 문자열의 ST에서의 시작 인덱스를 저장해야함. 전역변수로 처리할지 반환값으로 처리할지 결정해야함
* [ ] 반환한다면, 반환값을 int로 두고 -1(동일한 문자열 존재 x), 0~ (시작인덱스) 
* [ ] 함수내에서 nfree값이 필요한데 파라미터로 받아도 되는지 질문하기 (현재는 함수내에서 직접 계산)
* [ ] ST배열에서 문자의 끝에 '\0'인지, 빈칸인지 확인하기 (현재는 빈칸으로 처리해둠)
* [ ] 함수 새로 만들어도 되는지 질문하기

</br>

## ErrorType
```
enum errorTypes { noerror, illid, overst };
```
</br>

## 역할 분담
* 진주 : SkipSeperators, PrintHStable 함수 작성
* 영경 : PrintError, ReadID 함수 작성
* 하은 : ComputeHS, LookupHS 함수 작성
* 예원 : ADDHT 함수 작성 및 3/20 회의록 작성

</br>

## 과제 일정
* [x] [3/20] 실습1
* [ ] [3/20 ~ 3/23] 역할 분담한 함수 작성
* [ ] [3/23] 메인함수 작성 및 전체 코드 정리
* [ ] [3/27] 실습2 및 과제 제출본 정리



</br>

## 참고
*  대소문자 구분
*  어떤 함수에서 대소문자 구분해야할지 ->  hashcode 계산시
*  에러처리
*  각 함수에서 단계별로 처리된 결과를 그 다음 단계함수에서 어떻게 활용하나?

