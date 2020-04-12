#ifndef LETTERIMAGE_H
#define LETTERIMAGE_H
#include <vector>
#include <QString>
#include <QImage>
#include <QDir>


class letterImage
{
public:
    letterImage();
    letterImage(char c);

    QImage getRandomImage(void);
    bool haveImages(void);
    Qt::Key getKey(void);

private:
    std::vector<QString> path;
    int numberOfImages;
    Qt::Key key;
    void scanDir(QDir dir);

};

#endif // LETTERIMAGE_H
