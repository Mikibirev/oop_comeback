## 1.1: [Что такое система управления версиями?](https://learn.microsoft.com/ru-ru/devops/develop/git/what-is-version-control)
Система упавления версиями - это программное обеспечение, помогающее отслеживать изменения, внесённые в код с течением времени. Система управления версиями управляет всеми версяими кода, но одновременно предоставляет команде только одну версию. Предназначена для безопасного редактирования кода одним или несколькими людьми. <br>
#### Преимущества управления версиями:
1. Создание рабочих процессов
2. Использование версий
3. Код вместе
4. Сохранение журнала
5. Автоматизация задач
## 1.2: [Что такое репозиторий?](https://www.nic.ru/info/blog/repository/)
Репозиторий - это хранилище всех версий кода. <br>
Локальный репозиторий расположен на одном компьютере, и работать с ним может только один человек. <br>
Удалённый репозиторий хранится в облаке, а когда программист вносит правки в локальную версию, её можно синхронизировать с удалённой. <br>
Централизованный репозиторий расположен на сервере, куда имеют доступ несколько программистов. <br>
## 1.3: [Какие файлы следует добавлять к отслеживанию?](https://ru.stackoverflow.com/questions/474556/Что-должно-и-не-должно-быть-в-gitignore-для-любого-языка-и-ide)
#### Что стоит добавлять к отслеживанию:
1. Все файлы конфигурации git
2. Файлы, определяющие структуру проекта
3. Код и сопутствующие ресурсы
#### Что не стоит добавлять к отслеживанию:
1. Базы данных
2. Файлы, образующиеся в процессе компиляции проекта
3. Сторонние инструменты
4. Файлы, генерируемые тестовым фреймворком
5. Сгенерированная кодом документация
6. Логи
7. Временные файлы текстового редактора
8. Файлы, создаваемые операционной системой
## 1.4: [В каких случаях создавать ветку?](https://git-scm.com/book/ru/v2/Ветвление-в-Git-О-ветвлении-в-двух-словах)
Ветка в Git - это простой перемещаемый указатель на один из таких коммитов. По умолчанию, имя основной ветки в git. Как только вы начнёте создавать коммиты, ветка master будет всегда указывать на последний коммит. <br>
При создании новой ветки всего лишь создаётся новый указатель для дальнейшего перемещения. Используя ветвление, вы отклоняетесь от основной линии разработки и продолжаете работу независимо от неё, не вмешиваясь в основную линию
## 1.5: [Что такое конфликт?](https://www.atlassian.com/ru/git/tutorials/using-branches)
Конфликт Git возникает, когда два человека изменяют одни и те же строки в файле или один разработчик удаляет файл, который в это время изменяет другой разработчик; возникает также в том случае, когда Git не может автоматически определить, какое изменение является правильным. Конфликты затрагивают только того разработчика, который выполняет слияние, остальная часть команды о конфликте не знает. <br>
#### Обработка конфликта Git
При возникновении конфликта можно использовать команды:
1. git status (покажет, что из-за конфликта не удалось слить пути)
2. cat (покажет конкретное место, где произошёл конфликт).
3. git log (создаёт журнал со списком конфликтов)
4. git diff (помогает найти различия между коммитами)

В случае, если конфликт произошёл в начале слияния
1. git checkout (отмена изменений в файлах или для изменения веток)
2. git reset --mixed (отмена изменений в рабочем каталоге

В случае, если конфликт произошёл в процессе слияния
1. git merge --abort (возвращение к исходному состоянию)
2. git reset (восстановить заведомое состояние конфликта)
## 2.1: [Что такое АТД?](https://habr.com/ru/post/506170/)
Абстрактный тип данных (АТД) - это набор, включающий данные и выполняемые над ними операции, служащие для одной общей цели.
## 2.2: [Что такое предусловия/постусловия?](http://sergeyteplyakov.blogspot.com/2010/05/)
Для чёткого выражения задачи, выполняемой конкретной функцией, с ней связывают два утверждения - предусловие и постусловие. Предусловие определяет свойства, которые должны выполняться всякий раз перед вызовом функции, а постусловие определяет свойства, гарантируемые после завершения её выполнения. Предусловие и постусловие определяют контракт функции со всеми её клиентами. Используются во избежание ошибок.
## 2.3: [Что такое класс/объект?](http://ermak.cs.nstu.ru/cprog/html/101.htm)
Класс - в ООП, модель для создания объектов определённого типа, описывающая их структуру (набор полей и их начальное состояние) и определяющая алгоритмы (функции или методы) для работы с этими объектами. <br>
Объект - объект определённого типа, созданный на основе класса.
## 7.1 [Что такое исключительная ситуация?](https://blog.skillfactory.ru/glossary/isklyucheniya/)
Исключения в программировании - это механизм, который позволяет программе обрабатывать нетипичную ситуацию и при этом не прекращать работу.
## 7.2 [Как работает механизм обработки исключений?](https://prog-cpp.ru/cpp-exception/)
Обработка исключений происходит с помощью блока защищённого кода (конструкции try {}) и блока обработчика исключения (catch (error){}). Идея состоит в том, что функция, обнаружившая проблему, на не знающая как её решить, генерирует исключение в надежде, что вызвавшая её функция сможет решить возникшую проблему. <br>
Функция, которая может решать проблемы данного типа, указывает, что она перехватывает такие исключения.
## 7.3 [Что такое бизнес-логика?](https://ru.stackoverflow.com/questions/548021/)
Бизнес-логика - это логика доменной модели - всё, что в нашем приложении происходит в терминах предметной области. К бизнес логике не относится добавление цифры к выражению, но относится невозможность поставить несколько плавающих точек к одному числу.