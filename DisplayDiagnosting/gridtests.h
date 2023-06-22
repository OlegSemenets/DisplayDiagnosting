
#ifndef GRIDTESTS_H
#define GRIDTESTS_H

#include <QColor>
#include <QImage>
#include <QLabel>
#include <QList>
#include <QPushButton>
#include <QString>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

class GridTests : public QWidget
{
    Q_OBJECT
public:
    explicit GridTests(bool isAutoTest, size_t delay, QColor background, QWidget *parent = nullptr);
    ~GridTests();
    void SetGridColorList(QList<QColor> gridColorList) { m_GridColorList = gridColorList; }
    void MakeTest(int indexOfList);
    void SimulateRightArrowKey();
signals:

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    void createGridImage(QColor gridColor);

private:
    int m_TestIndex;
    bool m_IsAutoTest;
    size_t m_Delay;
    QList<QColor> m_GridColorList;
    QColor m_BackGroundColor;
    QPushButton *backButton;
    QTimer *timer;
    QLabel *picture;
};

#endif // GRIDTESTS_H
