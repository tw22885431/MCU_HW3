#include "square.h"
#include <QString>

square::square(const int size, const square::Direction direction )
{

    resize(size, direction);

}

int square::size() const {

    return _size;

}

void square::resize(const int size , const square::Direction direction){

    _size = size;

    QModelIndex Top = index(0,0);

    QModelIndex bottom = index(_size,_size);

    emit layoutAboutToBeChanged();

    _realloc();

    if (_size % 2)

        excute(direction);

    else

        excute2();

    emit dataChanged(Top,bottom);

    emit layoutChanged();


}

void square::_realloc(){

    delete [] square_value;

    square_value = new int[_size * _size]{};
}

int square::columnCount(const QModelIndex &) const{

    return _size + 1;

}

int square::rowCount(const QModelIndex &) const{

   return _size + 1;

}

QVariant square::data(const QModelIndex &index, int role) const{

    switch (role){

        case:: Qt::DisplayRole:

            if (index.row() == _size && index.column() == _size){

                int sum1 = 0,sum2=0;

                for (int i = 0;i< _size;i++){

                    sum1 += square_value[PositionCount(i,i)];

                    sum2 += square_value[PositionCount(_size-i -1,i)];

                }

                return QString("↖︎%1\n↗︎%2").arg(QString::number (sum1)).arg(QString::number(sum2));

            }

            if (index.row() == _size){

                int sum = 0;

                for (int i = 0;i<_size;i++)

                    sum += square_value[Position(i,index.column())];

                return QString("←%1").arg(QString :: number(sum));

            }

            if(index.column()== _size){

                int sum = 0;

                for (int i = 0;i<_size;i++)

                    sum+= square_value[Position(index.row(),i)];

                return QString("↑%1").arg(QString :: number(sum));

            }

            return square_value[PositionCount(index.row(),index.column())];
    }

    return QVariant();

}

void square::excute(Direction direction){

    int x = _size/2;

    int y = 0;

    int value = 1;

    square_value[PositionCount(x,y)] = value;

    while (value++ < _size*_size){

        int NextX = x,NextY= y;

        switch (direction) {

            case Direction::Left_To_Up:

                --NextX;

                --NextY;

                break;

            case Direction::Left_To_Down:

                --NextX;

                ++NextY;

                break;

            case Direction::Right_To_Up:

                ++NextX;

                --NextY;

                break;

            case Direction::Right_To_Down:

                ++NextX;

                ++NextY;

                break;

        }

        if (square_value[Position(NextX,NextY)]){

            if (direction == Left_To_Up || direction == Right_To_Up)

                --y;

            else

                ++y;

        }

        else{

            x = NextX;

            y = NextY;

        }

        square_value[Position(NextX,NextY)] = value;

    }

}

void square::excute2(){}

int square::PositionCount(const int x, const int y) const{

    int _x = x;

    int _y = y;

    return Position(_x,_y);

}

int square::Position(int &x, int &y){

    x = (x+_size)%_size;

    y = (y+_size)%_size;

    return x + y*_size;

}
