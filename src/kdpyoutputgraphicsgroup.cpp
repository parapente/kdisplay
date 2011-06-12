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

#include <KDebug>
#include <QFontMetrics>
#include <QBrush>
#include "kdpyoutputgraphicsgroup.h"

kdpyOutputGraphicsGroup::kdpyOutputGraphicsGroup(QGraphicsItem* parent): QGraphicsItemGroup(parent)
{
    m_rect = new QGraphicsRectItem(parent);
    m_nameText = new QGraphicsTextItem(parent);
    m_sizeText = new QGraphicsTextItem(parent);
    
    addToGroup(m_rect);
    addToGroup(m_nameText);
    addToGroup(m_sizeText);
}

void kdpyOutputGraphicsGroup::setRect(QRectF rect)
{
    setPos(rect.x(),rect.y());
    rect.setX(0);
    rect.setY(0);
    m_rect->setRect(rect);
    
    // Cause the size of the two labels to be recalculated
    setNameText(m_nameText->toPlainText());
    setSizeText(m_sizeText->toPlainText());
}

void kdpyOutputGraphicsGroup::setNameText(QString name)
{
    QFont f(m_nameText->font());
    QRect r(m_rect->rect().toRect());
    
    r.setHeight(r.height()/2);
    f.setPointSizeF(fontSizeForRect(name,r));
    m_nameText->setFont(f);
    m_nameText->setPlainText(name);
}

void kdpyOutputGraphicsGroup::setSizeText(QString size)
{
    QFont f(m_sizeText->font());
    QRect r(m_rect->rect().toRect());
    
    r.setY(r.y()+r.height()/2);
    r.setHeight(r.height()/2);
    f.setPointSizeF(fontSizeForRect(size,r));
    m_sizeText->setPos(r.x(),r.y());
    m_sizeText->setFont(f);
    m_sizeText->setPlainText(size);
}

qreal kdpyOutputGraphicsGroup::fontSizeForRect(QString name, QRect r)
{
    QFont f(name, r.height());
    QFontMetrics fm(f);
//     qreal cf = (fm.ascent()/(double)r.height())
//                 + (fm.descent()/(double)r.height())
//                 - (fm.descent()/(double)fm.height());
//     return r.height()*cf;
    qreal hsize, vsize;
    hsize = (qreal)r.width()/(qreal)fm.width(name)*f.pointSizeF();
    vsize = (qreal)r.height()/(qreal)fm.height()*f.pointSizeF();
    if (hsize < vsize)
	return hsize;
    return vsize;
}

void kdpyOutputGraphicsGroup::setRectFillColor(QColor color)
{
    m_rect->setBrush(QBrush(color));
}
