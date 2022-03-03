#ifndef MYLAVEL_H
#define MYLAVEL_H

#include <QLabel>

class mylavel : public QLabel
{
    Q_OBJECT
public:
    explicit mylavel(QWidget *parent = nullptr);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent *);
    void mouseMoveEvent(QMouseEvent *ev);
    
signals:

};

#endif // MYLAVEL_H
