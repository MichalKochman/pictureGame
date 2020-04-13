/*
 * letterimage.h
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
