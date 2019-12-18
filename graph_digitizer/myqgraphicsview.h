
#include <QGraphicsView>
 #include <QGraphicsScene>
 #include <QGraphicsEllipseItem>
 #include <QMouseEvent>

 class MyQGraphicsView : public QGraphicsView
 {
     Q_OBJECT
 public:
     explicit MyQGraphicsView(QWidget *parent = 0);

 signals:

 public slots:
     void mousePressEvent(QMouseEvent * e);
     // void mouseReleaseEvent(QMouseEvent * e);
     // void mouseDoubleClickEvent(QMouseEvent * e);
     // void mouseMoveEvent(QMouseEvent * e);
 private:
     QGraphicsScene * scene;
 };
