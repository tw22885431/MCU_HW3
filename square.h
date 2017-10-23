#ifndef SQUARE_H
#define SQUARE_H
//#include <>

#include <QAbstractTableModel>

class square : public QAbstractTableModel
{

public:

    enum Direction{

        Left_To_Down,

        Left_To_Up,

        Right_To_Up,

        Right_To_Down,

        Default = Left_To_Up,

    };

    square(const int size = 3, const Direction direction = Direction::Default);

    ~square();

    int size() const;

    QVariant data(const QModelIndex &index, int role) const;

    int rowCount(const QModelIndex &) const;

    int columnCount(const QModelIndex &) const;

    void resize(const int size , const square::Direction direction);

    int _size;

private:

    void _realloc();

    int *square_value;

    int Position(int &, int &);

    int PositionCount(const int x, const int y) const;

    void excute(Direction direction);

    void excute2();

};

#endif // SQUARE_H
