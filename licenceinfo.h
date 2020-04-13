/*
 * licenceinfo.h
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


#ifndef LICENCEINFO_H
#define LICENCEINFO_H

#include <QString>
class licenceInfo
{
public:
    licenceInfo();

    bool checkLicenceFile(const QString path);

    QString copyright = "letterGame v0.0.2  Copyright (C) 2020  Michal Kochman <michalkochman@email.cz>";
    QString waranty = "The program is provided AS IS with NO WARRANTY OF ANY KIND.";
    QString licence = "This is free software, and you are welcome to redistribute it under conditions of GPL, see www.gnu.org/licenses/gpl-3.0.txt.";
    QString QtInfo = "This program was made using Qt development enviroment obtained under GPL, see www.qt.io for more info.";
    QString obligations = "Any copy of this program must be distributed with full text of the licence.";
};

#endif // LICENCEINFO_H
