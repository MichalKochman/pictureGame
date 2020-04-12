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
