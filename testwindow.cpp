#include "testwindow.h"
#include <iostream>

TestWindow::TestWindow(WWidget *parent)
    : WWidget(parent)
{

}

void TestWindow::initUi()
{
    auto wgt = this;
    int width  = 920;
    int height = 570;
    int x = WScreen::width()  / 2 - width  / 2;
    int y = WScreen::height() / 2 - height / 2;

    wgt->setTitle(L"WWinApi Lib Заголовок");
    wgt->setGeometry(x,y,width,height);

    WLineEdit *edit = new WLineEdit(L"Hello", wgt);
    edit->setGeometry(10,80,250,20);
    edit->show();
    edit->setEchoMode(WLineEdit::EchoMode::Password);
    edit->on_change([](WString){/* ... */});

    WListBox *listbox = new WListBox({
        L"Item 1",
        L"Item 2",
        L"Item 3",
        L"Item 4"
    }, wgt);
    listbox->setGeometry(10, 110, 250, 100);
    listbox->show();

    WListView *listview = new WListView({
        L"One",
        L"Two",
        L"Three",
        L"Four"
    }, wgt);
    listview->setGeometry(270,10,186,100);
    listview->show();
    WStringListModel *listview_model = new WStringListModel({
        L"Une",
        L"Due",
        L"Tree",
        L"Quatro"
    }, wgt);
    listview->setModel(listview_model);
    listview->on_select([=](WModelIndex index){
        auto item = listview_model->data(index);
        WMessageBox::information(nullptr, L"Title", item);
    });

    WListView *listview2 = new WListView(wgt);
    listview2->setGeometry(270,120,186,100);
    listview2->show();
    listview2->setModel(listview_model);
    listview2->on_doubleClick([=](WModelIndex index){
        auto item = listview_model->data(index);
        WMessageBox::warning(nullptr, L"Title", item);
    });

    WPushButton *btn2 = new WPushButton(L"Мой батон", wgt);
    btn2->setGeometry(140,10,120,60);
    btn2->show();
    btn2->setFocus();
    btn2->on_clicked([=](WMouseEvent*e, bool checked){
        listview_model->setData({-1,0}, edit->value());

        listbox->addListItem(edit->value());
        if( e->modifiers() & WMouseEvent::KeyModifiers::ControlModifier ){
            WMessageBox::information(nullptr, L"Title", L"Control is hold");
        }
    });

    WPushButton *btn = new WPushButton(L"My Button", wgt);
    btn->setGeometry(10,10,120,60);
    btn->show();
    btn->on_clicked([&](WMouseEvent*, bool checked){
        WMessageBox::information(wgt, L"Title", L"Button 1 clicked");
    });
    delete btn;

    WCheckBox *chbox1 = new WCheckBox(wgt);
    chbox1->setTitle(L"WCheckBox 1");
    chbox1->setGeometry(10,210,120,20);
    chbox1->show();
    chbox1->on_toggleed([=](WMouseEvent*,bool ckd){
        WMessageBox::information(nullptr, L"WCheckBox 1", (ckd)?L"Cheked":L"Unchecked");
    });
    WCheckBox *chbox2 = new WCheckBox(wgt);
    chbox2->setTitle(L"WCheckBox 2");
    chbox2->setGeometry(10,230,120,20);
    chbox2->show();
    chbox2->on_toggleed([=](WMouseEvent*,bool ckd){
        WMessageBox::information(nullptr, L"WCheckBox 2", (ckd)?L"Cheked":L"Unchecked");
    });

    WRadioButton *rbtn1 = new WRadioButton(wgt);
    rbtn1->setTitle(L"WRadioButton 1");
    rbtn1->setGeometry(130,210,130,20);
    rbtn1->show();
    rbtn1->on_toggleed([=](WMouseEvent*,bool ckd){
        WMessageBox::information(nullptr, L"WRadioButton 1", (ckd)?L"Cheked":L"Unchecked");
    });
    WRadioButton *rbtn2 = new WRadioButton(wgt);
    rbtn2->setTitle(L"WRadioButton 2");
    rbtn2->setGeometry(130,230,130,20);
    rbtn2->show();
    WRadioButton *rbtn3 = new WRadioButton(wgt);
    rbtn3->setTitle(L"WRadioButton 3");
    rbtn3->setGeometry(130,250,130,20);
    rbtn3->show();
    WRadioButton *rbtn4 = new WRadioButton(wgt);
    rbtn4->setTitle(L"WRadioButton 3");
    rbtn4->setGeometry(130,270,130,20);
    rbtn4->show();

    WButtonGroup *btngrp = new WButtonGroup(wgt);
    btngrp->addButton(rbtn1);
    btngrp->addButton(rbtn2);
    btngrp->addButton(rbtn3);
    btngrp->addButton(rbtn4);

    WPlainTextEdit *ptedit1 = new WPlainTextEdit(wgt);
    ptedit1->setGeometry(470,10,200,200);
    ptedit1->show();

    WPlainTextEdit *ptedit2 = new WPlainTextEdit(wgt);
    ptedit2->setGeometry(680,10,200,200);
    ptedit2->show();

    ptedit1->on_changed([=](WString text){
        ptedit2->setPlainText(text);
    });
    ptedit2->on_changed([=](WString text){
        ptedit1->setPlainText(text);
    });
}


