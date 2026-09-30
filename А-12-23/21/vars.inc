; Параметры варианта А-12, M=21 (ТЗ 2026). Сгенерировано mpsgen — не править руками.

VAR_M        EQU 21            ; номер варианта
VAR_G        EQU 12            ; номер группы
Y2_CONST     EQU 33            ; G+M: Y2 = (Y2_CONST + X1 + X2) mod 256

; --- адреса внешних устройств (movx) ---
ADR_IND      EQU 0C000h        ; индикатор, CS Y6
ADR_KB       EQU 2000h        ; клавиатура: запись столбцов / чтение строк, CS Y1
ADR_Y2       EQU 0E000h        ; регистр Y2, CS Y7
BUF_START    EQU 0A000h        ; первая ячейка буфера, CS Y5
BUF_END      EQU 0A716h        ; первая ячейка ЗА буфером (точка заворота)
BUF_SIZE     EQU 1814

; --- внутреннее ОЗУ ---
HEAD_L       EQU 47h          ; «голова», младший байт
HEAD_H       EQU 48h          ; «голова», старший байт
TAIL_L       EQU 49h          ; «хвост», младший байт
TAIL_H       EQU 4Ah          ; «хвост», старший байт
F_EMPTY      BIT 15h          ; флаг пустоты буфера (22h.5)
F_OVF        BIT 21h          ; флаг переполнения буфера (24h.1)

; --- выводы ---
PIN_Y1       BIT P1.0         ; строб Y1, активный 0
PIN_Y2       BIT P1.1         ; строб Y2, активный 0
PIN_CSEN     BIT P3.4         ; CS_EN: разрешение дешифратора CS (1 — CS активны)

; --- таймеры (кварц 12 МГц) ---
T2_RELOAD_H  EQU 0F6h          ; строб Y2 2542 мкс, Timer1
T2_RELOAD_L  EQU 12h
TICK_H       EQU 0FCh          ; тик 1 мс для Y1/T3, Timer0
TICK_L       EQU 18h
Y1_TICKS     EQU 401           ; T1 = 401 мс
T3_TICKS     EQU 3390          ; T3 = 3390 мс
