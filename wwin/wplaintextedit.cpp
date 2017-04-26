#include "wplaintextedit.h"

/*!
 * \brief WPlainTextEdit::WPlainTextEdit Конструктор с инициализацией
 * \param parent
 */
WPlainTextEdit::WPlainTextEdit(WWidget *parent = nullptr)
    : WWidget(parent)
{
    this->initWndClass(L"EDIT");
}

/*!
 * \brief WPlainTextEdit::setPlainText Установить текст в поле ввода
 * \param text
 */
void WPlainTextEdit::setPlainText(WString text)
{
    this->setTitle(text);
}

/*!
 * \brief WPlainTextEdit::on_changed привязать обработчик на событие изменения текста.
 * \param callback
 */
void WPlainTextEdit::on_changed(std::function<void (WString)> callback)
{
    _cblChanged.push_back(callback);
}

/*!
 * \brief WPlainTextEdit::style Переопределение стилей для многострочного поля
 * \return
 */
int WPlainTextEdit::style()
{
    return WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL;
}

/*!
 * \brief WPlainTextEdit::changeEvent обработка события изменения
 * \param e - экземпляр WEvent
 * \return WEvent::isAccepted
 */
bool WPlainTextEdit::changeEvent(WEvent *e)
{
    wchar_t *buf = new wchar_t[_maxLength];
    GetDlgItemText( this->parentHwnd(), this->cid(), buf, _maxLength);

    _title = WString(buf);

    delete buf;

    for(auto callback : _cblChanged){
        callback( this->title() );
    }

    e->accept();
    return e->isAccepted();
}

/**
 * @brief WPlainTextEdit::nativeEvent - Обработка нативных событий системы и интерпретация их в систему событий WWin
 * @param hWnd
 * @param message
 * @param wParam
 * @param lParam
 * @return bool - is accepted event
 */
bool WPlainTextEdit::nativeEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if( EN_CHANGE == HIWORD(wParam) ){
        return this->event( new WEvent(WEvent::Type::WindowTitleChange) );
    }
    return WWidget::nativeEvent(hWnd, message, wParam, lParam);
}

/*!
 * \brief WPlainTextEdit::event Обработка событий
 * \param e
 * \return
 */
bool WPlainTextEdit::event(WEvent *e)
{
    if( e->type() == WEvent::Type::WindowTitleChange ){
        return changeEvent(e);
    }
    return e->isAccepted();
}
