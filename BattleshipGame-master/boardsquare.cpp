#include "boardsquare.h"



boardsquare::boardsquare(QGraphicsScene *Mscene, int size, int x, int y, int n, int m)
{
    x_pos = x;
    y_pos = y;
    squaresize = size;
    scene = Mscene;

    doIt = 0;

    n_array = n;
    m_array = m;


    setFlag(ItemIsSelectable);
    scene->addItem(this);

}

QRectF boardsquare::boundingRect() const
{
    return QRectF(x_pos, y_pos, squaresize, squaresize);
}

void boardsquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::gray);

    if (doIt == 0)
    {
        brush.setColor(Qt::gray);
    }
    else if (doIt == 64)
    {
        brush.setColor(Qt::green);
    }
    else if (doIt == 1)
    {
        brush.setColor(Qt::blue);
    }
    else if (doIt == 2)
    {
        brush.setColor(Qt::red);
    }
    painter->fillRect(rec,brush);

    painter->drawRect(rec);
}


void boardsquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}


void boardsquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit Clicked(n_array, m_array);

    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void boardsquare::OnReceiveOrders(int n, int m, int doThis)
{
    if (n == n_array && m == m_array)
    {
        setEnabled(false);
        doIt = doThis;
        update();
    }
}


