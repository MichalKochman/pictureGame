#include "infowidget.h"
#include "ui_infowidget.h"
#include <QDebug>

infoWidget::infoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infoWidget)
{
    ui->setupUi(this);

    ui->copyleft->setText("letterGame \n (c)Michal Kochman, 2020 \n michalkochman@email.cz" );
    setLayout();






}

infoWidget::~infoWidget()
{
    delete ui;
}



void infoWidget::setTextWelcome(){
    ui->textLabel->setText( "Press ESC to quit the program\n"
                            "Press any key to start the game\n"
                            "During the game, press letters to play or 'ESC' to terminate the program");
    ui->textLabel->setWordWrap(true);
    ui->textLabel->setAlignment(Qt::AlignCenter);
    setLayout();

}
void infoWidget::setTextNoImg(){
    ui->textLabel->setText("Press ESC to quit the program\n"
                           "No images was found - please create directory img/ in the directory containing your program. "
                           "In /img create subdirectories 'A/'..'Z/' and put your images in JPEG and/or PNG formats there. Then restart the program \nPress ESC to quit the program\n");
    ui->textLabel->setWordWrap(true);
    ui->textLabel->setAlignment(Qt::AlignCenter);
    setLayout();

}

void infoWidget::setFrame(void){
    ui->frame->setGeometry(QRect(5,5,this->geometry().width()-10, this->geometry().height()-10));
    ui->frame->setLineWidth(10);

}

void infoWidget::setLayout(void){
    setFrame();
    this->setBackgroundRole(QPalette::Midlight);
    int w = this->geometry().width();
    int h = this->geometry().height();
    int margin=10;
    ui->copyleft->setGeometry(margin, h-60,w, 50) ;
    ui->textLabel->setGeometry(margin,margin,w-2*margin, h-80-2*margin);
    ui->copyleft->setAlignment(Qt::AlignBottom);
}

