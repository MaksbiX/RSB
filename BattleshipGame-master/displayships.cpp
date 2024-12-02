#include "displayships.h"
#include "vars.h"
#include <QDebug>

displayships::displayships(QGraphicsScene *Mscene, int num)
{
    scene = Mscene;

    Pressed = false;

    shipnum = num;

    shipsize = shipnum+2;



    orient = 0;
    orientations[shipnum] = 0;
    x_pos[shipnum] = this->pos().x();
    y_pos[shipnum] = this->pos().y();
    setFlag(ItemIsMovable);
    // DrawShip();
}

QRectF displayships::boundingRect() const
{
    switch(shipsize)
    {
    case 2:
        return QRectF(0,0,SQUARE,SQUARE*2);
        break;
    case 3:
        return QRectF(0,0,SQUARE,SQUARE*3);
        break;
    case 4:
        return QRectF(0,0,SQUARE,SQUARE*4);
        break;
    case 5:
        return QRectF(0,0,SQUARE,SQUARE*5);
        break;
    }
    return QRectF();
}

void displayships::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    if(Pressed)
    {
        brush.setColor(Qt::red);
    }
    else
    {
        brush.setColor(Qt::green);
    }



    painter->fillRect(rec,brush);
    // painter->drawEllipse(rec);
    painter->drawRect(rec);
}


void displayships::DrawShip()
{

}


void displayships::ReOrientShip()
{
    QPointF xandy;

    int currentX;
    int currentY;

    xandy = pos();

    currentX = xandy.x();
    currentY = xandy.y();


    if (orient == 0)
    {
        orient = 1;
        orientations[shipnum] = 1;
        setX(currentX + 65);
        setY(currentY + 50);
        setRotation(SQUARE*3);
    }
    else
    {
        orient = 0;
        orientations[shipnum] = 0;
        setX(currentX - 65);
        setY(currentY - 50);
        setRotation(0);
    }
    update();
}


void displayships::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(phaseIsSetupShips)
    {
            Pressed = true;
        update();
        QGraphicsItem::mousePressEvent(event);
    }
}


void displayships::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
if(phaseIsSetupShips)
{
        ReOrientShip();

    QGraphicsItem::mouseDoubleClickEvent(event);
}
}


void displayships::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
if(phaseIsSetupShips)
{
    Pressed = false;

    QPointF xandy;

    int x;
    int y;

    int currentX;
    int currentY;

    xandy = pos();

    currentX = xandy.x();
    currentY = xandy.y();



    if (currentY < 0)
    {
        setY(0);
    }

    if (currentX < 0)
    {
        x = 0;
    }
    else
    {
        x = (currentX / SQUARE * SQUARE);
        if ((currentX % SQUARE) >= (SQUARE/2))
        {
            x = x + SQUARE;
        }
    }

    if (currentY < 0)
    {
        y = 0;
    }
    else
    {
        y = (currentY / SQUARE * SQUARE);
        if ((currentY % SQUARE) >= (SQUARE/2))
        {
            y = y + SQUARE;
        }
    }

    if (orient == 0)
    {
        if (x > ((SQUARE * WID) - SQUARE))
        {
            x = (SQUARE * WID) - SQUARE;
        }

        if (y > ((SQUARE * WID)  - (SQUARE*shipsize)))
        {
            y = (SQUARE * WID) - (SQUARE*shipsize);
        }
    }
    else
    {
        if (y > ((SQUARE * WID) - SQUARE))
        {
            y = (SQUARE * WID) - SQUARE;
        }

        if (x > ((SQUARE * WID)))
        {
            x = (SQUARE * WID);
        }

        if (x < (SQUARE*shipsize))
        {
            x = (SQUARE*shipsize);
        }
    }
    setX(x);
    setY(y);

    bool pass = false;
    while(pass==false)
    {
        pass = true;
    }

    x_pos[shipnum] = this->pos().x();
    y_pos[shipnum] = this->pos().y();
    update();
    QGraphicsItem::mouseReleaseEvent(event);
    emit displayship_clicked(shipnum);
}
}


void displayships::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
if(phaseIsSetupShips)
{
    x_pos[shipnum] = this->pos().x();
    y_pos[shipnum] = this->pos().y();
    update();
    QGraphicsItem::mouseMoveEvent(event);
}
}
