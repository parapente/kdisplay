/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  Θεόφιλος Ιντζόγλου <int.teo@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef KDPYGRAPHICSVIEW_H
#define KDPYGRAPHICSVIEW_H

#include <QGraphicsView>


class kdpyGraphicsView : public QGraphicsView
{
    Q_OBJECT
    
public:
    kdpyGraphicsView(QGraphicsScene* scene, QWidget* parent = 0);
    
signals:
    void viewResized(void);

protected:
    virtual void resizeEvent(QResizeEvent* event);
};

#endif // KDPYGRAPHICSVIEW_H
