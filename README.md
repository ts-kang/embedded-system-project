embedded-system-project
=======================

Summary
-------
청기 백기 게임을 변형한 게임.
깃발 개수가 3개로 늘어남 -> RGB(빨강, 초록, 파랑) 깃발

- Text LCD로 랜덤하게 문제 표시
- Push Switch로 R,G,B 올리고, 가만히, 내리고 구현
- FND(Seven-segment Display)로 남은 시간 알림
- Dip Switch로 사용할 깃발 선택, 시간 제한 3단계 난이도 조절
- 성공하면 Pi Camera로 사진 찍고, LED, Dot Matrix로 애니메이션 출력
- 실패하면 Buzzer로 알림, Step Motor 돌리기

Directory Hierarchy
-------------------
```
/devices			FPGA 장치 제어 코드
  /buzzer	       		Buzzer 장치 제어 코드
  /camera	       		Pi Camera 장치 제어 코드
  /dip_switch			Dip Switch 장치 제어 코드
  /dot_matrix			Dot Matrix 장치 제어 코드
  /fnd				FND 장치 제어 코드
  /led				LED 장치 제어 코드
  /push_switch			Push Switch 장치 제어 코드
  /step_motor			Step Motor 장치 제어 코드
  /text_lcd			Text LCD 장치 제어 코드
/drivers			FPGA 장치 드라이버
  /fpga_push_switch		Push Switch 장치 드라이버
/main				게임 코드
/include			헤더 파일
/scripts			빌드 관련 스크립트
```
