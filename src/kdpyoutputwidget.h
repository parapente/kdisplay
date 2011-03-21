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


#ifndef KDPYOUTPUTWIDGET_H
#define KDPYOUTPUTWIDGET_H

#include "ui_details.h"
#include <QWidget>

namespace EasyRandR {
class Output;
}

class kdpyOutputWidget : public QWidget, private Ui::details
{
    Q_OBJECT

public:
    explicit kdpyOutputWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);
    void setOutput(EasyRandR::Output* out);
    
signals:
    void outputChanged(void);
    
private slots:
    void changed(void);
    
private:
    void populateWidgets(void);
    EasyRandR::Output *output;
};

#endif // KDPYOUTPUTWIDGET_H
