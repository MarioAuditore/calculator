#include <QSignalMapper>
#include "dialog.h"
#include "ui_dialog.h"
#include "calculator.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QSignalMapper* digit_mapper = new QSignalMapper(0);

    digit_mapper->setMapping(ui->pushButton_0, 0);
    connect(ui->pushButton_0, SIGNAL(clicked()), digit_mapper, SLOT(map()));


    digit_mapper->setMapping(ui->pushButton_1, 1);
    connect(ui->pushButton_1, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_2, 2);
    connect(ui->pushButton_2, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_3, 3);
    connect(ui->pushButton_3, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_4, 4);
    connect(ui->pushButton_4, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_5, 5);
    connect(ui->pushButton_5, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_6, 6);
    connect(ui->pushButton_6, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_7, 7);
    connect(ui->pushButton_7, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_8, 8);
    connect(ui->pushButton_8, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    digit_mapper->setMapping(ui->pushButton_9, 9);
    connect(ui->pushButton_9, SIGNAL(clicked()), digit_mapper, SLOT(map()));

    QSignalMapper* sign_mapper = new QSignalMapper(0);

    sign_mapper->setMapping(ui->pushButton_dot, ".");
    connect(ui->pushButton_dot, SIGNAL(clicked()), sign_mapper, SLOT(map()));

    sign_mapper->setMapping(ui->pushButton_plus, "+");
    connect(ui->pushButton_plus, SIGNAL(clicked()), sign_mapper, SLOT(map()));


    sign_mapper->setMapping(ui->pushButton_minus, "-");
    connect(ui->pushButton_minus, SIGNAL(clicked()), sign_mapper, SLOT(map()));

    sign_mapper->setMapping(ui->pushButton_multiply, "*");
    connect(ui->pushButton_multiply, SIGNAL(clicked()), sign_mapper, SLOT(map()));

    sign_mapper->setMapping(ui->pushButton_divide, "/");
    connect(ui->pushButton_divide, SIGNAL(clicked()), sign_mapper, SLOT(map()));

    sign_mapper->setMapping(ui->pushButton_equal, "=");
    connect(ui->pushButton_equal, SIGNAL(clicked()), sign_mapper, SLOT(map()));

    sign_mapper->setMapping(ui->pushButton_reset, "C");
    connect(ui->pushButton_reset, SIGNAL(clicked()), sign_mapper, SLOT(map()));



    void  mappedInt(int i);
    //void  mappedInt(double i);
    void  mappedObject(QObject *object);
    void  mappedString(const QString &text);
    void  mappedWidget(QWidget *widget);

    Calculator * calculator = new Calculator(0);
    connect(digit_mapper, SIGNAL(mappedInt(int)), calculator, SLOT(digitButtonPressed(int)));
    connect(calculator, SIGNAL(valueChanged(double)), ui->lcdNumber, SLOT(display(double)));
    //connect(calculator, SIGNAL(valueChanged(QString)), ui->lcdNumber, SLOT(display(const QString)));
    connect(sign_mapper, SIGNAL(mappedString(const QString)), calculator, SLOT(operationButtonPressed(const QString)));
}

Dialog::~Dialog()
{
    delete ui;
}

