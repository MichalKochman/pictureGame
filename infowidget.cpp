/*
 * infowidget.cpp
 *
 * Copyright 2020 Michal Kochman <michalkochman@email.cz>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */
#include "infowidget.h"
#include "ui_infowidget.h"
#include "licenceinfo.h"
#include <QDebug>

infoWidget::infoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infoWidget)
{
    ui->setupUi(this);

    ui->copyleft->setText(licenceInfo().copyright + "\n\n" +licenceInfo().QtInfo);
    ui->copyleft->setWordWrap(true);
    ui->licence->setText(licenceInfo().licence + "\n\n"   + licenceInfo().obligations);
    ui->licence->setWordWrap(true);

    setLayout();






}

infoWidget::~infoWidget()
{
    delete ui;
}



void infoWidget::setTextWelcome(){
    ui->textLabel->setText( "Press ESC to quit the program\n"
                            "Press any other key to start the game\n"
                            "During the game, press letters to play or 'ESC' to return here");
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


void infoWidget::setSplitter(int middleY, int startX, int endX){
    ui->splitterV->setGeometry(middleY,startX,3,endX-5);
    ui->splitterH->setGeometry(5, startX,this->geometry().width()-10, 3);

}

void infoWidget::setLayout(void){
    setFrame();
    this->setBackgroundRole(QPalette::Midlight);
    int w = this->geometry().width();
    int h = this->geometry().height();
    int margin=10;
    int m = w/2;
    int downHeight = 200;


    ui->copyleft->setGeometry(margin,   h-downHeight, m-2*margin, downHeight-margin) ;
    ui->licence->setGeometry (m+margin, h-downHeight, m-2*margin, downHeight-margin);

    ui->textLabel->setGeometry(margin,margin,w-2*margin, h-80-2*margin);

    ui->copyleft->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->licence->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    setSplitter(m, h-downHeight, downHeight);



}

