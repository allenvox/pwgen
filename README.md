# Password Generator (pawg)

## Техническое задание<br>

 1. **Функциональность**<br>

 Реализуемый продукт — генератор паролей для терминала *(командной строки)*. Используется для создания устойчивых ко взлому паролей, опции к которым можно задать в аргументах к программе. С помощью аргументов можно задать длину паролей в символах, получить разное их количество. Пароли могут быть состоящими как непосредственно из цифр и букв латинского алфавита, так и с использованием специальных символов *(!, $, %, & и т.д.)*.
<br><br><br>**Сценарии использования (примеры):**<br>

*Генерация одного пароля стандартной длины (8) со стандартными опциями:* <br>
```
$ pawg
akbspiun
```
<br>*Генерация трёх паролей длиной в 10 символов со стандартными опциями:* <br>
```
$ pawg 3 10
aslkrjnabs fajvmmcnal dffjasjwfg
```
<br>*Генерация пяти паролей длиной в 5 символов с хотя бы одной цифрой и заглавной буквой, вывод результата в столбик:* <br>
```
$ pawg 5 5 -с -n -1
1H9fA
j4cNA
3D9ja
LA01B
kK5aq
```
<br>*Генерация трёх паролей длиной в 5 символов, основанных на хешировании строки *hello*, вывод в столбик:* <br>
```
$ pawg 3 5 -1 -sha1 hello
aaf4c
9cf5c
1eec5
```
<br>*Генерация одного пароля длиной в 10 символов, используя спецсимволы и цифры:* <br>
```
$ pawg 1 10 -y -n
aa2jk&js1!
```
 2. **Формат входных данных** <br>
 
    `$  pawg [N] [length] [args]` <br>
*N* — количество генерируемых паролей <br>
*length* — длина пароля <br>
*args* — аргументы командной строки <br> <br>

3. **Интерфейс** <br>
Программа является приложением для терминала (командной строки), соответственно никакого графического интерфейса не требует. <br> <br>


4. **Аргументы командной строки** <br>


| Аргумент | Расшифровка     | Назначение                                                                                                                                    |
|----------|-----------------|-----------------------------------------------------------------------------------------------------------------------------------------------|
| -h       | help            | Вывести справку и помощь по программе                                                                                                         |
| -c       | capitalize      | Включить в пароль хотя бы одну букву верхнего регистра                                                                                        |
| -n       | numbers         | Включить в пароль хотя бы одну цифру                                                                                                          |
| -1       | one column      | Вывести пароли в один столбец                                                                                                                 |
| -v       | vowels          | Не включать в пароль гласные буквы                                                                                                            |
| -y       | special symbols | Включить в пароль хотя бы один специальный символ                                                                                             |
| -s       | secure          | Сгенерировать хаотичный пароль со всеми возможными символами *(алиас флагов -n -y -c)*                                                        |
|-H *(-sha1)*| SHA-1 Hash    | Использовать хеш SHA-1 заданного сида *(строки)* как генератор непроизвольных знаков. Запомнив генерирующий сид, можно восстановить пароль или серию паролей.| <br><br><br>

5. **Реализация** <br>

Генерируемые пароли выводятся в терминал *(командную строку)* без вывода результатов в файл.<br><br>
Для составления пароля используются 2 массива: массив символов `char password[length]` и массив целых чисел `int cells[length]`. В первый помещаются символы генерируемого пароля, во второй — заполнение ячеек под  *(1 / 0)*.<br><br>
Перебираются введённые аргументы.<br><br>
При наличии флага *(опции)* для генерации пароля, выбирается случайная ячейка с индексом `i`, для которой выполняется проверка, заполнена она или нет ( `cells[i] == 1` ? ).<br><br>
Если ячейка не заполнена (`cells[i] = 0`), в неё помещается случайный символ из алфавита заданной опции (для `-c` это от A до Z, для `-n`: от 0 до 9, для `-y`: от ! до +).<br><br>
При отсутствии дополнительных аргументов (флагов), оставшиеся ячейки заполняются через цикл for, в котором выполняется проверка, заполнена ячейка или нет.<br><br>
Если ячейка не заполнена, для неё подбирается значение из общего алфавита (для аргументов `-n -c` это `(a-z)+(0-9)+(A-Z)`).
<br><br>

6. **Подбор случайного значения** <br><br>

Значения для генерации псевдослучайных символов подбираются по генерации псевдослучайных чисел функцией `getRand()`, используемых для получения определённых символов из ASCII функцией `getASCII()`. Для специальных символов это значения от 33 до 47, для цифр - от 48 до 57, для латинских букв верхнего регистра - от 65 до 90, нижнего регистра - от 97 до 122.

```
#include <stdlib.h>

int getRand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

char getASCII(int i)
{
    return (char)i;
}
```
<br>

7. **Guards (проверки, используемые для предотвращения ошибок)** <br>

| **Условие**   | **Назначение**                                                           | **Результат** |
|---------------|--------------------------------------------------------------------------|---------------|
| args.len > length | Если количество аргументов больше количества доступных символов в пароле | Ошибка о малой длине пароля |
|args.len = 1<br>args = "-s"<br>length < 3| Если аргумент является алиасом для нескольких аргументов<br>(`-s` для `-n -y -c`)| Ошибка о малой длине пароля|