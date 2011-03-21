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


#include "kdpymainwidget.h"
#include "kdpyoutputwidget.h"
#include <KDebug>
#include <easyrandr/configuration.h>

kdpyMainWidget::kdpyMainWidget(QWidget* parent, Qt::WindowFlags f): QWidget(parent, f)
{
    mainlayout = new QVBoxLayout(this);
    view = new QGraphicsView(this);
    view->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    
    tabwidget = new KTabWidget(this);
    tabwidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    randrcfg  = new EasyRandR::Configuration();
    randrscreens = randrcfg->getScreenCount();
    kDebug() << "Screens:" << randrscreens;
    for (int i=0; i<randrscreens; i++)
	randrouts.append(randrcfg->getOutputList(i));
    
    kdpyOutputWidget *out;
    for (int i=0; i<randrouts.count(); i++) {
	out = new kdpyOutputWidget(tabwidget);
	out->setOutput(randrouts.at(i));
	tabwidget->addTab(out,randrouts.at(i)->name());
	
	connect(out,SIGNAL(outputChanged()),this, SLOT(outputChanged()));
    }

    splitter = new QSplitter(Qt::Vertical);
    splitter->addWidget(view);
    splitter->addWidget(tabwidget);
    
    mainlayout->addWidget(splitter);
    this->setLayout(mainlayout);
    
    changed = false; // Keeps if the configuration has changed
}

kdpyMainWidget::~kdpyMainWidget()
{
    delete view;
    delete tabwidget;
    delete mainlayout;
}

void kdpyMainWidget::outputChanged(void )
{
    changed = true;
    emit configChanged(true);
}
