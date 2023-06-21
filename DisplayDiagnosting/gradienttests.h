
#ifndef GRADIENTTESTS_H
#define GRADIENTTESTS_H

#include <QColor>
#include <QList>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

class GradientTests : public QWidget
{
    Q_OBJECT
public:
    explicit GradientTests(bool isAutoTest, size_t delay, QWidget *parent = nullptr);
    ~GradientTests();
    void SetColorList(QList<QColor> colorList) { m_GradientList = colorList; }
    void MakeTest(int indexOfList);
    void SimulateRightArrowKey();
signals:

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int m_TestIndex;
    bool m_IsAutoTest;
    size_t m_Delay;
    QList<QColor> m_GradientList;
    QPushButton *backButton;
    QTimer *timer;
};

#endif // GRADIENTTESTS_H
