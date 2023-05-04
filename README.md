g++ -DBOOST_ERROR_CODE_HEADER_ONLY -I/usr/local/include/boost/ ./src/main.cpp -L/usr/lib/x86_64-linux-gnu/ -lboost_thread -lboost_timer -lboost_chrono -lrt
g++ -std=c++17  main.cpp ./shell/*.cpp -lboost_thread -lboost_timer -lboost_chrono -lrt

# Клиент асинхронного чата на C++ с использованием библиотеки Boost

## Введение

Данный проект представляет собой клиент асинхронного чата на C++, который использует библиотеку Boost для реализации асинхронных операций ввода/вывода. Кроме того, в проекте были использованы красивые шаблоны проектирования, такие как "Команда" и Consumer/Producer.

## Основные компоненты

### Класс ChatClient

Основной класс клиента чата, который обеспечивает подключение к серверу и отправку/прием сообщений. Для реализации асинхронных операций ввода/вывода используется библиотека Boost.Asio.

### Шаблон проектирования "Команда"

Шаблон проектирования "Команда" используется для реализации команд, которые могут быть отправлены на сервер. Каждая команда представляет собой отдельный класс, который реализует интерфейс ICommand. Команды могут быть добавлены в очередь и выполнены позже.

### Шаблон проектирования Consumer/Producer

Шаблон проектирования Consumer/Producer используется для реализации очереди команд. Producer добавляет команды в очередь, а Consumer забирает их и выполняет. Это позволяет упростить асинхронную обработку команд.

## Available commands

### Send One Client

### Send Group

### Send File To Client

### Login

### Logout

### Пример использования

// Создание клиента чата
ChatClient client("localhost", 8080);

// Подключение к серверу
client.connect();

// Отправка сообщения на сервер
client.send("Hello, world!");

// Создание команды и добавление ее в очередь
auto command = std::make_unique<SendMessageCommand>("Hello, world!");
client.addCommand(std::move(command));

// Запуск обработки очереди команд
client.run();

## Docker Integration


## Заключение

Клиент асинхронного чата на C++ с использованием библиотеки Boost и шаблонов проектирования представляет собой пример эффективного использования современных технологий и методов программирования. Он позволяет реализовать надежное и масштабируемое приложение для обмена сообщениями в режиме реального времени.