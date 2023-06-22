
#ifndef FOCUSTESTS_H
#define FOCUSTESTS_H

#include <QColor>
#include <QLabel>
#include <QList>
#include <QPushButton>
#include <QString>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

enum FocusTestTypes : int {
    NONE_FOCUS_TEST = -1,
    WHITEPATTERN = 0,
    BLACKPATTERN,
    SHARPNES,
};

class FocusTests : public QWidget
{
    Q_OBJECT
public:
    explicit FocusTests(bool isAutoTest, size_t delay, QWidget *parent = nullptr);
    ~FocusTests();
    void SetFocusList(QList<int> focusCodeList) { m_FocusCodeList = focusCodeList; }
    void MakeTest(int indexOfList);
    void SimulateRightArrowKey();
signals:

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int m_TestIndex;
    bool m_IsAutoTest;
    size_t m_Delay;
    QList<int> m_FocusCodeList;
    FocusTestTypes m_TestType;
    QPushButton *backButton;
    QTimer *timer;
    QLabel *picture;
};

#endif // FOCUSTESTS_H
