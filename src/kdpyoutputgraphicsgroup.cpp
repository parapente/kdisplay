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


#include "kdpyoutputgraphicsgroup.h"

kdpyOutputGraphicsGroup::kdpyOutputGraphicsGroup(QGraphicsItem* parent): QGraphicsItemGroup(parent)
{
    m_rect = new QGraphicsRectItem(parent);
    m_rect->setRect(0,0,400,300);
    m_nameText = new QGraphicsTextItem(parent);
    m_nameText->setPlainText(QString("Test"));
    m_sizeText = new QGraphicsTextItem(parent);
    m_sizeText->setPlainText(QString("1x1"));
    
    addToGroup(m_rect);
    addToGroup(m_nameText);
    addToGroup(m_sizeText);
}

void kdpyOutputGraphicsGroup::setRect(QRectF rect)
{
    m_rect->setRect(rect);
}

void kdpyOutputGraphicsGroup::setNameText(QString name)
{
    m_nameText->setPlainText(name);
}

void kdpyOutputGraphicsGroup::setSizeText(QString size)
{
    m_sizeText->setPlainText(size);
}

