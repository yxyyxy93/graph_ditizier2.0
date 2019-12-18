/********************************************************************************
** Form generated from reading UI file 'GraDigwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADIGWINDOW_H
#define UI_GRADIGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraDigwindow
{
public:
    QAction *actionload_graph;
    QAction *actionsave;
    QAction *actionload;
    QAction *actionsave_graph;
    QAction *actionl_l;
    QAction *actionl_log;
    QAction *actionlog_l;
    QAction *actionlog_log;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *xcalibrate;
    QPushButton *ycalibrate;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLCDNumber *xfactor;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLCDNumber *yfactor;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLCDNumber *xbase;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QLCDNumber *ybase;
    QGroupBox *groupBox1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *manual;
    QPushButton *auto_2;
    QPushButton *resetButton;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *axistype_combobox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton;
    QMenuBar *menubar;
    QMenu *menufiles;
    QMenu *menuaxis_types;

    void setupUi(QMainWindow *GraDigwindow)
    {
        if (GraDigwindow->objectName().isEmpty())
            GraDigwindow->setObjectName(QStringLiteral("GraDigwindow"));
        GraDigwindow->resize(1153, 641);
        actionload_graph = new QAction(GraDigwindow);
        actionload_graph->setObjectName(QStringLiteral("actionload_graph"));
        actionsave = new QAction(GraDigwindow);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionload = new QAction(GraDigwindow);
        actionload->setObjectName(QStringLiteral("actionload"));
        actionsave_graph = new QAction(GraDigwindow);
        actionsave_graph->setObjectName(QStringLiteral("actionsave_graph"));
        actionl_l = new QAction(GraDigwindow);
        actionl_l->setObjectName(QStringLiteral("actionl_l"));
        actionl_log = new QAction(GraDigwindow);
        actionl_log->setObjectName(QStringLiteral("actionl_log"));
        actionlog_l = new QAction(GraDigwindow);
        actionlog_l->setObjectName(QStringLiteral("actionlog_l"));
        actionlog_log = new QAction(GraDigwindow);
        actionlog_log->setObjectName(QStringLiteral("actionlog_log"));
        centralwidget = new QWidget(GraDigwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setEnabled(true);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        xcalibrate = new QPushButton(groupBox);
        xcalibrate->setObjectName(QStringLiteral("xcalibrate"));
        xcalibrate->setFont(font);

        verticalLayout->addWidget(xcalibrate);

        ycalibrate = new QPushButton(groupBox);
        ycalibrate->setObjectName(QStringLiteral("ycalibrate"));
        QFont font1;
        font1.setPointSize(10);
        font1.setKerning(true);
        ycalibrate->setFont(font1);

        verticalLayout->addWidget(ycalibrate);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        xfactor = new QLCDNumber(groupBox);
        xfactor->setObjectName(QStringLiteral("xfactor"));
        xfactor->setFont(font);

        horizontalLayout->addWidget(xfactor);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        yfactor = new QLCDNumber(groupBox);
        yfactor->setObjectName(QStringLiteral("yfactor"));
        yfactor->setFont(font);

        horizontalLayout_2->addWidget(yfactor);


        verticalLayout->addLayout(horizontalLayout_2);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_4->addWidget(label_10);

        xbase = new QLCDNumber(groupBox);
        xbase->setObjectName(QStringLiteral("xbase"));
        xbase->setFont(font);

        horizontalLayout_4->addWidget(xbase);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_5->addWidget(label_11);

        ybase = new QLCDNumber(groupBox);
        ybase->setObjectName(QStringLiteral("ybase"));
        ybase->setFont(font);

        horizontalLayout_5->addWidget(ybase);


        verticalLayout->addLayout(horizontalLayout_5);

        groupBox1 = new QGroupBox(groupBox);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        groupBox1->setFont(font);
        verticalLayout_2 = new QVBoxLayout(groupBox1);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        manual = new QPushButton(groupBox1);
        manual->setObjectName(QStringLiteral("manual"));
        manual->setMinimumSize(QSize(80, 0));
        manual->setFont(font);

        verticalLayout_2->addWidget(manual);

        auto_2 = new QPushButton(groupBox1);
        auto_2->setObjectName(QStringLiteral("auto_2"));
        auto_2->setFont(font);

        verticalLayout_2->addWidget(auto_2);

        resetButton = new QPushButton(groupBox1);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setFont(font);

        verticalLayout_2->addWidget(resetButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        axistype_combobox = new QComboBox(groupBox1);
        axistype_combobox->setObjectName(QStringLiteral("axistype_combobox"));
        QFont font2;
        font2.setPointSize(8);
        axistype_combobox->setFont(font2);

        horizontalLayout_3->addWidget(axistype_combobox);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_2 = new QRadioButton(groupBox1);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 3, 0, 1, 1);

        radioButton_3 = new QRadioButton(groupBox1);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 1, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox1);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 2, 0, 1, 1);

        radioButton = new QRadioButton(groupBox1);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox1);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        GraDigwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GraDigwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1153, 29));
        menufiles = new QMenu(menubar);
        menufiles->setObjectName(QStringLiteral("menufiles"));
        menuaxis_types = new QMenu(menubar);
        menuaxis_types->setObjectName(QStringLiteral("menuaxis_types"));
        GraDigwindow->setMenuBar(menubar);

        menubar->addAction(menufiles->menuAction());
        menubar->addAction(menuaxis_types->menuAction());
        menufiles->addAction(actionsave);
        menufiles->addAction(actionload);
        menuaxis_types->addAction(actionl_l);
        menuaxis_types->addAction(actionlog_l);
        menuaxis_types->addAction(actionl_log);
        menuaxis_types->addAction(actionlog_log);

        retranslateUi(GraDigwindow);

        QMetaObject::connectSlotsByName(GraDigwindow);
    } // setupUi

    void retranslateUi(QMainWindow *GraDigwindow)
    {
        GraDigwindow->setWindowTitle(QApplication::translate("GraDigwindow", "GraDigwindow", Q_NULLPTR));
        actionload_graph->setText(QApplication::translate("GraDigwindow", "load graph", Q_NULLPTR));
        actionsave->setText(QApplication::translate("GraDigwindow", "save", Q_NULLPTR));
        actionload->setText(QApplication::translate("GraDigwindow", "load", Q_NULLPTR));
        actionsave_graph->setText(QApplication::translate("GraDigwindow", "save graph", Q_NULLPTR));
        actionl_l->setText(QApplication::translate("GraDigwindow", "l-l", Q_NULLPTR));
        actionl_log->setText(QApplication::translate("GraDigwindow", "l-log", Q_NULLPTR));
        actionlog_l->setText(QApplication::translate("GraDigwindow", "log-l", Q_NULLPTR));
        actionlog_log->setText(QApplication::translate("GraDigwindow", "log-log", Q_NULLPTR));
        xcalibrate->setText(QApplication::translate("GraDigwindow", "Calibrating x", Q_NULLPTR));
        ycalibrate->setText(QApplication::translate("GraDigwindow", "Calibrating y", Q_NULLPTR));
        label_2->setText(QApplication::translate("GraDigwindow", "factors (arb./point)", Q_NULLPTR));
        label_3->setText(QApplication::translate("GraDigwindow", "X", Q_NULLPTR));
        label_4->setText(QApplication::translate("GraDigwindow", "Y", Q_NULLPTR));
        label_7->setText(QApplication::translate("GraDigwindow", "axis loc. (point) ", Q_NULLPTR));
        label_10->setText(QApplication::translate("GraDigwindow", "X", Q_NULLPTR));
        label_11->setText(QApplication::translate("GraDigwindow", "Y", Q_NULLPTR));
        manual->setText(QApplication::translate("GraDigwindow", "Manual select", Q_NULLPTR));
        auto_2->setText(QApplication::translate("GraDigwindow", "Auto select", Q_NULLPTR));
        resetButton->setText(QApplication::translate("GraDigwindow", "Reset", Q_NULLPTR));
        axistype_combobox->clear();
        axistype_combobox->insertItems(0, QStringList()
         << QApplication::translate("GraDigwindow", "linear-linear", Q_NULLPTR)
         << QApplication::translate("GraDigwindow", "linear-log", Q_NULLPTR)
         << QApplication::translate("GraDigwindow", "log-linear", Q_NULLPTR)
         << QApplication::translate("GraDigwindow", "log-log graph", Q_NULLPTR)
        );
        radioButton_2->setText(QApplication::translate("GraDigwindow", "l-log", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("GraDigwindow", "log-l", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("GraDigwindow", "log-log", Q_NULLPTR));
        radioButton->setText(QApplication::translate("GraDigwindow", "l-l", Q_NULLPTR));
        menufiles->setTitle(QApplication::translate("GraDigwindow", "files", Q_NULLPTR));
        menuaxis_types->setTitle(QApplication::translate("GraDigwindow", "axis types", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GraDigwindow: public Ui_GraDigwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADIGWINDOW_H
