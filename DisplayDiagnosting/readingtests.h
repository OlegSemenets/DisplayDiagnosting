
#ifndef READINGTESTS_H
#define READINGTESTS_H

#include <QColor>
#include <QList>
#include <QPaintEvent>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

enum ReadingTestsType : int { WhiteOnBlack = 0, BlackOnWhite, BlueOnGreen, YellowOnBlue };

class ReadingTests : public QWidget
{
    Q_OBJECT
public:
    explicit ReadingTests(bool isAutoTest, size_t delay, QWidget *parent = nullptr);
    ~ReadingTests();
    void SetReadingList(QList<int> readingList) { m_ReadingList = readingList; }
    void MakeTest(int indexOfList);
    void SimulateRightArrowKey();
    void paintEvent(QPaintEvent *event) override;
signals:

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int m_TestIndex;
    bool m_IsAutoTest;
    size_t m_Delay;
    QList<int> m_ReadingList;
    QPushButton *backButton;
    QTimer *timer;
    QColor m_BackGroundColor;
    QColor m_TextColor;
};

#endif // READINGTESTS_H
