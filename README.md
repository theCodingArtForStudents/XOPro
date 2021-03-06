# WWin
Qt-like library for WINAPI | Похожая на *Qt* библиотека написанная от нефиг делать на WINAPI

Эта библиотека пишется для удовлетворения собственного любопытства.
Она не ставит себе целью превзойти *Qt* или догнать его,
из *Qt* берутся лишь лучшие, необходимые и интересные для реализации идеи,
а так-же сохраняется стиль наименования методов для упрощённого понимания.

## Быстрый старт
1. [Клонируете](https://github.com/TheCodingArt/WWin.git) репозиторий или скачайте [zip](https://github.com/TheCodingArt/WWin/archive/master.zip) архив.
2. Скачиваете и запускаете IDE [Qt Creator](https://www.qt.io/download-open-source/#section-2)
3. Открываете проект
4. Пробуете скомпилировать.

## Простейшее приложение
```c++
#include "wwin/wapplication.h"
#include "wwin/wgui.h"

int WINAPI WinMain(HINSTANCE hInstace, HINSTANCE hPrevInst, LPSTR lpCmdString, int nCmdShow)
{
    WApplication *app = WApplication::instance(hInstace, hPrevInst, lpCmdString, nCmdShow);

	// Центрирование окна на экране
	int width  = 260;
	int height = 80;
	int x = WScreen::width()  / 2 - width  / 2;
	int y = WScreen::height() / 2 - height / 2;

	// Создание окна приложения
	WWidget *w = new WWidget(nullptr);
	w->setTitle(L"Hello World");
	w->setGeometry(x,y,width,height);
	w->show();

	// Создание поля ввода
	WLineEdit *edit = new WLineEdit(L"Введи своё имя...", w);
	edit->setGeometry(10,10,160,20);
	edit->show();

	// Создание кнопки
	WPushButton *btn = new WPushButton(L"Ввод", w);
	btn->setGeometry(180,10,60,20);
	btn->show();
	btn->on_clicked([&](WMouseEvent*, bool){
		WMessageBox::information(w, L"Окно приветствия", L"Привет " + edit->value() );
	});

    return app->run();
}

```

## Подробнее

### C++11 и STL
В библиотеке активно используются новшества языка `C++` из стандарта `C++11` и более новых, такие как:
- Лямбда функции
- Итераторы
- Умные указатели *(планируется)*
- Списки инициализации
- Enum классы

В том числе в библиотеке активно используются структуры данных из стандартной библиотеки `STL`, такие как:
- std::string
- std::vector
- std::list
- std::map

### Observer
Библиотека *WWin* не реализует систему сигналов-и-слотов из *Qt*,
вместо этого в ней частично реализован паттерн *Observer*, для подписки на события
что позволяет легко добавить необходимое количество обработчиков на событие.

### Документация
Библиотека задокументирована на русском языке, с применением `doxygen` комментариев,
так что при желании вы сможете понять что в ней сделано и для чего.

### Процесс разработки
В проектах на *github* есть Канбан-доска, где вы можете посмотреть что было реализовано
и что планируется реализовать, а так же что сейчас находится в разработке, но не сильно
этому доверяйте, мы иногда перебрасываем таски обратно в *Input Stream*

### Ваши мольбы
Если что-то хотите предложить, попросить, пожаловаться - пишите *issue*.
Возможно мы его прочитаем, и даже есть не нулевая вероятность что сделаем, но это не точно.

### Присоедениться
Если хотите принять участие в разработке - добро пожаловать, можете писать в *issue*,
для обсуждения чего-либо, и делать *pull-request*'ы с реализацией чего-либо, мы будем рады.
Только, пожалуйста, пишите документацию, соблюдайте стиль наименования методов из *Qt*, если
вы пишите аналог какого-то класса из этой библиотеки, что ещё? ну... ничего вроде.
Ах да, коммит-мессейджы пишите на английском, пусть даже на ломаном.
Разработку ведём по процессу [Git Flow](https://habrahabr.ru/post/106912/).

### Open Source
Библиотека является *Open Source*, а в качестве лицензии можете считать `MIT`, т.е. делайте что хотите
мы никаких претензий не имеем, а если сможете использовать для себя в целях монетизации - то молодцы.
Библиотека предоставляется **как есть(As is)** и её авторы не несут никакой ответственности,
за нанесение прямого или коссвенного ущерба, применяйте её на свой страх и риск.

**Приятного использования.**
