# OS-labs
# lab2
Необходимо написать программу для работы с файлами, получающую информацию из командной строки или из консоли ввода.
Программа должна корректно обрабатывать ключи и аргументы в случае ввода из командной строки, либо программа должна показывать список действий в случае ввода из консоли ввода.
Программа должна иметь возможность осуществлять:
-	копирование файлов,
-	перемещение файлов,
-	получение информации о файле (права, размер, время изменения),
-	изменение прав на выбранный файл.
Просто вызвать функцию для копирования файла нельзя. Также программа должна иметь help для работы с ней, он должен вызываться при запуске программы с ключом --help.
Копирование файла должно производиться при помощи команд блочного чтения и записи в файл. Размер буфера для чтения и записи должен быть больше единицы. Не допускается так же производить копирование файла при помощи однократной команды чтения и записи, так как при таком подходе предполагается, что оперативной памяти достаточно, чтобы прочитать весь файл одной командой. Это неверно, так как в общем случае размер файла может существенно превышать оперативную память и файл подкачки.
# lab3
Необходимо написать программу, которая разделяется на две части. Первая часть – клиентская – взаимодействует с пользователем, содержит интерфейс ввода вывода чисел из консольного ввода. Желательно обойтись без передачи параметров расчета через параметры программы (argv). Справка так же выводится по ключу –help, как и ранее. Вторая часть (серверная) ничего не выводит на экран, только принимает информацию от клиентской части, производит вычисления в зависимости от варианта ниже и отправляет клиентской части результат.
Программа должна разделяться на две части при помощи системного вызова fork(). Создание неименованных каналов должно происходить до вызова fork().
Исходный код и клиентской, и серверной частей программы можно разместить в одном файле внутри одной функции main. При отладке программы в отладчике gdb необходимо помнить о том, что клиентская и серверная части работают одновременно и представляют собой разные процессы.
Другой вариант написания лабораторной работы – подмена стандартных ввода и вывода (функция int dup2(int oldfd, int newfd)), и запуск расчетной и клиентской частей через функцию семейства exec. При этом oldfd будет указывать на ваш созданный канал, newfd – на файл, соответствующий стандартному потоку ввода вывода – 0 или 1. В этом случае лабораторная работа будет состоять из трех .cpp файлов, и трех запускных, соответственно.
Для корректной работы необходимо создать два канала, каждый из которых описывается массивом двух чисел. Один канал будет использоваться для передачи данных и команд серверу от клиента, второй – для передачи результата от клиента к серверу.
Таким образом, стандартный набор действий, следующий: 
1. Проверка командной строки на ключ --help. При наличии такового должен быть выведен help и программа должна завершить свою работу.
2. Создание каналов.
3. Разделение на клиентскую и серверную части.
4. Работа
5. После обмена (достаточно единственного) и сервер, и клиент могут завершить свою работу, команд для завершения работы сервера от клиента предусматривать не требуется.
Не забывайте закрывать каналы после использования.
Работа клиентской части:
1. Предложение ввода параметров, ожидание ввода с клавиатуры.
2. Передача данных в канал на сервер
3. Чтение результатов из канала от сервера
4. Вывод результатов расчета на экран
5. Выход.
Работа серверной части:
1. Чтение данных из канала от клиента.
2. Расчет.
3. Запись данных в канал клиенту.
4. Выход.
Вариант 11.
Вычисление многочленов Лагерра (первые 6). 
# Lab 4
Задания выполняются на С++ в операционной системе Windows. В качестве дополнительного задания можно избрать любой другой язык программирования и другую операционную систему. 
Вариант 11.
Сервер должен в режиме эхопечати (т.е. сразу выводится на экран) получать все введенные данные с клиента. Предусмотреть случай стирания текста через backspace. Клиент должен отправлять данные о каждом введенном символе, эхопечать должна поддерживать русский язык (в случае отсутствия поддержки задание засчитывается по минимальному баллу). Минимум 1 клиент. Если выбрана реализация с несколькими клиентами, то каждый из них должен выводить свои символы на сервере своим уникальным для него цветом текста.
# Lab 5
Использовать семафоры (мьютексы) для синхронизации работы процессов (потоков) в процессе реализации задания на лабораторную работу. При необходимости также можно использовать события. Требуется реализовать консольный вариант. Базовый вариант реализации – Win32 API в Windows. Дополнительные варианты реализации при использовании других операционных систем и языков программирования – на усмотрение студента. Желательно предусмотреть для всех заданий событие, при котором соответствующий процесс завершает свою работу, если это возможно.
Вариант 11.
Задача о парикмахере. Начало 19 века. В небольшом городе есть только 1 парикмахерская. Там обычно работает один парикмахер. Когда клиентов в очереди становится больше 2, он зовет своего младшего брата-мясника, который ему помогает. После обслуживания 4 клиентов парикмахер отдыхает, как и его брат. Создать много-процессное приложение, моделирующее рабочий день парикмахерской. Допускается использовать в качестве сервера процесс-парикмахерскую, в котором есть два потока – парикмахера и его брата. Клиенты – отдельные процессы. Взаимодействие между ними должно быть на уровне текстового диалога, например, такого: «Добро пожаловать, процесс X. «Здравствуйте, господин цирюльник» … «Всего доброго, приходите к нам еще!» При желании, можно добавить диалог между парикмахером и процессом клиентом.
# Lab 6
Реализовать графический интерфейс пользователя для функционала межпроцессного взаимодействия ранее сделанной лабораторной работы № 4 или для лабораторной работы № 5. В качестве получения дополнительного бонуса допускается реализация обеих лабораторных работ.
Все происходящие события должны документироваться: должен писаться лог, то есть журнал событий – сколько процессов запущено, когда, что передано каким клиентом/процессом на сервер и т.п. Должно быть предусмотрено сохранение лога в файл, а также возможность просмотра лога предыдущей запущенной сессии (допустимо использование для этого разных файлов).
Ограничений по языку программирования, технологиям, операционной системе нет.
