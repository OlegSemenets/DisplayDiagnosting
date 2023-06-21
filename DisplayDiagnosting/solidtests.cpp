#include "solidtests.h"

#include <QGuiApplication>
#include <QKeyEvent>
#include <QMap>
#include <QScreen>

SolidTests::SolidTests(bool isAutoTest, size_t delay, QWidget *parent)
    : QWidget{parent}
    , m_IsAutoTest{isAutoTest}
    , m_Delay{delay}
{
    backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: green;");
    backButton->setGeometry(
        QRect(QPoint(QGuiApplication::primaryScreen()->geometry().width() - 35, 5), QSize(30, 30)));
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    m_TestIndex = 0;
    setFocusPolicy(Qt::StrongFocus);

    if (m_IsAutoTest) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &SolidTests::SimulateRightArrowKey);
        timer->start(m_Delay * 1000);
    }
}

SolidTests::~SolidTests()
{
    if (backButton != nullptr)
        delete backButton;
    if (timer != nullptr)
        delete timer;
}

void SolidTests::MakeTest(int indexOfList)
{
    setStyleSheet(QString("background-color: %1;").arg(m_ColorList[indexOfList].name()));
}

void SolidTests::SimulateRightArrowKey()
{
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    keyPressEvent(event);
    delete event;
}

void SolidTests::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        m_TestIndex = (m_TestIndex - 1 + m_ColorList.size()) % m_ColorList.size();
        MakeTest(m_TestIndex);
        break;
    case Qt::Key_Right:
        m_TestIndex = (m_TestIndex + 1) % m_ColorList.size();
        MakeTest(m_TestIndex);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}
