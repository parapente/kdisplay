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


#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <KTabWidget>
#include <QVBoxLayout>
#include <QSplitter>

namespace EasyRandR {
class Configuration;
class Output;
}


class kdpyMainWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit kdpyMainWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual ~kdpyMainWidget();

private slots:
    void outputChanged(void);
    
signals:
    void configChanged(bool);
    
private:
    QVBoxLayout *mainlayout;
    QGraphicsView *view;
    KTabWidget *tabwidget;
    QSplitter *splitter;
    
    EasyRandR::Configuration *randrcfg;
    int randrscreens;
    QList<EasyRandR::Output*> randrouts;
    
    bool changed;
};

#endif // MAINWIDGET_H
