/*
 * letterimage.cpp
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
#include "letterimage.h"
#include <vector>
#include <QDebug>
#include <QDir>
#include <QImageReader>


letterImage::letterImage()
{
    qDebug()<<__PRETTY_FUNCTION__;
    numberOfImages = 0;

}
letterImage::letterImage(char c)
{
    numberOfImages = 0;
    QDir imgDir("img/"+QString(c)+"/");

    // QDir imgDir("img/");

    if (imgDir.exists())
    {  qDebug() << __PRETTY_FUNCTION__ << "FileFound: " << imgDir;
        key = (Qt::Key) c;
        scanDir(imgDir);
    } else {
        qWarning()<< __PRETTY_FUNCTION__ << "FileNotFound:" << imgDir;
        numberOfImages = 0;
    }
}

QImage letterImage::getRandomImage(){
   int tmp = rand()%numberOfImages;
   QImageReader reader(path.at(tmp));
   reader.setAutoTransform(true);
   return reader.read();

}

void letterImage::scanDir(QDir dir)
{
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.PNG" << "*.JPG" << ".*jpeg" << "*.JPEG";
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    qDebug() << "Scanning: " << dir.path();

    QStringList fileList = dir.entryList();
    qDebug()<<fileList;
    for (int i=0; i<fileList.count(); i++)
    {
        if(fileList[i] != "main.nut" &&
           fileList[i] != "info.nut")
        {
            qDebug() << "Found file: " << fileList[i];
            path.push_back(dir.path() + "/" + fileList[i]);
            numberOfImages++;
        }
    }
    path.shrink_to_fit();
    qDebug()<<"Scanning over";
}


bool letterImage::haveImages(void){
    return numberOfImages>0;
}
Qt::Key letterImage::getKey(void){
    return this->key;
}
