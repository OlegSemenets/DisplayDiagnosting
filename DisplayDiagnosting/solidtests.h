
#ifndef SOLIDTESTS_H
#define SOLIDTESTS_H

#include <QColor>
#include <QList>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

class SolidTests : public QWidget
{
    Q_OBJECT
public:
    explicit SolidTests(bool isAutoTest, size_t delay, QWidget *parent = nullptr);
    ~SolidTests();
    void SetColorList(QList<QColor> colorList) { m_ColorList = colorList; }
    void MakeTest(int indexOfList);
    void SimulateRightArrowKey();
signals:

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int m_TestIndex;
    bool m_IsAutoTest;
    size_t m_Delay;
    QList<QColor> m_ColorList;
    QPushButton *backButton;
    QTimer *timer;
};

#endif // SOLIDTESTS_H
