#ifndef CALIBRAIONTESTS_H
#define CALIBRAIONTESTS_H

#include <QColor>
#include <QLabel>
#include <QList>
#include <QPushButton>
#include <QString>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

enum CalibraionTestTypes : int {
    NONE_TEST = -1,
    LCD_ = 0,
    SCOPE_,
    BRIGHTNES_,
};

class CalibraionTests : public QWidget
{
    Q_OBJECT
public:
    explicit CalibraionTests(bool isAutoTest, size_t delay, QWidget *parent = nullptr);
    ~CalibraionTests();
    void SetCalibrationList(QList<int> calibraionCodeList)
    {
        m_CalibraionCodeList = calibraionCodeList;
    }
    void MakeTest(int indexOfList);
    void SimulateRightArrowKey();
signals:

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int m_TestIndex;
    bool m_IsAutoTest;
    size_t m_Delay;
    QList<int> m_CalibraionCodeList;
    CalibraionTestTypes m_TestType;
    QPushButton *backButton;
    QTimer *timer;
    QLabel *picture;
};

#endif // CALIBRAIONTESTS_H
