#include "GraDigwindow.h"
#include "ui_GraDigwindow.h"
#include "stdio.h"

GraDigwindow::GraDigwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraDigwindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(graph);
}

GraDigwindow::~GraDigwindow()
{
    delete ui;
    delete graph;
}

// axis calibration
void GraDigwindow::mousePressEvent(QMouseEvent *event)
{
    QPointF pt_scene = ui->graphicsView->mapToScene(event->pos());
    pt_scene.operator-=(QPoint(xbias, ybias));

    if(xflag) {
        CalibrationVector.push_back(pt_scene);  // Add the point object to the calibration vector
        graph->addRect(pt_scene.x()-rad, pt_scene.y()-rad, rad*2.0, rad*2.0, QPen(), QBrush(Qt::SolidPattern));
        xCalibrationCheck(); // A function to verify that the calibration is done andto calculate the Lengend's length
    }
    if(yflag) {
        CalibrationVector.push_back(pt_scene); // Add the point object to the distance vector
        graph->addRect(pt_scene.x()-rad, pt_scene.y()-rad, rad*2.0, rad*2.0, QPen(), QBrush(Qt::SolidPattern));

        yCalibrationCheck(); // A variable to record the total measured distance
    }
    if (manualflag){
        CalibrationVector.push_back(pt_scene);  // Add the point object to the calibration vector
        graph->addEllipse(pt_scene.x()-rad, pt_scene.y()-rad, rad*2.0, rad*2.0, QPen(), QBrush(Qt::SolidPattern));
    }
    if (autoflag){
        QImage mimg = map.toImage();
        // judge the minimum point
        int count=0; // limit the number of points too 100
        try {
            while (pt_scene.x()-x_sr>=y_base && count <= 100){
//            qDebug() << pts[0].x() << "y_base" << y_base;
                autoit(pt_scene, mimg);
                count++;
            }
        }
        catch (std::runtime_error & e) {
            qDebug() << "runtime is too long";
            e.what();
        }
    }
}

void GraDigwindow::xCalibrationCheck() // This function is called to check and finish calibration
{
    if (CalibrationVector.size()==2) // We need only two points to finish calibration
    {
        // check whether select right point
        if (abs(CalibrationVector[0].y()-CalibrationVector[1].y()) >=10){
            QMessageBox msgBox;
            msgBox.setText("The calibrating points might not be correctly chosen.");
            msgBox.exec();
        }

        x_base += CalibrationVector[1].y();
        xflag=false; // Switching off calibration as soon as we have two points
        bool ok; // This boolean varaible is True if the user accepts the dialog and false if they rejec the dialog (press "Cancel" intead of "OK")

        // Shows a dialog to ask the user for the length of the legend
        x_length = QInputDialog::getDouble(this, tr("X factor (the log index for log axis)"),tr("Enter the x  factor in units of arb. "), 0, -1000, 1000, 1, &ok);
        x_Calibration_factor = x_length/CalculateDistance(CalibrationVector); // Calculates the calibration facto
        x_base = x_base/2;

        // Shows a dialog to ask the user for the base corrodinate
        x_Calibration_base = QInputDialog::getDouble(this, tr("X base (the log index for log axis)"),tr("Enter the x base in units of arb."), 0, -1000, 1000, 1, &ok);

        ui->xfactor->display(x_Calibration_factor);
        ui->xbase->display(x_base);
        CalibrationVector.clear(); // Clears the vector for calibration to allow for recalibration if needed
    }
    else {
        x_base += CalibrationVector[0].y();
    }
}

void GraDigwindow::yCalibrationCheck() // This function is called to check and finish calibration
{
    if (CalibrationVector.size()==2) // We need only two points to finish calibration
    {
        // check whether select right point
        if (abs(CalibrationVector[0].x()-CalibrationVector[1].x()) >=10){
            QMessageBox msgBox;
            msgBox.setText("The calibrating points might not be correctly chosen.");
            msgBox.exec();
        }

        y_base += CalibrationVector[1].x();
        yflag=false; // Switching off calibration as soon as we have two points

        bool ok; // This boolean varaible is True if the user accepts the dialog and false if they rejec the dialog (press "Cancel" intead of "OK")

        // Shows a dialog to ask the user for the length of the legend
        y_length = QInputDialog::getDouble(this, tr("Y factor (the log index for log axis)"),tr("Enter the y length in units of arb."), 0, -1000, 1000, 1, &ok);
        y_Calibration_factor = y_length/CalculateDistance(CalibrationVector); // Calculates the calibration factor
        y_base = y_base/2;

        // Shows a dialog to ask the user for the base corrodinate
        y_Calibration_base = QInputDialog::getDouble(this, tr("Y base (the log index for log axis)"),tr("Enter the y base in units of arb."), 0, -1000, 1000, 1, &ok);

        ui->yfactor->display(y_Calibration_factor);
        ui->ybase->display(y_base);

        CalibrationVector.clear(); // Clears the vector for calibration to allow for recalibration if needed
    }
    else {
        y_base += CalibrationVector[0].x();
    }
}

double GraDigwindow::CalculateDistance(QVector<QPointF>& clickedPoints) // This function calculates the total distance among points saved in a vector
{
    double overall_distance=0; // The total distance variable

    for (int i=1;i<clickedPoints.size();i++) // Iterating over the length of the vector
        {
           // This is an implementation of the distance formula
           overall_distance += qSqrt(qPow(clickedPoints[i].x()-clickedPoints[i-1].x(),2)+qPow(clickedPoints[i].y()-clickedPoints[i-1].y(),2));
        }
    return overall_distance;
}

void GraDigwindow::on_xcalibrate_clicked()
{
    xflag = true; // Sets the x calibration flag to True
    manualflag = false;
    autoflag = false;
    yflag=false;
}

void GraDigwindow::on_ycalibrate_clicked()
{
    yflag = true; // Sets the x calibration flag to True
    manualflag = false;
    autoflag = false;
    xflag=false;
}

void GraDigwindow::autoit(QPointF &pt_scene, QImage img)
{
    int min_pix=255;
    int min_x=0;
    int min_y=0;

    for (int i=-x_sr/2; i<x_sr/2; i++) {
        for (int j= -y_sr/2; j<y_sr/2; j++) {
            int gray = qGray(img.pixel(int(pt_scene.x())+j, int(pt_scene.y()) +i));
            if (gray<min_pix){ // save the light (min) part
                min_pix = gray;
                min_x = j;
                min_y = i;
            }
        }
    }

    // change the pt to the minimum point
    pt_scene.operator+=(QPointF(min_x, min_y));

    // save the min pt
    CalibrationVector.push_back(pt_scene);

    qDebug() << min_x << min_y << qGray(img.pixel(min_x, min_y));
    // show one auto point
    graph->addEllipse(pt_scene.x()-rad, pt_scene.y()-rad, rad*2.0, rad*2.0, QPen(), QBrush(Qt::SolidPattern));
}

QVector<double> GraDigwindow::CalculateCoordinate(QPointF p, int flag)
{
    QVector<double> coordinate;

    double xc = (p.x()-y_base)*x_Calibration_factor + x_Calibration_base;
    double yc = (x_base - p.y())*y_Calibration_factor + y_Calibration_base;
    switch (flag){
    case 1: // linear-linear
        coordinate.push_back(xc);
        coordinate.push_back(yc);
    case 2: //linear-log
        coordinate.push_back(xc);
        coordinate.push_back(pow(10, yc));
    case 3: // log-linear
        coordinate.push_back(pow(10, xc));
        coordinate.push_back(yc);
    case 4: //log-log
        coordinate.push_back(pow(10, xc));
        coordinate.push_back(pow(10, yc));
    }
    return coordinate;
}

// menu actions
void GraDigwindow::on_actionsave_triggered()
{ // Called whenver a "Save" action is initiated

    // Read the notes written in the widget to the code:
    // Opening the save file dialog:
    QString filename=QFileDialog::getSaveFileName(this,tr("Save points"),tr("*.csv"));

    // Creating the file to be saved (and setting it in the write mode):
    QFile file(filename);

    file.open(QIODevice::WriteOnly);

    // "Flushing" the text into a saved file:
    QTextStream out(&file); // By reference because we don't want "copies" of our file

    // save the results of coordinate
    QVector<double> coordinatexy;
    out << "x:" << ",";
    for (int i=0; i< CalibrationVector.size(); i++){
        coordinatexy = CalculateCoordinate(CalibrationVector[i], axistype);
        out << coordinatexy[0] << ",";

    }

    out << "\n";
    out << "y:" << ",";
    for (int i=0; i< CalibrationVector.size(); i++){
        coordinatexy = CalculateCoordinate(CalibrationVector[i], axistype);
        out << coordinatexy[1] << ",";
//        out << "\n";
    }

    //Finally, close the file
    file.close();
}

void GraDigwindow::on_actionload_triggered() // the same function as "load graph" button
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Load Graph"),tr("*.png")); // Allows the usr to choose an input file

    map = QPixmap(filename); // Saves the file in a a QPixmap object

    graph->addPixmap(map); // Adds the pixmap to the scene
}

//*************** axis type choose*****
// by menu
void GraDigwindow::on_actionl_l_triggered()
{
    axistype=1;
}

void GraDigwindow::on_actionl_log_triggered()
{
    axistype=2;
}

void GraDigwindow::on_actionlog_l_triggered()
{
    axistype=3;
}

void GraDigwindow::on_actionlog_log_triggered()
{
    axistype=4;
}

// by combobox
void GraDigwindow::on_axistype_combobox_currentIndexChanged(int index)
{
    axistype = index;
}

//radioButton
void GraDigwindow::on_radioButton_clicked()
{
    axistype=1;
}

void GraDigwindow::on_radioButton_2_clicked()
{
    axistype=2;
}

void GraDigwindow::on_radioButton_3_clicked()
{
    axistype=3;
}

void GraDigwindow::on_radioButton_4_clicked()
{
    axistype=4;
}

//******************************

void GraDigwindow::on_manual_clicked()
{
    manualflag = true; //sets the selcet to True
    xflag = false;
    yflag = false;
    autoflag = false;
}

void GraDigwindow::on_resetButton_clicked()
{
    CalibrationVector.clear();
    graph->clear();
}

void GraDigwindow::on_auto_2_clicked()
{
    autoflag = true;
    manualflag = false; //sets the selcet to True
    xflag = false;
    yflag = false;
}
