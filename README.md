# so_long
Данный проект представляет собой создание игры "so_long", которая является 2D игрой на языке программирования C. В игре пользователь управляет персонажем, который должен собирать предметы и достигать выхода, избегая при этом препятствия и врагов.

Название программы: `so_long`.

Разрешенные файлы: Makefile, *.h, *.c, maps

Makefile: NAME, all, clean, fclean, re

Разрешенные функции: 
- open, close, read, write, malloc, free, perror, strerror, exit;
- все функции библиотеки `math` (-lm compiler option, man man 3 math)
- все функции библиотеки [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- свои функции из библиотеки [libft](https://github.com/AOhapkin/libft)

Программа принимает как параметр файл `.ber`

## Правила игры

Цель игрока собрать все предметы на карте и выбраться самым коротким путём.
Игрок перемещается по карте с помощью `W`, `A`, `S`, `D`.
Игрок должен иметь возможность двигаться в 4 направлениях: вверх, вниз, влево, вправо.
Игрок не может передвигаться через стены.
При каждом движении должно отображаться текущее количество перемещений.
Использовать 2D вид.
Игра не должна быть в реальном времени.


## Графика

Программа должна отображаться в окне.
Управление окном должно сохраняться (переход в другое окно, свертывание и т.д.).
Нажатие ESC должно закрывать окно и делать выход из программы.
Нажатие крестик окна должно закрывать окно и делать выход из программы.

## Карта

Карта должна быть построена из 3 компонентов: стены, предметы и свободное пространство.
Карта может состоять только из этих 5 символов:
- `0` обозначает пустое место,
- `1` - стена,
- `C` - предмет коллекционирования,
- `E` - выход,
- `P` - стартовая позиция игрока.

Пример простой валидной карты:
![](readme_pics/simple_map.png)

На карте должны быть минимум 1 выход, 1 предмет коллекционирования и 1 стартовая позиция игрока.

Карта должна быть прямоугольной.

Карта должны быть окружена стенами. Если это не так программа должны вернуть ошибку.

Не нужно проверять наличие валидного пути для выхода.

Ещё пример карты .ber:

![](readme_pics/map.png)

Если в файле обнаружена какая-либо неправильная конфигурация любого рода, программа должна завершиться корректно и вернуть «Error\n», за которым следует явное сообщение об ошибке по вашему выбору.

## Бонусная часть

- Игрок должен проиграть, когда касается врага.
- Добавить анимации спрайтов.
- Отображать количество движений прямо на экране, а не записывать его в оболочке.

## Чек-лист для проверки

- [x] Проект должен собираться с помощью команды `make` без релинка. Исполняемый файл должен называться `so_long`.
- [x] Проект должен работать с картами разного размера.
- [x] Программа должна выдавать ошибку и выходить, если с файлом карты что-то не так (невалидные символы, карта не является прямоугольником, не читается и т.д.).

- [x] Окно должно открываться при запуске программы и должно быть открыто во время исполнения программы.

- [x] Нажатие на крестик должно закрывать окно и завершать программу.
- [x] Нажатие ESC должно закрывать окно и завершать программу.
- [x] Проверить работу кнопок направления движения WASD

- [x] Игрок появляется в указанном на карте месте.
- [x] Есть текстуры стен и через них нельзя проходить.
- [x] Есть текстуры предметов коллекционирования. Они исчезают, если пройти по ним.
- [x] Есть текстура игрока, она может двигаться во все направления (только не через стены).

- [x] Есть счетчик ходов, который отображает количество сделанных ходов.
- [x] Программа обязательно использует mlx_put_image_to_window().
