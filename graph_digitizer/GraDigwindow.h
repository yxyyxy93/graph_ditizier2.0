#ifndef GraDigwindow_H
#define GraDigwindow_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFileDialog>
#include <QMouseEvent>
#include <QVector>
#include <QInputDialog>
#include <QtMath>
#include <QPointF>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class GraDigwindow; }
QT_END_NAMESPACE

class GraDigwindow : public QMainWindow
{
    Q_OBJECT

public:
    GraDigwindow(QWidget *parent = nullptr);
    ~GraDigwindow();

private slots:
    void on_actionsave_triggered();
    void on_actionload_triggered();

    // mouse press events
    void mousePressEvent(QMouseEvent *event);
    void xCalibrationCheck(); // Function to check if the calibration phase is finished or not
    void yCalibrationCheck(); // Function to check if the calibration phase is finished or not
    double CalculateDistance(QVector<QPointF>& clickedPoints); // Function to calculate the overall distance between all points in a vector

    void on_xcalibrate_clicked();
    void on_ycalibrate_clicked();

    // selet and calculate the coordinate
    QVector<double> CalculateCoordinate(QPointF f, int flag);

    void on_axistype_combobox_currentIndexChanged(int index);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_manual_clicked();

    void on_resetButton_clicked();

    void on_auto_2_clicked();

private:
    Ui::GraDigwindow *ui;
    QGraphicsScene *graph=new QGraphicsScene();

    //calibration flags
    bool xisCalibrating=false; // flag to indicate whether the app is in x calibrtion mode or not
    bool yisCalibrating=false; // flag to indicate whether the app is in y calibrtion mode or not

    QVector<QPointF> CalibrationVector;  // Vector for saving the calibration points

    //calibrating lengths
    double x_length=0; // Varaible to save the physical length of the x axis
    double y_length=0; // Varaible to save the physical length of the y axis
    double x_Calibration_factor=0; // Varaible to save the calibration factor x
    double y_Calibration_factor=0; // Varaible to save the calibration factor y
    double x_base=0;
    double y_base=0;
    double x_Calibration_base=0;
    double y_Calibration_base=0;

    //select
    bool manualflag=false;
    bool autoflag=false;
    int axistype=1;

    // map
    QPixmap map;

    // there are biases when adding the indication on graph
    int xbias = 14;
    int ybias = 38;
    double rad = 4; // radius of the indication
    // search range
    int x_sr = 30;
    int y_sr = 30;

    // find the points automatically
    void autoit(QPointF &pt_scene, QImage img);
};
#endif // GraDigwindow.H
