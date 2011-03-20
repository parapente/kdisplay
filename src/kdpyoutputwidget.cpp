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


#include "kdpyoutputwidget.h"
#include <easyrandr/output.h>
#include <QStandardItemModel>

kdpyOutputWidget::kdpyOutputWidget(QWidget* parent, Qt::WindowFlags f): QWidget(parent, f)
{
    setupUi(this);
}

void kdpyOutputWidget::setOutput(EasyRandR::Output* out)
{
    output = out;
    populateWidgets();
}

void kdpyOutputWidget::populateWidgets(void )
{
    blockSignals(true);
    if (output) {
	// Setup Size Combobox
	QMap<RRMode,QString> modes;
	RRMode curMode;
	modes = output->validModes();
	curMode = output->currentMode();
	QStandardItemModel *model = new QStandardItemModel(modes.count(),2);
	int row = 0;
	QMapIterator<RRMode,QString> modeIter(modes);
	while (modeIter.hasNext()) {
	    modeIter.next();
	    model->setItem(row,0,new QStandardItem(QString::number(modeIter.key())));
	    model->setItem(row,1,new QStandardItem(modeIter.value()));
	    row++;
	}
	
	sizeCombo->setModel(model);
	sizeCombo->setModelColumn(1);
	sizeCombo->setCurrentItem(modes.value(curMode));
	
	// Setup Orientation Combobox
	Rotation rot = output->validRotations();
	Rotation currot = output->currentRotation();
	Rotation rotmask = RR_Rotate_0 | RR_Rotate_90 | RR_Rotate_180 | RR_Rotate_270;
	
	if (rot & RR_Rotate_0)
	    orientationCombo->addItem("Normal", RR_Rotate_0);
	if (rot & RR_Rotate_90)
	    orientationCombo->addItem("Left", RR_Rotate_90);
	if (rot & RR_Rotate_180)
	    orientationCombo->addItem("Inverted", RR_Rotate_180);
	if (rot & RR_Rotate_270)
	    orientationCombo->addItem("Right", RR_Rotate_270);
	orientationCombo->setCurrentIndex(orientationCombo->findData(currot & rotmask));
	
	
	// Setup Reflection Combobox
	Rotation refmask = RR_Reflect_X | RR_Reflect_Y;
	
	reflectionCombo->addItem("None", 0);
	if (rot & RR_Reflect_X)
	    reflectionCombo->addItem("X-axis", RR_Reflect_X);
	if (rot & RR_Reflect_Y)
	    reflectionCombo->addItem("Y-axis", RR_Reflect_Y);
	reflectionCombo->setCurrentIndex(reflectionCombo->findData(currot & refmask));
	
	// Setup Number Inputs
	posxNumInput->setValue(output->x());
	posyNumInput->setValue(output->y());
    }
    blockSignals(false);
}


#include "kdpyoutputwidget.moc"
