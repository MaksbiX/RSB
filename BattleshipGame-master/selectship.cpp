
#include "selectship.h"
#include "displayships.h"

selectship::selectship(QGraphicsScene *Mscene, int num)
{
    scene = Mscene;

    shipnum = num;

    shipsize = shipnum + 2;

    Show = true;
    Sunk = false;


    orient = 0;

}

QRectF selectship::boundingRect() const
{
    switch(shipsize)
    {
    case 2:
        return QRectF(0,0,30,20);
        break;
    case 3:
        return QRectF(0,30,50,20);
        break;
    case 4:
        return QRectF(0,60,70,20);
        break;
    case 5:
        return QRectF(0,90,90,20);
        break;
    }
    return QRectF(0,0,0,0);
}


void selectship::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    if(Show)
    {
        brush.setColor(Qt::green);
    }
    else
    {
        brush.setColor(Qt::white);
    }

    if (Sunk ==true)
    {
        brush.setColor(Qt::red);
    }


    painter->fillRect(rec,brush);
    // painter->drawEllipse(rec);
    painter->drawRect(rec);
}


void selectship::DrawShip()
{


}


void selectship::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *)
{
    emit Clicked(shipnum);

    if(displayships::phaseIsSetupShips)
        delete this;

}


void selectship::OnSunk(int shipvalue)
{
    if(shipvalue == shipnum)
    {
        Sunk = true;
    }
    update();
}
