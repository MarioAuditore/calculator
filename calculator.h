#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QObject>
#include <QString>


class Calculator: public QObject
{
    Q_OBJECT
public:
   explicit Calculator(QObject *parent = 0) : QObject(parent), mSum(0), last_operation("none"),flag_count(0),
        displayValue(0), mMaxValue(999999999),flag_frac(0),frac_pow(1) {};
signals:
    void valueChanged(double value);
public slots:
    void digitButtonPressed(int button);
    void operationButtonPressed(const QString value);
private:
    double mSum;
    double displayValue;
    QString last_operation;
    int flag_count;
    int flag_frac;
    int frac_pow;
    int mMaxValue;
};

#endif // CALCULATOR_H
