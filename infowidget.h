#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include "ui_infowidget.h"
namespace Ui {
class infoWidget;
}

class infoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit infoWidget(QWidget *parent = nullptr);
    ~infoWidget();
    void setTextWelcome();
    void setTextNoImg();

private:
    Ui::infoWidget *ui;
    void setFrame(void);
    void setLayout(void);
};

#endif // INFOWIDGET_H
