# esp32-cavebot
esp32 based robot speleologist

<img src = "Images/code.png">

**Репозиторий о роботе-исследователе. Собрав его вы сможете исследовать труднодоступные места или искать вещи под диваном.**
Проблемы или вопросы? Напишите в issues

[![Issues](https://img.shields.io/badge/issues-0%20open-be4ad6?style=for-the-badge)](https://github.com/deltashrimp/arduino-cavebot/issues)
![aaaa](https://img.shields.io/badge/|-red?style=for-the-badge)
[![Latest Release](https://img.shields.io/github/v/release/deltashrimp/arduino-cavebot?include_prereleases&label=Release&color=96d83e&style=for-the-badge)](https://github.com/deltashrimp/arduino-cavebot/releases/latest)
![aaaa](https://img.shields.io/badge/|-red?style=for-the-badge)
[![Latest Release](https://img.shields.io/github/v/release/deltashrimp/arduino-cavebot?include_prereleases&label=Download&style=for-the-badge)](https://github.com/deltashrimp/arduino-cavebot/releases/latest)
[![Changelog](https://img.shields.io/badge/Changelog-View-0078D4?style=for-the-badge)](https://github.com/deltashrimp/arduino-cavebot/blob/main/Papers/CHANGELOG.md)

<h2>No longer maintained</h2>



## Файловая структура
- **Source** - исходники кода, который надо загрузить на arduino и все 3д модели
    - **Code** - код, который надо загрузить на микроконтроллеры
    - **3D models** - 3д модели (файл .blend для Blender 3D и файл .stl для печати)
- **Papers** - всякие бумажки
- **Images** - картинки
---
Для сборки проекта **необходимы**:
- Компьютер
- Провод с поддержкой передачи файлов (один конец - порт компьюьера, другой конец - порт esp32-wroom)
- Паяльник
- Припой для паяльника
- Кусачки и нож
- Мультиметр
- Базовое умение работать с паяльником
- Все компоненты, указанные в Parts.md

Опционально:
- Держатель для паяльника
- 3д принтер
- Программа слайсер
- Базовые знания в программировании(в случае если придётся редактировать код)

## Вопросы и ответы
Весь код был написан в **VS Code** через **Platform IO IDE**, а не через arduino ide. Код может отличаться, но не сильно. </br>

### Как скачать проект?
Если на главной странице нет кнопки "скачать", то вот так

<img src="Images/step1.png" width=40%>
<img src="Images/step2.png" width=50.5%>

### Где скачивать программы?
На официальных сайтах:
<a href = "https://www.blender.org/download/">Blender</a>, <a href = "https://code.visualstudio.com">VS Code</a>, <a href = "https://www.arduino.cc/en/software">Arduino IDE</a>, <a href = "https://ultimaker.com/software/ultimaker-cura/">UltiMaker Cura (для 3д печати)</a>.

### Это сложно?
Укладка проводов может быть трудной, а тонкие провода могут порваться.

### Как печатать детали?
В UltiMaker Cura перетащите .stl файл и поставьте необходимые настройки. <br>
Раземер модели должен быть таким (с учётом усадки материала)

<img src="Images/sizes.png" width=50%>



### Сколько стоит проект?
Актуально в марте 2025 года на сайте ozon.kz

| Компонент | Цена |
|-----------|------|
| Esp32-wroom | 3458 ₸ |
| Esp32-cam | 6467 ₸ |
| Аккумулятор 7.4 вольт (литиевый) | 4390 ₸ |
| Драйвер mx1508 | 1179 ₸ |
| Конденсатор 470 мкФ | 1152 ₸ |
| DC DC понижающий преобразователь | 911 ₸ |
| Провода для пайки | 2375 ₸ |
| Провода джамперы 120 штук | 2435 ₸ |
| **Итого** | **22367 ₸** |

Также можно купить их на aliexpress, где я и купил аккумулятор и драйвер. Выйдет дешевле, но может приехать бракованная деталь. Конденсаторы есть в магазине Delta Chip по 50 ₸ (вроде бы) за штуку
### Как загрузить код?
#### Arduino IDE
1. Скачайте программу
2. <a href="https://lastminuteengineers.com/esp32-arduino-ide-tutorial/">Здесь</a> написано как добавить всё необходимое и загрузить код
#### VS Code
1. Скачайте программу
2. Внутри установите расширение PlatformtoolsIO
3. Нажмите сюда

<img src="Images/platformio.png">

Затем сюда

<img src="Images/platformio2.png">

Затем сюда

<img src="Images/platformio3.png">

Введите название проекта и имя микроконтроллера(board)

<img src="Images/platformio4.png" width=70%>

Фреймворк оставьте "arduino".
После создания проекта нажмите на папку src, там будет файл **main.cpp**. Скопируйте код из моего main.cpp и вставьте в свой, тоже самое с platfrmio.ini.

Найдите кнопку **build**, обычно она слева внизу или справа вверху в меню.

<img src="Images/platformio5.png"> <img src="Images/platformio6.png" width=40%>

Если в открывшемся терминале в конце написано "success took X seconds", подключайте esp32 к компьютеру через провод(провод должен поддерживать передачу файлов) и нажимайте кнопку **upload**. Если в терминале написано success, значит код загружен.

<img src = "Images/amogus.png" width = 50px>
